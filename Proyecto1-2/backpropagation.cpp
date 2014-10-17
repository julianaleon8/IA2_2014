#include "backpropagation.h"

void Backpropagation::train(vector< vector<float> > examples, float learning_rate)
{
	
	for(;;)
	{
		
		for (std::vector< vector<float> >::iterator it = examples.begin() ; it != examples.end(); ++it)
		{
			
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