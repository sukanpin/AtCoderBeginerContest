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
    ll N;
    cin >> N;
    map<ll,mint> DP;
    //DP[i] = 持っている整数がiの時、最終的にNになる確率
    function <mint(ll)> d = [&](ll n)-> mint
    {//現在nのとき、最終的にNになる確率
        if(n==N)return (mint)1;//すでにNなら確率は1
        if(DP.count(n))return DP[n];//メモ化再帰

        mint temp = 0;
        for(int i = 2;i<=6;++i){
            if(N%(n*i)==0){
                temp += d(n*i)/5;
            }
        }
        DP[n] = temp;
        return temp;
    };
    cout<<d(1).val()<< endl;
}