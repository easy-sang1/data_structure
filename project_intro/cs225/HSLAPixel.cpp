/**
 * 
 * 이지상이 작성한 코드
 * 
 * 
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 */

#include "HSLAPixel.h"

namespace cs225 {

    HSLAPixel::HSLAPixel(){
        l = 1;
        a = 1;
    }

    HSLAPixel::HSLAPixel(double h, double s, double l){
        this->h = h;
        this->a = 1.0;
        this->s = s;
        this->l = l;
    }

    HSLAPixel::HSLAPixel(double h, double a, double s, double l){
        this->h = h;
        this->a = a;
        this->s = s;
        this->l = l;
    }
}
