#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int pe = 0,visit[10001]={0},low[10001]={0},stamp[10001]={0};
bool in[10001]={false};
stack<int> st;

inline int min(int &a,int &b){
    return (a<b)? a:b;
}

void tarjan(int s,vector<int>* &v){
    visit[s]=low[s]=++pe;
    st.push(s);
    in[s]=true;
    for(vector<int>::iterator it = v[s].begin();it!=v[s].end();it++){
        if(!visit[*it]){
            tarjan(*it,v);
        }
        if(in[*it]){
            low[s] = min(low[s],low[*it]);
        }
    }
    if(visit[s]==low[s]){
        while(st.top()!=s){
            in[st.top()]=false;
            stamp[low[s]]++;
            st.pop();
        }
        stamp[low[s]]++;
        in[st.top()]=false;
        st.pop();
    }
}

int dfs(int s,vector<int>* &v){
        int n = 1;
        visit[s]=true;
        if(!v[s].size())
            return 1;
        else{
            for(vector<int>::iterator it = v[s].begin();it!=v[s].end();it++){
                if(!visit[*it])
                    n+=dfs(*it, v);
            }
            return n;
        }
    
}

int main(){
    int t,n,m,p,q;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> *v = new vector<int>[n+1]();
        for(int i=0;i<m;i++){
            cin>>p>>q;
            v[p].push_back(q);
        }
        while(!st.empty()){
            st.pop();
        }
        memset(visit, 0, 4*10001);
        memset(stamp, 0, 4*10001);
        memset(in, 0, 10001);
        pe=0;
        bool tag = false;
        int high=1;
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                if(tag){
                    high = i;
                }
                tag = true;
                tarjan(i, v);
            }
        }
         memset(visit, 0, 4*10001);
        int k = dfs(high, v);
        if(k < n)
            cout<<0<<endl;
        else
            cout<<stamp[low[high]]<<endl;
    }
    return 0;
}