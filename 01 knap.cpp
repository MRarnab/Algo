#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter N: ";
    cin>>n;
    cout<<"enter capacity: ";
    int cap;
    cin>>cap;
    int item[n];
    int weight[n];
    int price[n];

    cout<<"enter item weight price: "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>item[i]>>weight[i]>>price[i];
    }
    int table[n+1][cap+1];
    for(int i=0;i<=n;i++)
    {
        table[i][0]=0;
    }
    for(int j=0;j<=cap;j++)
    {
        table[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        int w=weight[i-1];
        int p=price[i-1];
        for(int j=1;j<=cap;j++)
        {
            if(w<=j)
            {
                table[i][j]=max(table[i-1][j],table[i-1][j-w]+p);
            }else{
               table[i][j]=table[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<< "Maximum profit: " << table[n][cap];
    cout<<endl;
    cout<<"Selected Item: ";
    int i=n;
    int j=cap;
    while(i>0&&j>0)
    {
        if(table[i][j]==table[i-1][j])
        {
            i--;
        }else
        {
            cout<<item[i-1]<<" ";
            i--;
            j-=weight[i-1];

        }
    }
}
