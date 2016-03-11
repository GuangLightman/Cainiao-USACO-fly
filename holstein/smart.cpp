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
int cmb[25] = {0};
int ans[25] = {0};
int ansMin = 0x3f3f3f3f;
int curMin = 0x3f3f3f3f;
int curKinds = 0;
int ansKinds = 0x3f3f3f3f;
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
void replace(){
    ansKinds = curKinds;
    ansMin = curMin;
    for(int i = 0; i < G; i++){
        ans[i] = cmb[i];
    }
}    
void dfs(int level){
    if(check()){    
        if(curKinds < ansKinds ||\
           (curKinds == ansKinds && curMin < ansMin)){
            replace();
            return;
        } 
    }
    if(level == G) 
        return;
    //try no 
    dfs(level+1);
    //try add vit means del
    del(level);
    cmb[level] = 1;
    int tmpMin = curMin;
    curKinds++;
    curMin = min(curMin, level);
    dfs(level+1);
    add(level); 
    cmb[level] = 0;
    --curKinds;
    curMin = tmpMin;
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
    dfs(0);
    fout << ansKinds;
    for(int i = 0; i < G; i++)
        if(ans[i])
            fout << " " << i+1;
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}
