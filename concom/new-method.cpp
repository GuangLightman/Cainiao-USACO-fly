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
// simulate share flow
int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    int n;
    fin >> n;
    queue<pair<int, int> > Q;
    vector<pair<int, int> > res;
    while(n--){
        int i, j, s;
        fin >> i >> j >> s;
        if(i == j) continue;
        share[i][j] = s;
        N = max(N, max(i, j));
        if(s > 50){
            res.push_back(make_pair(i, j));
            Q.push(make_pair(i, j));        
        }
    }
    while(!Q.empty()){
        auto q = Q.front();
        Q.pop();
        int i, j;
        i = q.first, j = q.second;
        for(int k = 1; k <= N; k++){
            if(i != k && share[i][k] <= 50){
                share[i][k] += share[j][k];
                if(share[i][k] > 50){
                    res.push_back(make_pair(i, k));
                    Q.push(make_pair(i, k));
                }
            }
        }
    }
    sort(res.begin(), res.end());
    for(auto p : res)
        fout << p.first << " " << p.second << endl;
    fin.close();
    fout.close();
    return 0;
}
