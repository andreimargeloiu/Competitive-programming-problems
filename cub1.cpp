# include <fstream>
# include <vector>
# include <queue>
using namespace std;
queue <int> q;
vector <int> v[1000005];
ifstream f("cub1.in");
ofstream g("cub1.out");
int di[]={1,-1,0,0,0,0};
int dj[]={0,0,1,0,-1,0};
int dk[]={0,0,0,1,0,-1};
int put[]={1,2,4,8,16,32};
int i,j,k,n,m,p,nr,x,maxx,I,J,K,X,ok,nrsol,np,o,NR,viitor;
int ap[1000005];
short a[1000005],sol[1000005];
bool accesibil (int i, int j, int k)
{
    if (i>=1 && i<=n && j>=1 && j<=n && k>=1 && k<=n) return 1;
        else return 0;
}
void IJK (int vx)
{
    I=(vx-1)/np+1; vx=vx-(I-1)*np;
    J=(vx-1)/n+1; vx=vx-(J-1)*n;
    K=vx;
}
void BFS ()
{
    ap[1]=1;
    q.push(1);
    while (! q.empty())
    {
        X=q.front (); q.pop ();
        x=a[X];
        IJK(X);
        if (X==np*n) break;
        for (o=5; o>=0; --o)
        {
             if (x>=put[o] && accesibil(I+di[o],J+dj[o],K+dk[o]))
             {
                 x-=put[o];
                 viitor=X+(di[o]*np)+(dj[o]*n)+dk[o];
                 if (ap[viitor]==0) {
                                        ap[viitor]=ap[X]+1;
                                        q.push(viitor);
                                    }
             }
             if (x>=put[o]) x-=put[o];
        }
    }
}
int main ()
{
    f>>p>>n;
    np=n*n;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            for (k=1; k<=n; ++k)
            {
                NR=(i-1)*np+(j-1)*n+k; nr=0;
                f>>x; a[NR]=x;
                for (o=5; o>=0; --o)
                {
                    if (x>=put[o] && accesibil(i+di[o],j+dj[o],k+dk[o])) x-=put[o],++nr;
                    if (x>=put[o]) x-=put[o];
                }
                if (nr>maxx)
                {
                    maxx=nr,I=i,J=j,K=k;
                }
            }
    if (p==1) {g<<I<<" "<<J<<" "<<K<<"\n"; return 0;}
    BFS();
    if (ap[n*n*n]==0) {g<<"-1\n"; return 0;}
        else g<<ap[n*n*n]<<"\n";
    ok=1; X=n*n*n;
    while (X!=1)
    {
        sol[++nrsol]=X;
        for (o=5; o>=0; --o)
        {
            viitor=X+(di[o]*np)+(dj[o]*n)+dk[o];
            if (ap[viitor]==ap[X]-1)
            {
                X=viitor;
                break;
            }
        }
    }
    g<<"1 1 1\n";
    for (i=nrsol; i>=1; --i)
    {
        IJK(sol[i]);
        g<<I<<" "<<J<<" "<<K<<"\n";
    }
    return 0;
}
