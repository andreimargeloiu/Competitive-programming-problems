# include <fstream>
# include <algorithm>
# include <vector>
# define NR 500
using namespace std;
ifstream f("segment.in");
ofstream g("segment.out");
vector <int> xadd[NR], xout[NR]; //daca intra si iese vreun segment la x
vector <pair< int, int> > v[NR]; //v[x] - daca am segment pe orizontala la x
int i,j,n,m,suma,x1,x2,y1,y2,CI,CS,maxx;
int ARB[NR];
void update (int nod, int ci, int cs, int wanted, int val)
{
    if (ci==wanted && wanted==cs) ARB[nod]=val;
    else {
             int mij=(ci+cs)/2;
             if (wanted<=mij)     update (2*nod, ci, mij, wanted, val);
             else if (wanted>mij) update (2*nod+1, mij+1, cs, wanted, val);

             ARB[nod]=ARB[2*nod]+ARB[2*nod+1];
         }
}
void cauta (int nod, int ci, int cs)
{
    if (CI<=ci && cs<=CS) suma+=ARB[nod];
    else {
             int mij=(ci+cs)/2;
             if (CI<=mij) cauta (2*nod, ci, mij);
             if (CS>mij)  cauta (2*nod+1, mij+1, cs);
         }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x1>>y1>>x2>>y2;
        if (x1>x2) swap(x1, x2);
        if (y1>y2) swap(y1, y2);

        if (y1==y2) //e orizontal
        {
            xadd[x1].push_back(y1);
            xout[x2].push_back(y2);
        }
        if (x1==x2) // e vertical
        {
            v[x1].push_back(make_pair(y1, y2));
        }

        maxx=max (maxx, x2);
    }

    for (i=0; i<=maxx; ++i)
    {
        //adaug noile segmente
        for (j=0; j<xadd[i].size(); ++j)
            update (1, 1, maxx, xadd[i][j], 1);


        for (j=0; j<v[i].size(); ++j)
        {
            CI=v[i][j].first; CS=v[i][j].second;
            suma=0;
            cauta (1, 1, maxx);
            g<<suma<<"\n";
        }


        //scot segmente
        for (j=0; j<xout[i].size(); ++j)
            update (1, 1, maxx, xout[i][j], 0);
    }


    return 0;
}
