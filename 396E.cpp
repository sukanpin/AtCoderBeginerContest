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
    vector<ll> X(M),Y(M),Z(M);
    rep(i,M){
        cin>>X[i]>>Y[i]>>Z[i];
        X[i]--;Y[i]--;
    }
    ll max = 30;//10^9<2^30
    vector A(N,vector<ll>(max,-1));//未定の場合は-1
    for(ll bit=29;bit>=0;--bit){//1<<0-1<<29
        vector<vector<pair<ll,bool>>> Relation(N);
        //同じなら0,違うなら1

        rep(i,M){
            //そのbitが立っていれば
            //A X[i]とA Y[i]のbit番目は違う
            auto t = (Z[i] & (1<<bit))>0;
            Relation[X[i]].emplace_back(Y[i], t);
            Relation[Y[i]].emplace_back(X[i], t);
        }

        vector<ll> Visit(N,-1);
        //A[i]が確定していれば1か0、していなければ-1
        rep(i,N){
            if(Visit[i]!=-1)continue;
            vector<ll> TempOne;
            //最初に調べたものを1としたとき、1となるもの
            vector<ll> TempZero;
            //最初に調べたものを1としたとき、0となるもの

            queue<pair<ll,ll>> Q;
            Q.push({i,1});
            while(!Q.empty()){
                auto [now,num] = Q.front();
                Q.pop();
                if(Visit[now]!=-1){//すでに決まっていれば
                    if(Visit[now]!=num){//矛盾が生じたら
                        cout<<-1<<endl;
                        return 0;
                    }
                    continue;
                }
                Visit[now]=num;
                if(num==1)TempOne.push_back(now);
                else TempZero.push_back(now);

                for(auto [next,nextnum]:Relation[now]){
                    Q.push({next,num^nextnum});
                }
            }

            if(TempZero.size()<TempOne.size()){
                swap(TempOne,TempZero);
            }

            for(auto a:TempOne)A[a][bit]=1;
            for(auto a:TempZero)A[a][bit]=0;
            //A[t][bit];
        }
    }

    rep(i,N){
        ll ans = 0;
        for(ll bit=29;bit>=0;--bit){
            if(A[i][bit]==1){
                ans += 1<<bit;
            }
        }
        cout<<ans;
        if(i==N-1)cout<<endl;
        else cout<<" ";
    }
}