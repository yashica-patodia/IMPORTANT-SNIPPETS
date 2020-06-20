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
vector<vector<int>>g;
int n,m;
int dis[100100];
int get_far(int x)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=MOD;
	}
	queue<int>q;
	q.push(x);
	dis[x]=0;
	int last=x;
	while(!q.empty())
	{
		int vert=q.front();
		q.pop();
		for(auto j:g[vert])
		{
			if(dis[j]>dis[vert]+1)
			{
				q.push(j);
				dis[j]=dis[vert]+1;
				last=j;//last is giving the farthest neighbour bs we exploit the property that  bfs is level order and the last pushed  into the queue before empty will give the node with the farthest distance
			}
		}
	}
	return last;
}
void solve()
{
	cin>>n>>m;
	q.resize(n+1);
	fr2(i,m)
	{
		int a,b;
		cin>>a>>b;
		g[a].eb(b);
		g[b].eb(a);

	}
	int x=get_far(1);
	int y=get_far(x);
	cout<<dis[y]<<endl;//gives the diameter of graph
	

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
