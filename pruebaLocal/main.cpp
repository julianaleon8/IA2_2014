#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "network.h"
using namespace std;
int main (int argc, char* argv[])
{
	// argv[1] is filemame
	// argv[2] is numbers of cases
	// argv[3] is numbers of pattern's
	// argv[4] is numbers of desired
	//cout << "prin" << argv[4];
	
	if (argc > 4){ 
	DataReader a;

	
	int numCases = atof(argv[2]);
	int numV = atof(argv[3]);
	int numD = atof(argv[4]);
	 
	a.DataReader::loadData(argv[1],numCases,numV,numD);
	

	srand (static_cast <unsigned> (time(0)));
	
	std::cout << a.target[1];
	
	NeuralNetwork b = NeuralNetwork(2, 2, 1);
	b.train_network(a);
	
	double acc = b.test(a);
	
	std::cout << acc << " test"<< std::endl;
	}
	else {
		cout << "parametros Incorrectos " << endl; 
		return 1;
	}
}
