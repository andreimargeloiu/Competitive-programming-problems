#include <iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
long long a,b,c,d,e;
int main()
{
    cin>>a>>b>>c>>d>>e;
    long long nr=(a+b+c+d+e)/5;
    long long sum=a+b+c+d+e;
    if (sum==0) {cout<<"-1\n";return 0;}
    if (sum%5!=0) cout<<"-1\n";
        else cout<<nr<<"\n";
    return 0;
}
