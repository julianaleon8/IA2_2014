/* 
 * 08-10608 Juliana Leon
 * 09-10855 Karen Troiano
 * 09-10203 Stefano De Colli 
 */

#include <stdio.h>
#include <iostream>



using namespace std;

int x1 [6] = {0,0,0,1,1,1};
int x2 [6] = {0,0,1,0,1,0};
int x3 [6] = {0,1,0,0,0,1};
int desired [6] = {0,0,0,0,0,0};
int threshold = 0.5;
int learning_rate = 0.1;
int weights [3] = {0, 0, 0};


int classification (int i ){
		
	return (x1[i]*desired[i]+ x2[i]*desired[i]+ x3[i]*desired[i]);	 

}


int main (int argc, char ** argv ) {

	while (1){
		int r = 0;
		int count_error = 0;
		int i = 0 ;
		for ( i ; i < 7; i++){
			cout << " primero " << weights[1] << weights[2]<< weights[3];
			if (classification (i) > threshold )
				r = 0;
			else 
				r = 1;
			int error = desired[i] - r;
			if (error != 0 ){
				int j = 0 ; 
				for (j ; j< 3; j++)
					weights [j] = weights[j-1] + (learning_rate * error * x1[i]) +
						(learning_rate * error * x2[i]) + (learning_rate * error * x3[i]);
			}
			
		}
		if 	(count_error == 0)
			break;
		
	}
	
}
