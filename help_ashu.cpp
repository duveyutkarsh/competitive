#include<iostream>
using namespace std;
const int maxn = 1e5+5;
int tree[maxn] , n;
void update(int idx,int val)
{
    for(;idx<=n;idx += idx &(-idx) )tree[idx] += val;
}
int get(int idx)
{
    int sum = 0;
    for(;idx>0;idx -= idx &(-idx))sum+=tree[idx];
    return sum;
}
int main()
{
    int q , k;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&k) , update(i , k%2);
    scanf("%d",&q);
    while(q--)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(x==0)
        {
            int val = get(y) - get(y-1);
            update(y , z%2- val);
        }
        else if(x==1)printf("%d\n" , z-y+1 - ( get(z) - get(y-1) ));
        else printf("%d\n",get(z) - get(y-1));
    }
    return 0;
} 