lli ans=0;
    for(int i=0;i<(1<<n);i++){
        int m = i;
        for(int s=m;;s=(s-1)&(m)){
            for(int j=0;j<n;j++){
                if(s&(1<<j)){
                    ans+=arr[j];
                }
            }
            if(s==0)break;
        }
    }
    cout<<ans<<endl;