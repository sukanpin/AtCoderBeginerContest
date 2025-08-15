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
    vector<pair<ll,ll>> XY(N);
    rep(i,N){
        cin>>XY[i].first>>XY[i].second;
    }
    sort(ALL(XY));//これでXY[i].x<=XY[i+1].xが保証される

    map<pair<ll,ll>,map<ll,ll>> Slopes;
    //傾きごとの直線リスト　長さをmapで分類
    //
    rep(i,N){
        for(ll j=i+1;j<N;++j){
            auto [xi,yi] = XY[i];
            auto [xj,yj] = XY[j];
            ll x = xj - xi;//>=0
            ll y = yj - yi;

            pair<ll,ll> pl;
            ll length;
            if(x==0){
                pl = {0,1};
                length = abs(y);
            }else if(y==0){
                pl = {1,0};
                length = abs(x);
            }else{
                ll g = gcd(x,y);//最大公約数で割る
                pl = {x/g,y/g};
                length = abs(x)+abs(y);
            }

            if(Slopes[pl].count(length)>0){
                Slopes[pl][length]++;
            }else{
                Slopes[pl][length]=1;
            }
        }
    }

    ll ans = 0;
    ll sub = 0;
    for(auto [pl,lenmap]:Slopes){//その傾きの中で
        ll x = 0;
        for(auto [length,num]:lenmap){//各長さがnum個
            sub += num*(num-1)/2;//同じ長さのものが数本あれば追加
            x+=num;
        }
        ans += x*(x-1)/2;
    }
    cout<<ans-(sub/2)<<endl;
}