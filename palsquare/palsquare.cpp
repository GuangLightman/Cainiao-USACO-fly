/*
ID: guangli1
PROG: palsquare
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
        char c;
        if(mod < 10)
            c = '0' + mod;
        else c = 'A'+ mod - 10; 
        res.push_back(c);
    }
    reverse(res.begin(), res.end());
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int B;
    fin >> B;
    for(int i = 1; i <= 300; i++){
        string s = trans(i*i, B);
        if(isPal(s))
            fout << trans(i, B) << " " << s << endl;
    }
    return 0;
}
