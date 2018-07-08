#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1030;
int tree[maxn][maxn] , n;
void update(int x , int y , int val)
{
    for(;x<maxn; x += x&(-x) )
    {
        int y1 = y;
        for(;y1<maxn ; y1 += y1&(-y1))
        {
            tree[x][y1] += val;
        }
    }
}
int query(int x,int y)
{
    int sum = 0;
    for(;x>0;x -= x&(-x))
    {
        int y1 = y;
        for(;y1>0;y1 -= y1&(-y1))
        {
            sum += tree[x][y1];
        }
    }
    return sum;
}
int main()
{
    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        string s;
        memset(tree,0 ,sizeof(tree));
        while(cin>>s)
        {
            if(s=="END")break;
            if(s=="SET")
            {
                int x,y,z;
                scanf("%d %d %d",&x,&y,&z);
                x++ , y++;
                int val = query(x,y) - query(x-1,y) - query(x,y-1) + query(x-1,y-1);
                update(x,y,z - val);
            }
            else
            {
                int x1 , x2 , y1 , y2;
                scanf("%d %d %d %d",&x1 , &y1 , &x2 , &y2);
                x1++,y1++,x2++,y2++;
                printf("%d\n",query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1));
            }
        }
        printf("\n");
    }
    return 0;
} 