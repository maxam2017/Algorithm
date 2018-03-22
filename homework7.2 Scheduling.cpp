#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct job{
    int seq;
    int time;
    long long fine;
};

bool cmp(job a,job b){
    return  (double)a.fine/a.time > (double)b.fine/b.time;
}

int main() {_
    int t;
    cin>>t;
    while(t--){
        int n;
        job j[10000];
        cin>>n;
        for(int i=0;i<n;i++){
            j[i].seq=i+1;
            cin>>j[i].time;
        }
        for(int i=0;i<n;i++){
            cin>>j[i].fine;
        }
        sort(j,j+n,cmp);
        int at=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=at*j[i].fine;
            at+=j[i].time;
        }
        cout<<sum<<endl;
        for(int i=0;i<n;i++){
            cout<<j[i].seq<<' ';
        }
        cout<<endl;
    }
    return 0;
}