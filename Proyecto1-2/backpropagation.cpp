#include "backpropagation.h"

using namespace std;

inline double Backpropagation::dot_product(vector<float> inputCase,float *w) 
{
	double res = 0;
	for (int i = 0; i < 3; ++i)
		res += inputCase[i] * w[i];
	return res;
}


inline double Backpropagation::sigma(double x) 
{
	return 1 / (1 + exp(-x));
}

inline double Backpropagation::devSigma(double x)
{
	return x * (1 - x);
}

void Backpropagation::train(vector< vector<float> > examples, float learning_rate)
{
	
	vector<double> in; 
	double ini = 0.0;
	for(;;)
	{
		for (std::vector< vector<float> >::iterator it = examples.begin() ; it != examples.end(); ++it)
		{
			ini = dot_product(*it , weights[0][0]);
			in.push_back(sigma(ini));
			
			ini = dot_product(*it, weights[0][1]);
			in.push_back(sigma(ini));
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
	weights[1][1][0] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[1][1][1] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	weights[1][1][2] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.5));
	
}