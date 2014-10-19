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
	output_neurons_output = new double[n_output]();

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
		w_hidden_to_output[i] = new double[n_output]();
		delta_hidden_to_output[i] = new double[n_output]();
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
		
		double aux = sigma(hidden_neurons_output[i]);
		//std::cout << "aux es " << aux << std::endl;
		//std::cout << "hidden es " << hidden_neurons_output[i] << std::endl;  
		hidden_neurons_output[i] =aux;
		
	}

	// Output
	for (int i = 0; i < n_output; ++i)
	{
		output_neurons_output[i] = 0;
		for (int j = 0; j <= n_hidden; ++j)
			output_neurons_output[i] += hidden_neurons_output[j] * w_hidden_to_output[j][i];
		
		//	std::cout << "output_neurons_output[i] " << output_neurons_output[i] << std::endl;
	
		output_neurons_output[i] = sigma(output_neurons_output[i]);
	}
}

void NeuralNetwork::backpropagate(const double* desired)
{
	// Output -> Hidden
	for (int i = 0; i < n_output; ++i)
	{
		output_error[i] = dev_sigma(output_neurons_output[i]) * (desired[i] - output_neurons_output[i]);
		//	std::cout << "desired[i] " << desired[i] << std::endl;
		//	std::cout << "output_neurons_output[i] " << output_neurons_output[i] << std::endl;
		//	std::cout << "output_error[i] " << output_error[i] << std::endl;
				
		for (int j = 0; j <= n_hidden; ++j)
			delta_hidden_to_output[j][i] += learning_rate * hidden_neurons_output[j] * output_error[i];
	}

	// Hidden -> Input
	for (int i = 0; i < n_hidden; ++i)
	{
		double out = dot_product(w_hidden_to_output[i], output_error, n_output);
		hidden_error[i] = dev_sigma(hidden_neurons_output[i]) * out;
		
		//std::cout << "hidden_error[i] " << hidden_error[i] << std::endl;
		//char c; std::cin >> c;
		
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
		//	std::cout << "w_Input_Hidden " << delta_input_to_hidden[i][j] << std::endl;
			//char c; std::cin >> c;
			w_input_to_hidden[i][j] += delta_input_to_hidden[i][j];
			delta_input_to_hidden[i][j] = 0;
		}
	}
		
	
	for (int i = 0; i <= n_hidden; ++i)
	{
		for (int j = 0; j < n_output; ++j)
		{
		//	std::cout << "w_Hidden_Output " << delta_hidden_to_output[i][j] << std::endl;
		//	char c; std::cin >> c;
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
		double input[2];
		input[0] = d.patternX[i];
		input[1] = d.patternY[i];

		double desired[1];
		desired[0] = d.target[i];
		
		fowardpropagate(input);
		backpropagate(desired);
		
		for (int j = 0; j < n_output; ++j)
		{
			if (filter(output_neurons_output[j]) != desired[j]) 
				has_error = true;
		}
	}
	
	update_weights();
	
	return has_error;
}

inline int NeuralNetwork::filter( double x )
{
	if ( x < 0.1 )
		return 0;
	else if ( x > 0.9 )
		return 1;
	else
		return -1;
}

void NeuralNetwork::train_network(const DataReader d)
{
	for (int i = 0; i < max_iter; ++i)
	{
		bool b = train_iteration(d, 500);
		if (!b){
			std::cout << "Pare en " << i << std::endl;
			return;
		}
			
		for (int j = 0; j < n_output; ++j)
		{
			std::cout << output_neurons_output[j] << std::endl;
			std::cout << "error " << output_error[j] << std::endl;
		}
	}
}


double NeuralNetwork::test( const DataReader d )
{
	double incorrectResults = 0;
		
	//for every training input array
	for ( int i = 0; i < 500; ++i)
	{						
		double input[2];
		input[0] = d.patternX[i];
		input[1] = d.patternY[i];
		double desired[1];
		desired[0] = d.target[i];
		
		//feed inputs through network and backpropagate errors
		fowardpropagate( input );
		
		bool correctResult = true;

	
		for ( int k = 0; k < n_output; ++k)
		{
			if ( filter(output_neurons_output[k]) != desired[k])
				 correctResult = false;
		}
		
	
		if ( !correctResult ) incorrectResults++;	
		
	}
	
	
	return 100 - (incorrectResults/500 * 100);
}
