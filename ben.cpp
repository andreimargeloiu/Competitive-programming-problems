 # include <fstream>
 # include <algorithm>
 # define MOD 32173
 # define NR 30005
 using namespace std;
 ifstream f("ben.in");
 ofstream g("ben.out");
 int i,j,n,m,x,y,ci,cs,CS,K,rez;
 int mars[NR], A[NR], incep[NR];
 int aranjamente (int n, int k)
 {
     int rez=1;
     for (int i=n-k+1; i<=n; ++i)
         rez=rez*i%MOD;

     return rez;
 }
 int main ()
 {
     f>>n;
     for (i=1; i<=n; ++i) {
        f>>ci>>cs; CS=max(CS, cs);

        ++mars[ci]; --mars[cs+1];
        ++incep[ci];
     }

     for (i=1; i<=CS; ++i) {
        A[i]=A[i-1] + mars[i];
        K=max(K, A[i]);
     }

     rez=1;
     for (i=1; i<=CS; ++i)
        if (incep[i]) {
            rez=rez * aranjamente (K - (A[i] - incep[i]), incep[i]);
            rez%=MOD;
     }
     g<<K<<" "<<rez<<"\n";

     return 0;
 }
