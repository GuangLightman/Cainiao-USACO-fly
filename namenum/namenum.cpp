/*
ID: guangli1
PROG: namenum
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
char table[][3] = {{'A', 'B', 'C'}, 
                   {'D', 'E', 'F'},                    
                   {'G', 'H', 'I'},
                   {'J', 'K', 'L'},
                   {'M', 'N', 'O'}, 
                   {'P', 'R', 'S'},
                   {'T', 'U', 'V'}, 
                   {'W', 'X', 'Y'}}; 
string inp;
set<string> dict;
vector<string> res;
string test;
void dfs(int l){
    if(l == inp.size() && dict.find(test) != dict.end()){
        res.push_back(test);
        return;
    }else if(l >= inp.size())
        return;
    int index = inp[l] - '2';
    for(int i = 0; i < 3; ++i){
        char c = table[index][i];
        test.push_back(c);
        dfs(l+1);
        test.pop_back();
    }
    return;
}
int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fdict("dict.txt");
    fin >> inp;
    string name;
    while(fdict >> name){
        dict.insert(name);
    }
    dfs(0);
    for(auto name : res)    
        fout << name << endl;
    if(res.empty())
        fout << "NONE" << endl;
    return 0;
}
