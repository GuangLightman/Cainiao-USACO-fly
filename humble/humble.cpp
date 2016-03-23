/*
ID: guangli1
PROG: humble
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
const int N = 105;
const int M = 100005;
int p[N];
int num[M];
int h[N] = {0};
int n, m;
int main(){
    freopen("humble.out", "w", stdout);
    freopen("humble.in", "r", stdin);
    cin >> n >> m;
    //scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
       cin >> p[i];
       // scanf("%d", &p[i]);
    int l = 0;
    num[l] = 1;
    while(l < m){
        ++l; 
        int a = INF;
        for(int i = 0; i < n; i++){
            while(num[h[i]]*p[i] <= num[l-1])
                h[i]++;
            a = min(a, num[h[i]]*p[i]);
        }
        num[l] = a; 
    } 
    cout << num[m] << endl;
    return 0;
}
