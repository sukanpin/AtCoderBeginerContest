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
#include <bits/basic_string.h>

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
    ll N,M,X;cin>>N>>M>>X;
    vector G(2*N,vector<pair<ll,ll>>());
    rep(i,M){
        ll u,v;cin>>u>>v;u--;v--;
        G[u].emplace_back(v,1);
        G[v+N].emplace_back(u+N,1);
    }
    rep(i,N){
        G[i].emplace_back(i+N,X);
        G[i+N].emplace_back(i,X);
    }

    vector<ll> Dist(2*N,LLONG_MAX);
    using pll = pair<ll,ll>;//距離、番号
    priority_queue<pll,vector<pll>,greater<pll>> Q;
    Dist[0]=0;
    Q.emplace(0,0);//距離0、頂点0から開始
    while(!Q.empty()){
        auto [dist,now] = Q.top();
        Q.pop();
        if(Dist[now]<dist)continue;
        for(auto [next,w]:G[now]){
            ll d = Dist[now]+w;
            if(d<Dist[next]){
                Dist[next]=d;
                Q.emplace(d,next);
            }
        }
    }
    cout<<min(Dist[N-1],Dist[2*N-1])<<endl;
}