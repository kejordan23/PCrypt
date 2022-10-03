//
// Created by Kylie Jordan on 10/3/22.
//

#ifndef PROJECT_FUNCTION_H
#define PROJECT_FUNCTION_H

#include "CImg.h"
#include <iostream>
using namespace cimg_library;
using namespace std;

class Function{
private:
    CImgDisplay disp = CImgDisplay(600, 800, "Hello", 0);
    CImgDisplay dispz = CImgDisplay(500,500,"[#17] - Zoomed Image",0);
    CImg<unsigned char> img = CImg<unsigned char>(600, 800, 1, 3, 0);
public:
    Function(){};
    void* item_image_zoomer();
    void drawPixels();
};

#endif //PROJECT_FUNCTION_H
