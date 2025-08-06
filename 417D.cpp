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
    vector<ll> P(N),A(N),B(N);
    vector<ll> Bsum(N+1,0);
    ll maxPA = 0;
    rep(i,N){
        cin>>P[i]>>A[i]>>B[i];
        if(i>0)Bsum[i]=Bsum[i-1];
        Bsum[i]+=B[i];

        maxPA = max(maxPA,P[i]+A[i]);
    }
    vector DP (N+1,vector<ll>(maxPA+1,0));
    
    //i番目のプレゼントを受け取った時点でテンションがjの時、最終的にいくつになるか
    for(int j=0;j<=maxPA;++j){
        DP[N][j]=j;
    }
    for(ll i=N;i>0;--i){
        for(ll j=0;j<=maxPA;++j){
            if(j<=P[i-1]){//喜び
                DP[i-1][j] = DP[i][j+A[i-1]];
            }else{
                DP[i-1][j] = DP[i][j-min(j, B[i-1])];
            }
        }
    }


    ll Q;cin>>Q;
    vector<ll> Tension(Q);
    rep(q,Q)cin>>Tension[q];

    rep(q,Q){
        ll tension=Tension[q];
        if(tension<=maxPA){
            cout<<DP[0][tension]<<endl;
        }else{
            auto itr = lower_bound(ALL(Bsum),tension-maxPA);
            if(itr==Bsum.end()){
                cout<<tension-Bsum[N-1]<<endl;
            }else{
                auto id = itr -Bsum.begin();
                cout<<DP[id+1][tension-min(tension,Bsum[id])]<<endl;
            }
            //初めてtension-Bsum[i]が500を切るところのidから調べる
        }
        
    }
}