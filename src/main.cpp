
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
    cout<<"\t\t\tWelcome to PCrypt\n"<<endl;
    cout<<"An esoteric programming language that allows users to encrypt\n"
          "and decrypt data through image processing.\n"
          "\n"
          "In other words...\n"
          "\n"
          "Coding for artists! Users can visualize complicated code\n"
          "as colored pixel patterns. Images both created with PCrypt or not\n"
          "can be translated back to data. There is also an option\n"
          "for users to \"draw\" with pixels to create an encoded image.\n"<<endl;

    while(!end) {
        cout << "Options:" << endl;
        cout << "\t(1)\tData translator" << endl;
        cout << "\t(2)\tPixel translator" << endl;
        cout << "\t(3)\tPixelate" << endl;
        cout << "\nPress q/Q to quit" << endl;

        cout << ">> ";
        cin >> choice;

        ifstream fr;
        if (choice == '1') {
            bool home = false;
            while(!home) {
                bool valid = false;
                cout << "<*Data translator*>" << endl;
                cout << "Enter final image width\n*> ";
                while(!valid) {
                    cin >> wi;
                    if (strlen(wi) > 4)
                        cout << "Please enter a valid image width between 1 and 9000\n*> ";
                    else
                        valid = true;
                }
                valid = false;
                cout << "Enter final image height\n*> ";
                while(!valid) {
                    cin >> he;
                    if (strlen(he) > 3)
                        cout << "Please enter a valid image height between 1 and 900\n*> ";
                    else
                        valid = true;
                }
                valid = false;
                cout << "Enter final pixel size\n*> ";
                while(!valid) {
                    cin >> pix;
                    if (strlen(pix) > 2)
                        cout << "Please enter a valid pixel size between 1 and 90\n*> ";
                    else
                        valid = true;
                }
                valid = false;
                cout << "Enter final image title\n*> ";
                cin >> name;
                cout << "Enter absolute path to data\n*> ";
                while(!valid) {
                    cin >> path;
                    fr.open(path);
                    if (!fr.is_open()) {
                        cout << "Error opening file" << endl;
                        cout << "Enter absolute path to data\n*> ";
                    }
                    else
                        valid = true;
                }
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
                    if(ismain)
                        f.createImage(fr, true, p, true);
                    else
                        f.createImage(fr, false, p, false);

                }
                char a;
                bool v = false;
                cout<<"Would you like to take a screenshot?(y/n)\n*>";
                while(!v) {
                    cin >> a;
                    if(a == 'y'){

                        valid = true;
                    }
                    else if (a == 'n') {
                        //do
                        valid = true;
                    }
                    else{
                        cout<<"Enter a valid choice"<<endl;
                        cout<<"Would you like to take a screenshot?(y/n)\n*>";
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



    ifstream fr;
    fr.open("/Users/kyliejordan/Desktop/Test/apollo.agc");
    //f.createImage(fr, false, 15, false);


    return 0;
}


