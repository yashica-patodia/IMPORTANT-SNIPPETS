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


typedef struct node
{
	//node (*bit)[2];
	node  *bit[2];
	lli cnt=0;
}trie;
trie* head;
void insert(lli x)
{
	trie *curr=head;
	for(lli i=30;i>=0;i--)
	{
		lli ch=(x>>i)&1;
		if(curr->bit[ch]==NULL)
			curr->bit[ch]=new trie();
		curr=curr->bit[ch];
		curr->cnt++;
	}
}
void remove(lli x)
{
	trie *curr=head;
	for(lli i=30;i>=0;i--)
	{
		lli ch=(x>>i)&1;
		curr=curr->bit[ch];
		curr->cnt--;
	}
}
lli maxxor(lli x)
{
	trie *curr=head;
	lli ans=0;
	for(lli i=30;i>=0;i--)
	{
		lli ch=(x>>i)&1;
		if(curr->bit[!ch]!=NULL && curr->bit[!ch]->cnt>0)
		{
			ans+=(1LL<<i);
			curr=curr->bit[!ch];
		}
		else
			curr=curr->bit[ch];
	}
	return ans;
}
int32_t main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	
	head=new trie();//first allocate space for trie dynamically;
	insert(0);
	lli q;
	cin>>q;
	while(q--)
	{
		char ch;
		cin>>ch;
		lli x;
		cin>>x;
		if(ch=='+')
			insert(x);
		else if(ch=='-')
			remove(x);
		else
			cout<<maxxor(x)<<endl;
	}
}
