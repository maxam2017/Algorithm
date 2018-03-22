#include <iostream>
#define P 29989
using namespace std;

struct matrix{
    int lu,ru,ld,rd;
};

matrix multi(matrix a,matrix b){
    matrix m;
    m.lu=((a.lu*b.lu)%P+(a.ru*b.ld)%P)%P;
    m.ru=((a.lu*b.ru)%P+(a.ru*b.rd)%P)%P;
    m.ld=((a.ld*b.lu)%P+(a.rd*b.ld)%P)%P;
    m.rd=((a.ld*b.ru)%P+(a.rd*b.rd)%P)%P;
    return m;
}
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=2){
            cout<<1<<endl;
        }
        else{
            matrix a;
            a.lu=1; a.ru=0; a.ld=0; a.rd=1;
            matrix b;
            b.lu=1; b.ru=1; b.ld=1; b.rd=0;
            int k=n-2;
            while(k!=0){
                if(k%2==1){
                    a=multi(a,b);
                }
                k/=2;
                b=multi(b,b);
            }
            cout<<(a.lu+a.ru)%P<<endl;
        }
    }
    return 0;
}