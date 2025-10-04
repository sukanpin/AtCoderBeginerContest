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

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;
S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main () {
    ll N,Q;cin>>N>>Q;
    vector<ll> A(N+1);//バージョンがi以下の台数
    rep(i,N+1)A[i]=i;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    while(Q--){
        ll x,y;cin>>x>>y;
        ll n = seg.get(x);//x以下の個数
        if(n<0){
            cout<<0<<endl;
            continue;
        }
        cout<<n<<endl;
        seg.apply(0,y,-n);
    }
}