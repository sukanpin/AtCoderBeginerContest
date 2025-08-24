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
    ll N,M;cin >> N>>M;
    //道路,所要時間
    //空港の場合はi->0をT時間、0->iを0時間とする
    const ll INF = LLONG_MAX;
    vector Dist(N+1, vector<ll>(N+1, INF));
    //各点から各点への最短距離
    rep(i,N+1)Dist[i][i]=0;

    rep(i,M){
        ll a,b,c;cin >> a>>b>>c;
        Dist[a][b]=min(Dist[a][b],c);
        Dist[b][a]=min(Dist[b][a],c);
    }
    ll K,T;cin >> K>>T;
    rep(i,K){
        ll d;cin >> d;
        Dist[d][0]=T;
        Dist[0][d]=0;
    }

    //ワーシャルフロイド法
    function<void(ll)> add = [&](ll k){
            rep(i,N+1){
                rep(j,N+1){
                    if(Dist[i][k]==INF)continue;
                    if(Dist[k][j]==INF)continue;
                    Dist[i][j]=min(Dist[i][j], 
                        Dist[i][k]+Dist[k][j]);
                }
            }
        };//辺の追加
    rep(k,N+1){
        add(k);
    }

    ll Q;cin >> Q;
    while(Q--){
        ll q;cin >> q;
        
        if(q==1){//道路
            ll x,y,t;cin >> x>>y>>t;
            Dist[x][y]=min(Dist[x][y],t);
            Dist[y][x]=min(Dist[y][x],t);
            add(x);
            add(y);
        }else if(q==2){//空港
            ll x;cin >> x;
            Dist[0][x]=0;
            Dist[x][0]=min(Dist[x][0],T);
            add(0);
            add(x);
        }else{
            ll ans = 0;
            for(int i=1;i<=N;++i){
                for(int j=1;j<=N;++j){
                    if(Dist[i][j]== INF)continue;
                    ans += Dist[i][j];
                }
            }
            cout<<ans<<endl;
        }
    }
}