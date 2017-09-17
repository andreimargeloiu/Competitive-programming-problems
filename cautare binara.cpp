#include <iostream>

using namespace std;
int n,i,j,a[30][30];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=n-j+1;
            if(i==j) a[i][j]=0;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}
