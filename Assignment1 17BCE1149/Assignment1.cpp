#include <stdio.h>
#include <iostream>
#include<math.h>
#include <graphics.h>
using namespace std;

const int xmax = 100;
const int xmin = 50;
const int ymax = 100;
const int ymin = 50;
float max(int a, int b){
	if(a > b){
		return a;
	}
	return b;
}

float min(int a, int b){
	if(a < b){
		return a;
	}
	return b;
}

void LiangBarsky(int x1, int y1, int x2, int y2){
	int p[4], q[4], t[4], dx = x2 - x1, dy = y2 - y1;
	float tmin = 0, tmax = 1;
	p[0] = -(x2 - x1);
	p[1] = (x2 - x1);
	p[2] = -(y2 - y1);
	p[3] = (y2 - y1);
	q[0] = x1 - xmin;
	q[1] = xmax - x1;
	q[2] = y1 - ymin;
	q[3] = ymax - y1;
	
	for(int i = 0; i < 4; i++){
		if(p[i] < 0){
			tmin = max(tmin, (float)q[i]/(float)p[i]);
		}
		else if(p[i] > 0){
			tmax = min(tmax, (float)q[i]/(float)p[i]);
		}
		else{
			if(q[i] < 0){
				tmax = 0;
				tmin = 1;
				break;
			}
		}
	}
	//cout<<tmin<<" "<<tmax<<endl;
	if(tmin < tmax){
		cout<<ceil(x1 + tmin * dx)<<","<<ceil(y1 + tmin * dy)<<" to "<<floor(x1 + tmax * dx)<<","<<floor(y1 + tmax * dy)<<endl;
		line(x1 + tmin * dx, y1 + tmin * dy, x1 + tmax * dx, y1 + tmax * dy);
	}
	else{
		cout<<"Line lies outside boudary"<<endl;
	}
}
int main(){
	initwindow(640, 480, "LiangBarsky");
	rectangle(xmin, ymin, xmax, ymax);
	line(7, 3, 10, 5);
	line(75, 80, 25, 25);
	line(60, 60, 80, 80);
	line(40, 40, 40, 101);
	getch();
	cleardevice();
	rectangle(xmin, ymin, xmax, ymax);
	LiangBarsky(7, 3, 10, 5);
	LiangBarsky(75, 80, 25, 25);
	LiangBarsky(60, 60, 80, 80);
	LiangBarsky(40, 40, 40, 101);
	getch();
}
