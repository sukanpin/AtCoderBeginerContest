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
    ll N;cin>>N;
    vector<ll> R(N),C(N);
    rep(i,N){
        cin>>R[i]>>C[i];
    }
    sort(ALL(R));
    ll t = R[N-1] - R[0];
    sort(ALL(C));
    ll d = C[N-1] - C[0];
    ll m = max(t,d);
    ll ans = m/2 + m % 2;
    cout<<ans<<endl;
}