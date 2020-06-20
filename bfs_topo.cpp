//in -degree term kahn's algortihm
//queue<int>q will maintain all the in-degree=0 for all vertices
while(!q.empty())
int x=q.front();
q.pop();
topo.push_back(x);
for(neigh:adj[x])
{
	in_Degree[neigh]--;
	if(in_degree[neigh]==0)
		push_it(topo);
}
//alll the nodes that dont appear in the topo vector are part of cycle 
//eqsy to detect nodes which are part of cycle

longest path starting from i 
dp[i]
//refer to spoj_topo 
replacing queues with priority queues gives in lexicograohical order

//adjacency matrix 
topo vector
topo.clear();
    g.clear();
    g.resize(26);
    cin>>n>>m;
    arr.resize(n);
    map<char,int> seen;
    fr(i,n){
        cin>>arr[i];
        fr(j,m){
            seen[arr[i][j]]=1;
        }
    }
void dfs(int n)
{
	vector<int>deg;
	deg.assign(26,0);
	priority_queue<int>pq;


for(int i=0;i<n;i++)
{
	for(auto j:adj[i])
	{
		deg[j]++;
	}
}
for(int i=0;i<26;i++)
{
	if(deg[i]==0)
	{
		pq.push(-i);
	}
}
while(!pq.empty())
{
	int v=-pq.top();
	pq.pop();
	topo.eb(v);
	for(auto j:adj[v])
	{
		deg[j]--;
		if(deg[j]==0)
			pq.push(-j);
	}
}
if(topo.size()<26)
f=0;


}

//to check if a graph has cycle using topo 
g.clear();
	g.resize(n+1);
	vis.resize(n+1);
	vis.assign(n+1,0);
	deg.resize(n+1);
	deg.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		
			if(adj[i].ss.ff>k)
			{
				g[adj[i].ff.ff].pb(adj[i].ff.ss);
				deg[adj[i].ff.ss]++;
			}

	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0)
			q.push(i);

	}
	t.clear();
	while(!q.empty())
	{
		int vert=q.front();
		q.pop();
		t.eb(vert);
		vis[vert]=1;
		for(auto i:g[vert])
		{
			if(vis[i]==0)
			{
				deg[i]--;
				if(deg[i]==0)
				q.push(i);
			}
		}
	}
	if(t.size()==n)
		return true;//no cycle
	else
		return false;

	//to print the topo sort of graph
	void topo(int p)
{
	g.clear();
	g.resize(n+1);
	vis.resize(n+1);
	vis.assign(n+1,0);
	deg.resize(n+1);
	deg.assign(n+1,0);

	//priority_queue<int>q;
	queue<int>q;
	for(int i=0;i<m;i++)
	{
		if(adj[i].ss.ff>p)
			{
				g[adj[i].ff.ff].pb(adj[i].ff.ss);
				deg[adj[i].ff.ss]++;
			}
	}
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0)
			q.push(i);

	}
	t.clear();
	while(!q.empty())
	{
		int vert=q.front();
		q.pop();
		t.eb(vert);
		vis[vert]=1;
		for(auto i:g[vert])
		{
			if(vis[i]==0)
			{
				deg[i]--;
				if(deg[i]==0)
				q.push(i);
			}
		}
	}
	t stores the topo sort