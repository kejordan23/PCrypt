
#include <string>
#include <iostream>
#include <ctype.h>
#include <fstream>
#include <vector>
#include "Function.h"
#include "Char.h"
#include "String.h"
#include "Action.h"
using namespace std;

int w = 0;
int h = 0;
int p = 0;
char wi[50];
char he[50];
char pix[50];
char name[50];
char path[100];

int main(int argc, char* argv[])
{
    char choice;
    int end = false;
    cout<<"\t\t\tWelcome to PCrypt"<<endl;

    while(!end) {
        cout << "Options:" << endl;
        cout << "\t(1)\tData translator" << endl;
        cout << "\t(2)\tPixel translator" << endl;
        cout << "\t(3)\tPixelate" << endl;
        cout << "\nPress q/Q to quit" << endl;

        cout << ">> ";
        cin >> choice;

        if (choice == '1') {
            bool home = false;
            while(!home) {
                cout << "<*Data translator*>" << endl;
                cout << "Enter final image width\n*> ";
                cin >> wi;
                cout << "Enter final image height\n*> ";
                cin >> he;
                cout << "Enter final pixel size\n*> ";
                cin >> pix;
                cout << "Enter final image title\n*> ";
                cin >> name;
                cout << "Enter absolute path to data\n*> ";
                cin >> path;
                bool wdigits = true;
                bool hdigits = true;
                bool pdigits = true;
                bool ismain = false;
                string temp = path;
                if(temp.substr(temp.size()-4) == ".cpp")
                    ismain = true;
                for (int i = 0; i < strlen(wi); i++) {
                    if (!isdigit(wi[i]))
                        wdigits = false;
                }
                for (int i = 0; i < strlen(he); i++) {
                    if (!isdigit(he[i]))
                        hdigits = false;
                }
                for (int i = 0; i < strlen(pix); i++) {
                    if (!isdigit(pix[i]))
                        pdigits = false;
                }
                if (wdigits && hdigits && pdigits) {
                    w = atoi(wi);
                    h = atoi(he);
                    p = atoi(pix);
                    Function f(w, h, name);
                    ifstream fr;
                    fr.open(path);
                    if (!fr.is_open())
                        cout << "Error opening file" << endl;
                    else {
                        if(ismain)
                            f.createImage(fr, true, p, true);
                        else
                            f.createImage(fr, false, p, false);
                    }
                }
                char c;
                cout << "Would you like to translate more data?(y/n)\n*> ";
                cin >> c;
                if (c == 'n')
                    home = true;
            }
        } else if (choice == '2') {
            cout << "2" << endl;
        } else if (choice == '3') {
            Function f;
            bool home = false;
            f.item_image_zoomer();
        } else if (choice == 'q' || choice == 'Q') {
            end = true;
            break;
        } else {
            cout << "Please type a valid option\n" << endl;
        }
    }


//    string h = "(153, 0, 51)";
//    string e = "(153, 0, 0)";
//    string l = "(51, 51, 0)";
//    string o = "(0, 102, 0)";
//    vector<string> p = vector<string>();
//    p.push_back(h);
//    p.push_back(e);
//    p.push_back(l);
//    p.push_back(l);
//    p.push_back(o);
//    String c(p);
//
//    cout<<c<<endl;
//
    //f.drawPixels();
    //f.item_image_zoomer();
//    string s = "print";
//    Action a(s);
//    Color c = a.getColor();
//    c.print();
//    int** fr = a.getForm();
//    for(int i = 0; i< 3; i++){
//        for(int j = 0; j< 3; j++)
//            cout<<fr[i][j]<<" ";
//        cout<<endl;
//    }

    ifstream fr;
    fr.open("/Users/kyliejordan/Desktop/Test/apollo.agc");
    //f.createImage(fr, false, 15, false);


    return 0;
}


