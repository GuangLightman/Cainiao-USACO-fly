/*
ID: guangli1
PROG: ride 
LANG: C++11   
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int help(char *s){
    int x = 1;
    for(int i = 0; i< 6 && s[i] != '\0'; i++)
        x *= s[i]-'A'+1;
    return x%47;
}
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    const int n = 8;
    char a[8], b[8];
    fin >> a >> b;
    if(help(a) == help(b))
        fout << "GO" << endl;
    else
        fout << "STAY" <<endl;
    return 0;
}
