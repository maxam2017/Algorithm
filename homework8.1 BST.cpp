#include <iostream>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct node{
    int v;
    node* l;
    node* r;
};

void plant(node* &root , int k){
    if(root==NULL){
        root = new node();
        root -> v = k;
    }
    else if(root->v > k){
        plant(root->r,k);
    }
    else if(root->v<k){
        plant(root->l,k);
    }
    else{
        exit(0);
    }
}
void search(node* &root,int k){
    if(root == NULL){
        cout<<"qwq";
        exit(0);
    }
    else{
        if(root -> v == k){
            cout<<endl;
            return;
        }
        else if(root->v > k){
            cout<<"L";
            search(root->r,k);
        }
        else {
            cout<<"R";
            search(root->l,k);
        }
    }
}
int main() {_
    int n,s;
    while(cin>>n>>s){
        int k;
        node *root = NULL;
        while(n--){
            cin>>k;
            plant(root,k);
        }
        search(root,s);
    }
    return 0;
}