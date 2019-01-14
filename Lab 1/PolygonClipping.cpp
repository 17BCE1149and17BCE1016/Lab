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
			 if((x < xmin) || (x > xmax) || (y < ymin) || (y > ymax)){
			 	break;
			 }
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
	 
int findNext(int i, int n, int points[][2]){
	for(int j = i + 1; j < n; j++){
		if(points[j][0] != NULL){
			return j;
		}
	}
}
void polygonClip(int n, int points[][2]){
	int i, count = 0, flag = 0;
	int final[2*n][2] = {NULL, NULL};
	if(computeRegion(&points[n-1][0],&points[n-1][1])!=0){
		flag = 1;
	}
	for(i = 0; i < n - 1; i++){
		int start[2] = {points[i][0], points[i][1]};
		int end[2] = {points[i+1][0], points[i+1][1]};
		if(computeRegion(&end[0], &end[1]) == 0 && computeRegion(&start[0], &start[1]) != 0){
			count++;
			final[count][0] = NULL;
			final[count][1] = NULL;
			count++;
		}
		cout<<start[0]<<" "<<end[0]<<endl;
		clip(&start[0], &start[1], &end[0], &end[1]);
		
		cout<<start[0]<<" "<<end[0]<<endl<<endl;
		if(start[0] == NULL){
			count++;
		}
		final[count][0] = start[0];
		final[count][1] = start[1];
		count++;
		final[count][0] = end[0];
		final[count][1] = end[1];
		count++;
		count--;
	}
	count++;
	if(flag == 1){
		final[count][0] = NULL;
		final[count][1] = NULL;
		count++;
	}
	for(int i = 0; i < count; i++){
		cout<<final[i][0]<<" "<<final[i][1]<<endl;
	}
	int startIndex = findNext(-1, count, final);
	int start[2] = {final[startIndex][0], final[startIndex][1]};
	flag = 0;
	//int end[2] = {final[1][0], final[1][0]};
	int back[2] = {start[0], start[1]};
	for(i = startIndex + 1; i <= count; i++){
		cout<<endl<<final[i][0]<<"X"<<final[i+1][0]<<"Y"<<endl;
		if(flag == 1 && final[i][0] != NULL){
			flag = 0;
			if(final[i-1][0] == NULL){
			//cout<<endl<<final[i][0]<<"BA"<<final[i][1]<<endl;
			back[0] = final[i][0];
			back[1] = final[i][1];
			}	
			continue;
		}
		if(final[i][0] == NULL){
			cout<<"1"<<endl;
			continue;
		}
		else if(final[i+1][0] == NULL){
			line(start[0], start[1], final[i][0], final[i][1]);
			//start[0] = final[i][0];
			//start[1] = final[i][1];
			cout<<final[i][0]<<"a"<<final[i][1]<<"b"<<back[0]<<" "<<back[1]<<endl;
			line(final[i][0], final[i][1], back[0], back[1]);
			int index = findNext(i, count, final);
			start[0] = final[index][0];
			start[1] = final[index][1];
			flag = 1;
			cout<<"2"<<endl;
		}
		else{
			cout<<start[0]<<" "<<start[1]<<"3"<<final[i][0]<<" "<<final[i][1]<<endl;
			line(start[0], start[1], final[i][0], final[i][1]);
			start[0] = final[i][0];
			start[1] = final[i][1];
		}
		if(final[i-1][0] == NULL){
			//cout<<endl<<final[i][0]<<"BA"<<final[i][1]<<endl;
			back[0] = final[i][0];
			back[1] = final[i][1];
		}
	}
}
int main()
{
	int point[6][2];
	for(int i = 0; i < 6; i++){
		cin>>point[i][0]>>point[i][1];
	}
	initwindow(640, 480, "CAR");
	int orig[12];
	for(int i = 0; i < 12; i++){
		orig[i] = point[i/2][i%2];
	}
	for(int i = 0; i < 12; i++){
		cout<<orig[i]<<endl;
	}
	drawpoly(6, orig);
	getch();
	getch();
	cleardevice();
	polygonClip(6, point);
	getch();
return 0;    
}

