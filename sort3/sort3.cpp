/*
ID: guangli1
PROG: sort3
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
const int N = 1000;
int num[N];
int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int T;
    fin >> T;
    int diff[4][4] = {0};
    int cnt[4] = {0};
    for(int i = 0; i < T; i++){
        fin >> num[i];
        cnt[num[i]]++;
    }
    int index = 0;
    for(int i = 1; i <= 3; i++){
        int end = index + cnt[i];
        while(index < end){
           if(num[index] != i)
                diff[i][num[index]] ++;
            ++index;
        } 
    }
    int step = 0;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            if(i != j){
                int n = min(diff[i][j], diff[j][i]); 
                step += n; 
                diff[i][j] -= n;
                diff[j][i] -= n;
            }
    step += 2*max(diff[1][2], diff[1][3]);
    fout << step << endl;
    fin.close();
    fout.close();
    return 0;
}
