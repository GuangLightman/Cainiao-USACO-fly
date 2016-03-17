/*
ID: guangli1
PROG: maze1
LANG: C++11  
*/
#include <iostream>
#include <stdio.h>
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
#define INF (~(1<<31))
using namespace std;
char maze[2*100+5][2*38+5];
int W, H;
int dist[100][38];
int res = 0;
struct Pair{
    int x, y;
    Pair(){};
    Pair(int _x, int _y): x(_x), y(_y){
    }
};
Pair exits[2];
void intial(ifstream & fin){
    fin >> W >> H;
    fin.getline(maze[0], 2*38+5);// eat \n
    int index = 0;
    for(int i = 0; i < 2*H+1; i++){
        fin.getline(maze[i], 2*38+5);
        if(i == 0)
            for(int j = 0; j < 2*W+1; j++)
                if(maze[i][j] == ' ')
                    exits[index++] = Pair(i/2, j/2); 
        if(i == 2*H)
            for(int j = 0; j < 2*W+1; j++)
                if(maze[i][j] == ' ')
                    exits[index++] = Pair(H-1, j/2); 
        if(i%2 == 1){
            if(maze[i][0] == ' ')
                exits[index++] = Pair(i/2, 0);
            if(maze[i][2*W] == ' ')
                exits[index++] = Pair(i/2, W-1);
        }
    }
    for(int i = 0; i < 100; ++i)
        for(int j = 0; j < 38; ++j)
            dist[i][j] = INF;
    dist[exits[0].x][exits[0].y] = 1;
    dist[exits[1].x][exits[1].y] = 1; 
}
void bfs(Pair p){
    queue<Pair> Q;
    Q.push(p);
    while(!Q.empty()){
        Pair p = Q.front();
        Q.pop();
        for(int i = p.x-1; i <= p.x + 1; i++)
            for(int j = p.y-1; j <= p.y+1; j++){
                if(i < 0 || i >= H || j < 0 || j >= W ||\
                   (int)(abs(i-p.x) + abs(j-p.y)) != 1 ||\
                    maze[(2*p.x+1+2*i+1)/2][(2*p.y+1+2*j+1)/2] != ' '){
                    continue;
                }
                int d = min(dist[i][j], dist[p.x][p.y]+1);
                if(dist[i][j] > d || dist[i][j] == INF)
                    Q.push(Pair(i, j));
                dist[i][j] = d;
            }
    }
}
void run(){
    bfs(exits[0]);
    bfs(exits[1]);
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j)
            res = max(res, dist[i][j]);
}
int main() {
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    intial(fin);
    run();
    fout << res << endl;
    fin.close();
    fout.close();
    return 0;
}
