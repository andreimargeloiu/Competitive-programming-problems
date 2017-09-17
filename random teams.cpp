# include <iostream>
using namespace std;
long long n,m,minn,maxx,intreg,nr,rest;
int main ()
{
    cin>>n>>m;
    //minim
    nr=n/m;
    rest=n%m;
    minn=(nr-1)*nr/2*m+rest*nr;
    cout<<minn<<" ";
    //maxim
    nr=n-m+1;
    maxx=(nr-1)*nr/2;
    cout<<maxx<<"\n";


    return 0;
}
