/*
ID: guangli1
PROG: friday
LANG: C++   
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
int luck( int year){
    if(year%4 == 0 && (year%100 != 0 || year%400 == 0))
        return 1;
    return 0;
}
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int N; 
    fin >> N;
    int days[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                 {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int cnt[7] = {0};
    int base = (2 + 13 - 1)%7;
    for(int i = 0; i < N; i++){
        int year = 1900+i;
        int index = luck(year);
        ++cnt[base];
        for(int month = 0; month < 11; month++){
            base = (base + days[index][month])%7;
            ++cnt[base];    
        }
        base = (base + 31) % 7;
    }
    for(int i = 0; i < 6; i++)
        fout << cnt[i]<< " ";
    fout << cnt[6] << "\n";
    return 0;
}
