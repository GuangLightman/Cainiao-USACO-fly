/*
ID: guangli1
PROG: preface
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
using namespace std;
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
const int N = 7;
int val[] = {1, 5, 10, 50, 100, 500, 1000};
char chr[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int cnt[256] = {0};
string convert(int n){
    string res;
    int k = n/1000;
    res.append(k, 'M');
    n -= k * 1000;
    int index = 6;
    while(index){
        // 900
        if(n >= val[index] - val[index-2]){
            res.push_back(chr[index-2]);
            res.push_back(chr[index]); 
            n -= 9*val[index-2];
        }
        //500
        if(n >= val[index-1]){
            res.push_back(chr[index-1]);
            n -= val[index-1];
        }
        //400
        if(n >= 4*val[index-2]){
            res.push_back(chr[index-2]);
            res.push_back(chr[index-1]); 
            n -= 4*val[index-2];
        }
        //100
        if(n >= val[index-2]){
            res.append(n/val[index-2], chr[index-2]);
            n %= val[index-2];
        }
        index -= 2;
    }
    return res;
}
int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int T;
    fin >> T;
    for(int i = 1; i <= T; ++i)
        for(char c : convert(i))
           ++cnt[c]; 
    int m = 0;
    for(int i = 0; i < 7; ++i)
        m = max(m, cnt[chr[i]]); 
    for(int i = 0; i < 7; ++i){
       if(cnt[chr[i]]) fout << chr[i] << " " << cnt[chr[i]] << endl;
//        if(m == cnt[chr[i]]) break;
    }
    fin.close();
    fout.close();
    return 0;
}
