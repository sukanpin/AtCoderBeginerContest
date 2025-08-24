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
#include <bits/basic_string.h>

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

struct Node{
    public:
    char c=' ';//この文字
    map<char,ll> next;//次の文字とその位置
    ll count=0;//この文字の個数
    Node(){
    }
    Node(char c_){
        c=c_;
        count = 1;
    }
};
class trie{
    vector<Node> Nodes;
public:
    trie(){
        Nodes.push_back(Node());//rootノード
    }
    void AddString(string S){
        ll now = 0;//rootノードから始める
        rep(i,S.size()){
            ll next;
            if(Nodes[now].next.contains(S[i])){
                next = Nodes[now].next[S[i]];//次のノード
                Nodes[next].count++;
                now = next;
            }else{
                next = Nodes.size();
                Nodes[now].next[S[i]]=next;//次のノードへの経路
                Nodes.push_back(Node(S[i]));
                //新規作成
            }
            now = next;
        }
    }
    ll Answer(){
        ll ans = 0;
        queue<ll> Q;
        Q.push(0);
        while(!Q.empty()){
            auto q = Q.front();
            Q.pop();
            ll count = Nodes[q].count;
            if(count>=2) ans += count*(count-1)/2;
            for(auto [c,next]:Nodes[q].next){
                Q.push(next);
            }
        }
        return ans;
    }
};

int main () {
    ll N;cin>>N;
    vector<string> S(N);
    rep(i,N)cin>>S[i];

    trie Trie;
    rep(i,N){
        Trie.AddString(S[i]);
    }

    cout<<Trie.Answer()<<endl;
}