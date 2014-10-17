#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Backpropagation
{
	// 2 Capas x 2 Neuronas por capas x 3 pesos
	Backpropagation();
	float weights[2][2][3];
	double dot_product(vector<float> inputCase,float *w);
	double sigma(double x) ;
	double dev_sigma(double x);
	void train(vector< vector<float> >, float);
	void test(vector< vector<float> >);
};
