# include <fstream>
# include <algorithm>
# include <queue>
# define NR 25
using namespace std;
ifstream f("invcs.in");
ofstream g("invcs.out");
queue <int> q1, q2;
int i,j,n,m,nrsol,maxx,nr,N;
int L[NR], mat[1<<21];
int main ()
{
    f>>n;
    if (n==1)
    {
        g<<"1\n";
        return 0;
    }
    for (i=1; i<=n; ++i)
        f>>L[i];

    //il bagam pe
    for (i=1; i<=n; ++i) //fiecare pozitie pe care poate sa fie elementul 1
        if (L[i]==1)
        {
            nr=(1<<i); mat[nr]=1;
            q1.push(nr);
        }
    for (i=2; i<=n; ++i) // fiecare numar din permutare
    {
        while (! q1.empty())
        {
            nr=q1.front(); q1.pop();
            maxx=0;
            for (j=1; j<=n; ++j)
            {
                if ( nr & (1<<j)) maxx=max(maxx, L[j]);
                if ((nr & (1<<j))==0)
                {
                    if (maxx+1==L[j])
                    {
                        N=nr+(1<<j);
                        if (! mat[N]) q2.push(N);

                        mat[N]+=mat[nr];
                    }
                }
            }
        }

        //interschimb
        while (! q2.empty())
        {
            nr=q2.front(); q2.pop();
            q1.push(nr);
        }
    }
    g<<mat[(1<<(n+1))-2]<<"\n";


    return 0;
}
