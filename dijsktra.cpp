void printpath(lli j)
{
	if(par[j]==-1)
		return;
	//cout<<j<<" "<<par[j]<<endl;
	printpath(par[j]);
	cout<<j<<" ";
}
void solve()
{
	cin>>n>>m;
	dis.resize(n+1);
	par.resize(n+1);
	
	for(int i=0;i<=n;i++)
		dis[i]=MOD;
	fr2(i,m)
	{
		lli a,b,w;
		cin>>a>>b>>w;
		adj[a].eb(MP(b,w));
		adj[b].eb(MP(a,w));
	}
	pq.push(MP(0,1));
	dis[1]=0;
	par[1]=-1;
	while(!pq.empty())
	{
		lli v=pq.top().ss;
		if(vis[fs.ff])
			continue;
		vis[fs.ff]=1;
		pq.pop();
		for(auto j=adj[v].begin();j!=adj[v].end();j++)
		{
			lli u=(*j).ff;
			lli wei=(*j).ss;
			if(dis[u]>dis[v]+wei)
			{
				dis[u]=dis[v]+wei;
				pq.push(MP(-dis[u],u));
				par[u]=v;
			}
		}
	}
	if(dis[n]!=MOD)
	{
	cout<<1<<" ";
	printpath(n);
}
else
cout<<-1;
	//cout<<dis[n];
}
//given  a graph u need to find the time when the last edge will burn completel
find th minimum path to each node from the starting pojt using dijsktra and then it can happen that an edhe ge buned from both the nodes together
then if A and B are two end=points of the node then if abs(A-B)>=x where x is the length of x then time taken will be min(a,b)+x
if(abs(A-B)<x) then abs(A-B)+(x-abs(A-B)/2)
	THEN TAKE THE MAXIMAM OF THE NODES AND THE EDGES