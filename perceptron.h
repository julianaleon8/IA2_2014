/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include <stdio.h>
#include <iostream>

class Perceptron
{
private:
	int num_variables;
	int num_cases;
	int learning_rate;
	int **input;
	int *desired;
	float *weights;

	float dot_product(int*, float*);
	int Z(float result);

public:
	void learn();
	Perceptron(int** input, int *desired, float learning_rate, float* weights, int num_cases, int num_x);
	int prueba(int *input, float *w);
};