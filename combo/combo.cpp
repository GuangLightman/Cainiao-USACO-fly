/*
ID: guangli1
PROG: combo
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
int T;
int intersect(int x1, int x2){
    int d = min(abs(x2+T-x1), min(abs(x1-x2), abs(x1+T-x2)));
    return min(T, d>5? 0 : 5-d);
} 
int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    fin >> T;
    int x1, y1, z1, x2, y2, z2;
    fin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int edge = min(5, T);
    int v = pow(edge, 3);
    fout << 2*v - intersect(x1, x2)*intersect(y1, y2)*intersect(z1, z2)  << endl;
    return 0;
}
