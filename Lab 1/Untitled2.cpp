#include <stdio.h>
#include <iostream>
#include<math.h>
#include <graphics.h>
using namespace std;

int lineDDA(int xa,int ya, int xb, int yb)
{
	if(ya == yb)//Horizontal Line
	{
		int i, diff = abs(xa - xb), x1;
		if(xa>xb)
		{
			x1 = xb;
		}
		else
		{
			x1 = xa;
		}
		for(i = 0; i < diff; i++)
		{
			putpixel(x1++, ya, WHITE);
		}
	}
	else if(xa == xb)//Vertical Line
	{
		int i, diff = abs(ya - yb), y1;
		if(ya>yb)
		{
			y1 = yb;
		}
		else
		{
			y1 = ya;
		}
		for(i = 0; i < diff; i++)
		{
			putpixel(xa, y1++, WHITE);
		}
	}
	else
	{
    	int dx = xb-xa, dy = yb-ya ,steps,k, x1, y1;
    	float xincrement, yincrement ,x=xa , y=ya;
    	if(xa>xb)
		{
			x1 = xb;
		}
		else
		{
			x1 = xa;
		}
     	if(ya>yb)
		{
			y1 = yb;
		}
		else
		{
			y1 = ya;
		}
	    if(float(dy)/float(dx) == 1)//Diagonal line
	    {
			int i;
			for(i = 0; (x1 != xb && y1 != yb); i++)
			{
				putpixel(x1++, y1++, WHITE);
			} 
		}
		else if(float(dy)/float(dx) == -1)//Diagonal line
		{
		 	int i;
			for(i = 0; (x1 != xb && y1 != yb); i++)
			{
				putpixel(x1++, y1--, WHITE);
			} 
		}
		else
		{
		    if(abs(dx)>abs(dy))
		    {
		        steps = abs(dx);
		    }
		    else
			{
		        steps = abs(dy);
	 		}	
		 	xincrement = float(dx)/float(steps);
	     	yincrement = float(dy)/float(steps);
	     	putpixel(round(x),round(y),WHITE);
	     	for(k=0;k<steps;k++)
	     	{
	         	x += xincrement;
	         	y += yincrement;
	         	putpixel(round(x),round(y),WHITE);
	     	}
 		}
 	}
    return(0);
}
int main()
{   
	initwindow(640, 480, "CAR");
	int maxx = 3200/640, maxy = 2400/480; //Normalizing
	
	//Car Body
    lineDDA((349/maxx),(1090/maxy), (865/maxx), (1065/maxy));     
    lineDDA((865/maxx), (1065/maxy), (1077/maxx), (753/maxy));
    lineDDA((1077/maxx), (753/maxy), (1829/maxx), (753/maxy));
    lineDDA((1829/maxx), (753/maxy), (2001/maxx), (1069/maxy));
    lineDDA((2001/maxx), (1069/maxy), (2357/maxx), (1081/maxy));
    lineDDA((2357/maxx), (1081/maxy), (2509/maxx), (1477/maxy));
    lineDDA((2509/maxx), (1477/maxy), (2309/maxx), (1509/maxy));
    lineDDA((2353/maxx), (1509/maxy), (2365/maxx), (1573/maxy));
    lineDDA((2365/maxx), (1573/maxy), (2497/maxx), (1573/maxy));
    lineDDA((2497/maxx), (1573/maxy), (2497/maxx), (1545/maxy));
    lineDDA((2497/maxx), (1545/maxy), (2409/maxx), (1533/maxy));
    lineDDA((2409/maxx), (1533/maxy), (2405/maxx), (1509/maxy));
    arc((2085/maxx), (1537/maxy),8, 178,  ((2301-2085)/maxx));
    lineDDA((1853/maxx), (1529/maxy), (1005/maxx), (1537/maxy));
    arc((781/maxx), (1561/maxy),8, 178,  ((2301-2085)/maxx));
    lineDDA((545/maxx), (1537/maxy), (309/maxx), (1529/maxy));
    lineDDA((309/maxx), (1529/maxy), (329/maxx), (1113/maxy));
    lineDDA((329/maxx), (1113/maxy), (349/maxx),(1090/maxy));
    
    //Wheels
    circle((2085/maxx), (1537/maxy), ((2261-2085)/maxx));
    circle((2085/maxx), (1537/maxy), ((2181-2085)/maxx));
    circle((781/maxx), (1561/maxy), ((2261-2085)/maxx));
    circle((781/maxx), (1561/maxy), ((2181-2085)/maxx));
    
    //Windows and Doors
    int window1[] = {(1089/maxx), (793/maxy), (1429/maxx), (793/maxy),  (1429/maxx), (1057/maxy), (913/maxx), (1085/maxy), (1089/maxx), (793/maxy)};
    int window2[] = {(1493/maxx), (785/maxy), (1805/maxx), (797/maxy), (1937/maxx), (1061/maxy), (1485/maxx), (1061/maxy),(1493/maxx), (785/maxy)};
	int door1[] = {(1437/maxx), (1125/maxy), (965/maxx), (1125/maxy), (981/maxx), (1365/maxy), (1457/maxx), (1365/maxy), (1437/maxx), (1125/maxy)};
	int door2[] = {(1501/maxx), (1133/maxy), (1949/maxx), (1109/maxy), (1953/maxx), (1289/maxy), (1501/maxx), (1313/maxy), (1501/maxx), (1133/maxy)};
	
	drawpoly(5, window1);
    drawpoly(5, window2);
	drawpoly(5, door1);
    drawpoly(5, door2);
	
	getch();
	closegraph();
}
