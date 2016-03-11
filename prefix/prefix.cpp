/*
ID: guangli1
PROG: prefix
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
#include <cstring>
using namespace std;
set<string> dict;
int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    string T;
    while(T != string(".")){
        fin >> T;
        dict.insert(T);
    }
    string tmp; T = tmp;
    while(fin >> tmp) T += tmp;
    //bool state[N];
    vector<bool> state(T.size(), false);
   // memset(state, false, N*sizeof(bool));
  //  for(int i = 1; i <= 10 && i <= T.size(); ++i)
   //     if(dict.find(string(T.begin(), T.begin()+i)) != dict.end())
    //        state[i-1] = true;
    int index = 0;
    for(; index < T.size(); ++index){
        //bool flag = false;
        for(int i = 1; i <= 10 && index-i+1 >= 0; ++i){
            if((index - i + 1 == 0 || state[index-i]) && dict.find(string(T.begin()+index-i+1, T.begin()+index+1)) != dict.end()){
                state[index] = true;
                break;
         //       flag = true;
          //      break;
            }
        }
        //if(flag) continue;
        //break;
    }
    index = T.size();
    while(index >= 1 && !state[index-1]) --index;
    fout << index << endl;
    fin.close();
    fout.close();
    return 0;
}
