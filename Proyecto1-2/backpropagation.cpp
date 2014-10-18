#include "backpropagation.h"

using namespace std;

inline float Backpropagation::dot_product(vector<float> input_layer,float *w) 
{
	float res = 0;
	for (int i = 0; i < 3; ++i)
		res += input_layer[i] * w[i];
	return res;
}


inline float Backpropagation::sigma(float x) 
{
	return 1 / (1 + exp(-x));
}

inline float Backpropagation::dev_sigma(float x)
{
	return x * (1 - x);
}dot_product(*it, weights[0][0]);

void Backpropagation::train(vector< vector<float> > examples, float learning_rate)
{
	
	vector<float> in; 
	float ini = 0.0;
	for (;;)
	{
		for (std::vector< vector<float> >::iterator it = examples.begin() ; it != examples.end(); ++it)
		{
			float actual_output = dot_product(*it, weights[1][0]);
			float res = sigma(actual_output);
			float o = res * (1 - res);
			float error = *it[3] - res;

			float delta[3] = {0.0, 0.0, 0.0};
			for (int j = 0; j < 3; ++j)
				delta[j] += learning_rate * o * (*it[j]) * error;

			weights[1][0][0] += delta[0];
			weights[1][0][1] += delta[1];
			weights[1][0][2] += delta[2];


			/*ini = dot_product(*it, weights[1][0]);
			in.push_back(ini);
			
			ini = dot_product(*it, weights[0][1]);
			in.push_back(ini);

			float delta[3] = {0.0, 0.0, 0.0};

			delta[0] = 1.0;
			delta[1] = dev_sigma(in[0]) * (*it[3] - sigma(in[0]));
			delta[2] = dev_sigma(in[1]) * (*it[3] - sigma(in[1]));*/

		}

	}
}

void Backpropagation::test(vector< vector<float> > examples)
{

}


Backpropagation::Backpropagation(){
	
	srand (static_cast <unsigned> (time(0)));
	weights[0][0][0] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[0][0][1] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[0][0][2] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[0][1][0] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[0][1][1] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[0][1][2] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[1][0][0] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[1][0][1] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[1][0][2] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	//weights[1][1][0] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	//weights[1][1][1] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	//weights[1][1][2] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	
}
