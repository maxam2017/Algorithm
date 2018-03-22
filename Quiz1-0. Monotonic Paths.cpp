#include <iostream>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int map[100][100]={{0}};
bool reg[100][100]={{false}};
int main(){_
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	int d = (map[n-1][n-1]-map[0][0])/(2*n-2);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!i && !j)
				reg[i][j]=true;
			else if(!i){
				if(reg[i][j-1] && (map[i][j]==map[i][j-1]+d))
					reg[i][j]=true;
			}
			else if(!j){
					if(reg[i-1][j] && (map[i][j]==map[i-1][j]+d))
					reg[i][j]=true;
			}
			else{
				if((reg[i-1][j] && (map[i][j]==map[i-1][j]+d)) ||(reg[i][j-1] && (map[i][j]==map[i][j-1]+d)) )
					reg[i][j]=true;
			}
		}
	}
	if(reg[n-1][n-1])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}