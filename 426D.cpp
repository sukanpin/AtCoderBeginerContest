using namespace std;
#include <bits/stdc++.h>
#include <vector>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<string>
#include<deque>
#include<queue>
#include <numeric>
#include <set>
#include <utility>
#include <stdlib.h>
#include <bitset>
#include <atcoder/all>

#define rep(i,N) for(long long i=0; i<N;++i)
#define rrep(i,N) for(long long i=N-1; i>=0; --i)
#define ALL(a)  (a).begin(),(a).end()
#define ll long long
#define ull unsigned long long
#define ld long double
#define INTINF 2147483647 
#define MOD 998244353 
const int Move4[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int Move8[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }

using mint = atcoder::modint998244353;

int main () {
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        string S;cin>>S;

        ll longest0=0,longest1=0;
        ll cnt0=0,cnt1=0;
        ll sum0=0,sum1=0;
        for(auto c:S){
            if(c=='0'){
                sum0++;

                cnt0++;
                cnt1=0;
                longest0=max(longest0,cnt0);
            }else{
                sum1++;

                cnt1++;
                cnt0=0;
                longest1=max(longest1,cnt1);
            }
        }
        
        ll to0 = (sum0-longest0)*2+sum1;
        ll to1 = (sum1-longest1)*2+sum0;
        cout<<min({to0,to1})<<endl;
    }
    
}