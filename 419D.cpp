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
using mint = atcoder::modint998244353;

int main () {
    ll N,M;cin>>N>>M;
    string S;cin>>S;
    string T;cin>>T;
    vector<ll> SwapNum(N+1,0);//交換された回数
    rep(i,M){
        ll L,R;
        cin>>L>>R;
        L--;R--;
        SwapNum[L]++;
        SwapNum[R+1]--;
    }
    rep(i,N-1){
        SwapNum[i+1] += SwapNum[i];
    }
    rep(i,N){
        if(SwapNum[i] % 2 == 1) {
            cout<<T[i];
        }else{
            cout<<S[i];
        }
    }
    cout<<endl;
}