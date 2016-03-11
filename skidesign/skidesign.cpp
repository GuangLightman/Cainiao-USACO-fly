/*
ID: guangli1
PROG: skidesign
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
int calc(int h, vector<int> v){
    int ret = 0;
    for(auto num : v)
        if( num < h ){
            ret += (h-num) * (h-num);
            continue;
        }else if(num > h + 17){
            ret += (num - h - 17) * (num - h - 17);
            continue;
        }else
            continue;
    return ret;
}
int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int T;
    fin >> T;
    vector<int> heights;
    int height, minH, maxH;
    minH = ~(1<<31);
    maxH = 0;
    while(fin >> height){
        minH = min(minH, height);
        maxH = max(maxH, height);
        heights.push_back(height);
    }
    int h = minH;
    int ans = ~(1<<31);
    do{
        ans = min(ans, calc(h, heights));
        h++;
    }while(h <= maxH - 17);
    fout << ans << endl;
    return 0;
}
