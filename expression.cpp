# include <iostream>
using namespace std;
int a,b,c,maxx,i,v[10];
int main ()
{
    cin>>a>>b>>c;
    v[1]=a+b+c;
    v[2]=a*b*c;
    v[3]=(a+b)*c;
    v[4]=a*(b+c);
    v[5]=a+b*c;
    v[6]=a*b+c;
    for (i=1; i<=6; ++i)
        maxx=max(maxx,v[i]);
    cout<<maxx<<"\n";
    return 0;
}
