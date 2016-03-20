/*
ID: guangli1
PROG: fracdec
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
#include <sstream>
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace patch;
int main() {
    freopen("fracdec.out", "w", stdout);
    freopen("fracdec.in", "r", stdin);
    int m, n;
    scanf("%d %d", &m, &n);
    int z = m/n;
    int rst = m - z*n;
    vector<int> dec;
    vector<int>::iterator pos;
    vector<int> cmp;
    while(rst){
        rst *= 10;
        int d = rst/n;
        pos = find(dec.begin(), dec.end(), d);
        if(pos == dec.end() || rst != cmp[pos-dec.begin()]){
            dec.push_back(d);
            cmp.push_back(rst);
            rst -= d*n;
            continue;
        }
        break;
    }
    string show;
    //printf("%d.", z);
    show += to_string(z);
    show += string(".");
    if(!rst){
        //finite
        if(dec.size() == 0)
            //printf("0"); 
            show += to_string(0);
        else{
            for(auto num : dec)
                //printf("%d", num);
                show += to_string(num);
        }
    }else{
        //inf
        for(auto it = dec.begin(); it != pos; it++)
            //printf("%d", *it);
            show += to_string(*it);
        //printf("("); 
        show += string("(");
        for(auto it = pos; it != dec.end(); it++)
            //printf("%d", *it);
            show += to_string(*it);
        //printf(")"); 
        show += string(")");
    }
    int i = 0;
    for(; i < show.size(); i++){
        printf("%c", show[i]);
        if((i+1)%76 == 0)
            printf("\n");
    } 
    if(i%76)
        printf("\n");
    return 0;
}
