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
    ll T;cin>>T;
    while(T--){
        //入力
        ll N;cin>>N;//長さ2^N
        ll length = pow(2,N);
        vector<ll> P(length);
        rep(i,length){
            cin>>P[i];
        }
        using vll = vector<ll>;
        function <vll(vll)> solve = [&](vll X) -> vll{
            if(X.size()<=1)return X;
            vll L(X.begin(), X.begin() + X.size()/2);
            vll R(X.begin() + X.size()/2, X.end());
            L = solve(L);
            R = solve(R);

            vll ans;
            if(L[0]<R[0]){
                ans.insert(ans.end(),ALL(L));
                ans.insert(ans.end(),ALL(R));
            }else{//入れ替え
                ans.insert(ans.end(),ALL(R));
                ans.insert(ans.end(),ALL(L));
                
            }
            return ans;
        };
        auto Ans = solve(P);
        rep(i,length){
            cout<<Ans[i];
            if(i==length-1){
                cout<<endl;
            }else{
                cout<<" ";
            }
        }
    }
}