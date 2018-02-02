#include <iostream>

#ifndef _COUNTY_HPP
#define _COUNTY_HPP

class County {
private:
  std::string name;
  float unemployed_2015;
  float unemployed_2007;
  int med_income;
public:
  County(std::string name, float unemployed_2007, float unemployed_2015,
    int med_income);

  std::string get_name();
  float get_unemployed_2007();
  float get_unemployed_2015();
  int get_med_income();
};


#endif
