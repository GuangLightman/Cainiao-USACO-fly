/*
ID: guangli1
PROG: wormhole
LANG: C++11  
*/
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
int i,ans,n,nn,nnn,rig[12],par[12],cur,fac[6]={1,1,2,6,24,120};  
bool vis[12];  
  
struct Node {  
    int x,y;  
    bool operator < (const Node& a) const {  
        return y<a.y||(y==a.y&&x<a.x);  
    }  
}p[13];  
  
bool judge() {  
    int i;  
    for(i=0;i<n;++i) {  
        memset(vis,false,sizeof(vis));  
        cur=i;  
        while(true) {  
            cur=rig[cur];  
            if(cur==-1)  
                break;  
            cur=par[cur];  
            if(vis[cur])  
                return true;  
            vis[cur]=true;  
        }  
    }  
    return false;  
}  
  
void dfs(int num) {  
    if(num==nn) {  
        if(judge())  
            ++ans;  
        return ;  
    }  
    int i,j;  
    for(i=0;i<n;++i) {  
        if(num==0&&i>0)//特判是否在找第一对虫洞，如果是第一对虫洞并且都不是第一个虫洞则返回，防止重复计算（不要这个竟然超时...）  
            return;  
        if(par[i]==-1) {  
            for(j=i+1;j<n;++j)//j>i防止i和j一对与j和i一对同时出现，变排列为组合  
                if(par[j]==-1) {  
                    par[i]=j,par[j]=i;  
                    dfs(num+1);  
                    par[i]=par[j]=-1;  
                }  
        }  
    }  
}  
  
int main() {  
    freopen("wormhole.in","r",stdin);  
    freopen("wormhole.out","w",stdout);  
    while(1==scanf("%d",&n)) {  
        for(i=0;i<n;++i)  
            scanf("%d%d",&p[i].x,&p[i].y);  
        nn=n>>1,nnn=nn-1;  
        sort(p,p+n);  
        p[n].x=p[n].y=-1;//刚开始数组开小1个，导致越界，但是不提示，只说答案错误，狂交20次才发现...  
        for(i=0;i<n;++i) {//预处理所有点往右走能走到的点  
            par[i]=-1;  
            if(p[i].y!=p[i+1].y)  
                rig[i]=-1;  
            else  
                rig[i]=i+1;  
        }  
        ans=0;  
        dfs(0);  
        printf("%d\n",ans/fac[nnn]);//高中数学还记得，将m个物品n等分，最后需要除以A(n,n)=n!  
    }  
    return 0;  
}  

