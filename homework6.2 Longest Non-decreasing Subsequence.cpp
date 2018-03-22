#include <iostream>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main() {_
    int t;
    cin>>t;
    while(t--){
        int n,v,l=0,r=-1,rec[1000];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>v;
            if(r==-1)
                rec[++r]=v;
            else if(v>=rec[r])
                rec[++r]=v;
            else{
                int lo=l,hi=r,mid;
                while(lo<=hi){
                    mid=(lo+hi)/2;
                    if(rec[mid]<=v)
                        lo=mid+1;
                    else{
                        if(hi==lo)
                            rec[hi]=v;
                        hi=mid;
                    }
                }
            }
        }
        cout<<r+1<<endl;
    }
    return 0;
}