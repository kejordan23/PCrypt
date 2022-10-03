//
// Created by Kylie Jordan on 10/3/22.
//

#include "Function.h"


//referenced from https://github.com/GreycLab/CImg/blob/master/examples/CImg_demo.cpp
void* Function::item_image_zoomer() {
    disp.move((CImgDisplay::screen_width() - dispz.width())/2,
              (CImgDisplay::screen_height() - dispz.height() - disp.height())/2);
    dispz.move(disp.window_x(),disp.window_y() + disp.window_height() + 40);
    int factor = 10, x = 0, y = 0;
    bool grid = false, redraw = false, freeze = false, click = false;
    while (!disp.is_closed() && !dispz.is_closed() &&
           !disp.is_keyQ() && !dispz.is_keyQ() && !disp.is_keyESC() && !dispz.is_keyESC()) {
        if (disp.mouse_x()>=0) { x = disp.mouse_x(); y = disp.mouse_y(); redraw = true; }
        if (redraw) {
            const int
                    x0 = x - factor, y0 = y - factor,
                    x1 = x + factor, y1 = y + factor;
            const unsigned char red[] = { 255, 0, 0 }, black[] = { 0, 0, 0 }, white[] = { 255, 255, 255 };
            (+img).draw_rectangle(x0,y0,x1,y1,red,1.0f,~0U).display(disp);
            CImg<unsigned char> visu;
            if(!freeze){
                cout<<"freeze is false"<<endl;
                x = disp.mouse_x();
                y = disp.mouse_y();
                visu = img.get_crop(x0,y0,x1,y1).draw_point(x - x0,y - y0,black,0.2f).resize(dispz);
            }
            else{
                cout<<"freeze is true"<<endl;
                const int t = x;
                cout<<t<<endl;
                const int z = y;
                const int
                        x0 = t - factor, y0 = z - factor,
                        x1 = t + factor, y1 = z + factor;
                visu = img.get_crop(x0,y0,x1,y1).draw_point(t - x0,z - y0,black).resize(dispz);
                //dispz.wait();
            }
            while(click){
                cout<<"click is true"<<endl;
                if(disp.button()) {
                    click = false;
                    cout<<"click is false"<<endl;
                    disp.set_button();
                }
                else{
                    cout<<"waiting"<<endl;
                    disp.wait(100);
                    const int t = x;
                    cout<<t<<endl;
                    visu = img.draw_rectangle(x ,y, x+20, y+20, red, 1).display(dispz);
                }
            }
            const int bfac = 2*factor + 1;
            for (int i = 0; i<bfac; ++i) {
                const int X = i*dispz.width()/bfac, Y = i*dispz.height()/bfac;
                visu.draw_line(X,0,X,dispz.height() - 1,white).draw_line(0,Y,dispz.width() - 1,Y,white);
            }
            visu.draw_text(2,2,"Coords (%d,%d)",white,0,1,13,x,y).display(dispz);
        }
        if (disp.button()) {
            click = true;
            grid = !grid;
            freeze = !freeze;
            disp.set_button();
            dispz.set_button();
            redraw = true;
        }
        if (disp.is_resized()) disp.resize(disp);
        if (dispz.is_resized()) { dispz.resize(); redraw = true; }
        //dispz.wait();
        CImgDisplay::wait(disp,dispz);
    }
    return 0;
}

void Function::drawPixels(){
    while (!dispz.is_closed())
    {
        if (dispz.button() && dispz.mouse_y() >= 0 && dispz.mouse_x() >= 0)
        {
            const int y = dispz.mouse_y();
            const int x = dispz.mouse_x();

            unsigned char randomColor[3];
            randomColor[0] = rand() % 256;
            randomColor[1] = rand() % 256;
            randomColor[2] = rand() % 256;

            img.draw_point(x, y, randomColor);
        }
        //img.display(dispz);
    }
}

