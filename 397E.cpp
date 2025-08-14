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
#define INTINF 2147483647 
const int Move4[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int Move8[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

using mint = atcoder::modint998244353;

int main () {
    ll N,K;cin>>N>>K;
    vector G(N*K,vector<ll>());
    rep(i,N*K-1){
        ll u,v;cin>>u>>v;u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    function<ll(ll,ll)> DFS = [&](ll now,ll prev)->ll{
        ll temp = 1;//自分自身
        ll c = 0;//追加する枝の本数
        for(auto next:G[now]){if(next!=prev){
            ll d = DFS(next,now);
            if(d==-1)return -1;//元が不適なのですでに不適
            if(d>0)c++;//枝数を追加
            temp += d; 
        }}

        if(c<=1){//枝の起点か中間か終点
            if(temp==K)return 0;
            else return temp;
        }else if(c==2){//2本なので、ちょうどKならOK
            if(temp==K)return 0;
            else return -1;
        }else{//3本以上の枝なのでまとめられない
            return -1;
        }
    };

    if(DFS(0,-1)!=-1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}