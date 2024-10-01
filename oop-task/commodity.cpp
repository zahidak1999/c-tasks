#include "commodity.hpp"

// Constructor
Commodity::Commodity(const std::string &name_, int id_, double price_)
    : name(name_), id(id_), price(price_) {}

// Getter for name
std::string Commodity::get_name() const {
  return name;
}

// Getter for id
int Commodity::get_id() const {
  return id;
}

// Getter for price without tax
double Commodity::get_price(double quantity) const {
  return price * quantity;
}

// Getter for price with tax
double Commodity::get_price_with_sales_tax(double quantity) const {
  return price * (1 + sales_tax_rate) * quantity;
}

// Setter for price
void Commodity::set_price(double new_price) {
  price = new_price;
}
