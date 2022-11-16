//
// Created by Kylie Jordan on 10/3/22.
//

#ifndef PROJECT_CHAR_H
#define PROJECT_CHAR_H

#include <iostream>
#include <string>
#include <fstream>
#include "Color.h"

using namespace std;

class Char{
private:
    char c;
    Color color;
public:
    Char(){};
    Char(char& str){
        c = str;
        if (str == 'A')
            color.setColor(102, 51, 0);
        else if (str == 'B')
            color.setColor(0, 51, 102);
        else if (str == 'C')
            color.setColor(0, 0, 102);
        else if (str == 'D')
            color.setColor(40, 40, 60);
        else if (str == 'E')
            color.setColor(200, 5, 10);
        else if (str == 'F')
            color.setColor(255, 0, 0);
        else if (str == 'G')
            color.setColor(153, 153, 102);
        else if (str == 'H')
            color.setColor(102, 51, 0);
        else if (str == 'I')
            color.setColor(200, 200, 100);
        else if (str == 'J')
            color.setColor(102, 0, 51);
        else if (str == 'K')
            color.setColor(55, 45, 100);
        else if (str == 'L')
            color.setColor(60, 80, 92);
        else if (str == 'M')
            color.setColor(220, 50, 0);
        else if (str == 'N')
            color.setColor(4, 6, 20);
        else if (str == 'O')
            color.setColor(100, 7, 0);
        else if (str == 'P')
            color.setColor(60, 80, 90);
        else if (str == 'Q')
            color.setColor(70, 100, 30);
        else if (str == 'R')
            color.setColor(50, 200, 100);
        else if (str == 'S')
            color.setColor(90, 30, 4);
        else if (str == 'T')
            color.setColor(10, 20, 30);
        else if (str == 'U')
            color.setColor(60, 33, 40);
        else if (str == 'V')
            color.setColor(200, 100, 100);
        else if (str == 'W')
            color.setColor(20, 10, 40);
        else if (str == 'X')
            color.setColor(50, 22, 44);
        else if (str =='Y')
            color.setColor(70, 10, 60);
        else if (str == 'Z')
            color.setColor(8, 150, 0);

    };
    Char(string& str){
        //color = str;
        if (str == "(102, 51, 0)")
            c = 'A';
        else if (str == "(153, 102, 0)")
            c = 'B';
        else if (str == "(204, 51, 0)")
            c = 'C';
        else if (str == "(153, 51, 0)")
            c = 'D';
        else if (str == "(153, 0, 0)")
            c = 'E';
        else if (str == "(128, 0, 0)")
            c = 'F';
        else if (str == "(153, 51, 51)")
            c = 'G';
        else if (str == "(153, 0, 51)")
            c = 'H';
        else if (str == "(102, 0, 51)")
            c = 'I';
        else if (str == "(153, 51, 102)")
            c = 'J';
        else if (str == "(153, 0, 153)")
            c = 'K';
        else if (str == "(51, 51, 0)")
            c = 'L';
        else if (str == "(51, 102, 0)")
            c = 'M';
        else if (str == "(0, 51, 0)")
            c = 'N';
        else if (str == "(0, 102, 0)")
            c = 'O';
        else if (str == "(51, 153, 51)")
            c = 'P';
        else if (str == "(102, 153, 153)")
            c = 'Q';
        else if (str == "(0, 102, 102)")
            c = 'R';
        else if (str == "(0, 51, 102)")
            c = 'S';
        else if (str == "(51, 102, 153)")
            c = 'T';
        else if (str == "(51, 102, 204)")
            c = 'U';
        else if (str == "(0, 0, 255)")
            c = 'V';
        else if (str == "(0, 255, 0)")
            c = 'W';
        else if (str == "(255, 0, 255)")
            c = 'X';
        else if (str =="(255, 255, 0)")
            c = 'Y';
        else if (str == "(255, 0, 0)")
            c = 'Z';

    };
    Color& getColor(){ return color;};
    char& getChar(){return c;};
    friend std::ostream& operator<<(std::ostream& os, const Char& ch){
        return os<<ch.c;
    };
};

#endif //PROJECT_CHAR_H
