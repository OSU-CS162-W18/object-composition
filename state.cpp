#include "state.hpp"

State::State(std::string name, float unemployed_2007, float unemployed_2015,
    int med_income, int n_counties) : name(name),
      unemployed_2007(unemployed_2007),
      unemployed_2015(unemployed_2015),
      med_income(med_income),
      n_counties(n_counties) { }


State::~State() {
  for (int i = 0; i < this->n_counties; i++) {
    delete this->counties[i];
  }
}

int State::get_n_counties() {
  return this->n_counties;
}


std::string State::get_name() {
  return this->name;
}


float State::get_unemployed_2007() {
  return this->unemployed_2007;
}


float State::get_unemployed_2015() {
  return this->unemployed_2015;
}


int State::get_med_income() {
  return this->med_income;
}


County* State::get_county(int i) {
  return this->counties[i];
}


void State::add_county(County* county) {
  this->counties.push_back(county);
}
