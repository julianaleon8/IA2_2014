/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define MAX_ITER		100000
#define LEARNING_RATE	0.01f
#define NUM_OF_X		3
#define NUM_CASES		4

int input[NUM_CASES][NUM_OF_X] =
{
	{ 1, 0, 0 },
	{ 1, 0, 1 },
	{ 1, 1, 0 },
	{ 1, 1, 1 },
};

int desired[NUM_CASES] = { 0, 1, 1, 0 };

double weights[NUM_OF_X] = { 0.5, 0.2, 0.2 };
double delta_weights[3] = { 0.0, 0.0, 0.0 };

inline double dot_product(int* inputCase, double* w)
{
	double res = 0;
	for (int i = 0; i < NUM_OF_X; ++i)
	{
		res += inputCase[i] * w[i];
	}
	return res;
}

inline double sigma(double x)
{
	return 1 / (1 + exp(-x));
}

int main(void)
{
	// For max iterations
	int counter = 0;
	bool no_error = true;

	while (counter < MAX_ITER)
	{
		double res;
		double error;
		double o;
		bool no_error = true;
		double total_error = 0.0;
		delta_weights[0] = 0.0;
		delta_weights[1] = 0.0;
		delta_weights[2] = 0.0;
		// For each test case
		for (int i = 0; i < NUM_CASES; ++i)
		{
			res = sigma(dot_product(input[i], weights));
			o = res * (1 - res);
			error = desired[i] - res;
			total_error += error*error;

			for (int j = 0; j < NUM_OF_X; ++j)
			{
				delta_weights[j] += LEARNING_RATE * o *input[i][j] * error;
			}
		}

		for (int i = 0; i < NUM_OF_X; ++i)
		{
			weights[i] += delta_weights[i];
		}

		if (total_error > 0.01)
		{
			no_error = false;
		}
		cout << counter << "\t" << error << endl;
		++counter;

		if (no_error)
		{
			//			cout << "Number of iterations needed " << counter << endl;
			//			cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
			break;
		}
	}

	//	cout << "Max number of iterations" << endl;
	//	cout << "Final weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
}
