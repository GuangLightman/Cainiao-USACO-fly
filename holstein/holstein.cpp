/*
ID: guangli1
PROG: holstein
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
int V, G;
int req[25];
int vit[15][25];
int ans = ~(1<<31);
void del(int level){
    for(int i = 0; i < V; i++)
        req[i] -= vit[level][i];
}
void add(int level){
    for(int i = 0; i < V; i++)
        req[i] += vit[level][i];
}
bool check(){
    for(int i = 0; i < V; i++)
        if(req[i] > 0) 
            return false;
    return true;
} 
int mType(int n){
    int k = 1;
    while(!(n&1) && n){
        n >>= 1;
        ++k;
    }
    return k;
}
#define kinds(n) (n>>G)
void dfs(int level, int cmb, int * req){
    if(check()){    
        if(kinds(cmb) < kinds(ans))
            ans = cmb;
        else if( kinds(cmb) == kinds(ans) && mType(cmb) < mType(ans))
            ans = cmb;
    }
 
    if(level == G) 
        return;
    //try no 
    dfs(level+1, cmb, req);
    //try add vit means del
    del(level);
    cmb |= 1<<level;
    cmb = (1<<G) + cmb;
    dfs(level+1, cmb, req);
    add(level); 
}     
int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    fin >> V;
    for(int i = 0; i < V; i++)
        fin >> req[i];
    fin >> G;
    for(int i = 0; i < G; i++)
        for(int j = 0; j < V; j++)
            fin >> vit[i][j]; 
    dfs(0, 0, req);
    int k = ans>>G;
    fout << k;
    for(int i = 0; i < G; i++)
        if((ans>>i)&1)
            fout << " " << i+1;
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}
