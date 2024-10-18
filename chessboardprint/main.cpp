#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      return (color == Color::WHITE) ? "white" : "black";
    }

    virtual std::string type() const = 0;
    virtual char representation() const = 0;
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color) {}
    std::string type() const override {
      return color_string() + " king";
    }
    char representation() const override {
      return (color == Color::WHITE) ? 'K' : 'k';
    }
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx <= 1 && dy <= 1);
    }
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color) {}
    std::string type() const override {
      return color_string() + " knight";
    }
    char representation() const override {
      return (color == Color::WHITE) ? 'N' : 'n';
    }
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }
  };

  ChessBoard() {
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  vector<vector<unique_ptr<Piece>>> squares;

  // Function objects for handling events
  function<void(const Piece &, const string &, const string &)> on_piece_move;
  function<void(const Piece &, const string &)> on_piece_removed;
  function<void(Color)> on_lost_game;
  function<void(const Piece &, const string &, const string &)> on_invalid_move;
  function<void(const string &)> on_no_piece;
  function<void()> after_piece_move;

  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        if (on_piece_move)
          on_piece_move(*piece_from, from, to);
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            if (on_piece_removed)
              on_piece_removed(*piece_to, to);
            if (auto king = dynamic_cast<King *>(piece_to.get())) {
              if (on_lost_game)
                on_lost_game(king->color);
            }
          } else {
            if (on_invalid_move)
              on_invalid_move(*piece_from, from, to);
            return false;
          }
        }
        piece_to = move(piece_from);
        if (after_piece_move)
          after_piece_move(); // Call after move is made
        return true;
      } else {
        if (on_invalid_move)
          on_invalid_move(*piece_from, from, to);
        return false;
      }
    } else {
      if (on_no_piece)
        on_no_piece(from);
      return false;
    }
  }
};

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board) : board(board) {
    board.on_piece_move = [this](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << piece.type() << " is moving from " << from << " to " << to << endl;
    };
    board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
      cout << piece.type() << " is being removed from " << square << endl;
    };
    board.on_lost_game = [](ChessBoard::Color color) {
      cout << ((color == ChessBoard::Color::WHITE) ? "Black" : "White") << " won the game!" << endl;
    };
    board.on_invalid_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "Invalid move: cannot move " << piece.type() << " from " << from << " to " << to << endl;
    };
    board.on_no_piece = [](const string &square) {
      cout << "No piece at " << square << endl;
    };
    board.after_piece_move = [this]() {
      print_board();
    };
  }

  void print_board() const {
    for (int y = 7; y >= 0; --y) {
      for (int x = 0; x < 8; ++x) {
        if (board.squares[x][y]) {
          cout << board.squares[x][y]->representation() << " ";
        } else {
          cout << ". ";
        }
      }
      cout << endl;
    }
    cout << endl;
  }

private:
  ChessBoard &board;
};

int main() {
  ChessBoard board;
  ChessBoardPrint print(board);

  // Initialize the chessboard
  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
