/* 
ID: your_id_here 
PROG: hamming 
LANG: C++ 
*/  
#include <cstdio>  
#include <cstring>  
  
using namespace std;  
  
int n,b,d,ans[65],num,ready[255],rn,t,tt,tmp,mx;  
  
bool isLegal(int x,int y) {  
    x^=y,tmp=0;  
    for(t=0;t<b;++t)  
        if(x&(1<<t))  
            ++tmp;  
    return tmp>=d;  
}  
  
inline bool choose(int index) {  
    for(tt=1;tt<num;++tt)//再也不敢滥用全局变量了，查错好辛苦，我还是按规范来吧，谨慎点好  
        if(!isLegal(ans[tt],ready[index]))  
            return false;  
    return true;  
}  
  
bool dfs(int index) {  
    if(num==n)//找到结果  
        return true;  
    do {  
        while(index<rn&&!choose(index))  
            ++index;  
        if(index==rn) {//无法找到答案，数字个数-1  
            --num;  
            return false;  
        }  
        ans[num++]=ready[index++];  
        if(dfs(index))  
            return true;  
    }while(index<rn);  
    --num;//无法找到答案，数字个数-1  
    return false;  
}  
  
int main() {  
    int i;  
    freopen("hamming.in","r",stdin);  
    freopen("hamming.out","w",stdout);  
    while(3==scanf("%d%d%d",&n,&b,&d)) {  
        ans[0]=rn=0,num=1,mx=1<<b;  
        for(i=1;i<mx;++i)  
            if(isLegal(0,i))  
                ready[rn++]=i;  
        dfs(0);  
        for(--num,i=0;i<=num;++i)  
            printf("%d%c",ans[i],(i+1)%10==0||i==num?'\n':' ');  
    }  
    return 0;  
}  

