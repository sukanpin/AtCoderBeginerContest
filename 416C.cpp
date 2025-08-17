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
    ll N,K,X;cin>>N>>K>>X;
    //K個連結したときの辞書順X番目
    vector<string> S(N);
    rep(i,N)cin>>S[i];

    vector<string> T;
    function<void(ll,ll,string)> f 
        = [&](ll n,ll k,string U){

        U += S[n];

        if(k == 0){
            T.push_back(U);
            return;
        }

        rep(i,N){
            f(i,k-1,U);
        }
    };

    rep(i,N){
        f(i,K-1,"");
    }
    sort(ALL(T));

    cout<<T[X-1]<<endl;
}