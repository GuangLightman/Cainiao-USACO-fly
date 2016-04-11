/*
ID: guangli1
PROG: kimbits
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
#define inf 
#define INF (~(1<<31))
using namespace std;
int N, L;
long long I;
const int C = 32;
long long G[C][C];
void init(){
    for(int i = 0; i < C; i++)
        for(int j = 0; j < C; j++)
            G[i][j] = -1;

}
long long  g(int n, int l){
    if(n <= 0) return 0;
    if(l < 0) return 0;
    if(l == 0) return 1;
    l = min(l, n);
    if(n == 1){
        if(l == 1) 
            return 2;
        else
            return 1;
    }
    if(G[n][l] != -1)
        return G[n][l];
    return G[n][l] = g(n-1, l) + g(n-1, l-1); 
}
long long f(int n, int l, long long i){
    if(n == 1){
        if(l == 0 || i == 1)
            return 0;
        return 1;
    }
    if( i <=  g(n-1, l))
        return f(n-1, l, i); 
    else
        return (1<<(n-1)) + f(n-1, l-1, i-g(n-1, l));
}
string convert(int n){
    string s;
    while(n){
        s.push_back((char)('0'+(n&1)));
        n >>= 1; 
    }
    reverse(s.begin(), s.end());
    return string(N-s.size(), '0') + s;
}
int main() {
    freopen("kimbits.out", "w", stdout);
    freopen("kimbits.in", "r", stdin);
    init();
    cin >> N >> L >> I;
    cout << convert(f(N, L, I)) << endl;
    return 0;
}
