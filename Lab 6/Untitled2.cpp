#include <stdio.h>
#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;

float points[8][3] = {{100, 100, 0}, {100, 200, 0}, {200, 200, 0}, {200, 100, 0}, {100, 100, 100}, {100, 200, 100}, {200, 200, 100}, {200, 100, 100}};
float final[8][2];

void multiply(int d){
	float mat[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1/d, 1}};
	for(int c = 0 ; c < 8; c++){
		for(int i = 0; i < 4; i++){
               float temp = 0;
               for(int j = 0;  j < 4; j++){
                       if(j != 3)
							temp = temp + points[c][j] * mat[i][j];
						else
							temp = temp + 1 * mat[i][j];
                    
					   }
				if(i != 2)
               		final[c][i] = temp/(1 + (points[c][2]/d));
               }
	}
}     
int main( )
{
	initwindow( 640 , 480 , "WinBGIm" );
	multiply(1000);
	
	for(int i = 0; i < 3; i++){
		line((int)final[i][0], (int)final[i][1], (int)final[i + 1][0], (int)final[i + 1][1]);
		line((int)final[i + 4][0], (int)final[i + 4][1], (int)final[i + 5][0], (int)final[i + 5][1]);
		line((int)final[i][0], (int)final[i][1], (int)final[i + 4][0], (int)final[i + 4][1]);
	}
	line((int)final[3][0], (int)final[3][1], (int)final[0][0], (int)final[0][1]);
	line((int)final[4][0], (int)final[4][1], (int)final[7][0], (int)final[7][1]);
	line((int)final[3][0], (int)final[3][1], (int)final[7][0], (int)final[7][1]);
    
    while(!kbhit());
	closegraph( );
    
	return( 0 );
}

