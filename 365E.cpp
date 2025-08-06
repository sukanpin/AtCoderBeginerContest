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
    ll N;cin>>N;
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
    }

    ll ans = 0;
    for(ll bit=0;bit<=27;++bit){//10^8<2^27
        ll Zero = 0;//単体を含む、xorが0になる数
        ll One = 0;//単体を含む、xorが1になる数
        ll Count = 0;//全体での数
        rep(i,N){
            if(A[i]&(1LL<<bit)){//Aiのそのbitが1
                swap(Zero,One);
                Count += One;
                One++;//これは単体での1なので含めない
            }else{//そのbitが0
                Zero++;
                Count += One;
            }
        }
        ans += Count* (1LL<<bit);//
    }
    cout<<ans<<endl;
}