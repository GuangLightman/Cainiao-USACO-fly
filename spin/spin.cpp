/*
ID: guangli1
PROG: spin
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
struct wheel{
    int speed;
    int start;
    bool hole[360];
    wheel(int s):speed(s){
        for(int i = 0; i < 360; i++)
            hole[i] = false;
        start = 0;
    } 
    void update(int i, int j){
        ++j;
        while(j--)
            hole[(i++)%360] = true;
    }
    void run(){
        start += speed;
        start %= 360;
    }
};
bool check(vector<wheel> & w){
    for(int i = 0; i < 360; i++){
        bool hole = true;
        for(int j = 0; hole && j < w.size(); j++)
            hole = hole &&  w[j].hole[(i+360-w[j].start)%360];
        if(hole) return true;
    }
    return false;
}
int main() {
    freopen("spin.out", "w", stdout);
    freopen("spin.in", "r", stdin);
    vector<wheel> ws;
    int s;
    while(EOF != scanf("%d", &s)){
        wheel w(s);
        int cnt;
        scanf("%d", &cnt);
        for(int i = 0; i < cnt; i++){
            int start, length;
            scanf("%d %d", &start, &length);
            w.update(start, length);
        }
        ws.push_back(w);
    } 
    //simulate
    for(int i = 0; i < 360; i++){
        if(check(ws)){
            printf("%d\n", i);
            return 0;
        }
        for(auto & w : ws)
            w.run();
    }
    printf("none\n");
    return 0;
}
