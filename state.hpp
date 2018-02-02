#include <iostream>
#include <vector>

#include "county.hpp"

#ifndef _STATE_HPP
#define _STATE_HPP

class State {
private:
  std::string name;
  float unemployed_2015;
  float unemployed_2007;
  int med_income;
  int n_counties;
  std::vector<County*> counties;
public:
  State(std::string name, float unemployed_2007, float unemployed_2015,
    int med_income, int n_counties);

  ~State();

  int get_n_counties();
  std::string get_name();
  float get_unemployed_2007();
  float get_unemployed_2015();
  int get_med_income();
  County* get_county(int i);

  void add_county(County* county);
};

#endif
