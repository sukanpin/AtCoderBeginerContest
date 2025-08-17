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
    ll N;cin >> N;

    using pll = pair<ll,ll>;//面の値、ダイス番号
    priority_queue<pll,vector<pll>> A;//最大値から順に取り出す
    rep(i,N) {
        rep(j,6) {
            ll a; cin >> a;
            A.emplace(a, i);//面の値、ダイス番号
        }
    }
    
    vector Count(N,6);//そのダイスの残った面の数
    
    mint allFace = ((mint)6).pow(N);//残りのダイスの面の数
    //あるダイスのある面が最大値となる場合の数
    //=他のダイスの面がその値以下である場合の数の積

    mint ans = 0;
    while(!A.empty()){
        auto [a, i] = A.top(); 
        A.pop();

        allFace *= ((mint)Count[i]).inv();
        //このダイスの残りの面の数を割れば、残りのダイスの面の数の積になる

        ans += a * allFace;//そのダイスの面の値 * 残りのダイスの面の数

        Count[i]--;//そのダイスの面を1つ使う
        allFace *= Count[i];//残りのダイスの面の数を掛ける
    }
    ans *= ((mint)6).pow(N).inv();// 6^Nで割る
    cout<< ans.val() << endl;
}