//
// Created by Kylie Jordan on 10/23/22.
//

#ifndef PROJECT_ACTION_H
#define PROJECT_ACTION_H

#include <iostream>
#include "Color.h"

using namespace std;

class Action{
private:
    string type;
    Color color = Color();
    int** form;
public:
    Action(){};
    Action(string& s){
        type = s;
        form = new int*[3];
        for(int i = 0; i< 3; i++){
            form[i]= new int[3];
            for(int j = 0; j< 3; j++)
                form[i][j] = 0;
        }
        setColor();
        setForm();
    };
    void setColor(){
        if(type == "print"){
            color.setColor(0, 255, 0);
        }
    };
    void setForm(){
        if(type == "print"){
            form[0][0] = 1;
            form[0][1] = 1;
            form[1][1] = 1;
            form[0][2] = 1;
        }
    };
    Color& getColor(){return color;};
    int** getForm()
    {
        return form;
    };

};

#endif //PROJECT_ACTION_H
