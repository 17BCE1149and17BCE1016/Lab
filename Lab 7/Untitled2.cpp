#include <stdio.h>
#include <iostream>
#include<conio.h>
#include <graphics.h>
#include <math.h>
#define round(a)((int)(a+0.5))

using namespace std;
void Triangle(int ax, int ay, int bx, int by, int cx, int cy, int count){
                      float a, b, c, s, area, r, cenx, ceny;
                       c = sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by)));
                       b = sqrt(((ax - cx) * (ax - cx)) + ((ay - cy) * (ay - cy)));
                       a = sqrt(((cx - bx) * (cx - bx)) + ((cy - by) * (cy - by)));
                       cenx = ((a * ax) + (b * bx) + (c * cx))/(a + b + c);
                       ceny = ((a * ay) + (b * by) + (c * cy))/(a + b + c);
                  if(count % 2 != 0){
                      line(ax, ay, bx, by);
                      line(ax, ay, cx, cy);
                      line(bx, by, cx, cy);
                  }
                  else{
                       s = (a + b + c)/2;
                       area = sqrt(s * (s - a) * (s - b) * (s - c));
                       r = area / s;
                       circle((int)cenx, (int)ceny, (int)r);
                       }
                  setfillstyle(SOLID_FILL, (count + 1) % 15);
                  floodfill(cenx, ceny, WHITE);
                  if(count != 0){
                           if(count %2 == 0){
                           count--;
                       Triangle(abs((ax + bx))/2, abs((ay + by))/2, abs(bx + cx)/2, abs(by + cy)/2, abs(cx + ax)/2, abs(cy + ay)/2, count);
                       }
                       else{
                            count--;
                       Triangle(ax, ay, bx, by, cx, cy, count);
                            }
                       }
                  
     }
     
int main( )
{
    
	initwindow( 640 , 480 , "WinBGIm" );
    Triangle(100, 100, 300, 100, 200, 273, 4);    

    getch();
    return 0;
}
