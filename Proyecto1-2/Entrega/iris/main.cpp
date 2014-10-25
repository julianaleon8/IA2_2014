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

	if (argc > 5) 
	{
	DataReader a;
	DataReader c;

	int numCases = atof(argv[2]);
	int numV = 4;
	int numD = 1;

	int numTestCases = atof(argv[4]);
	int numPrueba = atof(argv[5]);

	a.DataReader::loadData(argv[1], numCases, numV, numD, numPrueba);
	
	c.DataReader::loadData(argv[3], numTestCases, numV, numD, numPrueba);

	srand (static_cast <unsigned> (time(0)));

	NeuralNetwork b = NeuralNetwork(numV, 4, numD, numPrueba);

	b.train_network(a);

	cout << "End training" << endl;

	double acc = b.test(c);

	std::cout << acc << " test"<< std::endl;
	}
	else {
		cout << "parametros Incorrectos " << endl;
		cout << "\t ./main achivo_training numCases archivo_prueba numTestCases [ 1 | 2 ] " << endl;
		return 1;
	}
}
