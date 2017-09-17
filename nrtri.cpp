 # include <fstream>
 # include <algorithm>
 # define NR 1005
 using namespace std;
 ifstream f("nrtri.in");
 ofstream g("nrtri.out");
 int i,j,n,m,ci,sol;
 int a[NR];
 int cb (int S)
 {
     int ci=1, cs=n, mij, sol=0;
     while (ci<=cs)
     {
         mij=(ci+cs)/2;
         if (a[mij]<=S) sol=mij, ci=mij+1;
                   else cs=mij-1;
     }
     return sol;
 }
 int main ()
 {
     f>>n;
     for (i=1; i<=n; ++i)
        f>>a[i];
     sort (a+1, a+n+1);

     for (i=1; i<n-1; ++i)
        for (j=i+1; j<n; ++j)
        {
            ci=cb(a[i]+a[j]);
            sol+=(ci-j);
        }
     g<<sol<<"\n";
     return 0;
 }
