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
    string S;cin>>S;
    string T;cin>>T;
    if(S==T){//S==T→0
        cout<<0<<endl;
        return 0;
    }
    vector<int> To(26,-1);//移動先がなければ-1のまま
    rep(i,N){
        int from = S[i] - 'a';
        int to = T[i] - 'a';
        if(To[from]!=-1&&To[from]!=to){//変換先が二つ以上あれば-1を返す
            cout<<-1<<endl;
            return 0;
        }
        if(To[from]==-1){
            To[from]=to;//異なるものに変化する必要があれば入力
        }
    }

    auto temp = To;
    sort(ALL(temp));
    auto loopflag = true;
    rep(i,26){
        if(temp[i]!=i)loopflag=false;
    }
    if(loopflag){//26個で循環→-1を返す
        cout<<-1<<endl;
        return 0;
    }

    vector<bool> IsTo(26,false);//その文字が変換先にあるならtrue
    atcoder::dsu UF(26);//連結成分
    int ans = 0;
    rep(from,26){
        int to = To[from];
        if(to!=-1&&to!=from){//向かう先があるなら
            ans ++;
            UF.merge(from,to);
            IsTo[to] = true;
        }
    }
    
    for(auto g:UF.groups()){//連結成分に分けて
        bool flag = true;
        for(auto from:g){
            if(!IsTo[from]){
                flag = false;
            }
        }
        if(flag){//駒を逃がせなければ（=すべての駒に移動先がある＝連結成分内に移動先があるなら）+1
            ans ++;
        }
    }
    
    cout<<ans<<endl;
}