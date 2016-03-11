/*
ID: guangli1
PROG: milk
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
using namespace std;
typedef pair<int, int> Farm;
int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int M, N;
    fin >> N >> M;
    vector<Farm> farms;
    for(int i = 0; i < M; i++){
       int price,  amount;
        fin >> price >> amount;
        farms.push_back(make_pair(price, amount));
    }
    sort(farms.begin(), farms.end()); 
    int cost = 0;
    for(auto farm : farms){
        if(N <= farm.second){
            cost += N * farm.first;
            break;
        }
        cost += farm.first * farm.second;
        N -= farm.second;
    }
    fout << cost << endl;
    return 0;
}
