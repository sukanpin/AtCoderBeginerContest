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
    ll N;cin >> N;
    vector A(N,vector<ll>(6));
    set<ll> uA;
    rep(i,N) {
        rep(j,6) {
            cin >> A[i][j];
            uA.insert(A[i][j]);
        }
    }
    vector<ll> uA_vec(ALL(uA));
    
    vector DP(N+1, vector<ll>(uA_vec.size()+1, 0));
    //i番目まで確認したとき、最大値がuA_vec[j-1]
    //である確率
}