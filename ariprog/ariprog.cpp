/*
ID: guangli1
PROG: ariprog
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
int M, N;
int n; 
vector<bool> legal;
bool test(int start, int diff){
   int cnt = 0;
    do{
        cnt += 1;
        start += diff;
    }while(start <= n && legal[start]);  
    return cnt >= N;
}
int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    fin >> N >> M;
    n = 2*M*M;
    legal.assign(n+1, false);
    for(int i = 0; i <= M; i++)
        for(int j = 0; j <= M; j++)
            legal[i*i+j*j] = true;
    vector<int> number;
    for(int i = 0; i <= n; i++)
        if(legal[i])
            number.push_back(i); 
    int maxDiff = (number.back() - number.front())/(N - 1) + 1; 
    bool flag = false;
    for(int diff = 1; diff <= maxDiff; diff++)
        for(int i = 0; i < number.size(); i++)
            if(test(number[i], diff)){
                flag = true;
                fout << number[i] << " " << diff << endl;
            }
    if(!flag)
        fout << "NONE" << endl;
    return 0;
}
