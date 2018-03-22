#include <iostream>
#include <cstring>
#include <algorithm>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
struct edge{
    int s;
    int f;
    double w;
};

bool cmp(edge a,edge b){
    return a.w < b.w;
}

int main() {_
    int n,m;
	double all=0,min=1e17;
    cin>>n>>m;
    edge* e = new edge[m]();
    int *ss = new int[m]();
    int* set = new int[n+1]();
    memset(set, -1, 4*n+4);
    double* sum = new double[n+1]();
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q>>e[i].w;
        ss[i]=(int)e[i].w;
        if(p<q){
            e[i].s=p;
            e[i].f=q;
        }
        else{
            e[i].s=q;
            e[i].f=p;
        }
    }
    sort(ss,ss+m);
    all = (m%2==0)? (double)(ss[m/2]+ss[m/2-1])/2 : ss[m/2];
    for(int i=0;i<m;i++){
    	e[i].w-=all;
    	if(e[i].w<0)
    		e[i].w = -e[i].w;
	}
    sort(e,e+m,cmp);
    
    for(int i=0;i<m;i++){
    	
        int p = e[i].s,q = e[i].f;
        if(set[p] >= 0){
            while(set[p] >=0 ){
                p = set[p];
            }
            set[e[i].s] = p;
        }
        if(set[q] >= 0){
            while(set[q] >=0 ){
                q = set[q];
            }
            set[e[i].f] = q;

        }
        
        if(p != q){
        	if(set[q]<0){
        		set[p]+=set[q];
        		set[q]=p;
			}
			sum[p]=max(sum[p],e[i].w);
		}

		if(set[p]==-n){
			cout<<sum[p]<<endl;
			break;
		}	
    }
    return 0;
}