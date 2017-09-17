# include <bits/stdc++.h>
# define NR 2005
using namespace std;
ifstream f("covor.in");
ofstream g("covor.out");
int i,j,n,m,act,nou,VV,suma,sol;
int top[3][NR], G[NR], st[NR];
char s[NR];
int main ()
{
    f>>n; f.get(); act=0; nou=1;
    for (i=1; i<=n; ++i) {
        VV=0; suma=0;

        f.getline (s+1, NR);
        for (j=1; j<=n; ++j) {
            st[j]=0; G[j]=0;

            if (s[j]=='0') top[nou][j]=1 + top[act][j];
                      else top[nou][j]=0;

            if (top[nou][j]) {// un nou stack
                st[++VV]=top[nou][j]; G[VV]=1;

                while (VV>1 && st[VV-1] >= st[VV]) {
                    suma=suma - (st[VV-1]*G[VV-1]);

                    G[VV-1]+=G[VV]; st[VV-1]=st[VV];
                    st[VV]=0; G[VV]=0;

                    --VV;
                }
                suma=suma + st[VV]*G[VV];

                sol=sol + suma;
            } else {
                suma=0;
                VV=0;
            }
        }
        swap(act, nou);
    }
    g<<sol<<"\n";

    return 0;
}
