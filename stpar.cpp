#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int main()
{   
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        stack<int> s;
        int pass = 1 , a[n+1];
        for(int i = 0;i<n;i++)cin>>a[i];
        for(int i = 0;i<n;)
        {
            if(a[i]==pass)i++ , pass++;
            else if(!s.empty() && s.top()==pass)
            {
                s.pop();
                pass++;
            } 
            else
            {
                s.push(a[i]);
                i++;
            }
        }
        bool f = 1;
        while(!s.empty())
        {
            if(s.top()!=pass)
            {
                f = 0;
                break;
            }
            else
            {
                s.pop();
                pass++;
            }
        }
        if(f)cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}