/*
	Rion Gipson-Hansen
	Markov model for predictive weather analysis


*/

#include "markov.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Markov::Markov(){
}

void Markov::run(){
	while (true) {
		//print menu
		cout<<"Predictive weather generation"<<endl;
		cout<<"To set order, enter 1"<<endl;
		cout<<"To enter a sequence, whos length matches the order, enter 2"<<endl;
		cout<<"To get stats for the next day, enter 3"<<endl;
		cout<<"To generate a sequence of possible days, enter 4"<<endl;
		cout<<"To exit, enter 9"<<endl;


		string response = "";
		getline(cin, response);
		int option = atoi(response.c_str());
		cout << endl;

		string order_string = "";
		int order = 1;

		string string_length = "";
		int length = 0;
		switch(option){
			case 1:
				cout<<"Enter an order: ";
				getline(cin, order_string);
				order = atoi(order_string.c_str());
				set_order(order);
				break;
			case 2:
				input_seed();
				break;
			case 3:
				get_stats();
				break;
			case 4:
				cout<<"Enter a length of desired result: ";
				getline(cin, string_length);
				length = stoi(string_length);
				generate_string(length);
				break;
			case 9:
				return;
			default:
				cout<<"Option not recognized"<<endl;
		}
		//flush the cin buffer
		// string temp;
		// cin.getline(temp, 64);
		// if (cin.fail()) {
		//     cin.clear();
		//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// }
	}
}

void Markov::initialize(){
	ifstream fin;
	fin.open(filepath);

	char delim = ',';
	char temp_string[256];
	string temp_val = "";
	int row = 0;
	int col = 0;
	vector<vector<string>> rows;
	vector<string> temp_column;

	while (fin.getline(temp_string, (streamsize) 256)){
		//create stringstream from read line
		stringstream s_stream(temp_string);
		//set columns to 0 since restarting the row
		col = 0;
		while(getline(s_stream, temp_val, delim)){
			temp_column.push_back(temp_val);
			col++;
		}
		rows.push_back(temp_column);
		temp_column.clear();
		row++;
	}

	//find the column of data we are interested in
	int index = 0;
	for(auto name : rows[0]){
		if(name == "SNWD"){
			snow_col = index;
		}
		index++;
	}

	//pull all usefull data from the desired column
	string depth = "";
	for(int i = 0; i < rows.size(); i++){
		if(atoi(rows.at(i).at(snow_col).c_str()) > (double) 1 / NUM_OPTIONS){
			depth = "1";
		}else depth = "0";
		depths.push_back(depth);
	}
	generate_map();
}

void Markov::set_order(int order){
	this->order = order;
	cout<<"Order has been set to "<<this->order<<endl;
	cout<<endl;
	generate_map();
	return;
}

void Markov::set_input_file(){

}

void Markov::input_seed(){
	//initialize the markov seed
	cout<<"Enter a string of 1s and 0s to start the string: ";
	cin>>seed;
	order = seed.length();
	generate_map();
}
void Markov::get_stats(){

}

void Markov::generate_string(int length){

	input_seed();

	//generate the rand seed
	srand(time(NULL));
	int value = 0;
	cout<<seed;
	for(int i = 0; i < length - order; i++){
		value = map_vector.at(order-1).at(seed).at(rand() % map_vector.at(order-1).at(seed).size());
		cout<<value;
		seed.erase(0,1);
		seed.append(to_string(value));
	}
	cout<<endl;
	cin.clear();
	fflush(stdin);
	return;
}

void Markov::generate_map(){
	//create keys, find the next value, and then increment the value at that value in the map
	string key = "";
	string_map.clear();
	for(int i = 0; i < depths.size() - order - 1; i++ ){
		key.clear();
		for(int j = i; j < i + order; j++){
			key +=depths.at(j);
		}
		string_map[key].push_back(stoi(depths.at(i + order)));
	}
	cout<<"Map with "<<string_map.size()<<" elements created (order "<< order<<")"<<endl;
	if(map_vector.size() < order){
		for(int i = map_vector.size(); i < order - 1; i++){
			map_vector.push_back(map<string, vector<int>>());
		}
		map_vector.push_back(string_map);
	}else(map_vector[order-1] = string_map);
	cout<<endl<<endl;
	return;
}
