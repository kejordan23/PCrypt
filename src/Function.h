//
// Created by Kylie Jordan on 10/3/22.
//

#ifndef PROJECT_FUNCTION_H
#define PROJECT_FUNCTION_H

#include "CImg.h"
#include <iostream>
#include <fstream>
#include "Action.h"
#include "String.h"
#include <stdlib.h>

using namespace cimg_library;
using namespace std;

class Function{
private:
    CImgDisplay disp;
    CImgDisplay dispz;
    CImg<unsigned char> img;
    vector<vector<Color>> currImg = vector<vector<Color>>();
    int maxX = 0;
    int maxY = 0;
    int pixSize = 20;
public:
    Function(){
        disp = CImgDisplay(1000, 900, "Hello World", 0);
        dispz = CImgDisplay(500,500,"Zoomed Image",0);
        img = CImg<unsigned char>(1000, 900, 1, 3, 0);
    };
    Function(int w, int h, char* name){
        disp = CImgDisplay(w, h, name, 0);
        dispz = CImgDisplay(500,500,"Zoomed Image",0);
        img = CImg<unsigned char>(w, h, 1, 3, 0);
    };
    void* item_image_zoomer();
    void computePixel(int&, int&);
    void changeColor(unsigned char*&);
    void createImage(ifstream&, bool, int, bool);
    void translate(int, int, Color&);
    void screenShot();
};

#endif //PROJECT_FUNCTION_H
