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
typedef vector<pii> vpii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
const int N=52;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,m,k;
int f=0;
char str[N][N];
bool vis[N][N];
vector<vpii> ans;
vpii v;
bool check(int x,int y)
{
	///cout<<n<<endl;
	if((x>=0 && x<=n-1) && (y>=0 && y<=m-1))
		return true;
	else
		return false;
}
bool edge(int x,int y)
{
	//cout<<n<<x<<y;
	if(x==0 || x==n-1 || y==0 || y==n-1)
		return true;
	else
		return false;
}
bool cmp( const vpii &a, const vpii &b)
{
	return a.size()<b.size();
}
void dfs(int x,int y)
{
	//cout<<x<<" "<<y<<endl;
	v.pb({x,y});
	vis[x][y]=true;
	for(int dir=0;dir<4;dir++)
	{
		int xx=x+dx[dir];
		int yy=y+dy[dir];
		//cout<<"dfs"<<xx<<" "<<yy<<endl;
		//cout<<check(xx,yy)<<" "<<edge(xx,yy)<<endl;
		// if( check(xx,yy)) 
		// {
		// 	if(str[xx][yy]=='.')
		// 	{
		if( !check(xx,yy))
		{
			f=0;
			continue;
		}
		//if(check(xx,yy))
		//{
		if(str[xx][yy]=='.' && !vis[xx][yy])
			dfs(xx,yy);
	//}
	}
	}

void solve()
{
	int cnt=0;
	cin>>n>>m>>k;
	//cout<<n;
	for(int i=0;i<n;i++)
		cin>>str[i];
	//cout<<str[0][0];
	mset(vis,false);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j] && str[i][j]=='.' )
			{
				//cout<<str[i][j];
				v.clear();
				f=1;
				dfs(i,j);
			//	cout<<f<<endl;
				if(f)
				{
					cnt++;
					ans.pb(v);
				}
				// for(auto jj:v)
				// 	cout<<jj.ff<<" "<<jj.ss;
				// cout<<endl;
			}
		}
	}
	sort(all(ans),cmp);
	//cout<<ans.size();
	//cout<<cnt<<endl;
	int sum=0;
	//cout<<ans.size();
	int rem=ans.size()-k;
	for(int  i=0;i<rem;i++)
	{
		sum+=ans[i].size();
		for(auto j:ans[i])
			str[j.ff][j.ss]='*';
	}
	cout<<sum<<endl;
	fr2(i,n)
	cout<<str[i]<<endl;

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
	// int t;
	// cin>>t;
	// for(int i=1;i<=t;i++)
	// {
	// 	//cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	//cout<<"hi";
	solve();

	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
