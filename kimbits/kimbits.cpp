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
long long int N, L, I;
void cal(long long int i, long long int* cnt, long long int* index){
    *cnt = 0;
    *index = 0;
    while(i){
       if(i&1)
            ++(*cnt);
        i >>= 1; 
        ++(*index);
    }
    if(*index == 0)
        *index = 1;
}
string run(int n, int l, int i){
    if( i <= (1<<l)){
        string s;
        for(int j = n-1; j >= 0; j--)
            s.push_back((i&(1<<j))? '1' : '0');
        return s;
    }
    else if(i-(1<<l) > 0 && i-(1<<l) <= ((1<<l)-1) ){
        string s(n-l-1, '0');
        s.push_back('1');
        return s + run(l, l-1, (i-(1<<l)));
    }
    else{
        return run(
    }
}
int main() {
    freopen("kimbits.out", "w", stdout);
    freopen("kimbits.in", "r", stdin);
    cin >> N >> L >> I;
    cout << run(N, L, I) << endl;
    return 0;
}
