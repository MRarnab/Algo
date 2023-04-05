#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int amount;
    cin>>amount;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int table[n+1][amount+1];
    for(int i=0;i<=n;i++)
    {
        table[i][0]=0;
    }
    for(int i=1;i<=amount;i++)
    {
        table[0][i]=amount+1;
    }

    for(int i=1;i<=n;i++)
    {
        int c=ar[i-1];
        for(int j=1;j<=amount;j++)
        {
            if(c<=j)
            {
                table[i][j]=min(table[i-1][j],table[i][j-c]+1);
            }else
            {
                table[i][j]=table[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Minimum Number Of Coin: "<<table[n][amount]<<endl;
    cout<<"Selected Coins: ";
    int i=n;
    int j=amount;
    while(i>0&&j>0)
    {
        if(table[i][j]==table[i-1][j])
        {
            i--;
        }else
        {
            cout<<ar[i-1]<<" ";
            i--;
            j-=ar[i];

        }
    }


}
