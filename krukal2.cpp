//n nodes m edges  a tree that connects all the nodes of graph with minimum cost ,out of  m edges we take n-1
//add edges to graoh with minimum weight and also keeps track if they are connected or not

//sort() e loge iterate for all v edges 
struct dsu
{
	int n;
	vector<int>par;
	vector<int>s;
	int conn;
	dsu()
	{

	}
	dsu(int _n)
	{
		n=_n;
		conn=_n;
		par.resize(n+1);//1 to  n nodes;
		s.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			s[i]=1;
		}

	}
	int find(int x)
	{
		while(x!=par[x])
		{
			par[x]=par[par[x]];
			x=par[x];
		}
		return x;
	}
	void merge(int x,int y)
	{
		int p1=find(x);
		int p2=find(y);
		if(p1!=p2)
		{
			if(s[p1]>=s[p2])
			{
				s[p1]+=s[p2];
				par[p2]=p1;
			}
			else
			{
				s[p2]+=s[p1];
				par[p1]=p2;
			}
			conn-=1;
		}
	}
	void reset()
	{
		conn=n;
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			s[i]=1;
		}

	}
	int conn_comp()
	{
		return conn;
	}
	void print()
	{
		for(int i=1;i<=n;i++)
			cout<<i<<"  -->"<<par[i]<<endl;
	}
};
vector<pair<int,int>>g[100100];
void solve()
{
	int n,m;
	cin>>n>>m;
	int a,b,c;
	vector<pair<lli,pair<int,int> > >edgel;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		edgel.pb({c,{a,b}});

	}
	sort(all(edgel));
	dsu uf(n);
	lli mst_cost=0;
	for(auto v:edegl)
	{
		int x=v.ss.ff;
		int y=v.ss.ss;
		if(uf.find(x)!=uf.find(y))
		{
			mst_cost=v.first;
			//make graph as well
			adj[x].pb({y,v.ff});
			adj[y].pb({x,v.ff});
			uf.merge(x,y);

			cnt++;
			//count of number of edges
		}
	}
	if(cnt!=n-1)
	{
		cout<<"NO solution"<<endl;
		return;
	}
	cout<<mst_cost<<endl;
	//if the graph is not connected then no mst otherwise sue mst;
}