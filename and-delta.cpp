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

int input[NUM_CASES][NUM_OF_X] = {
	{ 1, 0, 0 },
	{ 1, 0, 1 },
	{ 1, 1, 0 },
	{ 1, 1, 1 },
};

int desired[NUM_CASES] = { 0, 0, 0, 1 };

float weights[NUM_OF_X] = { 0.1f, 0.1f, 0.1f };

inline float dot_product(int* inputCase, float* w) {
	float res = 0;
	for (int i = 0; i < NUM_OF_X; ++i)
		res += inputCase[i] * w[i];
	return res;
}

int main(void) {
	// For max iterations
	int counter = 0;
	bool no_error = true;
	while (counter < MAX_ITER)
	{
		float res;
		float error;
		float deltak = 0.0f;
		bool no_error = true;
		float delta_weights[3];
		// For each test case
		for (int i = 0; i < NUM_CASES; ++i)
		{
			delta_weights[0] = 0.0f;
			delta_weights[1] = 0.0f;
			delta_weights[2] = 0.0f;
			// Calculate the doc product, then check if the value is 1 o -1
			res = dot_product(input[i], weights);
			error = desired[i] - res;

			for (int j = 0; j < NUM_OF_X; ++j)
				delta_weights[j] = LEARNING_RATE * input[i][j] * error;
		}

		for (int i = 0; i < NUM_CASES; ++i)
			weights[i] += delta_weights[i];

		cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;

		if (error != 0)
			no_error = false;

		++counter;

		if (no_error)
		{
			cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
			break;
		}
	}
}
