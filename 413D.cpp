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
        ll N;cin>>N;
        vector<ll> A(N);
        rep(i,N){
            cin>>A[i];
        }
        if(ranges::count(A,A[0])==N){
            cout<<"Yes"<<endl;
            continue;
        }
        ll a = ranges::count(A,A[0]);
        ll b = ranges::count(A,-A[0]);
        if(min(a,b)==N/2&&a+b==N){
            cout<<"Yes"<<endl;
            continue;
        }

        sort(ALL(A), [](auto const& lhs, auto const& rhs) {
            return abs(lhs) < abs(rhs); 
        });
        bool flag = true;
        rep(i,N-2){
            if(A[i]*A[i+2]!=A[i+1]*A[i+1]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}