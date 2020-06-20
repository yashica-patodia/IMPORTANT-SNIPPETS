struct node
{
	int cnt;//subtree mein kitne element hai
	node *child[2];
	node()//constructor
	{
		cnt=0;
		child[0]=child[1]=NULL;
	}

};
#define LN 30
struct trie
{
	node *root;
	trie()
	{
		root=new node;

	}
	void insert(int x)
	{
		node *cur=root;
		for(int i=LN-1;i>=0;i--)
		{
			cur->cnt++;
			int ch=(x>>i)&1;//i th bit one hai ya nahi
			if(cur->child[ch]==NULL)
			{
				cur->child[ch]=new node;
			}
			cur=cur->child[ch];
		}
		cur->cnt++;

	}
	void remove(int x)
	{
		node *cur=root;
		for(int i=LN-1;i>=0;i--)
		{
			cur->cnt--;
			int ch=(x>>i)&1;//i th bit one hai ya nahi
			if(cur->child[ch]==NULL)
			{
				assert(1==0);
				//cur->child[ch]=new node;
			}
			cur=cur->child[ch];
		}
		cur->cnt--;

	}
	int maxxor(int x)
	{
		node *cur=root;
		for(int i=LN-1;i>=0;i--)
		{
			//cur->cnt++;
			int ch=((x>>i)&1)^1;//i th bit one hai ya nahi
			if(cur->child[ch]==NULL || cur->child[ch]==0)
			{
				ch=ch^1;
				//cur->child[ch]=new node;
			}
			ans=ans|(ch<<i);
			cur=cur->child[ch];
		}
		return ans^x;
		//cur->cnt++;

	}
};
void solve()
{
	trie tt;
	tt.insert(3);
	tt.insert(1);
	cout<<tt.maxxor(2)<<endl;
}