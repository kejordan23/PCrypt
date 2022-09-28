
#include "CImg.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace cimg_library;
using namespace std;

int main(int argc, char* argv[])
{
//    string path = "/Users/kyliejordan/Desktop/cat.png";
//    char* buffer = &path[0];
//    CImg<unsigned char> image = CImg<unsigned char>(buffer);
//
//    image.display();

    unsigned int w = 300;
    unsigned int h = 400;
    int size_z = 0;
    int numberOfColorChannels = 3; // R G B
    unsigned char initialValue = 0;

    const unsigned char bluegreen[] = {0, 170, 255};

    CImg<unsigned char> image(w, h, 1, 3, 255);

    //image.draw_circle(w/2, h/2, 100, bluegreen);

    CImgDisplay display(w, h, "Hello", 0);
//
//    display.display(image);
//
//    std::getchar();

    while (!display.is_closed())
    {
        display.wait();
        if (display.button() && display.mouse_y() >= 0 && display.mouse_x() >= 0)
        {
            const int y = display.mouse_y();
            const int x = display.mouse_x();

            unsigned char randomColor[3];
            randomColor[0] = rand() % 256;
            randomColor[1] = rand() % 256;
            randomColor[2] = rand() % 256;

            image.draw_point(x, y, randomColor);
        }
        image.display(display);
    }


    return 0;
}
