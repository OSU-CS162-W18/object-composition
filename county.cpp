#include "county.hpp"

County::County(std::string name, float unemployed_2007, float unemployed_2015,
    int med_income) : name(name),
      unemployed_2007(unemployed_2007),
      unemployed_2015(unemployed_2015),
      med_income(med_income) { }


std::string County::get_name() {
  return this->name;
}


float County::get_unemployed_2007() {
  return this->unemployed_2007;
}


float County::get_unemployed_2015() {
  return this->unemployed_2015;
}


int County::get_med_income() {
  return this->med_income;
}
