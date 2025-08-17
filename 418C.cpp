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
    ll N,Q;cin>>N>>Q;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(ALL(A));
    ll maxA = A[N-1];
    vector<ll> X(maxA+1,0);
    X[1]=1;//1個とるなら当然1
    ll count = 0;
    for(ll i=1;i<maxA;++i){
        count += A.end() - lower_bound(ALL(A),i);
        X[i+1] = count + 1;
    }

    while (Q--) {
        ll b;
        cin >> b;
        if (b > maxA) {
            cout << -1 << endl;
        } else {
            cout << X[b] << endl;
        }
    }
}