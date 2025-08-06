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
#define INTINF 2147483647 
const int Move4[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int Move8[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

using mint = atcoder::modint998244353;

int main () {
    ll N;cin>>N;
    ll MOD = 1e8;
    vector<ll> A(N);
    ll ans = 0;
    rep(i,N){
        cin>>A[i];
        ans += A[i]*(N-1);
    }
    sort(ALL(A));
    rep(i,N){
        if(A[i]>=MOD)ans -= MOD;
        auto num =A.end()
            -lower_bound(A.begin()+i+1,A.end(),MOD-A[i]);
        //超える個数
        ans -= MOD * num;
    }
    cout<<ans<<endl;
}