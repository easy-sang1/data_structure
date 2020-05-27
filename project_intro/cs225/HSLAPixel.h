/**
 * 
 * 이지상이 작성한 코드
 * 
 * 
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 */

#pragma once

namespace cs225 {

    class HSLAPixel{
    public :
        double h;
        double a;
        double s;
        double l;

        HSLAPixel();
        HSLAPixel(double h, double s, double l);
        HSLAPixel(double h, double a, double s, double l);

    };
}
