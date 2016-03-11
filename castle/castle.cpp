/*
ID: guangli1
PROG: castle
LANG: C++11  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
const int West = 0b1;
const int North = 0b10;
const int East = 0b100;
const int South = 0b1000;
const int n = 50;
int label[n*n] = {0};
int node[n*n];
int M, N;
int house = 0;
int maxArea = 0, area;
int A[n*n] = {0};
void try_label(int i){
    if(label[i]) return;
    label[i] = house;
    ++area;
    int y = i%M;
    int x = i/M;
    int wall = node[i];
    if(!(wall&West) && y > 0)
        try_label(M*x + y-1);
    if(!(wall&North) && x > 0)
        try_label(M*(x-1) + y);
    if((!(wall&East)) && y < M - 1)
        try_label(M*x + y+1);
    if(!(wall&South) && x < N-1)
        try_label(M*(x+1) + y);
}
void dfs(){
    for(int i = 0; i < M*N; i++){
        if(label[i] != 0)
            continue;
        ++house;
        area = 0;
        try_label(i);
        A[house] = area;
        maxArea = max(maxArea, area);
    }
}
int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin >> M >> N;
    for(int i = 0; i < M*N; i++)
        fin >> node[i];
    // label M*N each node to house
    dfs();
    // number of house && area of biggest house
    // try remove walls
    //try_remove()
        // i from 0 to M-1 then j from N-1 to 0
        // try remove N then E 
    int cur, mX, mY, dir;
    cur = mX = mY = dir = 0;
    for(int y = 0; y < M; ++y)
        for(int x = N-1; x >= 0; --x){
            //try North
            int x1 = x-1, y1 = y;
            int i = x*M+y, i1 = x1*M+y1;
            if(node[i]&North &&\
               x1 >= 0&&\
               label[i1] != label[i]&&\
               A[label[i]] + A[label[i1]] > cur){ 
                mX = x;
                mY = y;
                dir = North;
                cur = A[label[i]] + A[label[i1]];
            }
            x1 = x, y1 = y+1, i = x*M+y, i1 = x1*M+y1;
            if(node[i]&East &&\
               y1 < M &&\
               label[i1] != label[i]&&\
               A[label[i]] + A[label[i1]] > cur){ 
                mX = x;
                mY = y;
                dir = East;
                cur = A[label[i]] + A[label[i1]];
            }
        }
    fout << house << endl;
    fout << maxArea << endl;
    fout << cur << endl;
    char c = dir == East? 'E' : 'N';
    fout << mX+1 << " " << mY+1 << " " << c << endl; 
    fin.close();
    fout.close();
    return 0;
}
