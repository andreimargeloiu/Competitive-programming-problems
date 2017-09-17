# include <fstream>
using namespace std;
ifstream f("prisme.in");
ofstream g("prisme.out");
int i,j,n,S,maxx;
int st[10],dr[10],ext[10],St[10],Dr[10],Ext[10],uz[10];
int verificare (int k)
{
    if (k==1) return 1;
    else if (k<n) {
                       if (Dr[k]==St[k-1]) return 1;
                          else return 0;
                  }
         else {
                  if (Dr[k]==St[k-1] && St[k]==Dr[1]) return 1;
                      else return 0;
              }
}
void back (int k)
{
    if (k==n+1) maxx=max(S,maxx);
    else
    {
        int i,v1,v2,v3;
        for (i=1; i<=n; ++i)
        {
            if (!uz[i])
            {
                uz[i]=1;
                v1=st[i]; v2=dr[i]; v3=ext[i];

                St[k]=v1; Dr[k]=v2; Ext[k]=v3;
                if (verificare (k)) {S+=Ext[k]; back(k+1); S-=Ext[k];}

                St[k]=v2; Dr[k]=v3; Ext[k]=v1;
                if (verificare (k)) {S+=Ext[k]; back(k+1); S-=Ext[k];}

                St[k]=v3; Dr[k]=v1; Ext[k]=v2;
                if (verificare (k)) {S+=Ext[k]; back(k+1); S-=Ext[k];}

                uz[i]=0;
            }
        }
    }
}
int main ()
{
    n=6;
    for (i=1; i<=n; ++i)
        f>>st[i]>>dr[i]>>ext[i];

    back (1);
    g<<maxx<<"\n";

    return 0;
}
