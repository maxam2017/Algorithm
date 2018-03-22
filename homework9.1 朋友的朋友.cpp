#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {_
    int n,t,p,q,max = 1;
    cin>>n>>t;
    int *count=new int[n+1]();
    int *pos = new int[n+1]();
    for(int i=1;i<=n;i++){
        count[i]=1;
        pos[i]=i;
    }
    while(t--){
        cin>>p>>q;
        if(p>q)
            swap(p,q);
        int r=p,s=q;
        while(r!=pos[r]){
            r=pos[r];
        }
        pos[p]=r;
        while(s!=pos[s]){
            s=pos[s];
        }
        pos[q]=s;
        if(r!=s){
            count[r]+=count[s];
            if(count[r]>max)
                max = count[r];
            pos[s] = r;
        }
    }
    cout<<max<<endl;
    return 0;
}