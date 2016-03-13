/*
ID: guangli1
PROG: money
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
#define LL unsigned long long
using namespace std;
const int VV = 25;
const int NN = 10000;
int V, N, visit[VV+1][NN+1];
LL table[VV+1][NN+1];
int money[VV+1]; 
LL dp(int v, int n){
    if(visit[v][n]) return table[v][n];
    if(v == 1){
        visit[v][n] = 1;
        if(n%money[v] == 0)
            table[v][n] = 1;
        return table[v][n];
    }
    LL kind = 0;
    for(int i = 0; i <= n/money[v]; ++i)
        kind += dp(v-1, n - money[v]*i);
    visit[v][n] = 1;
    return table[v][n] = kind;
}
// observe that table[v][n] fully relies on table[v-1] row
// so it is possible to write that
// dp[n] denotes possible ways of combination up to m1, ,,, mi comes
// routie would be update dp[a] dp[a+1] up to dp[n]
int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    fin >> V >> N;
    set<int> m;
    for(int i = 1; i <= V; i++){
        int num;
        fin >> num;
        m.insert(num);
    }
    int kinds = 0;
    auto it = m.begin();
    while(it != m.end()){
        kinds++;
        money[kinds] = *it;
        it++;
    }
    fout << dp(kinds, N) << endl;
    fin.close();
    fout.close();
    return 0;
}
