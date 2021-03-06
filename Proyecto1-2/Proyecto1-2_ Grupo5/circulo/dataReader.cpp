#include "dataReader.h"

using namespace std;
void DataReader::loadData( const char* file, int numCases, int numVariables, int numDesired)
{
	// File input for the training examples
	std::ifstream input(file);
	// Read from file
	string line;

	pattern = new  double* [numCases]();
	target = new  double* [numCases]();
	for (int i = 0 ; i < numCases; i++ )
	{
		pattern[i] = new double[numVariables]();
	}
	for (int i = 0 ; i < numCases; i++ )
	{
		target[i] = new double[numDesired]();
	}

	char* sopa = NULL;

	num_cases = numCases;


	for (int j = 0 ; j < numCases; j++)
	{

		getline(input, line);

		char* aux = new char[line.length() + 1];
		strcpy(aux, line.c_str());
		sopa = strtok(aux, " ");

		for (int i = 0 ; i < numVariables ; ++i)
		{
			if (sopa != 0)
			{
				pattern[j][i]= atof(sopa);
				sopa = strtok (NULL, " ");
			}
		}

		for (int i = 0 ; i < numDesired ; ++i)
		{
			if (sopa != 0)
			{
				target[j][i] = atof(sopa);
				sopa = strtok (NULL, " ");
			}
		}


		delete[] aux;
	}

	//printPatterns(numVariables);
	//printTargets(numDesired);
}

void DataReader::printPatterns(int numInput)
{
	cout << "Input: \n";
	for (int i = 0; i < num_cases; ++i)
	{
		for (int j = 0; j < numInput; ++j)
		{
			cout << pattern[i][j] << ' ';
		}

		cout << endl;
	}
}

void DataReader::printTargets(int numOutput)
{
	cout << "Outputs: \n";
	for (int i = 0; i < num_cases; ++i)
	{
		for (int j = 0; j < numOutput; ++j)
		{
			cout << target[i][j] << ' ';
		}

		cout << endl;
	}
}
