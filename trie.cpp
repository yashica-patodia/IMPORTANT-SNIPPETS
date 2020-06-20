//har ek node  ke do children honge child[0] stores the zero bits and child[1] stores the 1 bits
//arrray declaration datatype (*variable name)[size of array]=null

//like int (*ptr)[5]=NULL
//CNT MEIN STORE KARENGE KI WHO NODE KITNE ELEMENTS KA PREFIX HAI
//BOHOT SAARE ZEORES NAHI HONGE KYA ?
//PURE 32 LEVELS HONGE NAA?
//AUR HAR EK ELEMENT LE LIYE LOGN THODI HOGA 32 HO GA NA
#define LN 30
typedef struct node
{
	int cnt;
	node (*child)[2];
	node()
	{
		cnt=0;
		child[0]=child[1]=NULL;
	}

}trie;

trie* head;
void insert(int x)
{
	trie* cur=head;
	for(int i=LN;i>=0;i--)
	{
		int b=(x>>i)&1;//ith bit 1 hai ya 0
		if(cur->child[b]==NULL)//agar child nahi hai toh
			cur->child[b]=new trie();
		cur=cur->child[b];
		cur->cnt++;
	}
}
void remove(int x)
{
	trie* cur=head;
	
	for(int i=30;i>=0;i--)
	{
		int b=(x>>i)&1;
		cur=cur->child[b];
		cur->cnt--;
	}
} 
int maxxor(int x)
{
	trie* cur=head;
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		int b=(x>>i)&1;
		if(cur->child[!b] && cur->child[!b]->cnt>0)
		{
			ans+=(1LL<<i);
			cur=cur->child[!b];
		}
		else
			cur=cur->child[b];
	}
	return ans;
}