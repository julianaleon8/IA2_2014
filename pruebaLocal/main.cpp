#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "network.h"
using namespace std;
int main ()
{
	int num;
	srand (static_cast <unsigned> (time(0)));
	DataReader a;
	a.DataReader::loadData();
	std::cout << a.target[1];
	NeuralNetwork b = NeuralNetwork(2, 2, 1);
	b.train_network(a);
	double acc = b.test(a);
	
	std::cout << acc << " test"<< std::endl;
	
}
