#include <iostream>
#include <fstream>
#include <conio.h>
#include <regex>
#include <string>
#include <vector>
#include <windows.h>
#include "draw.h"

using namespace std;



int main(){
        int o = 4;
        int oy = 4;

    int run = 1;
    while (run){
        
        if (system("CLS"))
            system("clear");
    cout << " ###############################################\n";
    if (kbhit()){
            int key_code = _getch();

         if (key_code == 100)
            {

                o += 1;
            }
            if (key_code == 97)
            {

                o += -1;
            }
            if (key_code == 115)
            {

                oy += +1;
            }
            if (key_code == 119)
            {

                oy -= +1;
            }
    }
    

    vector<int> x = {o,4,1};
    vector<int> y = {oy,3,2};
    vector<string> f = {"@","C","A"};
    
    runDraw(x,y,46,f,7);

    cout << " ###############################################\n";
    Sleep(1);

    }
    /*vector<string> drewy1 = draw(x,46,f);

    for (int i = 0;i<drewy1.size();i++){

    cout << drewy1[i];
    
    }*/
    while (1){
    if(kbhit()) break;
  }
    
    return 0;
}

