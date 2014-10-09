/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include <stdio.h>
#include <iostream>

#define MAX_ITER		1000
#define LEARNING_RATE	0.99f
#define NUM_OF_X		3
#define NUM_CASES		4

int input[NUM_CASES][NUM_OF_X] = {
	{ 1, 0, 0 },
	{ 1, 0, 1 },
	{ 1, 1, 0 },
	{ 1, 1 ,1 },
};

int desired[NUM_CASES] = { 0, 1, 1, 1 };

float learning_rate = 0.1f;
float weights[NUM_OF_X] = { 0.0, 0.0, 0.0 };

inline float dot_product(int *inputCase, float* w) {
	float res = 0.0;
	for (int j = 0; j < NUM_OF_X; ++j)
		res += inputCase[j] * w[j];
	return res;
}

inline int Z(float result) {
	if (result > 0.5f)
		return 1;
	else
		return 0;
}

int main(void) {
	// For max iterations
	int counter = 0;
	bool no_error = true;
	while (counter < MAX_ITER)
	{
		int res;
		int error;
		bool no_error = true;
		// For each test case
		for (int i = 0; i < NUM_CASES; ++i)
		{
			// Calculate the doc product, then check if the value is 1 o -1
			float dot = dot_product(input[i], weights);
			res = Z(dot);

			error = desired[i] - res;
			// If we have an error
			if (error != 0)
			{
				no_error = false;
				for (int j = 0; j < NUM_OF_X; ++j)
				{
					float delta_d = LEARNING_RATE * error * input[i][j];
					weights[j] += delta_d;
				}
			}
		}

		if (no_error)
		{
//			cout << "Number of iterations needed " << counter << endl;
//			cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
			return 0;
		}
		cout << counter << "\t" << error << endl;
		
		++counter;
		
	}

//	cout << "Max number of iterations" << endl;
//	cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
}
