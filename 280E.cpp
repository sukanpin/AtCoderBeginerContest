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
    ll N, P;
    cin >> N >> P;
    vector<mint> DP(N + 1, 0);
    //DP[i] = 敵が体力iの時、残りの回数の期待値
    //体力0の時は0
    for(int i = 1;i<=N;++i){
        if(i>=2){
            DP[i] += (mint)P/100*(DP[i-2]+1);
        }else{
            DP[i] += (mint)P/100*(DP[i-1]+1);
        }
        DP[i] += (mint)(100-P)/100*(DP[i-1]+1);
    }
    cout<<DP[N].val() << endl;
}