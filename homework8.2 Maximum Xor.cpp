#include <iostream>
#include <vector>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {_
    int t;
    cin>>t;
    while(t--){
        int n,max = 0;
        vector<int>s(1024,0);
        cin>>n;
        for(int i=0;i<n;i++){
            int p,q,r,x,y,z;
            vector<int>t(1024,0);
            cin>>p>>q>>r;
            if(i==0){
                s[p]++;
                s[q]++;
                s[r]++;
            }
            else{
                for(int j=0;j<1024;j++){
                    if(s[j]){
                        x=j^p; y=j^q; z=j^r;
                        t[x]++;t[y]++;t[z]++;
                        if(i == n-1){
                            if(x>max){
                                max = x;
                            }
                            if(y>max){
                                max = y;
                            }
                            if(z>max){
                                max=z;
                            }
                        }
                    }
                }
                s = t;
            }
            
        }
        cout<<max<<endl;
    }
    return 0;
}