/*
ID: guangli1
PROG: gift1 
LANG: C++11   
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    fin >> n;
    vector<string> names;
    map<string, int> money;
    for(int i = 0; i < n; i++){
        string name;
        fin >> name;
        names.push_back(name);
        money[name] = 0;
    }
    string name;
    while(fin >> name){
        int amount, n;
        fin >> amount >> n;
        if(n == 0) 
            continue;
        int rcv = amount / n;
        int res = amount - n*rcv;
        money[name] -= amount - res;
        for(int i = 0; i < n; ++i){
            fin >> name;
            money[name] += rcv;
        }
    }    
    for(int i = 0; i < n; ++i)
        fout << names[i] << " " << money[names[i]] << "\n";
    return 0;
}
