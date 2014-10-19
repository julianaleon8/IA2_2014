#include "dataReader.h"

using namespace std;
void DataReader::loadData(){
// File input for the training examples
	std::ifstream input( "datos_P1_2_SD2014_n500.txt" );
	// Read from file
	string line;
	
	
	
	char *sopa = NULL;
	for (int j = 0 ; j < NUM_CASES; j++){
		
		getline( input, line);
		
		char *aux = new char[line.length() + 1];
		strcpy(aux, line.c_str());
		//cout << aux << endl;
		sopa = strtok(aux, " ");
		
		
		patternX[j]= atof(sopa);	
		sopa = strtok (NULL, " ");
		patternY[j]= atof(sopa);
		sopa = strtok (NULL, " ");
		target[j]= atof(sopa);	
			
	}
}




		
	   
