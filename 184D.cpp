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
    ll A, B, C;
    cin >> A >> B >> C;
    double dA = A, dB = B, dC = C;
    vector DP(101, vector
        (101, vector<double>(101, 0.0)));
    //DP[a][b][c]:金貨がa枚、銀貨がb枚、銅貨がc枚のときの
    //残り回数の期待値
    rrep(a,100){
        rrep(b,100){
            rrep(c,100){
                double da = a, db = b, dc = c;
                double total = da + db + dc;
                DP[a][b][c] += (da / total) * (1 + DP[a+1][b][c]);
                DP[a][b][c] += (db / total) * (1 + DP[a][b+1][c]);
                DP[a][b][c] += (dc / total) * (1 + DP[a][b][c+1]);
            }
        }

    }
    cout<<fixed<<setprecision(15)<<DP[A][B][C] << endl;
}