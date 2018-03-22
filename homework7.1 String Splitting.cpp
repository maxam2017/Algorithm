#include <iostream>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {_
    int t;
    char s[1000];
    cin>>t;
    while(t--){
        int n,m;
        long long sum=0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        long long k=0;
        for(int i=0;i<n;i++){
            k*=10;
            k+=s[i]-'0';
            if(k%m==0){
                k=0;
                sum++;
            }
            else{
                k%=m;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}