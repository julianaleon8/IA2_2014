/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include <stdio.h>
#include <iostream>
#include <vector>

class Perceptron
{
private:
	int num_variables;
	int num_cases;
	int learning_rate;
	vector< vector<int> > input;
	vector<int> desired;
	vector<float> weights;

	float dot_product(vector<int>, vector<float>);
	int Z(float result);

public:
	void learn();
	Perceptron(int** input, int *desired, float learning_rate, float* weights);
};
