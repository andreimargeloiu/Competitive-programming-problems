# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("patrate6.in");
ofstream g("patrate6.out");
int i,j,n,m,VV,S,nr,numarate,k;
int put[5000],a[100005];
void preproc ()
{
    put[0]=1;
    while (put[k]*4<=n)
    {
        put[k+1]=put[k]*4;
        ++k;
    }
}
int main ()
{
    f>>n;
    if (n==1)
    {
        f>>a[1];
        g<<a[1]<<"\n";
        return 0;
    }
    preproc();
    for (i=1; i<=n; ++i) f>>a[i];
    sort (a+1, a+n+1);
    i=1; nr=1;
    while (i<n)
    {
        S=i;
        if (a[S]==a[i+1] && i+1<=n)
        {
            while (a[S]==a[i+1] && i+1<=n) ++i,++nr;
        }
        else {//le pun intr-un patrat mai mare
                 //am nr bucati de latura a[i]
                 if (put[a[i+1]-a[i]]==0) nr=2;
                    else nr=1+((nr+3)/put[a[i+1]-a[i]]);
                 ++i;
             }
    }
    VV=0;
    while (nr>1)
        nr=nr/4,++VV;
    g<<a[n]+VV<<"\n";

    return 0;
}
