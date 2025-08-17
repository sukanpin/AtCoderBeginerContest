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
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(ALL(A));
    vector<ll> Num;//uniqueなA[i]
    vector<ll> Count;//A[i]の個数
    ll num=A[0];
    ll count = 1;
    for(ll i=1;i<N;++i){
        if(num==A[i]){
            count++;
        }else{
            Num.push_back(num);
            Count.push_back(count);
            num = A[i];
            count = 1;
        }
    }
    Num.push_back(num);
    Count.push_back(count);

    vector<ll> SumCount;//A[i]の個数
    rep(i, Num.size()) {
        if (i == 0) {
            SumCount.push_back(Count[i]);
        } else {
            SumCount.push_back(SumCount[i - 1] + Count[i]);
        }
    }
    ll NewN = Num.size();
    ll ans = 0;
    rep(i,NewN){
        ans += Count[i]*(Count[i]-1)/2;
        if(i==NewN-1)continue;
        ll left = i+1,right;
        ll x;//x倍の範囲[left,right)を調べる
        while(1){
            x=Num[left]/Num[i];
            auto itr = lower_bound(Num.begin()+left,Num.end(),
                Num[i] * (x+1));
            right = itr - Num.begin();
            
            ans += (SumCount[right-1]-SumCount[left-1])*x*Count[i];
            
            if(itr ==Num.end())break;
            left = right;
        }
    }
    cout << ans << endl;
}