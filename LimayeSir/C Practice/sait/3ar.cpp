
   int thunder() {
    Aradhya Pitlawar
    ll test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        deque<ll> dq;
        for(ll i=1;i<=n;i++){
            dq.push_back(i);
        }
        ll cn1=0,cn0=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='1'){
                cn1++;
            }
            else{
                cn0++;
            }
        }
        ll ans;
        if(cn1==cn0){
            for(auto &x:dq){
                cout<<x<<" ";
            }

        }
        else  if(cn1>cn0){
            ans=cn1-cn0;
            while(ans--){
                ll temp=dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
                        for(auto &x:dq){
                cout<<x<<" ";
            }
        }
        else{
            ans=cn0-cn1;
                while(ans--){
                ll temp=dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
                        for(auto &x:dq){
                cout<<x<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
   