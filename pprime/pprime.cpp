/*
ID: guangli1
PROG: pprime
LANG: C++11  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
bool pal_str(string str){
    int s = 0; 
    int t = str.size() - 1;
    while( s < t ){
        if(str[s] != str[t])
            return false;
        ++s;
        --t;
    }
    return true;
} 
bool pali(int n){
    string s;
    while(n){
        s.push_back(n%10);
        n /= 10;
    }
    if(pal_str(s)) return true;
    return false;
}    
const int N = 10000010;

int main() {
    bool * prime = new bool[N];
    memset(prime, true, N);
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    int a, b;
    fin >> a >> b;
    int n = b; //+ 10;
    for(int i = 2; i <= sqrt(n); i++)
        if(prime[i])
            for(int j = i*i; j <= n; j += i)
                prime[j] = false;
    for(int i = a; i <= b; i++)
        if(prime[i] && pali(i))
            fout << i << endl;
    return 0;
}
