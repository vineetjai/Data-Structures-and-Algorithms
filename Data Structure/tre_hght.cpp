#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int n,root=0;
	cin>>n;
	vector< vector<int> > nodes(n);
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==-1)root=i;
		else nodes[a[i]].push_back(i);
	}
	queue<int> q;
	q.push(root);
	int height=0;
	while(true){
		int nodecount=q.size();
		if(nodecount ==0){
			cout<<height<<endl;
			break;
		}
		height+=1;
		while(nodecount){
			int node=q.front();
			q.pop();
			if(!nodes[node].empty()){
				for(int i=0;i<nodes[node].size();i++)
					q.push(nodes[node][i]);
			}
			nodecount--;
		}
	}

}