/*
ID: guangli1
PROG: fact4
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
int N;
int main() {
    freopen("fact4.out", "w", stdout);
    freopen("fact4.in", "r", stdin);
    cin >> N;
    unsigned int a = 1;
    for(int i = 1; i <= N; i++)
    {
        a *= i;
        while(a%10 == 0)
            a /= 10;
        a = a%100000;     
    }
    string s = to_string(a);
    cout << s.back() << endl;
    return 0;
}
