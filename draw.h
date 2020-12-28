#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>
#include <conio.h>


using namespace std;

vector<int> SOR;
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
            vc.push_back("");

        }else if (i == siz-1){

            vc.push_back("");
            break;

        }
           // cout  << SOR[i];



    }


    return vc;


}
void runDraw(vector<int> posx, vector<int> posy, int siz, vector<string> asn,int ya){
    
    if (posy.size() != posx.size()){
        cout << "posy and posx not same size";
        return;
    }

    int xya = 1;
    while (xya < ya+1){
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

void clearScreen(){
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}


vector<int> GetXYDmap(string f, int t,int debug){
SOR = {};
//SAUSAGE
  ifstream myl;
  vector<string> vesc;
    myl.open(f);
    string memn , nen;
    myl.seekg (0, ios::beg);
    int ypos = 0;

    vector<int> xxpos;
    vector<int> yypos;
    vector<string> CC;


    while (!myl.eof()){

    std::getline(myl,memn);
    for (int s = 0; s<memn.size();s++){
        if (memn[s] != ' '){
        SOR.push_back(0);

            xxpos.push_back(s);
            yypos.push_back(ypos);
            string xf(1,memn[s]);
            CC.push_back(xf);

        }
    }

    vesc.push_back(memn);
        ypos += 1;


    }
    if(debug == 1){
       cout << '{';

    for (int o = 0; o<CC.size(); o++){
        cout << '"' <<CC[o] << '"' << ',';
    //cout << CC[o] << " "<< yypos[o] << " " << xxpos[o] << "\n";
    }
        cout << '}' << ";\n";
// ################################################################################## DEVIDER
    cout << '{';

        for (int o = 0; o<CC.size(); o++){
            cout <<yypos[o] << ',';
        //cout << CC[o] << " "<< yypos[o] << " " << xxpos[o] << "\n";
        }
    cout << '}' << ";\n";

// ################################################################################## DEVIDER
    cout << '{';

        for (int o = 0; o<CC.size(); o++){
            cout  <<xxpos[o]  << ',';
        //cout << CC[o] << " "<< yypos[o] << " " << xxpos[o] << "\n";
        }
    cout << '}' << ";\n";


    while (1){
        if(kbhit()) break;
        }
    }
 
    if (t == 0){
        return xxpos;

    }else{
        return yypos;

    }
}
vector<string> GetCDmap(string f){

  ifstream myl;
  vector<string> vesc;
    myl.open(f);
    string memn , nen;
    myl.seekg (0, ios::beg);
    int ypos = 0;

    vector<int> xxpos;
    vector<int> yypos;
    vector<string> CC;


    while (!myl.eof()){

    std::getline(myl,memn);
    for (int s = 0; s<memn.size();s++){
        if (memn[s] != ' '){
            xxpos.push_back(s);
            yypos.push_back(ypos);
            string xf(1,memn[s]);
            CC.push_back(xf);

        }
    }

    vesc.push_back(memn);
        ypos += 1;


    }

       


    
 
    
        return CC;

    
}

int CollisionMulti(vector<string> f, vector<int> rx, vector<int> ry, string p1, string p2){

    int p1x;
    int p1y;

    for (int x = 0; x<f.size(); x++){
        if (f[x] == p1){

            p1x = rx[x];
            p1y = ry[x];
            break;



        }
    }
    for (int x = 0; x<f.size(); x++){
        if (f[x] == p2){
        if(rx[x] == p1x){
            if(ry[x] == p1y){
                
                return 1;
                    
                }
        }
        }
    }
    return 0;

}
int findPos(vector<string> f,string o){
    for (int x = 0; x<f.size(); x++){
        if (f[x] == o){

            return x;
            



        }
    }
    return 0;
}

void loadSprite(vector<string> &f, vector<int>& x, vector<int> &y,string sn,int xs,int ys,int id,int rp){
    if (id != 0){
    for (int p = 0; p<rp; p++){
    for (int i = 0; i<f.size(); i++){
        if(SOR[i] == id){
           // cout << "ok";
            f.erase(f.begin()+i);
            x.erase(x.begin()+i);

            y.erase(y.begin()+i);

            SOR.erase(SOR.begin()+i);



        }
            //cout  << SOR[i] << " " << id << " ";

    }
    }
    }
    


    ifstream myl;
    vector<string> vesc;
    myl.open(sn);
    string memn , nen;
    myl.seekg (0, ios::beg);
    int ypos = ys;

    vector<int> xxpos = x;
    vector<int> yypos = y;
    vector<string> CC = f;


    while (!myl.eof()){

    std::getline(myl,memn);
    for (int s = 0; s<memn.size();s++){
        if (memn[s] != ' '){
        SOR.push_back(1);
        //cout<< SOR[s] << " ";


            xxpos.push_back(s + xs);
            yypos.push_back(ypos);
            string xf(1,memn[s]);
            CC.push_back(xf);

        }
    }
    vesc.push_back(memn);
        ypos += 1;


    
    }
    f = CC;
    y = yypos;
    x = xxpos; 


     /*cout << '{';

        for (int o = 0; o<f.size(); o++){
            cout  <<f[o]  << ',';
        //cout << CC[o] << " "<< yypos[o] << " " << xxpos[o] << "\n";
        }
    cout << '}' << ";\n";*/
    


}



