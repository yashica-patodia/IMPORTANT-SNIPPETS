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
// int main()
// {
// 		#ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// 	#endif
// 	IOS
// 	clock_t start,end;
// 	start=clock();
// 	int t;
// 	cin>>t;
// 	for(int i=1;i<=t;i++)
// 	{
// 		cout<<"Case #"<<i<<": ";
// 		solve();

// 	}
	
	
// 	end=clock();
	
// 	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
// 	cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
// }

const int sigma=128;
typedef struct node
{
	node *next[sigma];
	int wend;
	int prefix;
	node()
	{
		wend=0;
		prefix=0;
		for(int i=0;i<sigma;i++)
			next[i]=NULL;
	}
}trie;
trie *head;
void insert(string &s)
{
	trie *cur=head;
	for(int i=0;i<s.length();i++)
	{
		if(cur->next[s[i]-'a']==NULL)
		{
			cur->next[s[i]-'a']=new trie();
			cout<<s[i]-'a'<<" ";
		}
		cur=cur->next[s[i]-'a'];
		cur->prefix++;
		cout<<cur->prefix<<endl;

	}
	cur->wend++;
	cout<<s<<" "<<cur->wend<<endl;

}
int count(string &s)
{
	trie *cur=head;
	for(int i=0;i<s.length();i++)
	{
		//cout<<cur->next[s[i]-'a']<<endl;
		if(cur->next[s[i]-'a']==NULL)
		{
			cout<<"a"<<endl;
			cout<<cur->next[s[i]-'a']<<" "<<endl;
			return 0;
		}
		cur=cur->next[s[i]-'a'];
	}
	cout<<s<<" "<<cur->wend<<endl;
	return cur->wend;
}
int prefix(string &s)
{
	trie *cur=head;
	for(int i=0;i<s.length();i++)
	{
		if(cur->next[s[i]-'a']==NULL)
		{
			cout<<cur->next[s[i]-'a']<<" "<<endl;
			return 0;
		}
		cur=cur->next[s[i]-'a'];
	}
	cout<<s<<" "<<cur->prefix<<endl;
	return cur->prefix;


}
int32_t main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	
	head=new trie();//first allocate space for trie dynamically;
	string s="abcd";
	string s2="yashi";
	string s3="abcd";
	insert(s);
	insert(s2);
	insert(s3);
	int k=count(s);
	cout<<k<<endl;
	string s4="ab";
	int m=prefix(s4);
	cout<<m<<endl;
}	