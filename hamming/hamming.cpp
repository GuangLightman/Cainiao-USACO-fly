/*
ID: guangli1
PROG: hamming
LANG: C++11  
*/
// wrong solution. DFS should be applied
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
int N, B, D;
int num[256] = {0};
int M;
int start = 1;
vector<int> ans;
int count_one(int num){
    int cnt = 0;
    while(num){
        if(num&1)
            ++cnt;
        num >>= 1;
    }
    return cnt;
}
int dist(int a, int b){
    int c = a^b;
    return count_one(c);
}

bool check( int num){
    for(auto n : ans)
        if(dist(n, num) < D)
            return false;
    return true;
}
int find(){
    for(int i = start; i <= M; i++)
        if(check(i))
            return i;
    return 0;
}
int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    fin >> N >> B >> D;
    M = (1<<B) - 1;
    ans.push_back(0);
    --N;
    while(N){
        int next = find();
        start = next+1;
        ans.push_back(next);
        --N;
    }    
    sort(ans.begin(),ans.end());
    int k = 1;
    for(auto num : ans){
        if(k%10 && k!= ans.size())
            fout << num << " ";
        else
            fout << num << endl;
        k++;
    }
    fin.close();
    fout.close();
    return 0;
}
