#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,l,r,x;
    cin>>n>>l>>r>>x;
    int arr[n];
    int arr2[1<<n][n];
    vector<int>v;
    int go = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
        {
            go+=1;
        }
    }
    for(int i = 0;i<(1<<n);i++)
    {
        for(int j = 0;j<n;j++)
        {
            if((i&(1<<j))==0)
            {
                arr2[i][j]=arr[j];
            }
            else
            {
                arr2[i][j] = 0;
            }
        }
    }

    int fd = 0;
    int c = 0;
    for(int i = 0;i<(1<<n);i++)
    {
        vector<int>v;
        for(int j = 0;j<n;j++)
        {
            if(arr2[i][j]!=0)
            {
                v.push_back(arr2[i][j]);
            }
        }
        if(v.size()>=2)
        {

        int fu = 0;
        vector<int>::iterator it;
        for(it = v.begin();it!=v.end();it++)
        {
            fu+=*it;
        }

        if(l<=fu&&fu<=r)
        {
            sort(v.begin(),v.end());
            vector<int>::iterator it1 = v.begin();
            vector<int>::iterator it2 = v.end()-1;
            if(abs(*it1-*it2)>=x)
            {
                c+=1;
            }
        }

        }

    }
    cout<<c;
    return 0;
}
