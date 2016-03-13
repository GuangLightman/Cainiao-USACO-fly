/*
ID: guangli1
PROG: nocows
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
// D(n, k) represent no of tree with exact height k and n nodes
// P(n, k)                           at most hegight k and n nodes
// D(n, k) = sum D(i, k-1)*P(n-1-i, k-2) +  over i from 1 to n-1-1
//         + sum D(i, k-1)*D(n-1-i, k-1)         
LL P_table[200+5][100+5];
LL P_visit[200+5][100+5];
LL D_table[200+5][100+5];
LL D_visit[200+5][100+5];
LL P(int n, int k);
LL D(int n, int k){
    if(D_visit[n][k])
        return D_table[n][k];
    if(n == 1){
        if(k == 1) return 1;
        return 0;
    }
    LL cnt = 0;
    for(int i = 1; i <= n-2; i+=2)
       cnt += D(i, k-1)*P(n-1-i, k-2) + P(i, k-2)*D(n-1-i, k-1) + D(i, k-1)*D(n-1-i, k-1);
    D_visit[n][k] = 1;
    return D_table[n][k] = cnt%9901;
}
//P(n, k) = sum P(i, k-1)*P(n-1-i, k-1) over i from 
LL P(int n, int k){
    if(P_visit[n][k])
        return P_table[n][k];
    if(n == 1){
        if(k >= 1) return 1;
        return 0;
    }
    LL cnt = 0;
    for(int i = 1; i <= n-2; i+=2)
       cnt += P(i, k-1)*P(n-1-i, k-1);
    P_visit[n][k] = 1;
    return P_table[n][k] = cnt%9901;
 
} 
int N, K;
int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    fin >> N >> K;
    fout << D(N, K)%9901 << endl;
    fin.close();
    fout.close();
    return 0;
}
