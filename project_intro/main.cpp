// 이지상이 직접 만든 코드

#include <iostream>
#include <stdlib.h>

#include "intro.h"
#include "cs225/PNG.h"

#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned int width = (unsigned int)atoi(argv[1]);
    std::cout << "myArt 그림 만들기 (크기 :  " << width << ", " << width << ") myart.png로 저장." << std::endl;
    

    cs225::PNG png = myArt(width, width);
    png.writeToFile("myart.png");

    cs225::PNG png1;
    png1.readFromFile("input.png");
    std::cout << "input.png 회전시켜서 output_rotate.png로 저장." << std::endl;
    rotate("input.png", "output_rotate.png");

    std::cout << "input.png파일의 가운데 부분만 밝게 만들어서 output_highlight.png파일로 저장" << std::endl;
    createSpotlight(png1, png1.width()/2, png1.height()/2).writeToFile("output_highlight.png");
  
  return 0;
}
