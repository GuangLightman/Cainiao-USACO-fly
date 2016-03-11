/*
ID: guangli1
PROG: beads
LANG: C++   
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
int help(string &s, int pos){
    if(s.empty()) return 0;
    pos %= s.size(); 
    int cnt = 1;
    char color = s[pos];
    while(cnt < s.size() && (color == 'w' || s[(pos+1)%s.size()] == 'w' || s[(pos+1)%s.size()] == color))
    {
        pos = (pos+1)%s.size();
        if(color == 'w' && s[pos] != 'w')
            color = s[pos];
        ++cnt;
    }
    return cnt;
}
int help_r(string &s, int pos){
    if(s.empty()) return 0;
    pos = (pos+s.size()) % s.size(); 
    int cnt = 1;
    char color = s[pos];
    while(cnt < s.size() && (color == 'w' || s[(pos-1+s.size())%s.size()] == 'w' || s[(pos-1+s.size())%s.size()] == color ))
    {
        pos = (pos-1+s.size())%s.size();
        if(color == 'w' && s[pos] != 'w')
            color = s[pos];
        ++cnt;
    }
    return cnt;
}
int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int N;
    fin >> N;
    string s;
    fin >> s;
    int ret = 0;
    for(int i = 0; i < N; i++){
        int total = help(s, i) + help_r(s, (i-1)%N);
        total = total > N? N : total;
        ret = max(ret, total);
    }
    fout << ret << endl;
    return 0;
}
