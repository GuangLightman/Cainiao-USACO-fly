/*
ID: guangli1
PROG: frac1
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
#define eps 1e-6
void f( double a, double b, int N, int n, ofstream& ofs){
        if(n > N) return;
        if(n == 1)
            ofs << "0/1" << endl;
        int m1 = n*a;
        int m2 = n*b;
        for(int m = m1; m <= m2; m++){
            double v = m/(double)n;
            if(v > a+eps && v < b-eps) 
                ofs << m << '/' << n << endl;
            f(max(a, m/(double)n), min(b, (m+1)/(double)n), N, n+1, ofs);
        }
        if( n == 1)
            ofs << "1/1" << endl;
}
int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int N;
    fin >> N;
    f(0, 1.0, N, 1, fout);
    fin.close();
    fout.close();
    return 0;
}
