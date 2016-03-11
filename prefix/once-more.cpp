/*
ID: guangli1
PROG: prefix
LANG: C++11  
*/
#include <iostream>
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
using namespace std;
string T;
set<string> dict;
vector<bool> state;
void dfs(int index){
    if(state[index]) return;
    for(int i = 1; i <= 10 && index+i <= T.size(); i++)
        if(dict.find(string(T.begin()+index, T.begin()+index+i)) != dict.end()){
            dfs(index+i);
            state[index+i] = true;
        }
}

void bfs(){
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        if(state[pos]) continue;
        for(int i = 1; i <= 10 && pos+i <= T.size(); i++)
            if(dict.find(string(T.begin()+pos, T.begin()+pos+i)) != dict.end()){
                  Q.push(pos+i);
            }
        state[pos] = true;
    }
}
       
        
int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    while(T != string(".")){
        fin >> T;
        dict.insert(T);
    }
    string tmp; T = tmp;
    while(fin >> tmp) 
        T += tmp;
    state.assign(T.size()+1, false);
    //dfs(0);
    bfs();
    int index = T.size();
    while(index >= 0 && !state[index]) --index;
    index = index > 0 ? index : 0;
    fout << index << endl;
    fin.close();
    fout.close();
    return 0;
}
