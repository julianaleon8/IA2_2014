
using namespace std;

#include "perceptron.hpp"

Input::Input(vector <float> in, int d ){
	this -> input = in;
	this -> desired = d;

}

Perceptron::Perceptron(vector <float> w,
					   float l)
{
	this->learnig_rate = l;
	this->weights =  w;
}
	
inline float Perceptron::dot_product(Input in , Perceptron p ) 
{
	float res = 0;
	for (int i = 0; i < NUM_CASES; ++i)
		res += in.input[i] * p.weights;
	return res;
}

inline int Perceptron::Z(float result) 
{
	if (result > 0)
		return 1;
	else
		return -1;
}

float* Perceptron::perceptron(Input in , Perceptron p ) 
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
			res = Z(dot_product(in.input[i], p.weights));
			error = in.desired - res;

			// If we have an error
			if (error != 0)
			{
				no_error = false;
				for (int j = 0; j < NUM_OF_X; ++j)
					p.weights = LEARNING_RATE * error * in.input[j];
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

