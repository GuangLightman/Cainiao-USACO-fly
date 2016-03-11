/* 
ID: guangli1 
PROG: pprime 
LANG: C++ 
*/  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
  
using namespace std;  
  
int a,b,num;  
  
bool witness(long long a,long long n) {  
    long long d,x;  
    d=1;  
    int i=ceil(log(n-1.0)/log(2.0))-1;//ceil()是向上取整  
    for(;i>=0;i--) {  
        x=d;  
        d=(d*d)%n;  
        if(d==1&&x!=1&&x!=n-1)  
            return true;  
        if(((n-1)&(1<<i))>0)  
            d=(d*a)%n;  
    }  
    return d==1?false:true;  
}  
  
bool miller_rabin(long long n) {  
    int s[]={2,3,5};//只用2，3，5和下面的特例判断就能正确判断10^8以内的所有素数，枚举一遍用时40s左右  
    if(n==2||n==3||n==5||n==7)  
        return true;  
    if(n==1||(n&1)==0||0==n%3||0==n%5||n==4097||n==1048577||n==16777217||n==25326001)  
        return false;  
    for(int i=0;i<3;i++)  
        if(witness(s[i], n))  
            return false;  
    return true;  
}  
  
int main() {  
    int i,j,k,l,m;  
    freopen("pprime.in","r",stdin);  
    freopen("pprime.out","w",stdout);  
    while(2==scanf("%d%d",&a,&b)) {  
        //根据样例输出100以内的回文素数  
        if(a<=5&&5<=b)  
            printf("5\n");  
        if(a<=7&&7<=b)  
            printf("7\n");  
        if(a<=11&&11<=b)  
            printf("11\n");  
  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                if(miller_rabin(num=101*i+10*j)&&a<=num&&num<=b)  
                    printf("%d\n",num);  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                if(miller_rabin(num=1001*i+110*j)&&a<=num&&num<=b)  
                    printf("%d\n",num);  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                for(k=0;k<=9;++k)  
                    if(miller_rabin(num=10001*i+1010*j+100*k)&&a<=num&&num<=b)  
                        printf("%d\n",num);  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                for(k=0;k<=9;++k)  
                    if(miller_rabin(num=100001*i+10010*j+1100*k)&&a<=num&&num<=b)  
                        printf("%d\n",num);  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                for(k=0;k<=9;++k)  
                    for(l=0;l<=9;++l)  
                        if(miller_rabin(num=1000001*i+100010*j+10100*k+1000*l)&&a<=num&&num<=b)  
                            printf("%d\n",num);  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                for(k=0;k<=9;++k)  
                    for(l=0;l<=9;++l)  
                        if(miller_rabin(num=10000001*i+1000010*j+100100*k+11000*l)&&a<=num&&num<=b)  
                            printf("%d\n",num);  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                for(k=0;k<=9;++k)  
                    for(l=0;l<=9;++l)  
                        for(m=0;m<=9;++m)  
                            if(miller_rabin(num=100000001*i+10000010*j+1000100*k+101000*l+10000*m)&&a<=num&&num<=b)  
                                printf("%d\n",num);  
        for(i=1;i<=9;i+=2)  
            for(j=0;j<=9;++j)  
                for(k=0;k<=9;++k)  
                    for(l=0;l<=9;++l)  
                        for(m=0;m<=9;++m)  
                            if(miller_rabin(num=100000001*i+100000010*j+10000100*k+1001000*l+110000*m)&&a<=num&&num<=b)  
                                printf("%d\n",num);  
    }  
    return 0;  
}  

 
