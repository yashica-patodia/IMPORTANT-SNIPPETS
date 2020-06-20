cin>>n>>m;
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
		if(i!=j)
			dis[i][j]=1e9;
		else 
			dis[i][j]=0;

}
int par[n][n];
for(int i=0;i<m;i++)
{
	cin>>a>>b>>c;
	dis[a][b]=min(dis[a][b],c);
}
par[i][j]  i-->x--->y ...-->par[i][j]-->j
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
		par[i][j]=i;
}
for(int k=0;k<n;k++)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(dis[i][j]>dis[i][k]+dis[k][j])
			{
			dis[i][j]=min(dis[i][j],dis[i][k],dis[k][j]);
			par[i][j]=par[k][j];
			}
		}	
}
///we may have to print the path for the required shortest distance
void printpath()
{
	if(i!=j)
		printpath(i,par[i][j]);
	cout<<j<<endl;
}

//how many nodes are reachable from a particular node a
//CALLED TRANSITIVE CLOSER

for(int i=0;i<m;i++)
{
	int a,b,c;
	cin>>a>>b>>c;
	dis[a][b]=1;
}
for(int k=0;k<n;k++)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dis[i][j]=dis[i][j]|(dis[i][k]&dis[k][j]);
		}
	}
}

//find the shortest cycle
if we dont intialize dis[i][i]=0;
then it will store the  shortest length of path to reach i to i 

int ans=1e9;
for(int i=0;i<n;i++)
{
	ans=min(ans,dis[i][i]);
}
if(ans<0)
cout<<"YES";
else cout<<"NO";

//finding the negative  cycles

//FINDING DIAMETER OF PATH--->LONGEST SHORTEST PATH
IMP
IF N<=400 WE CAN FLOYYD WARSHALL 
