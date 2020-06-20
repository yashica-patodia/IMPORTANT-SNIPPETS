
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
}

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
vector<pair<int,int>>g[100100];
lli dis[100100];
void bfs01(int sc)
{
	deque<int>dq;
	for(int i=1;i<=n;i++)
		dis[i]=1e9;
	//first intilalize all dis ti INF
	dq.push_back(sc);
	dis[sc]=0;
	while(!dq.empty())
	{
		int xx=dq.front();
		dq.pop_front();
		for(auto v:g[xx])
		{
			int neigh=v.ff;
			int w=v.ss;
			if(dis[neigh]>dis[xx]+w)
			{
				dis[neigh]=dis[xx]+w;
				if(w==0)
					dq.push_front(neigh);
				else
					dq.push_back(neigh);
			}

		}
	}
}
void solve()

{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});

	}
	int sc;
	cin>>sc;
	bfs01(sc);
	//for all the nodes we know te ans!!,can we use for multisource bfs
}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	clock_t start,end;
	start=clock();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();

	}
	
	
	end=clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
