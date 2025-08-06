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
    ll N,M;cin>>N>>M;
    vector Edge(N,vector<ll>());
    rep(i,M){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }

    vector<bool> NeedErase(N,false);
    ll ans = 0;
    ll connect_num = 0;
    atcoder::dsu UF(N);//たどり着けるか
    rep(i,N){
        connect_num ++;
        if(NeedErase[i])ans--;
        for(auto j:Edge[i]){
            //自分より下ならつなぐ
            if(j<i){
                if(!UF.same(i,j)){
                    UF.merge(i,j);
                    connect_num--;
                }
            }
            //自分より上なら消すべき頂点リストに加える
            else{
                if(!NeedErase[j]){
                    ans++;
                }
                NeedErase[j]=true;
            }
        }
        if(connect_num==1){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;//1-iを一塊にできないので
        }
    }
}