/*
* 08-10608 Juliana Leon
* 09-10855 Karen Troiano
* 09-10203 Stefano De Colli
*/

using namespace std;

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <boost/foreach.hpp>
#define NUM_CASES 500


int main(){
// File input for the training examples
std::ifstream input( "datos_P1_2_SD2014_n500.txt" );
// Read from file
string line;


vector< vector<float > > examples;

vector< float > example(3);
char *sopa = NULL;
for (int j = 0 ; j < NUM_CASES; j++){
	
	getline( input, line);
	
	char *aux = new char[line.length() + 1];
	strcpy(aux, line.c_str());
	//cout << aux << endl;
	sopa = strtok(aux, " ");
	
	example[0]= atof(sopa);	
	sopa = strtok (NULL, " ");
	example[1]= atof(sopa);
	sopa = strtok (NULL, " ");
	example[2]= atof(sopa);	
	
	

	examples.push_back(example);
	cout << examples[j][0] << "    "<< examples[j][1] << "    "<< examples[j][2] << endl;

}

}
