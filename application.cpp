#include <iostream>
#include <fstream>

#include "state.hpp"
#include "county.hpp"

State* read_state_data(std::ifstream& infile) {
  std::string name;
  float unemployed_2007, unemployed_2015;
  int med_income, n_counties;

  infile >> name >> unemployed_2007 >> unemployed_2015 >> med_income >> n_counties;

  return new State(name, unemployed_2007, unemployed_2015, med_income, n_counties);
}


County* read_county_data(std::ifstream& infile) {
  std::string name;
  float unemployed_2007, unemployed_2015;
  int med_income;

  infile >> name >> unemployed_2007 >> unemployed_2015 >> med_income;

  return new County(name, unemployed_2007, unemployed_2015, med_income);
}


int main(int argc, char const *argv[]) {
  std::ifstream infile;
  infile.open(argv[1]);
  if (infile.fail()) {
    std::cerr << "Error opening file: " << argv[1] << std::endl;
    return 1;
  }

  int n_states;
  infile >> n_states;
  std::cout << "n_states: " << n_states << std::endl;

  State** states = new State*[n_states];
  for (int i = 0; i < n_states; i++) {
    states[i] = read_state_data(infile);
    for (int j = 0; j < states[i]->get_n_counties(); j++) {
      County* county = read_county_data(infile);
      states[i]->add_county(county);
    }
  }

  for (int i = 0; i < n_states; i++) {
    std::cout << "== " << states[i]->get_name() << "\t"
      << states[i]->get_unemployed_2007() << "\t"
      << states[i]->get_unemployed_2015() << "\t"
      << states[i]->get_med_income() << std::endl;

    for (int j = 0; j < states[i]->get_n_counties(); j++) {
      County* county = states[i]->get_county(j);
      std::cout << "  - " << county->get_name() << "\t"
        << county->get_unemployed_2007() << "\t"
        << county->get_unemployed_2015() << "\t"
        << county->get_med_income() << std::endl;
    }
  }

  for (int i = 0; i < n_states; i++) {
    delete states[i];
  }
  delete[] states;

  return 0;
}
