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
    vector A(N,vector<ll>(6));
    vector<ll> Num;
    Num.push_back(0);
    rep(i,N){
        rep(j,6){
            cin>>A[i][j];
            Num.push_back(A[i][j]);
        }
    }
    sort(ALL(Num));
    Num.erase(unique(ALL(Num)), Num.end());
    ll Size = Num.size();

    vector DP(N+1,vector<mint>(Size+1,0));//i番目まで確認し、最大の目がjである確率 * 6 ^ N
    DP[0][0]=1;
    rep(i,N){
        rep(j,Size+1){
            if(DP[i][j]==0)continue;
            rep(k,6){
                if(Num[j]>A[i][k]){
                    DP[i+1][j]+= DP[i][j];
                }else{
                    auto id = lower_bound(ALL(Num),A[i][k])-Num.begin();
                    DP[i+1][id]+= DP[i][j];
                }
            }
        }
    }
    mint ans = 0;
    rep(j,Size+1){
        // j * DP[N][j]/(6^N) が各期待値
        mint temp = j;
        temp *= DP[N][j];
        temp /= mint(6).pow(N);
        ans += temp;
    }
    cout<<ans.val()<<endl;
}