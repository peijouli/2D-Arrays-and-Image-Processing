#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width){
for (int i =left; i <= left + width; i++){

   if ((top >= 0) && (top <=SIZE) && (i >=0) && (i <= SIZE)){
      image[top][i]=0;}
   if ((top + height >= 0) && (top +height <=SIZE) && (i >=0) && (i <= SIZE)){
      image[top+height][i]=0;
   }
}


for (int j=top; j <= top + height; j++){
   
   if((j >=0) && (j <=SIZE)&&(left >=0) && (left <= SIZE)){
      image[j][left]=0;}
   if((j >=0) && (j <=SIZE)&&(left + width >=0) && (left+width <= SIZE)){
      image[j][left + width]=0;
   }
}

 
}




// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
//int cy = center row (horizontal)
//int cx = center column (vertical)
int x = 0;
int y= 0;
for (double i=0; i<2 * M_PI; i+=0.01){
   
   x=(int)((width/2)*cos(i) + cx);
   y=(int)((height/2)*sin(i) + cy);
   if ((x >=0) && (x <=SIZE) && (y >=0) && (y<= SIZE)){
   image[y][x]=0;
}
}

}
int main() 
{
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
   int x;
   int top;
   int left; 
   int height;
   int width;
   int cy;
   int cx;
   int height1;
   int width1;
   
   cout << "To draw a rectangle, enter: 0 top left height width" << endl;
   cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
   cout << "To save your drawing as ""output.bmp"" and quit, enter: 2" << endl;
   cin >> x;
   
   while (x !=2){
       
   if (x== 0){
      cin >> top >> left >> height >> width;

      draw_rectangle(top, left, height, width);
   }

   if (x==1){
      cin >> cy >> cx >> height1 >> width1;
      draw_ellipse(cy, cx, height1, width1);
   }
   cin >> x;
   }
   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}