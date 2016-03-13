/*
ID: guangli1
PROG: concom
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
#define NN 101
int share[NN][NN];
int N = 0; 
vector<int> controls(int start){
    int cont[NN] = {0};
    int shr[NN] = {0};
    vector<int> res;
    queue<int> Q;
    Q.push(start);
    cont[start] = 1;
    while(!Q.empty()){
        int times = Q.size();
        while(times--){
            int c = Q.front();
            Q.pop();
            for(int i = 1; i <= N; i++){
               shr[i] += share[c][i]; 
               if(cont[i] == 0 && shr[i] > 50){
                    cont[i] = 1;
                    Q.push(i);
                    res.push_back(i);
                }
            } 
        }
    }
    return res;
}
// complexity |V| *|E| if graph is stored using linked list
//            |V| * |V| * |V| if it is stored using array
// above is brute-force method
int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    int n;
    fin >> n;
    while(n--){
        int i, j, s;
        fin >> i >> j >> s;
        share[i][j] = s;
        N= max(N, max(i, j));
    }
    vector<pair<int, int> > res;
    for(int i = 1; i <= N; ++i){
        auto l = controls(i);
        for(auto j : l)
            res.push_back(make_pair(i, j));
    }
    sort(res.begin(), res.end());
    for(auto p : res)
        fout << p.first << " " << p.second << endl;
    fin.close();
    fout.close();
    return 0;
}
