/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include <stdio.h>
#include <iostream>

#define MAX_ITER		150
#define LEARNING_RATE	0.1f
#define NUM_OF_X		3
#define NUM_CASES		4

int input[NUM_OF_X][NUM_CASES] = {
	{ 1, 1, 1, 1 },
	{ 0, 0, 1, 1 },
	{ 0, 1, 0, 1 }
};

int desired[NUM_CASES] = { 0, 0, 0, 1 };

float learning_rate = 0.1;
float weights[NUM_OF_X] = { 0.0, 0.0, 0.0 };

inline float dot_product(int* inputCase, float* w) {
	float res = 0;
	for (int i = 0; i < NUM_CASES; ++i)
		res += inputCase[i] * w[i];
	return res;
}

inline int Z(float result) {
	if (result > 0)
		return 1;
	else
		return -1;
}

int main(void) {
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
			break;
		}
	}
}
