#include "dataReader.h"

using namespace std;
void DataReader::loadData( const char* file,int numCases, int numVariables, int numDesired, int numPrueba) {

// File input for the training examples
	std::ifstream input( file );
	// Read from file
	string line;

	pattern = new  double* [numCases]();
	target = new  double* [numCases]();
	for (int i = 0 ; i < numCases; i++ )
		pattern[i] = new double[numVariables]();
	for (int i = 0 ; i < numCases; i++ )
		target[i] = new double[numDesired]();

	char *sopa = NULL;

	num_cases = numCases;
	num_prueba = numPrueba;

	for (int j = 0 ; j < numCases; j++)
	{
		
		getline( input, line);

		char *aux = new char[line.length() + 1];
		strcpy(aux, line.c_str());
		sopa = strtok(aux, " ");

		for (int i = 0 ; i < numVariables ; i++){
			pattern[j][i]= atof(sopa);
			sopa = strtok (NULL, " ");
			
		}

		for (int i = 0 ; i < numDesired ; i++){
			if (sopa == NULL) {
				break;
			}
			target[j][i] = atof(sopa);
			sopa = strtok (NULL, " ");
		}
		
		delete[] aux;
	}
}






