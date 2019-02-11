#include <stdio.h>
#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;

int points1[4][2] = {{140, 60}, {260, 171}, {-48, 246}, {156, 350}};
int points2[4][2] = {{176 + (176 - 140), 60},{176 + (176 - 260), 171},{176 + (176 + 48), 246},{196, 350}};
int points3[4][2] = {{140, 60}, {140, 50}, {176 + (176 - 140), 50}, {176 + (176 - 140), 60}};
int points4[4][2] = {{140, 60}, {140, 70}, {176 + (176 - 140), 70}, {176 + (176 - 140), 60}};
int points5[4][2] = {{156, 350}, {156, 360}, {196, 360}, {196, 350}};
float M[4][4] = {{-1, 3, -3, 1}, {3, -6, 3, 0}, {-3 ,3, 0, 0}, {1, 0, 0, 0}};
int coord[2];

void Multiply(float t,int points[][2]){
       float P1[4];
       float tMat[4] = {t * t* t, t * t, t , 1};
       for(int i = 0; i < 4; i++){
               float temp = 0;
               for(int j = 0;  j < 4; j++){
                       temp = temp + tMat[j] * M[i][j];
                       }
               P1[i] = temp;
               }

       for(int i = 0; i < 2; i++){
                 float temp = 0;
                 for(int j = 0; j < 4; j++){
                         temp = temp + P1[j]*points[j][i];
                         }
                 coord[i] = int(temp);
               }
       }
       
int main( )
{
	initwindow( 640 , 480 , "WinBGIm" );
    float t = 0;
    while(t <= 1){
            Multiply(t,points1);
            putpixel(coord[0], coord[1], WHITE);
            Multiply(t,points2);
            putpixel(coord[0], coord[1], WHITE);
            Multiply(t,points3);
            putpixel(coord[0], coord[1], WHITE);
            Multiply(t,points4);
            putpixel(coord[0], coord[1], WHITE);
            Multiply(t,points5);
            putpixel(coord[0], coord[1], WHITE);
            //cout<<coord[0]<<" "<<coord[1]<<endl;
            t += 0.001;
            }
    
	while( !kbhit() ); 
  
    
    
	closegraph( );
    
	return( 0 );
}

