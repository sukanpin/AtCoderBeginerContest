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
    int N,M,L;
    cin>>N>>M>>L;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin>>A[i];
    vector<int> DP(M,INTINF);
    DP[0] = 0;
    for (int i = 0; i < L; i++) {
        vector<int> EP(M, INTINF);
        for(int j=0;j<M;j++){
            int cost = 0;
            for(int k = i; k < N; k += L){
                if(j >= A[k]) cost += j - A[k];
                else cost += j - A[k] + M;
                //mにするための操作回数
            }
            for(int k = 0; k < M; k++){
                chmin(EP[(k + j) % M], DP[k] + cost);
            }
        }
        DP = move(EP);
    }
    cout<<DP[0]<<endl;
}