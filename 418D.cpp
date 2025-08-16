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
    string T;
    cin>>T;

    ll zeroCount = 0;
    vector<ll> A;
    ll count = 1;
    rep(i,N){
        if(T[i]=='0'){
            A.push_back(count);
            count=1;
            zeroCount++;
        }else{
            count++;
        }
    }
    if(count>0)A.push_back(count);

    if(zeroCount==0){//全て1のとき
        cout<<T.size()*(T.size()+1)/2<<endl;
        return 0;
    }

    vector<ll> SumA(A.size(),0);
    SumA[A.size()-1]=A[A.size()-1];
    SumA[A.size()-2]=A[A.size()-2];
    for(ll i=A.size()-3;i>=0;i--){
        SumA[i] = A[i] + SumA[i+2];
    }

    ll ans = 0;
    for(ll i=0;i<A.size();++i){
        ans += A[i]*(A[i]-1)/2;//最初の〇の分
        if(i<A.size()-2){
            ans += A[i]*SumA[i+2];//次の〇の分
        }
    }
    cout<<ans<<endl;
}