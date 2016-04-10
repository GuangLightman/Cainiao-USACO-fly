/*
ID: guangli1
PROG: butter
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
#define INF (1<<28)  // (~(1<<31))
using namespace std;
const int N = 500, P = 800, C = 1250;
int n, p, c;
int d[P][P];
int path[P][P];
int cow_at[P] = {0};
int degree[P] = {0};
int st[P][P];
void init(){
    scanf("%d %d %d", &n, &p, &c);
    for(int i = 0; i < P; i++)
        for(int j = 0; j < P; j++){
            if(i == j)
                d[i][j] = path[i][j] = 0;
            else
                d[i][j] = d[j][i] = path[i][j] = path[j][i] = INF;
        }
    for(int i = 0; i < n; i++){
        int pasture;
        scanf("%d", &pasture);
        ++cow_at[pasture-1];
    }
    for(int i = 0; i < c; i++){
        int s, t, len;
        scanf("%d %d %d", &s, &t, &len);
        --s;
        --t;
        d[s][t] = d[t][s] = len;
        path[s][t] = path[t][s] = len;
        st[s][degree[s]++] = t;
        st[t][degree[t]++] = s;
    }
}
struct node{
    int index, val;
    node(int i, int v): index(i), val(v){}
    node():index(p), val(INF){}
};
class my_heap{
private:
    int size;
    int i2pos[P];
    node h[P];
public:
    int curDist(int t){
        return h[i2pos[t]].val;
    }
    my_heap(int * dist){
        for(int i = 0; i < p; i++){
            node n(i, dist[i]);
            h[i] = n;
            i2pos[i] = i;
        }
        size = p;
    }
    void decrease(int i, int v){
        int pos = i2pos[i];
        h[pos].val = v;
        while(pos != 0){
            int p = (pos-1)/2; 
            if(h[pos].val < h[p].val){
                i2pos[h[pos].index] = p;
                i2pos[h[p].index] = pos;
                swap(h[pos], h[p]);
                pos = p;
            }
            else
                break;
        }
    }
    void change(int pos, int dest){
        i2pos[h[dest].index] = pos;
        i2pos[h[pos].index] = dest;
        swap(h[pos], h[dest]);
    }
    void heapfy(){
        int pos = 0;
        change(pos, size-1);// swap first and last;
        --size;
        if(size <= 1) return;
        while(pos < size){
            int l = 2*pos + 1; 
            int r = 2*pos + 2; 
            if(l < size && h[pos].val > h[l].val && (r >= size || h[l].val <= h[r].val)){
                change(pos, l);
                pos = l;
            }else if(r < size && h[pos].val > h[r].val && h[r].val < h[l].val){
                change(pos, r);
                pos = r;
            }else
                pos = size;
        }
    }
    node remove_top(){
        node res = h[0];
        i2pos[res.index] = p;
        // re-heapfy;
        heapfy();
        return res;
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << h[i].index << "  ";
            if(INF ==  h[i].val)cout << "INF"; 
            else cout << h[i].val; 
            cout << "     ";
        }
        cout << endl;
        cout << endl;
    }
};
void fillline(int r){
    int cnt = 0;
    int dist[P];
    for(int i = 0; i < p; i++)
        dist[i] = INF;
    my_heap h(dist);
    h.decrease(r, 0);
    while(cnt++ != p){
        node n = h.remove_top(); 
        int s = n.index;
        dist[s] = n.val;
        //for(auto t: edge[n.index]){
        for(int k = 0; k < degree[s]; k++){
            int t = st[s][k];
            if(dist[t] != INF)
                continue;
            int cur = h.curDist(t);
            int v = min(cur, dist[s]+d[s][t]); 
            if(v < cur)
                h.decrease(t, v);
        } 
    }
    for(int i = 0; i < p; i++)
        path[r][i] = dist[i];
}
void fillpath(){
        // floyd algorithm, TLE
    //for(int k = 0; k < p; k++)
    //    for(int i = 0; i < p; i++)
    //        for(int j = 0; j < p; j++)
    //            path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
    for(int r = 0; r < p; r++)
        fillline(r);
}
int findmin(){
    int res = INF;
    for(int r = 0; r < p; r++){
        int total_len = 0;
        for(int i = 0; i < p; i++)
            total_len += cow_at[i] * path[i][r];
        res = min(res, total_len);
    }
    return res;
}
int main() {
    freopen("butter.out", "w", stdout);
    freopen("butter.in", "r", stdin);
    init();
    fillpath();
    cout << findmin() << endl;
    return 0;
}
