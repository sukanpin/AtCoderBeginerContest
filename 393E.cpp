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
    vector<ll> A(N);
    rep(i,N)cin>>A[i];

    ll M = *max_element(ALL(A));
    vector<ll> Num(M+1),Multi(M+1),Ans(M+1);
    //Aに含まれるiの個数、Aに含まれるiの倍数の個数、答え

    for(auto a:A){
        Num[a]++;
    }

    for(ll d=1;d<=M;++d){
        for(ll mul=d;mul<=M;mul+=d){
            Multi[d] += Num[mul];
        }
    }

    for(ll d=1;d<=M;++d){
        if(Multi[d]<K)continue;//Aに含まれるdの倍数の個数がK未満なら最小公倍数になりえない

        for(ll mul=d;mul<=M;mul+=d){
            Ans[mul] = max(Ans[mul],d);//大きければ大きいほどよい
        }
    }
    
    for(auto a:A){
        cout<<Ans[a]<<endl;
    }
}