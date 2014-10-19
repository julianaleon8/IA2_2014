#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "network.h"

int main ()
{

	srand (static_cast <unsigned> (time(0)));
	DataReader a;
	a.DataReader::loadData();
	std::cout << a.patternY[0];
	NeuralNetwork* b = new NeuralNetwork(2, 2, 1);
	b->train_network(a);

}
