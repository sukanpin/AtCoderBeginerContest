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
    int N;cin>>N;
    vector G(N,vector<int>());
    rep(i,N-1){
        int u,v;cin>>u>>v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<tuple<int,int,vector<int>>> Q;//now,prev,道筋
    Q.push({0,-1,{}});//頂点
    vector Parents(N,vector<int>());//各点の点0からの道順
    while(!Q.empty()){
        auto [now,prev,verVec] = Q.front();
        Q.pop();
        verVec.push_back(now);
        Parents[now]=verVec;
        for(auto next:G[now]){
            if(next!=prev){
                Q.push({next,now,verVec});
            }
        }
    }

    set<pair<int,int>> Odd;//奇数距離の組み合わせ
    vector Dist(N,vector<int>(N,-1));//i-jの距離
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            int iLen = Parents[i].size();
            int jLen = Parents[j].size();
            int commonLen = 0;
            rep(k,min(iLen,jLen)){
                if(Parents[i][k]!=Parents[j][k]){
                    break;
                }
                commonLen++;
            }
            Dist[i][j] = (iLen-1)+(jLen-1) - ( (commonLen-1)*2);
            if(Dist[i][j]!=1&&Dist[i][j]%2==1){//1以外の奇数なら偶閉路にできる  
                Odd.insert({i,j});
            }
        }
    }

    if(Odd.size()%2==1){//先行
        cout<<"First"<<endl;
    }else{//後攻
        cout<<"Second"<<endl;
    }
    while(!Odd.empty()){
        if(Odd.size()%2==1){//自分の手番
            auto [i,j] = *Odd.begin();
            cout<<i+1<<" "<<j+1<<endl;
            Odd.erase({i,j});
        }else{//相手の手番
            int i,j;
            cin>>i>>j;
            if(i==-1&&j==-1){
                return 0;
            }
            i--;j--;
            Odd.erase({i,j});
        }
    }
}