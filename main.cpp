#include <iostream>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;
const int MAX=1e6;

struct edge{
    int to,w;
};
struct node {
    int dis, u;
    bool operator>(const node& a) const { return dis > a.dis; }
};
vector<edge> e[MAX];
int dis[MAX],vis[MAX];
priority_queue<node, vector<node>, greater<> > q;

void dijkstra(int s){
    memset(dis,63,sizeof(dis));
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:e[u]){
            int v=ed.to, w=ed.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}


int main() {
    int n,m,S,T;
    cin>>n>>m>>S>>T;
    int x,y,z;
    for(size_t _=0;_<m;++_){
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    dijkstra(S);
    cout<<dis[T];
}
