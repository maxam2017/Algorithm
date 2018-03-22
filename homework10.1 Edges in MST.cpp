#include <iostream>
#include <cstring>
#include <algorithm>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
struct edge{
    int s;
    int f;
    int w;
    int n;
};

bool cmp(edge a,edge b){
    return a.w < b.w;
}

int main() {_
    int n,m;
    cin>>n>>m;
    edge* e = new edge[m]();
    bool* rec = new bool[m]();
    int* set = new int[n]();
    memset(set, -1, 4*n);
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q>>e[i].w;
        if(p<q){
            e[i].s=p;
            e[i].f=q;
        }
        else{
            e[i].s=q;
            e[i].f=p;
        }
        e[i].n = i;
    }
    sort(e,e+m,cmp);
    bool tag = false,tag2 = false;
    int bm = -1 , last = -1,end =-1;
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
        if(tag){
            if(e[i].w == bm){
                if(p == q)
                    rec[e[i].n]=true;
                continue;
            }
            else{
                end = i-1;
                i = last;
                tag2 = true;
                tag = false;
                continue;
            }
        }
        if(tag2){
            if(p!=q){
                set[q]=p;
            }
            if(i == end){
                tag2 = false;
            }
            continue;
        }
        if(p != q){
            tag = true;
            last = i-1;
            bm = e[i].w;
        }
        else{
            rec[e[i].n] = true;
        }
    }
    for(int i=0;i<m;i++){
        if(rec[i] == false){
            cout<<"at least one"<<endl;
        }
        else{
            cout<<"none"<<endl;
        }
    }
    return 0;
}