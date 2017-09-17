# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("joculet.in");
ofstream g("joculet.out");
long long unu[2005],doi[2005],trei[2005],nr[2005];
long long maxx (long long a,long long b, long long c)
{
    return max(max(a,b),c);
}
int main ()
{
    int i,j,n;
    f>>n;
    for (i=1; i<=n; ++i)
        f>>nr[i];

    //unu
    for (i=1; i<=n; ++i)
        unu[i]=nr[i];
    //doi
    for (i=1; i<n; ++i)
        doi[i]=maxx(nr[i]-nr[i+1], nr[i+1]-nr[i], nr[i]+nr[i+1]);

    //trei[i]=suma maxima pe care o poate obtine jucatorul din urmatarele j pozitii
    for (j=3; j<=n; ++j)
    {
        for (i=1; i<=n-j+1; ++i)
            trei[i]=maxx(nr[i]-doi[i+1],nr[i+j-1]-doi[i],nr[i]+nr[i+j-1]-unu[i+1]);

        for (i=1; i<=n; ++i)
        {
            unu[i]=doi[i];
            doi[i]=trei[i];
            trei[i]=0;
        }
    }
    g<<doi[1];
    return 0;
}
