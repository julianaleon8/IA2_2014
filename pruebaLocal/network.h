#include "dataReader.h"

class NeuralNetwork
{
private:
	int n_input;
	int n_hidden;
	int n_output;

	double learning_rate = 0.01;
	double momentum = 0.9;
	int max_iter = 1500;

	// These store the output
	double* input_neurons_output;
	double* hidden_neurons_output;
	double* output_neutons_output;

	// These the incoming weights
	double** w_input_to_hidden;
	double** w_hidden_to_output;

	double* hidden_error;
	double* output_error;

	double** delta_input_to_hidden;
	double** delta_hidden_to_output;

	void init_weights();
	double sigma(double);
	double dev_sigma(double);
	void fowardpropagate(double*);
	double dot_product(double*, double*, int);
	void update_weights();
	void training_iteration(DataReader, int);

public:
	NeuralNetwork(int, int, int);
	set_training_parameter(double, double, int);
	~NeuralNetwork();
	void backpropagate(double*);

	void train_network();
};
