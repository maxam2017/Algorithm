#include <iostream>
#include <algorithm>
using namespace std;

void maxHeapity(int *a,int p,int e){
    int c=p*2+1;
    while(c<=e){
        if(c+1<=e && a[c+1]>a[c])
            c++;
        if(a[p]>a[c])
            break;
        else{
            swap(a[p],a[c]);
            p=c;
            c=2*p+1;
        }
    }
}

int main() {
    int n;
    cin>>n;
    int *a=new int [n]();
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=(int)(n/2-1);i>=0;i--){
        maxHeapity(a,i,n-1);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    for(int i=n-1;i>=1;i--){
        swap(a[i],a[0]);
        maxHeapity(a, 0, i-1);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}