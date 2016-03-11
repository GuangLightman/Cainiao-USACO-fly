/* 
ID: guangli1  
PROG: sprime 
LANG: C++ 
*/  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
  
using namespace std;  
const int mn[9]={0,1,10,100,1000,10000,100000,1000000,10000000},mx[9]={0,10,100,1000,10000,100000,1000000,10000000,100000000};  
int a,b,num,l,r;  
  
bool witness(long long a,long long n) {  
    long long d=1,x;  
    int i=ceil(log(n-1.0)/log(2.0))-1;//ceil()是向上取整  
    for(;i>=0;i--) {  
        x=d;  
        d=(d*d)%n;  
        if(d==1&&x!=1&&x!=n-1)  
            return true;  
        if(((n-1)&(1<<i))>0)  
            d=(d*a)%n;  
    }  
    return d!=1;  
}  
  
bool miller_rabin(long long n) {  
    int s[]={2,3,5};  
    if(n==2||n==3||n==5||n==7)  
        return true;  
    if(n==1||(n&1)==0||0==n%3||0==n%5||n==4097||n==1048577||n==16777217||n==25326001||n==960946321)  
        return false;  
    for(int i=0;i<3;i++)  
        if(witness(s[i], n))  
            return false;  
    return true;  
}  
  
void solve(int nn) {  
    if(!miller_rabin(nn))  
        return ;  
    if(l<=nn&&nn<=r) {  
        printf("%d\n",nn);  
        return ;  
    }  
    nn*=10;  
    for(int i=1;i<=9;i+=2)  
        solve(nn+i);  
}  
  
int main() {  
    int i,pri[]={2,3,5,7};  
    freopen("sprime.in","r",stdin);  
    freopen("sprime.out","w",stdout);  
    while(1==scanf("%d",&num)) {  
        l=mn[num],r=mx[num];  
        for(i=0;i<4;++i)  
            solve(pri[i]);  
    }  
    return 0;  
}

