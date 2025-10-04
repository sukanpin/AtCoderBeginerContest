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
#define INTINF 1000000001
#define MOD 998244353 
const int Move4[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int Move8[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
using mint = atcoder::modint998244353;
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }

int main () {
    ll X;cin>>X;
    //(2n+2m+1)(2n-2m+1)=4X-1
    ll A = 4*X-1;

    vector<ll> Ans;
    // 各整数 i が N の約数かどうかを調べる
    for (ll i = 1; i * i <= abs(A); ++i) {
        // i が N の約数でない場合はスキップ
        if (A % i != 0) continue;

        ll j=A/i;
        //i,N/iが約数
        if((j-i-2)%4==0){
            Ans.push_back((j-i-2)/4);
        }
        if((i-j-2)%4==0){
            Ans.push_back((i-j-2)/4);
        }
        
    }

    sort(ALL(Ans));

    cout<<Ans.size()<<endl;
    rep(i,Ans.size()){
        cout<<Ans[i];
        if(i==Ans.size()-1)cout<<endl;
        else cout<<" ";
    }
}