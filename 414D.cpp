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
    ll N,M;cin>>N>>M;//家の個数、基地局の個数
    vector<ll> X(N);//家の位置
    rep(i,N){
        cin>>X[i];
    }
    sort(ALL(X));

    vector<ll> Sub(N-1);//次の家との差分
    rep(i,N-1){
        Sub[i] = X[i+1] - X[i];
    }
    sort(ALL(Sub));

    ll ans = 0;
    rep(i,N-M){//家に対して足りない基地局の個数
        ans += Sub[i];
    }
    cout<<ans<<endl;
}