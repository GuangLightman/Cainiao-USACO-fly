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
int V, N;
LL dp[NN+1];
// observe that table[v][n] fully relies on table[v-1] row
// so it is possible to write that
// dp[n] denotes possible ways of combination up to m1, ,,, mi comes
// routie would be update dp[a] dp[a+1] up to dp[n]
int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    fin >> V >> N;
    dp[0] = 1;
    for(int i = 1; i <= V; i++){
        int num;
        fin >> num;// assume all input are distinct
        for(int j = num; j <= N; j++)
            dp[j] += dp[j-num];
    }
    fout << dp[N] << endl;
    fin.close();
    fout.close();
    return 0;
}
