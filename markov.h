/*
	Rion Gipson-Hansen
	Markov model for predictive weather analysis


*/

#ifndef _MARKOV_H
#define _MARKOV_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Markov {
public:
	Markov();
	void run();
	void initialize();
	void set_order(int order);
	void set_input_file();
	void input_seed();
	void get_stats();
	void generate_string(int length);
	void generate_map();

private:
	map<string, vector<int>> string_map;
	vector<map<string, vector<int>>> map_vector;
	int order = 3;
	string seed = "";
	int NUM_OPTIONS = 2;


	vector<string> depths;
	string filepath = "Raw_Climate_Data.csv";
	int snow_col = 5;

};

#endif
