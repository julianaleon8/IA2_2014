#include "perceptron.h"

int main(void){
	
	int input[NUM_OF_X][NUM_CASES] = {
		{ 1, 1, 1, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 0, 1 }
	};

	int desired[NUM_CASES] = { 0, 0, 0, 1 };

	float learning_rate = 0.1;
	float weights[NUM_OF_X] = { 0.0, 0.0, 0.0 };
	
	Perceptron p = Perceptron(&input, &desired, 
							   learning_rate, &weights);
	
	float* pesos = p.perceptron();
	
	cout << "0 1 0: " << p.prueba({0,1,0}, &pesos) << endl;
}