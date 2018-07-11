#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = (1<<21)+5;
int tr[maxn] , a[maxn] , n;
void update(int idx ,int val)
{
    for(;idx<maxn;idx += idx&(-idx))tr[idx] += val;
}
int getindex(int k)
{
    int idx = 0 , mask = (1<<21) , ans = 0;
    while(mask)
    {
       int tidx = idx + mask;
       if(tr[tidx]<k)
       {
            k-=tr[tidx];
            idx = tidx;
       }
       else if(tr[tidx]==k)
       {
            ans = tidx;
       }
       mask >>= 1;
    }
    return ans;
}
int main()
{
    int q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]), a[i]%=2;
    for(int i=1;i<=n;i++)update(i,a[i]);
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x==1)
        {
            a[y] = (a[y]+1)%2;
            if(a[y]==0)update(y,-1);
            else update(y,1);
        }
        else 
        {
            if(tr[(1<<21)]<y)
            {
                printf("-1\n");continue;
            }
            printf("%d\n",getindex(y));
        }
    }
    return 0;
}