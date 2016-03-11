/*
ID: guangli1
PROG: transform
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
vector<string> original;
vector<string> ans;
void reflect(vector<string>& matrix){
    for(auto & row : matrix)
        reverse(row.begin(), row.end());
} 
void reverse(vector<string>& matrix){
   for(int i = 0; i<matrix.size(); ++i)
        for(int j = i+1; j < matrix[0].size(); ++j)
            swap(matrix[i][j],matrix[j][i]);
}
void rotate(vector<string>& matrix){
    reverse(matrix);
    reflect(matrix);
}
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int T;
    fin >> T;

    for(int i = 0; i < T; ++i){
        string row;
        fin >> row;
        original.push_back(row);
    }
    for(int i = 0; i < T; ++i){
        string row;
        fin >> row;
        ans.push_back(row);
    }
    vector<int> operation;
    if(original == ans)
        operation.push_back(6);
    
    auto rel_original = original;
    reflect(rel_original); 
    if(rel_original == ans)
        operation.push_back(4);
    for(int i = 1; i <= 3; i++){
        rotate(original);
        if(original == ans)
            operation.push_back(i);
        rotate(rel_original);
        if(rel_original == ans)
            operation.push_back(5);
    }
    if(!operation.empty()){
        sort(operation.begin(), operation.end());
        fout << operation[0] << endl;
        return 0;
    }
    fout << "7" << endl;
    return 0;
}
