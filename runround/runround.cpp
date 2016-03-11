/*
ID: guangli1
PROG: runround
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
bool round(string s){
    int n = s.size();
    int chr[10] = {0};
    for(auto c : s)
        if(c == '0' || chr[c-'0'])
            return false;
        else ++chr[c-'0'];
    int start = 0;
    int cnt = 0;
    int mark[10] = {0};
    while( cnt < n+1){
        if(mark[start]) return cnt == n && start == 0 ? true : false;
        ++mark[start];
        ++cnt;
        start = (start+s[start]-'0')%n;
    }
    return cnt == n;
}
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

        
int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    int T;
    fin >> T;
    while(!round(patch::to_string(++T)));
    fout << T << endl;
    fin.close();
    fout.close();
    return 0;
}
