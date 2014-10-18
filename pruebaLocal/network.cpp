#include "network.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

void NeuralNetwork::init_weights()
{

	srand (static_cast <unsigned> (time(0)));

	for (int i = 0; i <= n_input; ++i)
		for (int j = 0; j <= n_hidden; ++j)
			w_input_to_hidden[i][j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));

	for (int i = 0; i <= n_hidden; ++i)
		for (int j = 0; j <= n_output; ++j)
			w_input_to_hidden[i][j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
}

inline double NeuralNetwork::sigma(double x)
{
	return 1 / (1 + exp(-x));
}

inline double NeuralNetwork::dev_sigma(double x)
{
	return x * (1 - x);
}

NeuralNetwork::NeuralNetwork(int ni, int nh, int no)
{
	n_input = ni;
	n_hidden = nh;
	n_output = no;

	input_neurons_output = new(double[n_input + 1]);
	hidden_neurons_output = new(double[n_hidden + 1]);
	output_neutons_output = new(double[n_output]);

	hidden_error = new(double[n_hidden + 1]);
	output_error = new(double[n_output + 1]);

	input_neurons_output[n_input] = 1;
	hidden_neurons_output[n_hidden] = 1;

	w_input_to_hidden = new(double*[n_input + 1]);
	delta_input_to_hidden = new(double*[n_input + 1]);
	for (int i = 0; i <= n_input; ++i)
	{
		w_input_to_hidden[i] = new(double[n_hidden]);
		delta_input_to_hidden[i] = new(double[n_hidden]);
	}

	w_hidden_to_output = new(double*[n_hidden + 1]);
	delta_hidden_to_output = new(double*[n_hidden + 1]);
	for (int = 0; i <= n_hidden; ++i)
	{
		w_hidden_to_output[i] = new(double[n_output]);
		delta_hidden_to_output[i] = new(double[n_output]);
	}

	init_weights();
}

NeuralNetwork::NeuralNetwork()
{
	delete[] input_neurons;
	delete[] hidden_neurons;
	delete[] output_neutons;
	delete[] hidden_error;
	delete[] output_error;

	for (int i = 0; i <= n_input; ++i)
	{
		delete[] w_input_to_hidden[i];
		delete[] delta_input_to_hidden[i];
	}
	delete[] w_input_to_hidden;
	delete[] delta_input_to_hidden;

	for (int i = 0; i <= n_hidden; ++i)
	{
		delete[] w_input_to_hidden[i];
		delete[] delta_hidden_to_output[i];
	}
	delete[] delta_hidden_to_output;
	delete[] w_hidden_to_output;
}

void NeuralNetwork::set_training_parameter(double lr, double m, int iter)
{
	learning_rate = lr;
	momentum = m;
	max_iter = iter;
}

double NeuralNetwork::dot_product(double* x, double* y, int size)
{
	double res = 0;
	for (int i = 0; i < size; ++i)
		res += x[i] * y[i]
	return res;
}

// Only 1 case
void NeuralNetwork::fowardpropagate(double* pattern)
{
	for (int i = 0; i < n_input; ++i)
		input_neurons_output[i] = pattern[i];

	// Hidden
	for (int i = 0; i < n_hidden; ++i)
	{
		hidden_neurons_output[i] = 0;
		for (int j = 0; j <= n_input; ++j)
			hidden_neurons_output[i] += input_neurons_output[j] * w_input_to_hidden[j][i];

		hidden_neurons_output[i] = sigma(hidden_neurons_output[i]);
	}

	// Output
	for (int i = 0; i < n_output; ++i)
	{
		output_neutons_output[i] = 0;
		for (int j = 0; j <= n_hidden; ++j)
			output_neutons_output[i] = hidden_neurons_output[j] * w_hidden_to_output[j][i];

		output_neutons_output[i] = sigma(output_neutons_output[i]);
	}
}

void NeuralNetwork::backpropagate(double* desired)
{
	// Output -> Hidden
	for (int i = 0; i < n_output; ++i)
	{
		output_error[i] = (1 - output_neutons_output[i]) * (desired[i] - output_neutons_output[i]);

		for (int j = 0; j <= n_hidden; ++j)
			delta_hidden_to_output[j][i] += learning_rate * hidden_neurons_output[j] * output_error[i];
	}

	// Hidden -> Input
	for (int i = 0; i < n_hidden; ++i)
	{
		double out = dot_product(w_hidden_to_output[i], output_error, n_output);
		hidden_error[i] = hidden_neurons_output[i] * (1 - hidden_neurons_output[i]) * out;

		for (int j = 0; j <= n_input; ++j)
			delta_input_to_hidden[j][i] += learning_rate * input_neurons_output[j] * hidden_error[i];
	}

	update_weights();
}

void NeuralNetwork::update_weights()
{
	for (int i = 0; i <= n_input; ++i)
	{
		for (int j = 0; j < n_hidden; ++j)
		{
			w_input_to_hidden[i][j] += delta_input_to_hidden[i][j];
			delta_input_to_hidden[i][j] = 0;
		}
	}

	for (int i = 0; i <= n_hidden; ++i)
	{
		for (int j = 0; j < n_output; ++j)
		{
			w_hidden_to_output[i][j] += delta_hidden_to_output[i][j];
			delta_hidden_to_output[i][j] = 0
		}
	}
}

/*void NeuralNetwork::run_training_iteration(dataReader)
{

}*/
