/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;
#include <vector>
#include <stdio.h>
#include <iostream>

#define LEARNING_RATE	0.1f
#define NUM_OF_X		3
#define NUM_CASES		4
#define MAX_ITER		150


class Input {
	std:: vector <float> input;
	int desired;


};

class Perceptron
{
public:

	float learning_rate;
	std::vector <float> weights;
	
	Perceptron(float learning,
			   vector <float> weights);
	
	float dot_product( Input input, Perceptron p );
	
	int Z(float result);
	
	float* perceptron(Input , Perceptron );
	

};
