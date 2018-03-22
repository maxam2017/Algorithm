#include <iostream>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
struct card{
    int rank;
    char suit;
};
int main() {_
    int t;
    cin>>t;
    while(t--){
        int n,count[1000]={0},ans=0;
        cin>>n;
        card c[1000];
        for(int i=0;i<n;i++){
            cin>> c[i].rank>>c[i].suit;
        }
        int k=0;
        for(int i=0;i<n;i++){
            int max=0;
            if(c[i].rank==8){
                for(int j=k;j<i;j++){
                    if(max<count[j])
                        max=count[j];
                }
                ans+=max+1;
                k=i+1;
                continue;
            }
            for(int j=k;j<i;j++){
                if(c[i].rank==c[j].rank || c[i].suit==c[j].suit){
                    if(count[j]>max)
                        max=count[j];
                }
            }
            count[i]=max+1;
        }
        int last=0;
        for(int i=k;i<n;i++){
            if(last<count[i])
                last=count[i];
        }
        cout<<ans+last<<endl;
    }
    return 0;
}