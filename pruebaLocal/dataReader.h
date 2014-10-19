#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#define NUM_CASES 500

class DataReader {
	
public:
	int Num_Cases;
	double** pattern;
	double** target;
public:

	void loadData(const char* , int ,int , int );

};
