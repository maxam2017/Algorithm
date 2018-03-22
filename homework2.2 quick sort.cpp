#include <iostream>
#include <algorithm>
using namespace std;
int tx=0;
int Partition(int *a,int p,int r){
    int i=p-1;
    for(int j=p;j<r;j++){
        if(a[j]<=a[r]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
    
}
void Quicksort(int *a,int p,int r){
    if(p<r){
        int q=Partition(a, p, r);
        Quicksort(a, p, q-1);
        Quicksort(a, q+1, r);
    }
    else if(p>r)
        tx++;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *a=new int [n]();
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Quicksort(a,0,n-1);
        cout<<((tx==n-1)? "Yes":"No")<<endl;
        tx=0;
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        delete [] a;
    }
    return 0;
}