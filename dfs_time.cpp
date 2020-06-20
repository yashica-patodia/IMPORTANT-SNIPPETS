graph g;
int timer;

int in[100100];
int out[100100];


void dfs(int nn,int pp){
    in[nn] = timer++;
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn);
    }
    out[nn] = timer++;
}

void solve(){
    int n;
    timer = 0;
    cin>>n;
    g.resize(n+1);
    fr(i,n-1){
        int a,b;
        cin>>a>>b;
        g[a].EB(b);
        g[b].EB(a);
    }
    dfs(1,0);

    int q;cin>>q;
    fr(i,q){
        int x,y;
        cin>>x>>y;
        if(in[x]<=in[y]&&out[y]<=out[x]){
            x is a ancestor of y
        }
        else if(in[y]<=in[x]&&out[x]<=out[y]){
            y is a ancestor of x
        }else{
            no relation!!
        }
    }
}