
#include <vector>

class Backpropagation
{
	// 2 Capas x 2 Neuronas por capas x 3 pesos
	float weights[2][2][3];
	void train(vector< vector<float> >, float);
	void test(vector< vector<float> >);
};
