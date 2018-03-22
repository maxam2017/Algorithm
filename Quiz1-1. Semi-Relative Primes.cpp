#include <iostream>
#include <queue>
#include <cstring>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int** graph;
int parent[150]={0};
int n,v;
bool visit[150]={false};
int prime[46]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
int rr[100]={0};
bool inline min(int &a,int &b){
    return a<b;
}
bool bfs(int r[150][150]){
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
    int r[150][150];
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
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>rr[i];
	}
	v = 48+n;
	graph = new int*[v]();
	for(int i=0;i<v;i++){
		graph[i] = new int[v]();
		if(!i){
			for(int j=1;j<=46;j++){
				graph[0][j]=1;
			}
		}
		else if(i>=1 && i<=46){
			for(int j=0;j<n;j++){
				if(rr[j]%prime[i-1]==0)
					graph[i][47+j]=1;
			}
		}
		else if(i>=47 && i<=47+n){
			graph[i][v-1]=1;
		}
	}

	cout<<ford()<<endl;
    return 0;
}