#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int n,q;
vector<pair<int, int>>adj[1001];
int h[1001],parent[1001];
bool inq[1001]={false};
int eg[1001]={0};
int path[1001][1001];
int visit[1001];
struct Node {int b, d;};
bool operator<(Node n1, Node n2) {
    return n1.d > n2.d;
}

void label_correcting(int source){
    h[source]=0;
    for(int i=1;i<=n;i++){
        h[i]=1e9;
    }
    parent[source]=source;
    queue<int> q;
    q.push(source);
    inq[source]=true;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        inq[a]=false;
        if(inq[parent[a]])
            continue;
        for(vector<pair<int, int>>::iterator it=adj[a].begin();it!=adj[a].end();it++){
            int b = (*it).first,w = (*it).second;
            if(h[a]!=1e9 && h[a]+w<h[b]){
                h[b] = h[a]+w;
                parent[b] = a;
                eg[b]=eg[a]+1;
                if(eg[b]>n)
                    return;
                if(!inq[b]){
                    q.push(b);
                    inq[b]=true;
                }
            }
        }
    }
}
void dijkstra(int source){
    for (int i=1; i<=n; i++) visit[i] = false;
    for (int i=1; i<=n; i++) path[source][i] = 1e9;
    priority_queue<Node> pq;
    path[source][source] = 0;
    parent[source] = source;
    pq.push((Node){source, path[source][source]});
    
    for (int i=0; i<n; i++){
        int a = -1;
        while (!pq.empty() && visit[a = pq.top().b])
            pq.pop();
        if (a == -1) break;
        visit[a] = true;
        for(vector<pair<int, int>>::iterator it=adj[a].begin();it!=adj[a].end();it++){
            int b = (*it).first,w =(*it).second;
            if(!visit[b] && path[source][a]+w<path[source][b]){
                path[source][b] = path[source][a]+w;
                parent[b] = a;
                pq.push( (Node){b, path[source][b]});
            }
        }
    }
}

void johnson(){
    for(int i=1;i<=n;i++){
        adj[0].push_back(make_pair(i,0));
    }
    label_correcting(0);
    
    for(int i=1;i<=n;i++){
        for(vector<pair<int, int>>::iterator it=adj[i].begin();it!=adj[i].end();it++){
            (*it).second += h[i]-h[(*it).first];
        }
    }

    bool dodo[1001]={false};
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(!dodo[x]){
            dodo[x]=true;
            dijkstra(x);
        }
        if(path[x][y] == 1e9)
            cout<<"no path"<<endl;
        else
            cout<<path[x][y]-h[x]+h[y]<<endl;
    }

}
int main() {
    int m;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int s,t,r;
        cin>>s>>t>>r;
        adj[s].push_back(make_pair(t,r));
    }
    johnson();
    return 0;
}