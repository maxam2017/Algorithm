#include <iostream>
#include <queue>
#include <cstring>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int** graph;
int parent[64]={0};
int n,v;
bool visit[64]={false};
bool inline min(int &a,int &b){
    return a<b;
}
bool bfs(int r[64][64]){
    memset(visit,0,sizeof(visit));
    queue<int>q;
    q.push(0);
    visit[0] = true;
    parent[0] = -1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(!visit[i] && r[a][i]>0){
                q.push(i);
                visit[i]=true;
                parent[i] = a;
            }
        }
    }
    return visit[v-1];
}
int ford(){
    int r[64][64];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            r[i][j]=graph[i][j];
        }
    }
    int max = 0;
    while (bfs(r)){
        int flow = 1e9;
        for(int i=v-1;i>0;i=parent[i]){
            if(flow > r[parent[i]][i])
                flow = r[parent[i]][i];
        }
        for(int i=v-1;i>0;i=parent[i]){
            r[parent[i]][i] -= flow;
            r[i][parent[i]] += flow;
        }
        max += flow;
    }
    return max;
}

int main() {
    int t,n,m;
    cin>>t;
    while(t--){
        int s = 0;
        cin>>n>>m;
        v = 2+n+m;
        graph=new int*[v]();
        for(int i=0;i<v;i++){
            graph[i] = new int[v]();
        }
        for(int i=0;i<n;i++){
            cin>>graph[0][i+1];
            s+=graph[0][i+1];
        }
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<v-1;j++){
                graph[i][j]=1;
            }
        }
        for(int i=0;i<m;i++){
            cin>>graph[n+1+i][v-1];
        }
        
        if(ford()<s)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}