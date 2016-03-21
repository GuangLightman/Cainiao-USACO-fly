/*
ID: guangli1
PROG: agrinet
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

const int NN = 100;
int visited[NN] = {0};
int n;
int edge[NN][NN];
int dist[NN];
int pre[NN] = {0};
void intial(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &edge[i][j]);
    for(int i = 0; i < n; i++)
        dist[i] = INF;
    dist[0] = 0;
}
int cnt = 0;
int length = 0;
int find(){
    int l = INF;
    int node;
    for(int i = 0; i < n; i++)
        if(!visited[i] && dist[i] < l){
            node = i;
            l = dist[i];
        }
    return node;
}
void run(){
    while(cnt < n){
        int i = find();
        ++cnt;
        visited[i] = 1;
        length += edge[pre[i]][i];
        for(int j = 0; j < n; j++)
            if(!visited[j] && edge[i][j] < dist[j]){
                dist[j] = edge[i][j];
                pre[j] = i;
            }
    }
}
int main() {
    freopen("agrinet.out", "w", stdout);
    freopen("agrinet.in", "r", stdin);
    intial();
    run();
    printf("%d\n", length);
    return 0;
}
