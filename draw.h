#include <iostream>
#include <fstream>
#include <conio.h>
#include <regex>
#include <string>
#include <vector>
#include <vector>
using namespace std;

vector<string> drawX(vector<int> posx, int siz, vector<string> asn){    
    vector<string> vc;

    for (int i = 0;i<siz;i++){
        int masi = i;
        int rus = 1;
        for (int i = 0;i<posx.size();i++){
            if (posx[i] == masi){
                vc.push_back(asn[i]);
                rus = 0;
                break;
            }
        }
        if(rus){
            vc.push_back(" ");

        }
        if (i == 0){
            vc.push_back("#");

        }else if (i == siz-1){

            vc.push_back("#");
            break;

        }


    }


    return vc;


}
void runDraw(vector<int> posx, vector<int> posy, int siz, vector<string> asn,int ya){
    
    if (posy.size() != posx.size()){
        cout << "posy and posx not same size";
        return;
    }

    int xya = 1;
    while (xya < ya){
        vector<int> f1;
        vector<string> f2;

    for (int i = 0;i<posx.size();i++){

        if (posy[i] == xya){

            f1.push_back( posx[i]);
            f2.push_back( asn[i]);
            
           
            //cout << i1 << " " << po 

        }
        

    }
    vector<string> drewy1 = drawX(f1,siz,f2);

    for (int i = 0;i<drewy1.size();i++){

    cout << drewy1[i];
    
    }
    cout << "\n";
    xya++;
    }
    //cout << "\ncomp" << y3x[1] << y2x[1] << y1x[1];

 


}

