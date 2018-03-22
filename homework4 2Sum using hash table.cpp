#include <iostream>
#define N 100000
using namespace std;
struct node{
    int val;
    long long count;
    node* next;
};

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    while(t--){
        long long ans=0;
        node* list_head[N]={NULL};
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            bool exist=false;
            int s;
            cin>>s;
            int p=(s%N+N)%N,q=((k-s)%N+N)%N;
            for(node* ptr=list_head[q];ptr!=NULL;ptr=ptr->next){
                if(ptr->val==k-s){
                    ans+=ptr->count;
                    break;
                }
            }
            node* pre=NULL;
            for(node *ptr=list_head[p];ptr!=NULL;ptr=ptr->next){
                if(ptr->val==s){
                    ptr->count++;
                    exist=true;
                    break;
                }
                pre=ptr;
            }
            if(!exist){
                node* temp=new node();
                temp->val=s;
                temp->count=1;
                if(!pre)
                    list_head[p]=temp;
                else{
                    pre->next=temp;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}