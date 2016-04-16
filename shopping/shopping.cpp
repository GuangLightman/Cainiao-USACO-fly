/*
ID: guangli1
PROG: shopping
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
struct offer{
    int kind; 
    int sz[5];
    int code[5]; 
    int price;
    int saved;
};
int price[1000];  // for each code   per price
int s, b;
offer packs[100];
void init(){
    scanf("%d", &s);
    for(int i = 0; i < s; i++){
        int n;
        scanf("%d", &n);
        packs[i].kind = 0;
        packs[i].saved = 0;
        for(int j = 0; j < n; j++){
            int c, k;
            scanf("%d %d", &c, &k);
            packs[i].code[kind] = c;
            packs[i].sz[kind] = k;
            packs[i].kind += 1; 
        }
        scanf("%d", &(packs[i].price)); 
    }
    scanf("%d", &b);
    for(int i = 0; i < b; i++){
        int c, k, p;
        scanf("%d %d %d", &c, &k, &p);
        price[c] = p;
        
    }
}
int main() {
    freopen("shopping.out", "w", stdout);
    freopen("shopping.in", "r", stdin);
    return 0;
}
