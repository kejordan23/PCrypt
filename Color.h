//
// Created by Kylie Jordan on 10/23/22.
//

#ifndef PROJECT_COLOR_H
#define PROJECT_COLOR_H

using namespace std;

class Color{
private:
    int red = 0;
    int green = 0;
    int blue = 0;
    unsigned int* color = new unsigned int[3];
public:
    Color(){};
    Color(int r, int g, int b)
    {
        red = r; green = g; blue = b;
        color[0] = red;
        color[1] = green;
        color[2] = blue;
    };
    unsigned int* getColor(){ return color;};
    void setColor(int r, int g, int b){
        red = r; green = g; blue = b;
        color[0] = red;
        color[1] = green;
        color[2] = blue;
    }
    Color& operator=(Color& c){
        red = c.red; green = c.green; blue = c.blue;
        color[0] = c.red;
        color[1] = c.green;
        color[2] = c.blue;
    }
    void print(){
        cout<<"{"<<red<<", "<<green<<", "<<blue<<"}"<<endl;
    }
};

#endif //PROJECT_COLOR_H
