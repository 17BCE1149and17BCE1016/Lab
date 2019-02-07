#include <stdio.h>
#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;

float maxxDef= 3200/640, maxyDef = 2400/480;

class obj{
	private:
		float xref, yref, tran[3][3], scale[3][3], rotate[3][3], reflect[3][3], shear[3][3], final[3][3];
	public:
		obj(float xr = 0, float yr = 0, float xT = 0, float yT = 0, float angle = 0, float scaleX = 1, float scaleY = 1, float shearX = 0, float shearRefY = 0, float shearRefX = 0, float shearY = 0, float m = 0, float b = 0){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					tran[i][j] = 0;
					scale[i][j] = 0;
					rotate[i][j] = 0;
					reflect[i][j] = 0;
					shear[i][j] = 0;
				}
			}
			xref = xr;
			yref = yr;
			tran[2][2] = 1;
			scale[2][2] = 1;
			rotate[2][2] = 1;
			reflect[2][2] = 1;
			shear[2][2] = 1;
			tran[0][0] = 1;
			tran[0][2] = xT;
			tran[1][1] = 1;
			tran[1][2] = yT;
			scale[0][0] = scaleX;
			scale[1][1] = scaleY;
			rotate[0][0] = cos(angle * 3.142 / 180);
			rotate[0][1] = -sin(angle * 3.142 / 180);
			rotate[1][0] = sin(angle * 3.142 / 180);
			rotate[1][1] = cos(angle * 3.142 / 180);
			shear[0][0] = 1;
			shear[0][1] = shearX;
			shear[0][2] = -shearX * shearRefY;
			shear[1][0] = shearY;
			shear[1][1] = 1;
			shear[1][2] = -shearY * shearRefX;
			reflect[0][0] = (1 - (m * m)) / (1 + (m * m));
			reflect[0][1] = (2 * m) / (1 + (m * m));
			reflect[0][2] = ((-2) * m * b) / (1 + (m * m));
			reflect[1][0] = (2 * m) / (1 + (m * m));
			reflect[1][1] = ((m * m) - 1) / (1 + (m * m));
			reflect[1][2] = (2 * b) / (1 + (m * m));
		}
		
		void Multiply(int reflFlag = 0){
			float tempMat[3][3] = {0};
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					final[i][j] = 0;
					for(int k = 0; k < 3; k++){
						final[i][j] = final[i][j] + tran[i][k] * scale[k][j]; 
					}
				}
			}
			cout<<endl;
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					float temp = 0;
					for(int k = 0; k < 3; k++){
						temp = temp + final[i][k] * rotate[k][j]; 
					}
					tempMat[i][j] = temp;
				}
			}
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					final[i][j] = tempMat[i][j];
				}
			}
			cout<<"A"<<endl;
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					float temp = 0;
					for(int k = 0; k < 3; k++){
						temp = temp + final[i][k] * shear[k][j]; 
						//cout<<final[i][k]<<" "<<reflect[k][j]<<" "<<temp<<" "<<i<<" "<<j<<" "<<k<<endl;
					}
					tempMat[i][j] = temp;
				}
			}
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					final[i][j] = tempMat[i][j];
				}
			}
			if(reflFlag == 1){
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						float temp = 0;
						for(int k = 0; k < 3; k++){
							temp = temp + final[i][k] * reflect[k][j]; 
						}
						tempMat[i][j] = temp;
					}
				}
			}
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					final[i][j] = tempMat[i][j];
				}
			}
			for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						cout<<final[i][j]<<endl;
				}
			}
		}
		void Draw(int x = 0, int y = 0, int reflFlag = 0){
			int points[5][2] = {{xref + x + 20, yref + y + 10}, {xref + x + 40, yref + y + 10}, {xref + x + 35, yref + y + 20}, {xref + x + 15, yref + y + 20}, {xref + x + 20, yref + y + 10}};
			Multiply(reflFlag);
			int tempPoints[2];
			for(int c = 0; c < 5; c++){
			for(int i = 0; i < 3; i++){
					float tempPoint = 0;
					for(int k = 0; k < 3; k++){
						if(k != 2){
						tempPoint = tempPoint + final[i][k] * points[c][k];
					}
						else{
							tempPoint = tempPoint + final[i][k] * 1;
						}
					}
				if(i != 2){
				tempPoints[i] = tempPoint;
			}
			
			}
			points[c][0] = tempPoints[0];
			points[c][1] = tempPoints[1];
		}
		int finalPoints[10] = {0};
		
		int count = 0;
		for(int i = 0; i < 10; i++){
			finalPoints[i] = points[i / 2][count++];
			if(count == 2){
				count = 0;
			}
		}
		for(int i = 0; i < 10; i++){
			cout<<finalPoints[i]<<endl;
		}
		drawpoly(5, finalPoints);
		}
};

int main( )
{
	initwindow( 640 , 480 , "WinBGIm" );
    //obj a(0, 0, 20, 20, 0, 2, 2, 2, 0, 200);
    obj b(20, 20, 30, 30, 15, 1.5, 1.5, 0, 0, 0, 0, 1, 0);
    obj a(0,0);
    b.Draw(100, 50);
    a.Draw(100, 50);

	while( !kbhit() ); 
	closegraph( );
    
	return( 0 );
}
