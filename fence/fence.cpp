/*
ID: guangli1
PROG: fence
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
const int N = 500;
int degree[N+1] = {0};
int edge[N+1][N+1] = {0};
int pos = 0;
int path[2*1024+2];
int s; //starting point
bool flag; // true for path   false for tour
void init(){
    int F;
    scanf("%d", &F);
    while(F--){
        int s, t;
        scanf("%d %d", &s, &t);
        ++degree[s];
        ++degree[t];
        ++edge[s][t];
        ++edge[t][s];
    }
    s = 0;
    flag = true;
    for(int i = 1; i <= N; i++)
        if(degree[i] && degree[i]%2){
            s = i;
            break;
        }
    if(s == 0)
      for(int i = 1; i <= N; i++)
          if(degree[i] && degree[i]%2 == 0){
              s = i;
              flag = false;
              break;
          }
}
void find(int s){
    if(degree[s]){
        for(int i = 1; i <= N; i++){
            if(edge[s][i]){
                --edge[s][i];
                --edge[i][s];
                --degree[s];
                --degree[i];
                find(i);
            }
        }
    }
    path[pos++] = s;
}
void print(){
    if(flag){
        if(path[0] > path[pos-1]){
            int i = 0; 
            int j = pos - 1;
            while(i < j)
                swap(path[i++], path[j--]); 
        }
        for(int i = 0; i < pos; i++)
            cout << path[i] << "\n";
    }else{
        vector<int> p;
        int sz = 2*pos;
        while(sz--)
            p.push_back(path[sz%pos]);
        auto it = min_element(p.begin(), p.end());
        auto it2 = min_element(it+1, p.end());
        if(*(it+1) < *(it2-1))
            for(auto p = it; p <= it2; p++)
                cout << *p << endl;
        else{
            for(auto p = it2; p > it; p--)
                cout << *p << endl;
            cout << *it << endl;
        }
    }
}
void euler_tour(){
    pos = 0;
    find(s);
}
int main() {
    freopen("fence.out", "w", stdout);
    freopen("fence.in", "r", stdin);
    init();
    find(s);
    print();
    return 0;
}
