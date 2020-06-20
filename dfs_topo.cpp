int n;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>ans;
vector<int>col;
int f=1;
void dfs(int v)
{
	//vis[v]=true;
	///if enter a node colour is 1 when exit color is 2 
	//if color[u]=1 then we must have been in the same cycle bcs we didint exit it
	col[v]=1;
	for(auto i:adj[v])
	{
		//if(!vis[i])
		if(col[i]==0)
			dfs(i);
		else if(color[i]==1)
		{
			f=0;
			cout<<"cycle";
			break;
		}
	}
	col[v]=2;
	if(f!=0)
	ans.eb(i);
}
void topo()
{
	vis.assign(n,false);
	col.assign(n,0);
	ans.clear();
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
			dfs(i);
	}
	reverse(ans.begin(),ans.end());
}

// void dfs(int node,int p)
// {
//   vis[node]=1;
      
//     for(auto x : graph[node])
//     {
//      if(vis[x]==0)
//      {
//       dfs(x,node);   
//      }
//      else if(vis[x]==1 ) { cout << "Impossible"; exit(0); } 
//     }
    
//     ss+=('a' +node);
//     vis[node]=2;
// }
//  f(i,26) if(vis[i] == 0 ) dfs(i,-1);
        
//      reverse(ss.begin(),ss.end());   
//         