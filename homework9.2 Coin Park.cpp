#include <iostream>
#include <vector>
#include <cstring>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
vector<int> list[10001];
int val[10001];
int reg[10001];
bool visit[10001]={false};
int find_max(int root){
    visit[root]=true;
    if(list[root].size()==1 && root!=1){
        reg[root]=val[root];
    }
    else{
        int max=0;
        for(vector<int>::iterator it = list[root].begin();it!=list[root].end();it++){
            if(visit[*it])
                continue;
            if(reg[*it]==-1){
                reg[*it] = find_max(*it);
            }
            if(reg[*it]>max)
                    max = reg[*it];
        }
        reg[root]=val[root]+max;
    }
    return reg[root];
}
int main() {_
    int n,p,q;
    memset(reg, -1, 10001*sizeof(int));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<n;i++){
        cin>>p>>q;
        list[p].push_back(q);
        list[q].push_back(p);
    }
    cout<<find_max(1)<<endl;
    return 0;
}