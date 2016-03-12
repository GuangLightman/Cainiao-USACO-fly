/*
ID: guangli1
PROG: zerosum
LANG: C++11  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int N, sum;
int cnt = 0;
string op;
vector<string> res;
string trans(int n){
    string res;
    res.push_back('0' + n%10);
    n /= 10;
    while(n){
        res.push_back(' ');
        res.push_back('0' + n%10);
        n/= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
void dfs(int level, vector<int> &v){
    if(level >= v.size()-1){
        if(sum == 0){ 
            ++cnt;
            string l = trans(v[0]) ;
            for(int i = 1; i < v.size(); i++){
                l.push_back(op[i-1]);
                l += trans(v[i]);
            }
            res.push_back(l);
        }
        return;
    }
    op.push_back('+');
    sum += v[level+1];
    dfs(level+1, v);
    op.pop_back();
    op.push_back('-');
    sum -= 2*v[level+1]; 
    dfs(level+1, v);
    op.pop_back();
    sum += v[level+1];
}
int count(vector<int> v){
    if(v.empty()) return 0;
    sum = v[0];
    dfs(0, v);
    return cnt; 
}
vector<int> v;
int part(int index){
    if(index > N) count(v);
    int n = 0;
    for(int i = index; i <= N; i++){
        n = n*10 + i;
        v.push_back(n);
        part(i+1);
        v.pop_back(); 
    }
}


//void dfs(int level){
//   if(level > N){
//        if(sum == 0)
//            ++cnt; 
//        return;
//    }
//    int n = 0;
//    for(int i = level; i <= N; ++i){
//        n = n*10 + num[i];
//        sum += n;
//        if(n == 67)cout << level << "  " << n << " sum " << sum << endl;
//        dfs(i+1);
//        sum -= n;
//        if(level == 1) continue;
//        sum -= n;
//        dfs(i+1);
//        sum += n;
//    }
//}
int main() {
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
    fin >> N;
    part(1);
//    fout << cnt << endl;
    sort(res.begin(), res.end());
    for(auto l : res)
        fout << l << endl;
    fin.close();
    fout.close();
    return 0;
}
