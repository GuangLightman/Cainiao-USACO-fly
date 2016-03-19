/*
ID: guangli1
PROG: comehome
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
const int N = 2*26; 
int n;
int edge[N][N];
int toBarn[N];
int visited[N] = {0};
char to_char(int i){
    if(i>=0 && i < 26)
        return 'a'+i;
    return 'A' + i-26;
}
bool hasCow(int i){
    return i>=26 && to_char(i) != 'Z';
}
int to_index(char c){
    if(c>='a' && c<='z')
        return c-'a';
    else 
        return 26 + c-'A';
}
void intial(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            edge[j][i] = edge[i][j] = i==j? 0 : INF;
    for(int i = 0; i < N; i++)
        toBarn[i] = INF;
    scanf("%d\n", &n);
    while(n--){
        char s, t;
        int w;
        scanf("%c %c %d\n", &s, &t, &w);    
        int i = to_index(s);
        int j = to_index(t);
        edge[j][i] = edge[i][j] = min(edge[i][j], w);
    }
}
int nearest(int& d){
    int t = -1;
    for(int i = 0; i < N; i++)
        if(!visited[i] && toBarn[i] < d){
            t = i;
            d = toBarn[i];
        }
    return t;
}
void run(){
    toBarn[to_index('Z')] = 0;
//    visited[to_index('Z')] = 1;
    bool flag = false;
    while(!flag){// indicate find cow;
        int d = INF;
        int i = nearest(d);
        visited[i] = 1;
        if(hasCow(i)){
            printf("%c %d\n", to_char(i), d);
            flag = true; // not necessary
            return;
        }
        for(int j = 0; j < N; j++)
            if(!visited[j] && edge[i][j] < INF)
                toBarn[j] = min(toBarn[j], toBarn[i]+edge[i][j]);  
    }
}

int main() {
    freopen("comehome.out", "w", stdout);
    freopen("comehome.in", "r", stdin);
    intial();
    run();
    return 0;
}
