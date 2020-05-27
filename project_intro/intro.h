#pragma once

#include "cs225/PNG.h"

#include <string>

cs225::PNG createSpotlight(cs225::PNG image, int centerX, int centerY);
void rotate(std::string inputFile, std::string outputFile);
cs225::PNG myArt(unsigned int width, unsigned int height);
