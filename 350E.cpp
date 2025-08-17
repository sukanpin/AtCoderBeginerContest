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
#define LLINF 9223372036854775807
#define MOD 998244353 
const int Move4[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int Move8[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

using mint = atcoder::modint998244353;

int main () {
    ll N,A,X,Y;
    cin >> N >> A >> X >> Y;

    map<ll,double> NumS;
    //Nから0に至るまでに通る可能性のある数
    //そこに至るまでの金額の期待値
    function<void(ll)> d = [&](ll n){
        if(NumS.count(n)>0){
            return; //すでに計算済み
        }else{
            NumS[n] = 1e18;
        }

        for(int i=2;i<=6;++i){
            d(n / i);
        }
    };
    d(N);
    
    NumS[0] = 0.0;//0に至るまでに必要な金額は0
    for(auto [num,p]: NumS){
        if(num == 0) continue;
        d(num);

        double temp = 6.0/5 * Y;
        for(int b=2;b<=6;++b) {
            temp += 1.0/5 * NumS[num / b];
        }

        NumS[num] = min(NumS[num], temp);
        NumS[num] = min(NumS[num], NumS[num / A] + X);
    }
    cout<<fixed<<setprecision(15)<<NumS[N]<< endl;
}