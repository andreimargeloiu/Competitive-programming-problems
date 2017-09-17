# include <iostream>
# include <fstream>
# define NMAX 10000005
# define LSB(x) ((-x)&x)
# define mil 100005
using namespace std;
//ifstream f("san.in");
//ofstream g("san.out");
struct elem {
    int a, b;
}Q[mil];
int AIB[NMAX];
int q,a,b,i,j,nr,sol,VV,var,maxx;
int inv(int x) {
    int r=0,u;
    while(x>0) {
        u=x%10;
        r=r*10+u;
        x=x/10;
    }
    return r;
}
void update(int x) {
    int i;
    for(i=x; i<=NMAX; i+=LSB(i))
        AIB[i]+=1;
}
int sum(int x) {
    int s=0;
    for(int i=x; i>=1; i-=LSB(i))
        s += AIB[i];
    return s;
}
int main()
{
    cin>>q;

    for(i=1; i<=q; ++i) {
         cin>>Q[i].a>>Q[i].b;
         maxx=max(maxx, Q[i].b);
    }

    for(i=1; i<=maxx; ++i) {
        var=i; update(i);

        while(var < maxx) {
            var+=inv(var);

            if (var<=maxx) update(var);
        }
    }

    for(i=1; i<=q; ++i)
        cout<<(sum(Q[i].b) - sum(Q[i].a-1))<<"\n";

    return 0;
}
