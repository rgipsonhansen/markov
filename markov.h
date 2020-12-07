/*
	Rion Gipson-Hansen
	Markov model for predictive weather analysis


*/

#ifndef _MARKOV_H
#define _MARKOV_H

#include <string>
#include <map>
#include <vector>

class Markov {
public:
	Markov();
	void run();
	void initialize();
	void set_order(int order);
	void set_input_file();
	void print();
	void input_seed();
	void get_next_day();
	void generate_string();

private:
	std::map<std::string, std::vector<int>> map;
	int order = 1;

	string filepath = "Raw_Climate_Data.csv"
	int date_col = 1;
	int prec_col = 4;

};

#endif
