# include <bits/stdc++.h>
# define NR 5005
using namespace std;
char str[NR];
int n,i,nrflip,testCASE,j,k,ok, v[NR];
void REVERSE(int stanga, int dreapta) {
    while(stanga<dreapta) {
        v[stanga]=v[stanga]^1;
        v[dreapta]=v[dreapta]^1;
        swap(v[stanga],v[dreapta]);
        ++stanga; --dreapta;
    }
    if(stanga==dreapta) v[stanga]=v[stanga]^1;
}

int main()
{
    ifstream f("test.in");
    freopen("test.out","w",stdout);
    f>>testCASE; f.get();
    while(testCASE) {
        ++k; --testCASE;
        printf("Case #%d: ",k);
        f.getline(str, NR);
        n=strlen(str);
        for(i=0; i<n; ++i)
            if(str[i] == '+') v[i+1]=1;
                else v[i+1]=0;
        i=n;nrflip=0;
        while(i > 0) {
            if(v[i] == 0) {
                //trebuie sa aducem un 1 pe prima pozitie
                j=1; ok=0;
                while(v[j] > 0 && j<n)
                    v[j]=0, ++j, ok=1;

                if(ok==1) ++nrflip;
                ++nrflip;
                REVERSE(1,i);
            }
            --i;
        }
        printf("%d\n",nrflip);
    }

    return 0;
}
