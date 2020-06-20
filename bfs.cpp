#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	map<int,vector<int>>adj;
	int n;
	int vert;
	cin>>vert;
	cin>>n;
	while(n--)
	{
		int u,v;
		cin>>u>>v;
		adj[u].emplace_back(v);
		//adj[v].eb(u);
	}
	vector<bool>vis(vert+1,false);
	queue<int>qu;
	//int parent[n+1];
	qu.push(2);
	vis[2]=true;
	while(!qu.empty())
	{
		int st=qu.front();
		cout<<st<<" ";
		qu.pop();
		 for(auto i=adj[st].begin();i!=adj[st].end();i++)
		// {
		// 	if()

		// }
		//for(auto i:adj[st]->second)
		{
			if(!vis[*i])
			{
				vis[*i]=true;
				qu.push(*i);
				// parent[*i]=st;
			}
			// else
			// {
			// 	if(parent[*i]!=st)
			// 		//cycle exits
			// }
		}
	}


}