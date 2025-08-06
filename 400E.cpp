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

const ll MAX = pow(10,6);
vector<ll> isp(MAX+1, 0);
vector<ll> Two;
int main () {
    isp[0] = 1;
    isp[1] = 1;
    for (ll i=2; i<=MAX; i++) {
        if (isp[i]==2){
            Two.push_back(i);
        }
        if (isp[i]==0){//素数なら
            for(ll j = i; j <= MAX; j += i){
                isp[j]++;
            }
        }
    }
    sort(ALL(Two));
    ll Q;
    cin>>Q;
    while(Q--){
        ll A;
        cin>>A;
        ll sqA = (ll)sqrt(A);
        ll ok = -1;
        ll over = Two.size();
        while((over-ok)>1){
            ll mid = (ok+over)/2;
            if(Two[mid]<=sqA){//okの場合
                ok = mid;
            }else{//overの場合
                over = mid;   
            }
        }
        cout<<Two[ok]*Two[ok]<<endl;
    }
}