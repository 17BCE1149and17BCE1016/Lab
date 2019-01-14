#include <stdio.h>
#include <iostream>
#include<math.h>
#include <graphics.h>
using namespace std;

void Bresenham(int x1, int y1, int x2, int y2){
	float slope = (float)(y2 - y1)/(float)(x2 - x1);
	int x, y, startx, starty, xend, yend;
	if(x1 == x2){
		if(y1 > y2){
			starty = y2;
			yend = y1;
		}
		else{
			starty = y1;
			yend = y2;
		}
		while(starty != yend){
			putpixel(x1, starty, WHITE);
			starty++;
		}
	}
	else{
		if(x1 > x2){
			x = x2;
			y = y2;
			xend = x1;
			yend = y1;
		}
		else{
			x = x1;
			y = y1;
			xend = x2;
			yend = y2;
		}
		startx = x;
		starty = y;
		float yLine;
		int flag = 0;
		while(flag != 1){
			yLine = (x - startx)*slope + starty;
			float diff = y - yLine;
			if(diff >= 0.5){
				y--;
			}
			else if(diff <= -0.5){
				y++;
			}
			putpixel(x, y, WHITE);
			x++;
			if(x == xend + 1){
				flag = 1;
			}
		}
	}
}

int main(){
	initwindow(640, 480, "CAR");
	Bresenham(100, 100, 200, 100);
	Bresenham(100, 100, 100, 200);
	Bresenham(100, 200, 200, 200);
	Bresenham(200, 200, 200, 100);
	Bresenham(150, 100, 100, 150);
	Bresenham(100, 150, 150, 200);
	Bresenham(150, 200, 200, 150);
	Bresenham(200, 150, 150, 100);
	getch();
	closegraph();
}
