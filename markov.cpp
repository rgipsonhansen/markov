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
		cout<<"Predictive weather generation"<<endl;
		cout<<"To set order, enter 1"<<endl;
		cout<<"To enter a sequence, whos length matches the order, enter 2"<<endl;
		cout<<"To get just the next day, enter 3"<<endl;
		cout<<"To generate a sequence of possible days, enter 4"<<endl;
		cout<<"To exit, enter 5"<<endl;


		string response = "";
		getline(cin, response);
		int option = atoi(response.c_str());
		cout << endl;

		string order_string = "";
		int order = 1;
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
				get_next_day();
				break;
			case 4:
				generate_string();
				break;
			case 5:
				return;
			default:
				cout<<"Option not recognized"<<endl;
		}
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


	int index = 0;
	for(auto name : rows[0]){
		if(name == "SNWD"){
			snow_col = index;
		}
		index++;
	}
	string depth = "";
	for(int i = 0; i < rows.size(); i++){
		if(atoi(rows.at(i).at(snow_col).c_str()) > .5){
			depth = "1";
		}else depth = "0";
		depths.push_back(depth);
	}
	generate_map(order);
}

void Markov::set_order(int order){
	this->order = order;
	cout<<"Order has been set to "<<this->order<<endl;
	cout<<endl;
}

void Markov::set_input_file(){

}

void Markov::print(){

}

void Markov::input_seed(){

}
void Markov::get_next_day(){

}

void Markov::generate_string(){

}

void Markov::generate_map(int order){

}
