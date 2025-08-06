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
    ll N,A,B;cin>>N>>A>>B;
    vector<ll> D(N);
    rep(i,N){
        ll d;
        cin>>d;
        D[i] = d % (A+B);
    }
    sort(ALL(D));

    bool flag = false;
    rep(i,N){
        ll now=D[i];
        ll next;
        if(i==N-1){
            next = D[0] + A + B;
        }else{
            next = D[i+1];
        }
        if(next-now-1>=B)flag = true;
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}