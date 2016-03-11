/*
ID: guangli1
PROG: numtri
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
int total(vector<vector<int> >& triangle) {
    // 
    vector<int> v = triangle.back();
    for(int i = triangle.size()-2; i>= 0; --i){
        vector<int> tmpV;
        for(int j = 1; j < v.size(); ++j)
            tmpV.push_back(triangle[i][j-1] + max(v[j-1], v[j]));
        v = tmpV;    
    }
    return v.empty()? 0 : v[0];
}
int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int T;
    fin >> T;
    vector<vector<int> > tri(T, vector<int>({}));
    for(int i = 0; i < T; i++){
        for(int j = 0; j <= i; j++){
            int num;
            fin >> num;
            tri[i].push_back(num);
        }
    }
    fout << total(tri) << endl;
    return 0;
}
