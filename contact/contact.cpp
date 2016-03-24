/*
ID: guangli1
PROG: contact
LANG: C++11  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#define LL unsigned long long
#define inf 
#define INF (~(1<<31))
using namespace std;
int A, B;
int cnt[1<<13] = {0};
int n;
#define tun(a, i) ((1<<i)-1 + (((1<<i)-1)&a))
class cmp{
public:
    bool operator()(const pair<int, int> & lhs, const pair<int, int> &rhs) const {
        if(lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second))
            return true;
        return false;
    }
};
class tool{
    public:
    unsigned int a = 0;
    int len = 0;
    void read(char c){
        a <<= 1;
        len++;
        if(c == '1')
            a++;
        for(int i = A; i<= len && i <= B; i++)
            cnt[tun(a, i)]++;
    }
    string binary(int x)
    {
        string s;
        do
        {
            s.push_back('0' + (x & 1));
        } while (x >>= 1);
        reverse(s.begin(), s.end());
        return s;
    }
    string tostring(int i){
        int l = (int)log2((double)(i+1));
        int n = i - ((1<<l)-1);
        string s = binary(n);
        if(s.size() < l){
            string s1(l-s.size(), '0');
            return s1 + s;
        }
        return s;
    }
    void out(){
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> Q;
        for(int i = (1<<A)-1; i < (1<<(B+1))-1; i++)
            Q.push(make_pair(cnt[i], i));
        for(int i = 0; i < n && !Q.empty(); i++){
            auto p = Q.top();
            Q.pop();
            int c = p.first;
            cout << c << endl;
            cout << tostring(p.second);
            int index = 1;
            while(!Q.empty()){
                auto p = Q.top();
                if(p.first != c) break;
                Q.pop();
                index++;
                cout << " " << tostring(p.second);
                if(index % 6 == 0)
                    cout << "\n";
            }
            if(index%6) 
                cout << endl;
        }
    }
};
int main() {
    freopen("contact.out", "w", stdout);
    freopen("contact.in", "r", stdin);
    scanf("%d %d %d\n", &A, &B, &n);
    tool t;
    char c;
    while(EOF != scanf("%c", &c)){
        if(c == '0' || c == '1')
            t.read(c);
    }
    t.out();
    //cout << tun(2,3) << "  " << (1<<3)-1 << " " << (((1<<3)-1)&2);
    //cout  << ((1<<3)-1 + (((1<<3)-1)&2));
    return 0;
}
