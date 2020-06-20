
int n,m;
vector<string> arr;
int vis[1010][1010];

bool check(int x,int y){
    if(x<n && x>=0 && y<m && y>=0)return 1;
    return 0;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y){
    vis[x][y]=1;
    fr(k,4){
        int xx = x+dx[k];
        int yy = y+dy[k];
        if(check(xx,yy)&&!vis[xx][yy]){
            dfs(xx,yy);
        }
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,n){
        cin>>arr[i];
    }

    int cntans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                cntans++;
                dfs(i,j);
            }
        }
    }

    cout<<cntans<<endl;
}
