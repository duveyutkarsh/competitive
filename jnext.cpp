#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e6+5;
string a[maxn];
bool cmp(string a,string b)
{
    if(a+b < b+a)return 1;
    return 0;
}
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        scanf("%d",&n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(i=n-2;i>=0;i--)
        {
            if(cmp(a[i] , a[i+1]))break;
        }
        if(i==-1)printf("-1");
        else
        {
            int id = i+1;
            for(int j=i+1;j<n;j++)
            {
                if(cmp(a[i] , a[j]))id = j;           
            }
            swap(a[id] , a[i]);
            sort(a+i+1 , a+n , cmp);
            for(int i=0;i<n;i++)cout<<a[i];
        }
        printf("\n");      
    }
    return 0;
}