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
    ll T; cin >> T;
    while(T--){
        ll N,M; cin >> N >> M;
        ll ans = 0;

        multiset<ll> A;
        rep(i,N){
            ll a; cin >> a;
            a%= M;
            A.insert(a);
            ans += a;
        }

        vector<ll> B(N);
        rep(i,N){
            cin >> B[i];
            B[i] %= M;
            ans += B[i];
        }
        sort(ALL(B),greater<ll>());

        rep(i,N){
            auto itr = A.lower_bound(M-B[i]);
            if(itr == A.end()) {
                //これ以上消せない
                break;
            } else {
                A.erase(itr);
                ans -= M;
            }
        }
        cout<<ans<<endl;
    }
}