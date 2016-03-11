/*
ID: guangli1
PROG: subset
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
#include <cstring>
using namespace std;
int dp[40][40*40];
int f(int N, int diff){
    if(dp[N][diff] != -1) return dp[N][diff];
    if(N == 1 && diff == 1)
        return dp[N][diff] = 1;
    if(N >= 2)   
        if(N*(N+1)/2 < diff)
            return dp[N][diff] = 0;
        if(diff != 0)
            return dp[N][diff] = f(N-1, N+diff) + f(N-1, abs(N-diff)) * (N-diff == 0?2:1);
        else if(diff == 0)
            // can add another observation when sum(1:N) is odd, there is no way to divide
            return f(N-1, N);
    return dp[N][diff] = 0;
}
    
int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    memset(dp, -1, 40*40*40*sizeof(int));
    int T;
    fin >> T;
    fout << f(T, 0) << endl;
    fin.close();
    fout.close();
    return 0;
}
