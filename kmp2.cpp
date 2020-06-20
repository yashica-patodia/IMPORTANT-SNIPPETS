pi[x] represents the length of longest substring which is a prefix as well as suffix ending at length if 
pi[x] is the index for the next partial match for the string under index i
s#t
n#m	
max value of pi[x] is n 
if pi[i]=n then it means that the string s must be present in t ending at i
	dont forget thst positions in the string are made as s#t
thus if ats ome position pi[i]=n then at position i-2*n in the string t s appears
String :
vector<lli> prefix_function(string &s)
{
	lli n=s.size();
	vector<lli>pi(n);
	for(lli i=1;i<n;i++)
	{
		lli j=pi[i-1];
		while(j>0 && s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i]=j;

	}
	return pi;
}
vector<lli> find_occurences(string &text,string &pattern)
{
	string cur=pattern+'#'+text;
	lli sz1=text.size().sz2=pattern.size();
	vector<lli>v;
	vector<int>pi=prefix_function(cur);
	for(lli i=sz2+1;i<=sz1+sz2;i++)
	{
		if(pi[i]==sz2)
			v.eb(i-2*sz2);
	}

	return v;
}

vector:
vector<lli> prefix_function(vector<int> &v)
{//same as for strings
	int n=v.size();
	vector<int>pi(n);
	for(int i=1;i<n;i++)
	{
		int j=pi[i-1];
		while(j>0 && v[i]!=v[j])
			j=pi[j-1];
		if(v[i]==v[j])
			j++;
		pi[i]=j;
	}
	return pi;
}

vector<int> find_occurences(vector<int> &text,vector<int> &pattern)
{
	vector<int> v=pattern;
	v.push_back(-1);//instead of # we add -1
	for(auto &it:text)
		v.push_back(it);
	iint sz1=text.size(),sz2=pattern.size();
	vector<int>pi=prefix_function(v);
	vector<int>store;
	for(int i=sz2+1;i<=sz1;i++)
	{
		if(pi[i]==sz2)
			store.eb(i-2*sz2);
	}
	return store;
}
