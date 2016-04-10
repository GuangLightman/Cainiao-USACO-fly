/*
ID: guangli1
PROG: msquare
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
int target[8];
int start[8] = {1, 2, 3, 4, 5, 6, 7, 8};
void num2squares(int *s, int n){
    for(int i = 0; i < 8; i++){
        s[i] = 1 + (n & 0x7);
        n >>= 3;
    }
}
int squares2num(int *s){
    int n = 0;
    for(int i = 0; i < 8; i++)
        n |= ((s[i] - 1) << (i*3)); 
    return n;
}
int trans(int node, int j){
            int s[8];
            num2squares(s, node);
            if(j == 0){
                // A case
                for(int k = 0; k < 4; k++)
                    swap(s[k], s[7-k]);
            }else if(j == 1){
                // B case
                // 1 2 3 4
                swap(s[1], s[2]);// 1 3 2 4
                swap(s[1], s[3]);// 1 4 2 3
                swap(s[0], s[1]);// 4 1 2 3
                swap(s[6], s[5]);
                swap(s[6], s[4]);
                swap(s[7], s[6]);
            }else{
                // C case
                swap(s[6], s[1]); // 1 7 3 4     8 2 6 5
                swap(s[5], s[2]); // 1 7 6 4     8 2 3 5
                swap(s[6], s[2]); // 1 7 2 4     8 6 3 5 
            }
            int n = squares2num(s);
            return n;
}
int run(){
    int t = squares2num(target);
    int s = squares2num(start);
    if(s == t) cout << 0 << endl << endl;
    map<int, pair<int, int> > m;
    queue<int> q;
    q.push(s);
    m[s] = make_pair(s, 0);
    while(!q.empty()){
        int node = q.front();
            q.pop();
            for(int j = 0; j < 3; j++){
                //int next = state[node][j];
                int next = trans(node, j);
               //if(!visited[next]){
               if(m.find(next) == m.end()){
                    m[next] = make_pair(node, j);
                    if(next == t){
                       vector<int> out;
                       while(next != s){
                           auto p = m[next];
                           out.push_back(p.second);
                           next = p.first;
                       }    
                       int i = 1;               
                       cout << out.size() << endl;
                       for(; i <= out.size(); i++){
                            cout << (char)(out[out.size()-i]+'A');
                            if(i%60 == 0)
                                cout << endl;
                       }
                       if(i%60 != 1) 
                                cout << endl;
                       return 0;
                    }
                    q.push(next);
                }
            }
    } 
}
int main() {
    freopen("msquare.out", "w", stdout);
    freopen("msquare.in", "r", stdin);
    for(int i = 0; i < 8; i++)
        scanf("%d", &target[i]);
    //init();
    run();
    return 0;
}

