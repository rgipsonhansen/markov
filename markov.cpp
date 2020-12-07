/*
	Rion Gipson-Hansen
	Markov model for predictive weather analysis


*/

#include "markov.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

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
