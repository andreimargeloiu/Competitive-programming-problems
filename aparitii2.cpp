# include <bits/stdc++.h>
# define NR 2000005
using namespace std;
ifstream f("aparitii2.in");
ofstream g("aparitii2.out");
int Zdreapta, Zstanga, la,lb,i,j,n,m,st,dr,k;
int Zdr[NR], Zst[NR], margiki[NR];
char A[NR], B[NR], ST[NR], DR[NR];
void make_Z (char a[], int la, int Z[]) {
    int L=1, R=1;
    for (int i=2; i<=la; ++i) {
        if (R < i) { // trebuie sa fac brut sa vad cat este Z[i]
            L=R=i;
            while (R<=la && a[R]==a[R-i+1])
                ++R;

            --R; Z[i]=R-i+1;
        } else { //este intr-un Z-box si incerc sa ma folosesc de informatiile anterioare
            int k=i-L+1;
            if (i + Z[k] - 1 <R) Z[i]=Z[k];
            else {
                L=i; ++R;
                while (R<=la && a[R]==a[R-i+1])
                    ++R;
                --R; Z[i]=R-i+1;
            }
        }
    }
}
int main ()
{
    f.getline (A+1, NR); la=strlen(A+1);
    f.getline (B+1, NR); lb=strlen(B+1);

    //fac de la stanga la dreapta
    for (i=1; i<=lb; ++i) ST[++st]=B[i];
    ST[++st]='$';
    for (i=1; i<=la; ++i) ST[++st]=A[i];

    //fac pentru dreapta
    for (i=lb; i>=1; --i) DR[++dr]=B[i];
    DR[++dr]='$';
    for (i=la; i>=1; --i) DR[++dr]=A[i];

    //acum aplic Z algorithm pentru ambii vectori
    make_Z (ST, st, Zst);
    make_Z (DR, dr, Zdr);

    //acum incep sa fac dinamica
    for (i=1; i<=la; ++i) {
        k=i+lb-1; // capatul din dreapta
        if (k>la) break;

        Zstanga=Zst[i+lb+1];
        Zdreapta=Zdr[lb+1+(la-k+1)];

        ++margiki[min(Zstanga, Zdreapta)];

        /*if (min(Zstanga, Zdreapta)==1){
            g<<A[i]<<" "<<A[i+lb-1]<<"\n";
        }*/
    }
    for (i=lb; i>=1; --i)
        margiki[i]+=margiki[i+1];

    for (i=1; i<=lb/2; ++i)
        g<<margiki[i]<<"\n";

    return 0;
}
