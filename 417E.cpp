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


constexpr long long INF = (1LL << 60);

// 辺の情報
struct Edge
{
	// 行先
	int to;

	// コスト
	int cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.2 最短経路を再構築する)
// 頂点 startIndex から頂点 targetIndex までの最短経路を path に格納する
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph& graph, std::vector<long long>& distances, int startIndex, int targetIndex, std::vector<int>& path)
{
	// 直前の頂点を記録する配列
	std::vector<int> p(distances.size(), -1);

	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
	q.emplace((distances[startIndex] = 0), startIndex);

	while (!q.empty())
	{
		
	}
}

int main () {
    ll T;cin>>T;
    while(T--){
        ll N,M,X,Y;cin>>N>>M>>X>>Y;
        X--;Y--;

        vector G(N,vector<ll>());//次の頂点=重み
        rep(i,M){
            ll u,v;cin>>u>>v;
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector Distances(N,vector<ll>());//各頂点までの距離
        vector<ll> p(Distances.size(), -1);//直前の頂点を記録する配列

        using Pair = std::pair<vector<ll>, ll>;//distance,from
        priority_queue<Pair, std::vector<Pair>, std::greater<Pair>>Q;
        Q.emplace(vector<ll>(1,X),X);

        while(!Q.empty()){
            auto [distance,from] = Q.top();
            Q.pop();

            // 最短距離でなければ処理しない
            if (distance[0]!=X)continue;
            if (Distances[from].size()>0&&Distances[from] < distance)continue;

            // 現在の頂点からの各辺について
            for(auto e:G[from]){
                // to までの新しい距離

                auto newDistance = distance;
                if(find(ALL(newDistance),e)!=newDistance.end())continue;
                newDistance.push_back(e);

                // d が現在の記録より小さければ更新
                if (newDistance < Distances[e]||Distances[e].size()==0)
                {
                    // 直前の頂点を記録
                    p[e] = from;
                    Distances[e] = newDistance;
                    Q.emplace(Distances[e],e);
                }
            }
        }

        for(auto a:Distances[Y]){
            cout<<a+1<<" ";
        }
        cout<<endl;

    }
    
    
}