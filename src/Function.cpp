//
// Created by Kylie Jordan on 10/3/22.
//

#include "Function.h"


//referenced from https://github.com/GreycLab/CImg/blob/master/examples/CImg_demo.cpp
void* Function::item_image_zoomer() {
    //disp.move(2050, 800);
    //dispz.move(2870,800);
    CImg<unsigned char> visu;
    int factor = 10, x = 0, y = 0;
    int x0, y0, x1, y1;
    bool grid = false, redraw = false, freeze = false, click = false;
    while (!disp.is_closed() && !dispz.is_closed() &&
           !disp.is_keyQ() && !dispz.is_keyQ() && !disp.is_keyESC() && !dispz.is_keyESC()) {
        if (disp.mouse_x()>=0) { x = disp.mouse_x(); y = disp.mouse_y(); redraw = true; }
        if (redraw) {
            x0 = x - factor, y0 = y - factor, x1 = x + factor, y1 = y + factor;
            const unsigned char red[] = {255, 0, 0}, black[] = {0, 0, 0}, white[] = {255, 255, 255};
            (+img).draw_rectangle(x0, y0, x1, y1, red, 1.0f, ~0U).display(disp);
            if (!freeze) {
                //cout << "freeze is false" << endl;
                x = disp.mouse_x();
                y = disp.mouse_y();
                visu = img.get_crop(x0, y0, x1, y1).draw_point(x - x0, y - y0, black, 0.2f).resize(dispz);
            } else {
                //cout << "freeze is true" << endl;
                const int t = x;
                const int z = y;
                x0 = t - factor, y0 = z - factor, x1 = t + factor, y1 = z + factor;
                visu = img.get_crop(x0, y0, x1, y1).draw_point(t - x0, z - y0, black).resize(dispz);
            }
            while (click) {
                //cout << "click is true" << endl;
                if (disp.button()) {
                    click = false;
                    freeze = !freeze;
                    //cout << "click is false" << endl;
                    disp.set_button();
                } else {
                    //cout << "waiting" << endl;
                    disp.wait(100);
                    if (dispz.button()) {
                        x = dispz.mouse_x();
                        y = dispz.mouse_y();
                        computePixel(x, y);
                        const unsigned char green[] = {0, 255, 0};
                        if(dispz.is_keyA() || disp.is_keyA()) {
                            const unsigned color[] = {green[0], green[1], green[2]};
                            visu.draw_rectangle(x, y, x + 20, y + 20, color, 1).display(dispz);
                            img.draw_point(x0 + (x / 25) - 20, y0 + (y / 25) - 20, color).display(disp);
                        }
                        if (dispz.is_keyB() || disp.is_keyB()){
                            visu.draw_rectangle(x, y, x + 20, y + 20, red, 1).display(dispz);
                            img.draw_point(x0 + (x / 25) - 20, y0 + (y / 25) - 20, red).display(disp);
                        }
                        if (dispz.is_keyC() || disp.is_keyC()){
                            const unsigned color[] = {green[0], green[2], green[1]};
                            visu.draw_rectangle(x, y, x + 20, y + 20, color, 1).display(dispz);
                            img.draw_point(x0 + (x / 25) - 20, y0 + (y / 25) - 20, red).display(disp);
                        }
                        if (dispz.is_keyD() || disp.is_keyD()){
                            const unsigned color[] = {green[0], green[1], green[1]};
                            visu.draw_rectangle(x, y, x + 20, y + 20, color, 1).display(dispz);
                            img.draw_point(x0 + (x / 25) - 20, y0 + (y / 25) - 20, red).display(disp);
                        }
                        if (dispz.is_keyE() || disp.is_keyE()){
                            const unsigned color[] = {green[1], green[1], green[0]};
                            visu.draw_rectangle(x, y, x + 20, y + 20, color, 1).display(dispz);
                            img.draw_point(x0 + (x / 25) - 20, y0 + (y / 25) - 20, red).display(disp);
                        }
                    }
                }
            }

            if (disp.button()) {
                click = true;
                freeze = !freeze;
                disp.set_button();
                dispz.set_button();
                //redraw = true;
            }
        }
        if (disp.is_resized()) disp.resize(disp);
        if (dispz.is_resized()) { dispz.resize(); redraw = true; }
        //dispz.wait();
        CImgDisplay::wait(disp,dispz);
    }
    return 0;
}

void Function::computePixel(int& x, int& y) {
    x = (x/25)*25;
    y = (y/25)*25;
}

void Function::changeColor(unsigned char*& color){
    if(dispz.is_keyA()) {
        color[0] = 0;
        color[1] = 100;
        color[2] = 0;
    }
}

void Function::createImage(ifstream& file, bool trans, int pix, bool ismain){
    pixSize = pix;
    int x = 0;
    int y = 0;
    char buff[1000];
    string actions[1] = {"cout"};
    char datatype[2] = {'\"', '\''};
    bool progStart = false;
    while (file.getline(buff, 1000)){
        if(buff[0] != '#') {
            char *pch;
            pch = strtok(buff, "\t<({})");
            string ip = "int main";
            while (pch != NULL) {
                if(!ismain)
                    progStart = true;
                if (pch == ip && progStart == false && ismain == true) {
                    progStart = true;
                    pch = strtok(NULL, "\t({})");
                    break;
                }
                if (progStart) {
                    if (pch == actions[0]) {
                        string t = "print";
                        Action a(t);

                        maxX = x + (pixSize * 3);
                        maxY = y + (pixSize * 3);
                        int **fr = a.getForm();
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 3; j++) {
                                if (fr[i][j] == 1) {
                                    int tx = x / 20;
                                    //currImg[tx].push_back(a.getColor());
                                    img.draw_rectangle(x, y, x + pixSize, y + pixSize, a.getColor().getColor(),
                                                       1).display(disp);
                                    if (trans)
                                        translate(x, y, a.getColor());
                                }
                                x += pixSize;
                            }
                            x = 0;
                            y += pixSize;
                        }
                        if (x != disp.width()) {
                            y = 0;
                            x = maxX;
                        } else
                            x = 0;

                    }
                    else {
                        string s;
                        for (int i = 0; i < strlen(pch); i++) {
                            if (pch[i] != '\"')
                                s += pch[i];
                        }
                        String str(s);
                        vector<Color> colors = str.getColors();
                        maxX = x + (str.size() * pixSize);
                        maxY = y + pixSize;
                        if (maxX > disp.width()) {
                            x = 0;
                            y += pixSize;
                        }
                        for (int i = 0; i < str.size(); i++) {
                            //currImg[tx].push_back(colors[i]);
                            img.draw_rectangle(x, y, x + pixSize, y + pixSize, colors[i].getColor(), 1).display(disp);
                            if (trans)
                                translate(x, y, colors[i]);
                            x += pixSize;
                        }

                    }
                }
                pch = strtok(NULL, "\t<({})");
            }
        }
    }
    while (!disp.is_closed()  && !disp.is_keyQ()  && !disp.is_keyESC() ) {
        CImgDisplay::wait(disp);
    }
}

void Function::translate(int x, int y, Color& c){
    int currX = x;
    int currY = y;
    for(int j = 0; j< 3; j++) {
        for (int i = 0; i < 6; i++) {
//            int n1 = rand()%5;
//            int n2 = rand()%5;
            int n1 = 3;
            int n2 = 2;
            x += n1 * pixSize;
            y += n2 * pixSize;
            img.draw_rectangle(x, y, x + pixSize, y + pixSize, c.getColor(), 1).display(disp);
        }
        x = currX ;
        currX = x;
    }


};

