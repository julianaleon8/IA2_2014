/* 
 * 08-10608 Juliana Leon
 * 09-10855 Karen Troiano
 * 09-10203 Stefano De Colli 
 */

using namespace std;

#include <stdio.h>
#include <iostream>


int x1 [7] = {0,0,0,1,1,1,1};
int x2 [7] = {0,0,1,0,1,0,1};
int x3 [7] = {0,1,0,0,0,1,1};

int desired [7] = {0,0,0,0,0,0,1};

float threshold = 0.5;
float learning_rate = 0.5;
float weights [3] = {0.0, 0.0, 0.0};


int classification (int i ){
    	
	return (x1[i]*desired[i] + x2[i]*desired[i] + x3[i]*desired[i]);	 

}


int main (int argc, char ** argv ) {

	while (1)
	{
		int r = 0;
		int count_error = 0;
        
		for (int i = 0 ; i < 8; ++i)
		{
			cout << " weights: " << weights[1] << " " << weights[2] << " " << weights[3] << endl;
			
			if (classification (i) > threshold )
				r = 0;
			else 
				r = 1;
			
			int error = desired[i] - r;
			
			if (error != 0 ){ 
				count_error++;
				for (int j = 0; j < 3; ++j)
				{    
                    weights [j] += (learning_rate * error * x1[i]) +
						(learning_rate * error * x2[i]) + (learning_rate * error * x3[i]);				
				}
                
			}
			
		}
		if 	(count_error == 0)
			break;
	}
	
}
