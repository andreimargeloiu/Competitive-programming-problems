# include <fstream>
# include <algorithm>
# define NR 400005
using namespace std;
ifstream f("hotel.in");
ofstream g("hotel.out");
int i,j,n,m,I,l,tip,S,D,ok;
int st[NR], dr[NR], maxx[NR];
void init (int nod, int ci, int cs)
{
    st[nod]=dr[nod]=maxx[nod]=cs-ci+1;

    if (ci!=cs)
    {
        int mij=(ci+cs)/2;
        init (2*nod, ci, mij);
        init (2*nod+1, mij+1, cs);
    }
}
void update (int nod, int ci, int cs)
{
    if (S<=ci && cs<=D)
    {
        if (ok==1) st[nod]=dr[nod]=maxx[nod]=0;
        if (ok==2) st[nod]=dr[nod]=maxx[nod]=cs-ci+1;
    }
    else {
             int mij=(ci+cs)/2;
             if (maxx[nod]==0)
             {
                 maxx[nod*2]=st[nod*2]=dr[nod*2]=0;
                 maxx[nod*2+1]=st[nod*2+1]=dr[nod*2+1]=0;
             }
             if (maxx[nod]==cs-ci+1)
             {
                 maxx[nod*2]=st[nod*2]=dr[nod*2]=mij-ci+1;
                 maxx[nod*2+1]=st[nod*2+1]=dr[nod*2+1]=cs-mij;
             }
             if (S<=mij) update (2*nod, ci, mij);
             if (D>mij) update (2*nod+1, mij+1, cs);

             maxx[nod]=max (dr[2*nod] + st[2*nod+1], max(maxx[2*nod], maxx[2*nod+1]));
             //stanga
             if (st[2*nod]==mij-ci+1) st[nod]=st[2*nod]+st[2*nod+1];
                                 else st[nod]=st[2*nod];

             //dreapta
             if (dr[2*nod+1]==cs-mij) dr[nod]=dr[2*nod+1]+dr[2*nod];
                                 else dr[nod]=dr[2*nod+1];
         }
}
int main ()
{
    f>>n>>m;
    init (1, 1, n);
    for (i=1; i<=m; ++i)
    {
        f>>tip;
        if (tip==1) // update i M
        {
            f>>I>>l; S=I; D=I+l-1;
            ok=1;
            update (1, 1, n);
        }
        else if (tip==2) // plecare i M
        {
            f>>I>>l; S=I; D=I+l-1;
            ok=2;
            update (1, 1, n);
        }
        else if (tip==3) g<<maxx[1]<<"\n";
    }

    return 0;
}
