z-function for a string is an array of length n 
z[i]=greatest number of characters starting from position i that coincide with the first characters of s
Z[I]=S string -->max prefix length of s[i....n
	abcababc
	00020300
agar pattern matching karna hai toh wohi p#t	
abc#ababc
whenever the z[i]=length of pattern
it means i is the starting index aur position in t hoga i-n 
whereas kmp mein i end index hota hai isliye i-2*n hota hai

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
vector<lli> find_occurences(string &text,string &pattern)
{
	string cur=pattern+'#'+text;
	lli sz1=text.size().sz2=pattern.size();
	vector<lli>v;
	vector<int>pi=z_function(cur);
	for(lli i=sz2+1;i<=sz1+sz2;i++)
	{
		if(pi[i]==sz2)
			v.eb(i-sz2-1);
	}

	return v;
}