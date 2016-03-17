/*
ID: guangli1
PROG: ttwo
LANG: C++11  
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#define LL unsigned long long
using namespace std;
const int N = 10;
char B[N][N];
int fx, fy, cx, cy;
int df = 0, dc = 0;// 0 north 1 east 2-> south 3->west
void intial(ifstream& fin){
    for(int i = 0; i < 10; i++){
        fin >> B[i];
        for(int j = 0; j < 10; j++){
            if(B[i][j] == 'F'){
                fx = i;
                fy = j;
                B[i][j] = '.';
            }
            if(B[i][j] == 'C'){
                cx = i;
                cy = j;
                B[i][j] = '.';
            }
        }
    }
}
void update(int& x, int& y, int& dir){
    switch(dir){
        case 0:
            if(x-1<0 || B[x-1][y] == '*')
                dir = 1;
            else
                --x;
            break;
        case 1:
            if(y+1 >= N || B[x][y+1] == '*')
                dir = 2;
            else
                ++y;
            break;
        case 2:
            if(x+1 >= 10 || B[x+1][y] == '*')
                dir = 3;
            else
                ++x;
            break;
        case 3:
            if(y-1<0 || B[x][y-1] == '*')
                dir = 0;
            else
                --y;
            break;
        default:
            break;

    }
}
set<pair<pair<int, int>, int> > farmPath, cowPath;
bool farmLoop = false;
bool cowLoop = false;
int run(){
    int t = 0;
    while(fx != cx || fy != cy){
    printf("%d %d %d %d %d %d \n", fx, fy, df, cx, cy, dc);
        pair<pair<int, int>, int> f =\
                make_pair(make_pair(fx, fy), df); 
        pair<pair<int, int>, int> c =\
                make_pair(make_pair(cx, cy), dc); 
        if((farmLoop && farmPath.find(c) != farmPath.end()) || \
           (cowLoop && cowPath.find(f) != cowPath.end()) || t > 10000\
           )
            return 0;

        auto rs_f = farmPath.insert(f);
        auto rs_c = cowPath.insert(c);
        if(rs_f.second == false){ farmLoop = true;}
        if(rs_c.second == false){ cowLoop = true;}
    
        update(fx, fy, df);
        update(cx, cy, dc);
        ++t;
    } 
    return t;
}
int main(){
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    intial(fin);
    //printf("%d %d %d %d \n", fx, fy, cx, cy);
    //printf("%d %d %d %d \n", fx, fy, cx, cy);
    //fout << run() << endl;
    // this is soooooo tricky!
    int t = 0;
    while(fx != cx || fy != cy ){
        update(fx, fy, df);
        update(cx, cy, dc);
        ++t;
        if(t > 160000){ t = 0; break;} 
    } 
    fout << t << endl;
    fin.close();
    fout.close();
    return 0;
}
