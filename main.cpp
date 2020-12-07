/*
	Rion Gipson-Hansen
	Markov model for predictive weather analysis


*/

#include <iostream>
#include <cstdlib>
#include "markov.h"

using namespace std;

int main(int argc, char **) {
	Markov markov;
	markov.initialize();
	markov.run();
}
