/*
ID: guangli1
PROG: milk3
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
const int N = 21;
vector<int> T;
vector<int> v;
set<int> res;
int state[N][N][N] = { 0 };
void search(vector<int> v){
    if(state[v[0]][v[1]][v[2]] == 0){
        if(v[0] == 0) 
            res.insert(v[2]);
        state[v[0]][v[1]][v[2]] = 1;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                if(i == j) continue;
                auto u = v;
                int milk = min(u[i], T[j] - u[j]);
                u[i] -= milk;
                u[j] += milk;
                search(u);
            }
    }
}
        
int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    T.resize(3);
    v.resize(3);
    fin >> T[0] >> T[1] >> T[2];
    v[0] = v[1] = 0;
    v[2] = T[2];
    search(v);
    auto it = res.begin();
    fout << *it;
    while(++it != res.end())
        fout << " " << *it;
    fout << endl;
    return 0;
}
