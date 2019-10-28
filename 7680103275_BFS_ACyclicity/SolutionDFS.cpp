//Here is a simple solution for cycle detection and topological sort based on DFS.
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

const int N=1000;

vector<int> g[N];                                 //adjacent list storing for graph

int vis[N];

stack<int> stc;

bool dfs(int u) {
	vis[u] = -1;                                  //-1 denotes the node is being visited now
	
	if(!g[u].empty()) {
		for(auto &neigh:g[u]) {                   //dfs through its children nodes
			if(vis[neigh]==-1) {                  //this node is being visited for 2 times, cycle exists
				return false;
			}
			else if(!vis[neigh]&&!dfs(neigh)) {   //judge its children nodes first
				return false;
			}
		}
	}
	
	vis[u] = 1;
	stc.push(u);                                  //for topological sort use, can be omitted if only for cycle detection
	cout<<u<<" pushed"<<",";                      //to show the in stack order
	
	return true;
}



bool toposort(int n) {
	for(int i=0;i<n;++i) {
		if(!vis[i]) {
			cout<<"start from"<<i<<",";
			if(!dfs(i)) {                         //cycle detected
				return false;
			}
		}
	}
	
	cout<<endl;
	
	return true;
}



int main(int argc, const char * argv[]) {
	memset(vis,0,sizeof(vis));
	
	int V,E;
	cin>>V>>E;
	
	for(int i=0;i<E;i++) {
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	
	if(!toposort(V)) {
		cout<<"cycle exist"<<endl;
		return false;
	}
	
	while(!stc.empty()) {
		cout<<stc.top()<<endl;
		stc.pop();
	}
	
	return 0;
}