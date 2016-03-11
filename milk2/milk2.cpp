/*
ID: guangli1
PROG: milk2
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
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N;
    fin >> N;
    vector<pair<int, int> > times;
    for(int i = 0;i < N; ++i){
        int s, t;
        fin >> s >> t;
        times.push_back(make_pair(s, t));
    }
    sort(times.begin(), times.end());
    int longestMilk = 0, longestNoMilk = 0;
    if(!times.empty()){
        auto time = times[0];
        int s, t; 
        t = time.second;
        s = time.first;
        longestMilk = t - s;
        for(int i = 1; i < times.size(); ++i){
            time = times[i];
            int s1 = time.first;
            int t1 = time.second;
            if(s1 <= t){
                if(t1 > t){
                    t = t1;
                    longestMilk = max(longestMilk, t - s);
                }
            }
            else{
                longestNoMilk = max(longestNoMilk, s1 - t);
                s = s1;
                t = t1;
                longestMilk = max(longestMilk, t - s);
            }
        }
    }
    fout << longestMilk << " " << longestNoMilk << endl ;
    return 0;
}
