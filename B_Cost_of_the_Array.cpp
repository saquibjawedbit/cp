#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<int> a(n+1);for(int i=1;i<=n;i++)cin>>a[i];int r=k/2;vector<int> nd(n+2);nd[n]=n+1;nd[n+1]=n+1;for(int i=n-1;i>=1;i--)nd[i]=(a[i+1]==a[i]?nd[i+1]:i+1);unordered_map<int,vector<int>> pos;for(int i=1;i<=n;i++){pos[a[i]].push_back(i);}for(auto &p:pos)sort(p.second.begin(),p.second.end());
auto qeq=[&](int X,int L,int R)->int{if(!pos.count(X))return -1;auto &v=pos[X];auto it=lower_bound(v.begin(),v.end(),L);return(it!=v.end()&&*it<=R?*it:-1);};
auto qdev=[&](int X,int L,int R)->int{if(L>R)return -1; if(a[L]!=X)return L; int t=nd[L];return(t<=R?t:-1);};
auto nup=[&](int g){return n-k+2*g;};
auto sg=[&](int g){return(g<r?n-2*(r-g):n);};
int L=2, Rb=nup(1); int c=qdev(1,L,Rb); if(c!=-1){cout<<1<<"\n"; continue;}
vector<unordered_map<int,int>> dp(n+2);
int st=qeq(1,L,Rb); if(st==-1){cout<<1<<"\n"; continue;} dp[1][1]=st; int f=1, ans=-1;
while(true){int exp=f+1; bool dev=false; for(auto &e:dp[f]){int g=e.first, p=e.second, np=p+1; if(np<=sg(g)&&np<=n&&a[np]!=exp){dev=true; break;} if(g<r){int L2=p+2, R2=nup(g+1); if(L2<=R2 && qdev(exp,L2,R2)!=-1){dev=true; break;}}} if(dev){ans=f+1; break;} unordered_map<int,int> ndp; for(auto &e:dp[f]){int g=e.first, p=e.second, np=p+1; if(np<=sg(g)&&np<=n&&a[np]==exp){if(!ndp.count(g)||np<ndp[g])ndp[g]=np;} if(g<r){int L2=p+2, R2=nup(g+1); int t=qeq(exp,L2,R2); if(t!=-1){int ng=g+1; if(!ndp.count(ng)||t<ndp[ng])ndp[ng]=t;}}} if(ndp.empty()){ans=f+1; break;} f++; dp[f]=move(ndp);} cout<<ans<<"\n";} return 0;}
