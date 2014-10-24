#include "network.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdio.h>

void NeuralNetwork::init_weights()
{
	for (int i = 0; i <= n_input; ++i)
		for (int j = 0; j < n_hidden; ++j)
			w_input_to_hidden[i][j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.2));

	for (int i = 0; i <= n_hidden; ++i)
		for (int j = 0; j < n_output; ++j)
			w_hidden_to_output[i][j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.2));
}

inline double NeuralNetwork::sigma(const double x)
{
	return 1 / (1 + exp(-x));
}

inline double NeuralNetwork::dev_sigma(const double x)
{
	return x * (1 - x);
}

NeuralNetwork::NeuralNetwork(int ni, int nh, int no)
{
	n_input = ni;
	n_hidden = nh;
	n_output = no;

	input_neurons_output = new double[n_input + 1]();
	hidden_neurons_output = new double[n_hidden + 1]();
	output_neurons_output = new double[n_output + 1]();

	hidden_error = new double[n_hidden + 1]();
	output_error = new double[n_output + 1]();

	input_neurons_output[n_input] = -1;
	hidden_neurons_output[n_hidden] = -1;

	w_input_to_hidden = new double*[n_input + 1]();
	delta_input_to_hidden = new double*[n_input + 1]();

	for (int i = 0; i <= n_input; ++i)
	{
		w_input_to_hidden[i] = new double[n_hidden]();
		delta_input_to_hidden[i] = new double[n_hidden]();
	}

	w_hidden_to_output = new double*[n_hidden + 1]();
	delta_hidden_to_output = new double*[n_hidden + 1]();
	for (int i = 0; i <= n_hidden; ++i)
	{
		w_hidden_to_output[i] = new double[n_output + 1]();
		delta_hidden_to_output[i] = new double[n_output + 1]();
	}

	init_weights();
}

NeuralNetwork::~NeuralNetwork()
{
	/*delete[] input_neurons_output;
	delete[] hidden_neurons_output;
	delete[] output_neurons_output;
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
	delete[] w_hidden_to_output;*/
}

void NeuralNetwork::set_training_parameter(double lr, int iter)
{
	learning_rate = lr;
	max_iter = iter;
}

double NeuralNetwork::dot_product(const double* x, const double* y, const int size)
{
	double res = 0;
	for (int i = 0; i < size; ++i)
		res += x[i] * y[i];
	return res;
}

// Only 1 case
void NeuralNetwork::fowardpropagate(const double* pattern)
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
		output_neurons_output[i] = 0;
		for (int j = 0; j <= n_hidden; ++j)
			output_neurons_output[i] += hidden_neurons_output[j] * w_hidden_to_output[j][i];

		output_neurons_output[i] = sigma(output_neurons_output[i]);
	}
}

void NeuralNetwork::backpropagate(const double* desired)
{
	// Output -> Hidden
	
	for (int i = 0; i < n_output; ++i)
	{
		output_error[i] = dev_sigma(output_neurons_output[i]) * (desired[i] - output_neurons_output[i]);
	
		sum_error +=  output_error[i] * output_error[i] ;
		
		for (int j = 0; j <= n_hidden; ++j)
			delta_hidden_to_output[j][i] += learning_rate * hidden_neurons_output[j] * output_error[i];
	}
	
	// Hidden -> Input
	for (int i = 0; i < n_hidden; ++i)
	{
		double out = dot_product(w_hidden_to_output[i], output_error, n_output);
		hidden_error[i] = dev_sigma(hidden_neurons_output[i]) * out;

		for (int j = 0; j <= n_input; ++j)
			delta_input_to_hidden[j][i] += learning_rate * input_neurons_output[j] * hidden_error[i];
	}

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
			delta_hidden_to_output[i][j] = 0;
		}
	}
}

bool NeuralNetwork::train_iteration(const DataReader d, const int num_cases)
{
	bool has_error = false;

	for (int i = 0; i < num_cases; ++i)
	{

		fowardpropagate(d.pattern[i]);
		backpropagate(d.target[i]);

		for (int j = 0; j < n_output; ++j)
		{
			if (filter(output_neurons_output[j]) != d.target[i][j])
				has_error = true;
		}
	}
	
	std::cout << sum_error * 0.5 << std::endl;
	sum_error = 0;

	update_weights();

	return has_error;
}

inline int NeuralNetwork::filter( double x )
{
	if ( x > 0.5 )
		return 1;
	else
		return -1;
/*
	if (x > 0.5)
		return 1;
	else if (x < -0.5)
		return -1;
	else
		return 0;
	*/ 
/*
	 * si > 1.5 -> 3
	 * si < -1.5 -> -3
	 * else 0
	*/
}

void NeuralNetwork::train_network(const DataReader d)
{
	for (int i = 0; i < max_iter; ++i)
	{
	//	std::cout << "Iteriacion # " << i << " : ";
		bool b = train_iteration(d, d.num_cases);
		if (!b)
			return;
	}
}


double NeuralNetwork::test(const DataReader d)
{
	double incorrect = 0;
	for ( int i = 0; i < d.num_cases; ++i)
	{
		fowardpropagate(d.pattern[i]);

		bool correct = true;

		for ( int k = 0; k < n_output; ++k)
		{
			if (filter(output_neurons_output[k]) != d.target[i][k])
				 correct = false;
		}

		if (!correct)
			incorrect++;

		/*for (int n_in = 0; n_in < n_input; ++n_in)
		{
			std::cout << d.pattern[i][n_in] << ',';
		}*/

	/*	for (int n_in = 0; n_in < n_output; ++n_in)
		{
			std::cout << filter(output_neurons_output[n_in]) << " -" ;
		}
		*/

	}

	return 100 - (incorrect/d.num_cases * 100);
}
