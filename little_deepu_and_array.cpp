#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int n , tr[4*maxn];
vector<pair<int,int>> v;
void push(int u)
{
    tr[2*u] += tr[u];
    tr[2*u+1] += tr[u];
    tr[u] = 0;
}
void hit(int u,int l,int r,int L ,int R)
{
    if(l>R || r<L)return;
    if(l>=L && r<=R)tr[u]--;
    else
    {
        int m = (l+r)/2;
        push(u);
        hit(2*u,l,m,L,R);
        hit(2*u+1,m+1,r,L,R);
    }
}
int findval(int u,int l,int r ,int idx)
{
    if(l==r)return tr[u];
    else
    {
        int m = (l+r)/2;
        push(u);
        if(idx<=m)return findval(2*u,l,m,idx);
        else return findval(2*u+1,m+1,r,idx);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        v.pb({x,i});
    }
    sort(v.begin() , v.end());
    int q;cin>>q;
    while(q--)
    {
        int x;cin>>x;
        int l = 0 , r = n-1;
        while(l<r)
        {
            int m = (l+r)/2;
            if(findval(1,0,n-1,m) + v[m].F > x)r = m;
            else l = m+1;
        }
        if(findval(1,0,n-1,l) + v[l].F > x)
        {
            hit(1,0,n-1,l,n-1);
        }
    }
    int ans[n+1];
    for(int i=0;i<n;i++)
    {
        ans[v[i].S] = findval(1,0,n-1,i) + v[i].F ;
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}