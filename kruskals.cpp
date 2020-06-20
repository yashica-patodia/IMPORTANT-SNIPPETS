#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);


typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
struct DSU
{
int conn;
	int par[N],s[N];//N is thelimit of n
	DSU(){}
	DSU(int n)
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			s[i]=1;
		}
		conn=n;
	}
	int find(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}
	int getsize(int k)
	{
		return s[find[k]];
	}
	void unite(int u,int v)
	{
		int p1=find(u);
		int p2=find(v);
		if(p1==p2)
			return;
		conn--;
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
	}
};
vector<pair<int,int>>g[100100];
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int> > >edgelist;
	int a,b,c;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		edgelist.push_back({c,{a,b}});
	}
	DSU ds(n);
	sort(all(edgelist));
	int mst_cost=0;
	int cnt=0;//keep count of edges to check for a mst tree
	for(auto v:edgelist)
	{
		int x=v.ss.ff;
		int y=v.ss.ss;
		if(ds.find(x)!=ds.find(y))
		{ 
			cnt++;
			mst_cost+=v.ff;
			g[x].push_back({y,v.first});//to find the mst tree
			g[y].push_back({x,v.first});
			ds.unite(x,y);

		}
	}
	//if a graph is connected then it will also have a mst we can check it with finding the number of nodes
	if(cnt!=n-1)
	{
		cout<<"NO solution"<<endl;
		return;
	}
	cout<<mst_cost<<endl;

}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	
	
}
