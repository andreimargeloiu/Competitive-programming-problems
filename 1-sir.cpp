 # include <fstream>
 # include <algorithm>
 # define mod 194767
 # define NR 256*257/2+5
 using namespace std;
 ifstream f("1-sir.in");
 ofstream g("1-sir.out");
 int i,j,n,m,maxx,S;
 int a[NR], b[NR];
 int main ()
 {
     f>>n>>S;
     if (n*(n+1)/2<S)
     {
         g<<"0\n";
         return 0;
     }

     a[0]=1;
     for (i=2; i<=n; ++i)
     {
         maxx=i*(i+1)/2;
         for (j=0; j<=maxx; ++j)
             b[j]=(a[j+(i-1)]+a[abs(j-(i-1))])%mod;

         for (j=0; j<=maxx; ++j)
            a[j]=b[j], b[j]=0;
     }
     g<<a[S]<<"\n";

     return 0;
 }
