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
float learning_rate = 0.1;
float weights [3] = {0.0, 0.0, 0.0};
int inter =50;
float classification (int i ){
    
	return (x1[i]*weights[0] + x2[i]*weights[1] + x3[i]*weights[2]);	 

}


int main ( void) {
	int count = 0;
	while (count < inter){
		int r = 0;
		count ++;
		int count_error = 0;
        
		for (int i = 0 ; i < 8; ++i)
		{
			cout << " weights: " << weights[0] << " " << weights[1] << " " << weights[2] << endl;
			float result = classification (i); 
		
			if ( result > threshold ){
				
				r = 0;
			}
			else 
				r = 1;
			
			int error = desired[i] - r;
			
			if (error != 0 ){ 
				count_error++;
				for (int j = 0; j < 3; ++j)
				{
					int entrada [3] = {x1[i],x2[i],x3[i]}; 
                    weights [j] += (learning_rate * error * entrada[j]);
						cout << " entrada" << entrada[j];

				}
                
			}
			
		}
		if 	(count_error == 0)
			return 0;
	}
	
}
