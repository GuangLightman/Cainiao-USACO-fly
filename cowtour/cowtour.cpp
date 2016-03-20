/*
ID: guangli1
PROG: cowtour
LANG: C++11  
*/

#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
  
using namespace std;  
  
int n,i,j,k;  
long long x[155],y[155];  
double dis[155][155],ans;  
double mxd[155],dia[155];//mxd[i]表示与i最远的距离；dia[i]表示i所在牧场的直径  
const double INF=1000000000;  
char adj[155];  
  
inline double cal() {  
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));  
}  
  
int main() {  
    freopen("cowtour.in","r",stdin);  
    freopen("cowtour.out","w",stdout);  
    scanf("%d",&n);  
    ans=INF;  
    for(i=0;i<n;++i)  
        scanf("%I64d%I64d",x+i,y+i);  
    for(i=0;i<n;++i) {  
        scanf("%s",adj);  
        mxd[i]=dis[i][i]=0;  
        for(j=i+1;j<n;++j)  
            dis[i][j]=dis[j][i]=(adj[j]=='1'?cal():INF);  
    }  
    for(k=0;k<n;++k)//floyd算法算出各点之间最短路  
        for(i=0;i<n;++i)  
            for(j=0;j<n;++j)  
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);  
    for(i=0;i<n;++i)//算出与i，j最远的距离  
        for(j=i+1;j<n;++j)  
            if(dis[i][j]+0.0000001<INF) {//如果i和j在一个牧场  
                mxd[i]=max(mxd[i],dis[i][j]);  
                mxd[j]=max(mxd[j],dis[i][j]);  
            }  
    for(i=0;i<n;++i) {//算出i点所在牧场的直径  
        dia[i]=mxd[i];  
        for(j=0;j<n;++j)  
            if(dis[i][j]+0.0000001<INF)//如果i和j在一个牧场  
                dia[i]=max(dia[i],mxd[j]);  
    }  
    for(i=0;i<n;++i)//更新答案  
        for(j=i+1;j<n;++j)  
            if(dis[i][j]+0.0000001>INF)//如果i和j不在一个牧场  
                ans=min(ans,max(max(dia[i],dia[j]),mxd[i]+mxd[j]+cal()));  
    printf("%.6lf\n",ans);  
    return 0;  
}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <set>
//#include <map>
//#include <queue>
//#include <algorithm>
//#include <utility>
//#include <cmath>
//#include <cstring>
//#define LL unsigned long long
//using namespace std;
//struct Pair{
//    int x, y;
//    Pair(){}
//    Pair(int i, int j): x(i), y(j){}
//};
//int n;
//const int NN = 150;
//const double inf = 100000 * NN * 10;
//int edge[NN][NN];
//Pair node[NN];
//int color = 0;
//int visited[NN] = {0};
//double dist[NN][NN];
//double faraway[NN] = {0};
//double distance(int i, int j){
//    return sqrt(pow(node[i].x - node[j].x, 2) + pow(node[i].y - node[j].y, 2));
//}
//void bfs(int s){
//    queue<int> Q;
//    visited[s] = color;
//    Q.push(s);
//    while(!Q.empty()){
//        int node = Q.front();
//        Q.pop();
//        for(int i = 0; i < n; ++i){
//            if(edge[node][i] && !visited[i]){
//                visited[i] = color;
//                Q.push(i);
//            }
//        } 
//    } 
//} 
//void color_all(){
//    for(int i = 0; i < n; i++)
//        if(!visited[i]){
//            ++color;
//            bfs(i);
//        }
//}
//void intial(){
//    scanf("%d", &n);
//    // > nodes
//    for(int i = 0; i < n; i++){
//        int x, y;
//        scanf("%d %d", &x, &y);
//        node[i] = Pair(x, y);
//    }
//    // > edge
//    for(int i = 0; i < n; i++){
//        char s[NN];
//        scanf("%s", s);
//        for(int j = 0; j < n; j++){
//            edge[i][j] = s[j] == '0'? 0 : 1;
//        }
//    }
//
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < n; j++)
//            dist[i][j] = inf; //numeric_limits<double>::max();
//}
//void pair_dist(){
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < n; j++){
//            if(edge[i][j])
//                dist[i][j] = distance(i, j);
//            if(i == j)
//                dist[i][j] = 0;
//        }
//    for(int k = 0; k < n; k++)
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < n; j++)
//                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
//}
//void far_in_my_color(){
//    for(int i = 0; i < n; i++){
//        int color = visited[i]; 
//        for(int j = 0; j < n; j++){
//            if(visited[j] == color)
//                faraway[i] = max(faraway[i], dist[i][j]);
//        }
//    }    
//}
//
//void run(){
//    intial();
//    color_all();
//    pair_dist();
//    far_in_my_color();
//    //if(color == 1){
//    //    double res = inf;
//    //    for(int i = 0; i < n; i++){
//    //        for(int j = 0; j < n; j++){
//    //            double diameter = 0;
//    //            if(i == j || edge[i][j]) continue;
//    //            double d = distance(i, j);
//    //            for(int p = 0; p < n; p++)
//    //                for(int q = 0; q < n; q++){
//    //                    //dist[p][q]
//    //                    double new_dia = min(dist[p][q], d + min(dist[p][i]+dist[j][q], dist[p][j]+dist[i][q]));
//    //                    diameter = max(diameter, new_dia);
//    //                } 
//    //            res = min(res, diameter);
//    //        }
//    //    }
//    //    printf("%.6lf\n", res);
//    //    // return min(diamater, min( // run again???
//    //}else{ //if(color == 2){
//        // for each i, j with different color
//        // return minimize faraway[i] + faraway[j] + dist[i][j]
//        double diameter = inf;
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < n; j++){
//                if(visited[i] == visited[j]) continue;
//                diameter = min(diameter, distance(i, j) + faraway[i] + faraway[j]);
//            }
//        printf("%.6lf\n", diameter);
//        
//    //}//else{
////
// //   }
//}
//int main() {
//    //ofstream fout ("cowtour.out");
//    //ifstream fin ("cowtour.in");
//    freopen("cowtour.out", "w", stdout);
//    freopen("cowtour.in", "r", stdin);
//    run();
//    int T;
//    return 0;
//}
