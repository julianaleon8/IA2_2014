/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include "perceptron.h"

Perceptron::Perceptron(int i[NUM_OF_X][NUM_CASES],
					   int d[NUM_CASES],
					   float learning,
					   float w[NUM_OF_X]
  					)
{
	this->input = i;
	this->desired = d;
	this->learning_rate = learning;
	this->weights =  w;
}
	
inline float Perceptron::dot_product(int* inputCase, float* w) 
{
	float res = 0;
	for (int i = 0; i < NUM_CASES; ++i)
		res += inputCase[i] * w[i];
	return res;
}

inline int Perceptron::Z(float result) 
{
	if (result > 0)
		return 1;
	else
		return -1;
}

float* Perceptron::perceptron(void) 
{
	// For max iterations
	int counter = 0;
	bool no_error = true;
	while (counter < MAX_ITER)
	{
		int res;
		int error;
		// For each test case
		for (int i = 0; i < NUM_CASES; ++i)
		{
			// Calculate the doc product, then check if the value is 1 o -1
			res = Z(dot_product(input[i], weights));
			error = desired[i] - res;

			// If we have an error
			if (error != 0)
			{
				no_error = false;
				for (int j = 0; j < NUM_OF_X; ++j)
					weights[j] = LEARNING_RATE * error * input[j][i];
			}
		}

		if (!no_error)
		{
			cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
			return weights;
			break;
		}
	}
}

int prueba(int input[NUM_OF_X], float w[NUM_OF_X]){
	
	float sumatoria = 0.0;
        
	for(int i = 0 ; i < NUM_OF_X ; ++i)
	{
	    sumatoria += input[i] * w[i];	
    }

    return sumatoria > 0.5 ? 1:0;	
}