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
	// argv[5] is filename to test against
	// argv[6] is number of tests
	//cout << "prin" << argv[4];
	// argv[7] is number of hidden layer neurons

	if (argc > 7) {
	DataReader a;
	DataReader c;

	int numCases = atof(argv[2]);
	int numV = atof(argv[3]);
	int numD = atof(argv[4]);
	int numN = atof(argv[7]);

	int numTestCases = atof(argv[6]);
	a.DataReader::loadData(argv[1], numCases, numV, numD);
	c.DataReader::loadData(argv[5], numTestCases, numV, numD);
	srand (static_cast <unsigned> (time(0)));

	//cout << "Start training" << endl;
	NeuralNetwork b = NeuralNetwork(numV, numN, numD);
	b.train_network(a);
	//cout << "End training" << endl;

	double acc = b.test(c);

	std::cout << acc << "% test"<< std::endl;
	}
	else {
		cout << "parametros Incorrectos " << endl;
		return 1;
	}
}
