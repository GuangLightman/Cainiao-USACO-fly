/*
ID: guangli1
PROG: barn1
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

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M, S, C;
    fin >> M >> S >> C;
    vector<int> cows_pos;
    int pos;
    while(fin >> pos)
        cows_pos.push_back(pos);
    if(C == 1) 
        fout << 1 << endl;
    sort(cows_pos.begin(), cows_pos.end());
    int coverage = cows_pos.back() - cows_pos[0] + 1;
    vector<int> slices_width;
    for(int i = 0; i < cows_pos.size()-1; i++)
        slices_width.push_back(cows_pos[i+1] - cows_pos[i] - 1); 
    sort(slices_width.begin(), slices_width.end());
    int board_num = 1;
    while(board_num < M){
        if(!slices_width.empty()){
            coverage -= slices_width.back();
            slices_width.pop_back();
            ++board_num;
        }else break;
    }    
    fout << coverage << endl;
    return 0;
}
