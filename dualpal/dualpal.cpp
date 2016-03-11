/*
ID: guangli1
PROG: dualpal
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
using namespace std;
bool isPal(string s){
    int i = 0;
    int j = s.size() - 1;
    while(i < j)
        if(s[i] == s[j]){
            ++i;
            --j;
        }
        else return false;
    return true;
}
string trans(int num, int base){
    string res;
    while(num){
        int mod = num % base;
        num /= base;
        res.push_back(mod);
    }
    return res;
}
bool test( int num){
    int cnt = 0;
    for(int base = 2; base <= 10; base++)
        if(isPal(trans(num, base)))
            ++cnt;
    return cnt >= 2;
}
int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N, S;
    fin >> N >> S;
    int cnt = 0; int cur = S + 1;
    while(cnt < N){
        while(!test(cur))
            ++cur;
        ++cnt;
        fout << cur << endl;
        ++cur;
    }
    return 0;
}
