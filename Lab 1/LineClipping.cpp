#include<iostream>

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
//coordinates for rectangles
// i assume regular coordinate system hence the origin is bottom LEFT and not top LEFT corner of the screen.

const int xmin = 50;
const int xmax = 100;
const int ymin = 50;
const int ymax = 100;

const int inside =0; //inside = 0 0000
const int LEFT = 1; //LEFT = 1 0001
const int RIGHT = 2; //RIGHT = 2 0010
const int bottom = 4; //top = 4 0100
const int top = 8; //bottom =8 1000

int computeRegion(int *x,int *y)
{
    int a = inside;
    if(*x<xmin)
    {
        a = a + LEFT;          
    }
    else if(*x>xmax)
    {
        a = a+RIGHT;
    }
    if(*y<ymin)
    {
        a = a+bottom;
    }
    if(*y>ymax)
    {
        a = a+top;          
    }
    return a;
}

int clip(int *x1,int *y1,int *x2,int *y2)
{
    
    
    bool accept = false;
     while(true)
     {
     	int a1 = computeRegion(x1,y1);
    	int a2 = computeRegion(x2,y2);
         if((a1==0)&&(a2==0)) //inside the region
         {
             accept = true;
             break;
         }         
         else if(a1==a2)
         {
         	 *x1 = NULL;
         	 *x2 = NULL;
         	 *y1 = NULL;
         	 *y2 = NULL;
             break;
         }
         else if((a1 != a2) && (a1 != 0 && a2 != 0)){
         	int count = 0;
         	while(count != 2){
			int temp;
             int x,y;
             if(count == 0)
             {
                 temp = a1;
             }
             else
             {
                 temp = a2;
             }
			 if(temp & top)
			 {
			     //point is above the rectangle
			     x = *x1 + ((*x2-*x1)*(ymax-*y1)/(*y2-*y1));
			     y = ymax;
			 }
			 else if (temp & bottom)
			 {
			     x = *x1 + ((*x2-*x1)*(ymin-*y1)/(*y2-*y1));
			     y = ymin;
			 }
			 else if (temp & RIGHT)
			 {
			     y = *y1 + ((*y2-*y1)*(xmax-*x1)/(*x2-*x1));
			     x = xmax;
		     }
		     else if (temp & LEFT)
			 {
			     y = *y1 + ((*y2-*y1)*(xmin-*x1)/(*x2-*x1));
			     x = xmin;
			 }
			 cout<<count<<endl;
			 /*if((x < xmin) || (x > xmax) || (y < ymin) || (y > ymax)){
			 	break;
			 }*/
			 // depending on which endpoint is outside the rectangle
			 if (count == 0)
			 {
			     *x1=x;
				 *y1=y;
			 }
			 else
			 {
			     *x2=x;
			     *y2=y;
			 }
			 count++;
			 if(count == 2)
			 	accept = true;
			else{
				*x1 = NULL;
				*x2 = NULL;
				*y1 = NULL;
				*y2 = NULL;
			}
			}
			//break;
		 }
         else
         {
         	//cout<<"A"<<endl;
             int temp;
             int x,y;
             if(a1!=0)
             {
                 temp =a1;
             }
             else
             {
                 temp =a2;
             }
			 if(temp & top)
			 {
			     //point is above the rectangle
			     x = *x1 + ((*x2-*x1)*(ymax-*y1)/(*y2-*y1));
			     y = ymax;
			 }
			 else if (temp & bottom)
			 {
			     x = *x1 + ((*x2-*x1)*(ymin-*y1)/(*y2-*y1));
			     y = ymin;
			 }
			 else if (temp & RIGHT)
			 {
			     y = *y1 + ((*y2-*y1)*(xmax-*x1)/(*x2-*x1));
			     x = xmax;
		     }
		     else if (temp & LEFT)
			 {
			     y = *y1 + ((*y2-*y1)*(xmin-*x1)/(*x2-*x1));
			     x = xmin;
			 }
			 //cout<<x<<" "<<y<<endl;
			 // depending on which endpoint is outside the rectangle
			 if (temp == a1)
			 {
			     *x1=x;
				 *y1=y;
			 }
			 else
			 {
			     *x2=x;
			     *y2=y;
			 }
			 accept = true;
			 //break;    
         } //inside the same region completely outside
     }
	 if (accept) //accept == true 
	 {
	     cout <<"Line accepted from " << *x1 << ", "<< *y1 << " to "<< *x2 << ", " << *y2 << endl;
	 }
	 else
	 {
	     cout<<"Line Rejected"<<endl;
	 }
	 }     

int main()
{
	int n;
	cout<<"Enter number of lines:";
	cin>>n;
	int *points[2*n][2], point[2*n][2];
	for(int i = 0; i < 2*n; i += 2){
		cout<<"Enter points for line "<<(i/2)+1<<":";
		cin>>point[i][0]>>point[i][1];
		//cout<<i+1;
		cin>>point[i+1][0]>>point[i+1][1];
	}
	for(int i = 0; i < 2*n; i++){
		points[i][0] = &point[i][0];
		points[i][1] = &point[i][1];
	}
	for(int i = 0; i < 2*n; i += 2){
		clip(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
	}
	initwindow(640, 480, "Line Clipping");
	rectangle(50, 50, 100, 100);
	for(int i = 0; i < 2*n; i += 2){
		line(*points[i][0], *points[i][1], *points[i+1][0], *points[i+1][1]);
	}
	getch();
/*clip (10,5,7,3);
clip (7,3,6,12);
clip (60, 60, 80, 80);
clip (50,50,70,101);// partially inside not working!!

clip (25,25,75,80);*/
return 0;    
}

