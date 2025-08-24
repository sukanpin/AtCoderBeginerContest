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
    std::cout << __cplusplus << std::endl;
    ll N;cin>>N;
    vector<ll> A(N);
    vector<ll> Keta(N);
    rep(i,N){
        cin>>A[i];
        Keta[i] = log10(A[i])+1;
    }
    vector RSumKeta(N+1,vector<ll>(11,0));
    //末端からみたそこまでの桁数の累積和  
    //<=10^9なので0-10桁まである
    rrep(i,N){
        RSumKeta[i] = RSumKeta[i+1];
        RSumKeta[i][Keta[i]]++;
    }


    mint ans = 0;
    rep(i,N){
        rep(j,11){//0-10桁まで確認する必要がある
            mint temp =  A[i];
            temp *= RSumKeta[i+1][j];
            temp *= ((mint)10).pow(j);
            ans += temp;
        }
        mint temp2 = A[i] * i;
        ans += temp2;
    }
    cout<<ans.val()<<endl;
}