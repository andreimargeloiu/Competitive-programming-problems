#include <cstdio>


using namespace std;

int hp[5], atk[5], def[5], dmg[5], pas[5], h, a, d;

inline int maxa(int x, int y){

    if(x > y)
        return x;
    return y;
}

inline int mina(int x, int y){

    if(x > y)
        return y;
    return x;
}

int main(){

   // freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    scanf("%d %d %d\n %d %d %d \n %d %d %d", &hp[1], &atk[1], &def[1], &hp[2], &atk[2], &def[2], &h, &a, &d);

    int sol = 1e9;

    for(int i = 0; i <= 100; ++i)
        for(int j = 0; j <= 100; ++j)
            for(int k = 0; k <= 100; ++k){

                int auxhp = hp[1] + i, auxatk = atk[1] + j, auxdef = def[1] + k;
                dmg[1] = maxa(0, auxatk - def[2]);
                dmg[2] = maxa(0, atk[2] - auxdef);
                if(dmg[1] != 0){

                    if(hp[2] % dmg[1] == 0)
                        pas[1] = hp[2] / dmg[1];
                    else
                        pas[1] = hp[2] / dmg[1] + 1;
                    if(dmg[2] == 0)
                        sol = mina(sol, i * h + j * a + k * d);
                    else{

                        if(auxhp % dmg[2] == 0)
                            pas[2] = auxhp / dmg[2];
                        else
                            pas[2] = auxhp / dmg[2] + 1;
                        if(pas[1] < pas[2])
                            sol = mina(sol, i * h + j * a + k * d);
                    }
                }
            }
    printf("%d", sol);
    return 0;
}
