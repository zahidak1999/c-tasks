#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class SimpleWebServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint server_endpoint;
  tcp::acceptor server_acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    async_read_until(connection->socket, *read_buffer, "\r\n",
                     [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                       if (!ec) {
                         istream read_stream(read_buffer.get());
                         std::string request_line;
                         getline(read_stream, request_line);

                         // Print the request
                         cout << "Received request: " << request_line << endl;

                         // Prepare the response
                         std::string response;

                         if (request_line.find("GET / HTTP/1.1") == 0) {
                           // Respond to root route "/"
                           response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nDette er hovedsiden";
                         } else if (request_line.find("GET /en_side HTTP/1.1") == 0) {
                           // Respond to "/en_side" route
                           response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nDette er en side";
                         } else {
                           // Respond with 404 Not Found for everything else
                           response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found";
                         }

                         auto write_buffer = make_shared<std::string>(response);
                         async_write(connection->socket, boost::asio::buffer(*write_buffer),
                                     [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                       if (!ec) {
                                         connection->socket.shutdown(tcp::socket::shutdown_both);
                                         connection->socket.close();
                                       }
                                     });
                       }
                     });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_service);

    // Accepts a new (client) connection. On connection, immediately start accepting a new connection
    server_acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  SimpleWebServer() : server_endpoint(tcp::v4(), 8080), server_acceptor(io_service, server_endpoint) {}

  void runServer() {
    accept();
    io_service.run();
  }
};

int main() {
  SimpleWebServer web_server;

  cout << "Starting simple web server" << endl
       << "Test in a browser: http://localhost:8080 or http://localhost:8080/en_side" << endl;

  web_server.runServer();
}
