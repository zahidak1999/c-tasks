#pragma once
#include <string>

const double sales_tax_rate = 0.25; // 25% moms

class Commodity {
public:
  // Constructor
  Commodity(const std::string &name_, int id_, double price_);

  // Getter-functions
  std::string get_name() const;
  int get_id() const;
  double get_price(double quantity = 1.0) const;
  double get_price_with_sales_tax(double quantity = 1.0) const;

  // Setter-functions
  void set_price(double new_price);

private:
  std::string name;
  int id;
  double price; // This should be price without tax
};
