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
vector<pair<lli,lli> > generate(vector<pair<lli,lli>>a)
{
	vector<pair<lli,lli> >ans;
	int n=a.size();
	for(int i=0;i<(1<<n);i++)
	{
		lli w=0;
		lli pr=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				w+=a[j].ff;
				pr+=a[j].ss;
			}
		}
		ans.pb({w,pr});

	}
	sort(all(ans));
	return ans;
}
void solve()
{
	lli n,m;
	cin>>n>>m;
	vector<pair<lli,lli>>vp(n);
	fr(i,n)
	cin>>vp[i].ff;
	fr(i,n)
	cin>>vp[i].ss;
	vector<pair<lli,lli>>a,b;
	for(lli i=0;i<n;i++)
	{
		if(i%2==0)
			a.eb(vp[i]);
		else
			b.eb(vp[i]);
	}
	// for(auto i:a)
	// 	cout<<i.ff<<" "<<i.ss<<endl;
	// cout<<endl;
	// for(auto i:b)
	// 	cout<<i.ff<<" "<<i.ss<<endl;
	// cout<<endl;
	vector<pair<lli,lli> >ans1,ans2;
	ans1=generate(a);
	ans2=generate(b);
	// for(auto i:ans1)
	// 	cout<<i.ff<<" "<<i.ss<<endl;
	// cout<<endl;
	// for(auto i:ans2)
	// 	cout<<i.ff<<" "<<i.ss<<endl;
	// cout<<endl;

	int a1=ans1.size();
	int a2=ans2.size();
	lli ans=0;
	// for(int i=0;i<a1;i++)
	// {
	// 	int ind=upper_bound(all(ans2),MP(m-ans1[i].ff,MOD))-ans2.begin();//for using upper_bound on pairs use ({number ti be searched,INF}) AND FOR LOWER_BOUND USE({NUMBER TO BE SEARCHED,0})
	// //	cout<<ind<<" ";
	// 	if(ind!=0)
	// 	{
	// 		ind--;
		
	// 	ans=max(ans1[i].ss+ans2[ind].ss,ans);
	// 	}



	// }
	int curr=0;
	lli mv=0;
	for(int i=a1-1;i>=0;i--)
	{
		while(curr<a2 && ans1[i].ff+ans2[curr].ff<=m)
		{
			mv=max(mv,ans2[curr].ss);
			curr++;
		}
		if(curr!=0)
		{
			ans=max(ans,mv+ans1[i].ss);
		}

	}
	cout<<ans<<endl;
}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	// clock_t start,end;
	// start=clock();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		//cout<<"Case #"<<i<<": ";
		solve();

	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
