#include <iostream>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
struct taf{
    int count2;
    int count5;
};
inline int min(int a,int b){
    return (a<b)? a : b;
}
taf map[300][300];
int main() {_
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            int p=0,q=0;
            while(k%2==0){
                p++;
                k/=2;
            }
            while(k%5==0){
                q++;
                k/=5;
            }
            if(!i && !j)
                map[i][j]={p,q};
            else if(!i)
                map[i][j]={p+map[i][j-1].count2,q+map[i][j-1].count5};
            else if(!j)
                map[i][j]={p+map[i-1][j].count2,q+map[i-1][j].count5};
            else
                map[i][j]={p+min((map[i-1][j].count2),(map[i][j-1].count2)),q+min((map[i-1][j].count5),(map[i][j-1].count5))};
        }
    }
    cout<<min(map[n-1][n-1].count2,map[n-1][n-1].count5)<<endl;
    return 0;
}