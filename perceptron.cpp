/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include "perceptron.h"
#include <vector>
#include <iterator>

Perceptron::Perceptron(int** input, int *desired, float learning_rate, float* weights)
{
	this->input = input;
	this->desired = vector<int>(begin(desired), end(desired));
	this->learning_rate = learning_rate;
	this->weights = weights;
	this->num_cases = num_cases;
	this->num_variables = num_x;
}
	
inline float Perceptron::dot_product(vector<int> inputCase, vector<float> w)
{
	float res = 0;
	for (int i = 0; i < num_cases; ++i)
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

void Perceptron::learn() 
{
	// For max iterations
	int counter = 0;
	bool no_error = true;
	while (counter < 150)
	{
		int res;
		int error;
		// For each test case
		for (int i = 0; i < num_cases; ++i)
		{
			// Calculate the doc product, then check if the value is 1 o -1
			res = Z(dot_product(input[i], weights));
			error = desired[i] - res;

			// If we have an error
			if (error != 0)
			{
				no_error = false;
				for (int j = 0; j < num_variables; ++j)
					weights[j] = learning_rate * error * input[j][i];
			}
		}

		if (!no_error)
		{
			cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
			break;
		}
	}
}

int Perceptron::prueba(int *input, float *w) {
	
	float sumatoria = 0.0;

	for (int i = 0; i < num_variables; ++i)
		sumatoria += input[i] * w[i];

	return sumatoria > 0.5 ? 1:0;
}