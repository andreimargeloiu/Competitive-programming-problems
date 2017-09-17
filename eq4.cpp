 # include <fstream>
 # include <algorithm>
 # include <cstring>
 # include <vector>
 # define NR 100005
 using namespace std;
 ifstream f("eq4.in");
 ofstream g("eq4.out");
 vector <int> S2;
 int i,j,n,m,nr,suma,nrx,nry,nrz,nrt,l,o,ci,cs,ok,nrsol,E,S,x,y;
 int N[10];
 char s[NR];
 void citire ()
 {
     int i;
     f.getline (s+1, NR); l=strlen(s+1);
     for (i=1; i<=l; i+=0)
     {
         if (s[i]=='-') ok=-1;
                   else ok=1;
         ++i; nr=0;
         while ('0'<=s[i] && s[i]<='9' && i<=l)
         {
             nr=nr*10 + (s[i]-'0');
             ++i;
         }
         if(nr==0 && 'a'<=s[i] && s[i]<='z') nr=1;
         nr*=ok;
         if ('a'<=s[i] && s[i]<='z')
         {
             if (s[i]=='x') N[1]+=nr;
             if (s[i]=='y') N[2]+=nr;
             if (s[i]=='z') N[3]+=nr;
             if (s[i]=='t') N[4]+=nr;
             ++i;
         }
         else suma=suma + nr;
     }
     f>>ci>>cs>>E; E-=suma;
     //g<<nrx<<" "<<nry<<" "<<nrz<<" "<<nrt<<" "<<suma;
 }
 void suma2 (int x, int y)
 {
     int i,j;
     for (i=ci; i<=cs; ++i)
         for (j=ci; j<=cs; ++j)
            S2.push_back(i*N[x] + j*N[y]);
    sort (S2.begin(), S2.end());
 }
 int main ()
 {
     citire ();

     // rezolvam

     suma2 (3, 4);

     for (i=ci; i<=cs; ++i)
        for (j=ci; j<=cs; ++j)
        {
            S=i*N[1] + j*N[2];
            int complement=E-S;
            if (binary_search(S2.begin(), S2.end(), complement))
            {
                 nrsol=nrsol + ( upper_bound(S2.begin(), S2.end(), complement) - lower_bound(S2.begin(), S2.end(), complement));
            }
        }

     g<<nrsol<<"\n";

     return 0;
}
