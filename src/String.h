//
// Created by Kylie Jordan on 10/3/22.
//

#ifndef PROJECT_STRING_H
#define PROJECT_STRING_H

#include "Char.h"
#include <vector>

using namespace std;

class String{
private:
    string str;
    vector<Color> colors;
public:
    String(){};
    String(string& c){
        str = c;
        for(int i = 0; i< c.size(); i++){
            char temp = toupper(c[i]);
            Char ch(temp);
            colors.push_back(ch.getColor());
        }
    }
    String(vector<string>& c){
        for(int i = 0; i< c.size(); i++) {
            //colors.push_back(c[i]);
            Char ch(c[i]);
            str += ch.getChar();
        }
    };
    vector<Color>& getColors(){return colors;};
    int size(){ return str.size();};
    friend std::ostream& operator<<(std::ostream& os, const String& str){
        return os<<str.str;
    };
};

#endif //PROJECT_STRING_H
