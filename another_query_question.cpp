#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int a[maxn] , n , tree[maxn];
void update(int idx,int val)
{
    for(;idx<=n;idx += idx &(-idx) )tree[idx] += val;
}
int prefix_sum(int idx)
{
    int sum = 0;
    for(;idx>0;idx -= idx &(-idx))sum+=tree[idx];
    return sum;
}
int main()
{
    int q;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>q; 
    while(q--)
    {
        int k,y;
        cin>>k>>y;
        if(k==1)
        {
            update(1,-1);
            update(y+1,1);
        }
        else
        {
            int l = 1 , h = n;
            bool f = 0;
            while(l<=h)
            {
                int m = (l+h)/2;
                int val = a[m] + prefix_sum(m);
                if(val > y)h = m-1;
                else if(val < y)l = m+1;
                else
                {
                    f = 1;
                    break;
                }
            }
            if(f)cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
} 