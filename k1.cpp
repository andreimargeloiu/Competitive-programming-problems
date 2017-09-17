# include <fstream>
# include <algorithm>
# include <deque>
using namespace std;
ifstream f("k1.in");
ofstream g("k1.out");
deque <long long> d;
int i,j,n,m,x,VV,nr,ap[10005],a[1000005];
char s[10];
long long nod,minn,sol;

void make () {
    VV=1;
    for (i=n+1; i<=2*n-1; ++i) {
        nod=0;
        for (j=0; j<2; ++j) {
            if (!d.size() || (VV<=nr && a[VV]<d.front())) minn=a[VV], ++VV;
            else minn=d.front(), d.pop_front();

            nod+=minn;
        }
        sol+=nod;
        d.push_back(nod);
    }
}

void read (int &x) {
    x=0;
    f.getline (s, 10);
    int i=0;
    while (s[i]!='\0') {
        x=x*10 + s[i]-'0';
        ++i;
    }
}
int main ()
{
    read (n);
    for (i=1; i<=n; ++i) {
        read(x);
        ++ap[x];
    }
    for (i=1; i<=10000; ++i) {
        for (j=1; j<=ap[i]; ++j)
            a[++nr]=i;
    }
    make ();

    g<<sol<<"\n";

    return 0;
}
