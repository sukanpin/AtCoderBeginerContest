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

const int D = 60;
vector<mint> fact(D);
vector<mint> inv_fact(D);


// 階乗を求めて保存しておく
void fact_init(){
    fact[0] = 1;
    for (int d = 1; d < D; d++) fact[d] = fact[d - 1] * d;
    inv_fact[D - 1] = fact[D - 1].inv();
    for (int d = D - 1; d > 0; d--) inv_fact[d - 1] = inv_fact[d] * d;
}

// 二項係数を O(1)
mint bicom(int a, int b){
    if (a < b || b < 0) return 0;
    return fact[a] * inv_fact[a - b] * inv_fact[b];
}

int main () {
    ll T;cin>>T;
    // 前処理
    fact_init();
    while(T--){
        ll N,K;//1-Nまでの数でKこの1がある状態
        cin>>N>>K;
        mint ans = 0;

        mint L = 0;//これまでに決まったbit
        ll c = 0;//これまでにcこ
        for(int d = D-1;d >= 0;--d){
            if (N & (1ll << d)){
                mint way = bicom(d,K-c);
                mint ave = L;//1つ前までの1
                mint nokori = mint((1LL<<d) - 1);//残りの桁すべて
                //way* K-c /  * nokori
                if(d!=0){
                    ave += nokori *(K-c) * inv_fact[d] * fact[d-1];
                    //inv_fact[d]*fact[d-1]==1/d;
                }

                ans += way *ave;

                L += (1ll << d);
                c++;
            }
        }

        if(c==K){
            ans += N;
        }
        cout<<ans.val()<<endl;
    }
}