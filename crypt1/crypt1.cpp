/*
ID: guangli1
PROG: crypt1
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
vector<int> choices;
int match[5] = { 0 };
int appear[10] = { 0 };
int cnt = 0;
bool exist(int num){
    while(num){
        if(!appear[num%10])
            return false;
        num /= 10;
    }
    return true;
}
bool check(){
    int abc = match[0]*100 + match[1]*10 + match[2];
    int d = match[3];
    int e = match[4];
    int de = d*10 + e;
    int line1, line2, line3;
    line1 = abc*e;
    line2 = abc*d;
    line3 = abc*de;
    if(line1 <= 999 && line2 <= 999 && line3 <= 9999 &&\
        exist(line1) && exist(line2) && exist(line3))
        return true;
    return false;
}
void dfs(int level){
    if(level >= 5){
        if(level == 5 && check())
            ++cnt;
        return;
    }
    for(auto num : choices){
        match[level] = num;
        dfs(level+1);
    }
}
int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int T;
    fin >> T;
    int num;
    while(fin >> num){
        choices.push_back(num);
        appear[num] = 1;
    }
    dfs(0);
    fout << cnt << endl;
    return 0;
}
