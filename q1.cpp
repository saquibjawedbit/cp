// AYUSH THEPLA

// DIV 2 E till dec 2024

#include <bits/stdc++.h>
#define  ll long long int 
using namespace std;


void solve(){
    ll n;
    cin>>n;
  
    vector<ll> thepla(n);
    ll maxi=0;
    for(ll i=0;i<n;i++){
        cin>>thepla[i];
        maxi=max(maxi,thepla[i]);
    }

    ll add=0;
    ll count=0;
    ll flag=0;
    for(ll j=0;j<3;j++){
    
        bool chutiya=false;
        for(ll i=0;i<thepla.size();i++){
    
            if(thepla[i]>=maxi){
                maxi=max(thepla[i],maxi);
                maxi=max(add,maxi);
            }
            else {
                if(flag==0){
                    add+=thepla[i];
                    flag=1;
                    chutiya = true;
                }
                else if(flag==1){
                  
                    thepla[i-1]+=thepla[i];
                    count++;
                    thepla.erase(thepla.begin()+i);
                    i--;
                    chutiya = true;
                }
                if(add>=maxi){
                    maxi=max(maxi,add);
                    add=0;
                    flag=0;
                }
            }
        }
        
    }
    
    cout<<count;
}


signed main(){
    solve();
    return 0;
}