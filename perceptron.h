/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include <stdio.h>
#include <iostream>

#define LEARNING_RATE	0.1f
#define NUM_OF_X		3
#define NUM_CASES		4
#define MAX_ITER		150

class Perceptron
{
public:
	int input[NUM_OF_X][NUM_CASES];
	int desired[NUM_CASES];

	float learning_rate;
	float weights[NUM_OF_X];
	
	Perceptron(int input[NUM_OF_X][NUM_CASES],
			   int desired[NUM_CASES],
					   float learning,
					   float weights[NUM_OF_X]);
	
	float dot_product(int*, float*);
	
	int Z(float result);
	
	float* perceptron(void);
	
	int prueba(int[NUM_OF_X] , float[NUM_OF_X]);
};