#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
using namespace cs225;

// 픽셀의 위치를 서로 바꾸는 함수
void change(HSLAPixel& fir, HSLAPixel& sec)
{
  HSLAPixel temp = fir;
  fir = sec;
  sec = temp;
}

// 사진 가운데만 밝게 만들어주기
PNG createSpotlight(PNG image, int centerX, int centerY) {

  for(unsigned x = 0; x < image.width(); x++){
    for(unsigned y = 0; y < image.height(); y++){
      double length = sqrt(pow( centerX - int(x), 2) + pow(centerY - int(y), 2));

      HSLAPixel & pixel = image.getPixel(x, y);

      if(length > 160){
        pixel.l -= pixel.l*0.8;
      }
      else{
        pixel.l -= pixel.l* (length*0.005);
      }
    }
  }

  return image;

}


  // inputFile을 읽어서 180도 회전시킨 PNG파일을 만든후 outputFile 이름으로 PNG 파일 만들기
void rotate(std::string inputFile, std::string outputFile) {

  PNG ipng;

  cout << inputFile << ", " << outputFile << endl;
  ipng.readFromFile(inputFile);

  for(unsigned x = 0, w = ipng.width(); x < w; x++){
    for(unsigned y = 0, h = ipng.height()/2; y < h; y++){
      HSLAPixel & up = ipng.getPixel(x, y);

      HSLAPixel & down = ipng.getPixel(x, ipng.height() - y);
      
      change(up, down);
    }
  }
  
  ipng.writeToFile(outputFile);

}

// 직접 픽셀값을 조정해서 만들어본 사진
cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);

  double cwidth = width*0.5;
  double cheight = height*0.5;

  for(int i = 1; i <= width; i++){
    for(int j = 1; j <= height; j++){

      double tr = sqrt(pow(cwidth-i, 2) + pow(cheight-j, 2));


      if(tr < 100){

        HSLAPixel & hsla = png.getPixel(i-1, j-1);

        hsla.a = 1.0;
        hsla.h = (double)(i%360);
        hsla.s = 100;
        hsla.l = 50;
      }
      else if(tr > 150 && tr < 200){
        HSLAPixel & hsla = png.getPixel(i-1, j-1);

        hsla.a = 1.0;
        hsla.h = (double)(j%360);
        hsla.s = 100;
        hsla.l = 50;
        
      }
      else if(tr > 250){

        if(i < j){

        HSLAPixel & hsla = png.getPixel(i-1, j-1);

        hsla.a = 1.0;
        hsla.h = (double)((j/i)%360);
        hsla.s = 100;
        hsla.l = 50;
        }
        else{
          HSLAPixel & hsla = png.getPixel(i-1, j-1);

        hsla.a = 1.0;
        hsla.h = (double)((i/j)%360);
        hsla.s = 100;
        hsla.l = 50;
        }
      }

    }
  }

  return png;
}
