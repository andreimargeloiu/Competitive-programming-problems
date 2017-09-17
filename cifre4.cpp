# include <fstream>
# include <vector>
# include <queue>
using namespace std;
ifstream f("cifre4.in");
ofstream g("cifre4.out");
queue <long long> q;
int i,j,n,m,t,r,imp,ok,VV;
char ap[5000005];
int dx[]={2,3,5,7};
int main ()
{
    int i,o;
    long long k,nrv;
    f>>t;
    for (int o=1; o<=t; ++o)
    {
        f>>r>>imp;
        q.push(2); q.push(3); q.push(5); q.push(7);
        ok=1;
        while (! q.empty() && ok)
        {
            k=q.front(); q.pop();
            for (i=0; i<4; ++i)
            {
                nrv=k*10+dx[i];
                if (nrv%imp==r)
                {
                    g<<nrv<<"\n";
                    ok=0;
                    break;
                }
                else if (ap[nrv%imp]!=o)
                     {
                         ap[nrv%imp]=o;
                         q.push(nrv);
                     }
            }
        }
        if (ok) g<<"-1\n";
        while (! q.empty()) q.pop();
    }


    return 0;
}
