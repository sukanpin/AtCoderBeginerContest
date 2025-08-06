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
    vector<ll> A(N);
    vector<ll> X(N);
    map<ll,ll> Y;
    rep(i,N){
        cin>>A[i];
        X[i]=i+A[i];

        if(Y.count(i-A[i])>0){
            Y[i-A[i]]++;
        }else{
            Y[i-A[i]]=1;
        }
    }
    sort(ALL(X));
    ll ans = 0;
    rep(i,N){
        if(Y[X[i]]>0){
            ans += Y[X[i]];
        }
    }
    cout<<ans<<endl;
}