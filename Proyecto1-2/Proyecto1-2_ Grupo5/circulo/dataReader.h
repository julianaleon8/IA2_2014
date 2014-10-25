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
public:

	void loadData(const char*, int, int, int );
	void printPatterns(int);
	void printTargets(int);
};
