#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long p,q,r,x,y,z;
unsigned long long a(unsigned long long i){
    return p*i*i+q*i+r;
}
unsigned long long b(unsigned long long i){
    return x*i*i+y*i+z;
}
unsigned long long fun(unsigned long long af,unsigned long long ae,unsigned long long bf,unsigned long long be){
    if (ae-af==1)
        return min(max(a(af),b(bf)),min(a(ae),b(be)));
    if (ae==af)
        return min(a(ae),b(be));
    unsigned long long p=((ae-af+1)%2==0)?(a((af+ae-1)/2)+(a(af+ae+1)/2))/2:a(af+ae/2);
    unsigned long long q=((be-bf+1)%2==0)?(b((bf+be-1)/2)+(b(bf+be+1)/2))/2:b(bf+be/2);
    if(p==q)
        return p;
    else if (p>q)
        return ((ae-af+1)%2==0)? fun(af,(af+ae-1)/2,(be+bf+1)/2,be):fun(af,(af+ae)/2,(bf+be)/2,be);
    else
        return ((ae-af+1)%2==0)? fun((af+ae+1)/2,ae,bf,(bf+be-1)/2):fun((af+ae)/2,ae,bf,(bf+be)/2);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>p>>q>>r>>x>>y>>z;
        unsigned long long n;
        cin>>n;
        cout<<fun(0,n-1,0,n-1)<<endl;
    }
    return 0;
}