#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>

class DataReader {

public:
	int num_cases;
	double** pattern;
	double** target;
	// Si es la prueba de tipo 1 o 2
	int num_prueba;
public:

	void loadData(const char* , int ,int , int ,int);

};
