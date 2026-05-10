#pragma once
#include "main.h"
//139240
#define MAX_STUBOVA 8
#define MAX_BROJ 200000

int PrebrojavanjeProstihBrojeva(int broj)
{
    int slozeni[MAX_BROJ], brojac = 0, i, j;
    memset(slozeni, 0, sizeof(slozeni));
    if (broj < 2)
        return 0;

    for (i = 2; i < broj; i++)
        if (!slozeni[i])
        {
            brojac++;
            for (j = 2; j * i < broj; j++)
                slozeni[i * j] = 1;
        }

    return brojac;
}
void SrednjeVrednosti(int a, int srvr[2])
{
    int parni = 0, neparni = 0, cifra;
    double sumaP = 0, sumaNP = 0;
    int srvrP, srvrNP;
    while (a > 0)
    {
        cifra = a % 10;
        if (cifra % 2 == 0)
        {
            parni++;
            sumaP += cifra;
        }
        else
        {
            neparni++;
            sumaNP += cifra;
        }
        a /= 10;
    }
    srvrP = (int)floor(sumaP / parni);
    srvrNP = (int)ceil(sumaNP / neparni);
    srvr[0] = srvrP < 0 ? 0 : srvrP;
    srvr[1] = srvrNP < 0 ? 0 : srvrNP;
}

int* NajvecaPovrsinaVisinaVode(int stubovi[])
{
    int l = 0, r = 7, max1 = -1, a, b, p;
    int pronadjeni[] = { 0,0 };
    while (l < r)
    {
        a = r - l;
        b = stubovi[l] < stubovi[r] ? stubovi[l] : stubovi[r];
        p = a * b;
        if (p > max1)
        {
            max1 = p;
            pronadjeni[0] = l;
            pronadjeni[1] = r;
        }
        if (stubovi[l] < stubovi[r])
            l++;
        else
            r--;
    }
    return pronadjeni;
}
void PrikaziSpecStubove(int stubovi[], int levi, int desni, int  povrsina)
{
    int nivo = stubovi[levi] < stubovi[desni] ? stubovi[levi] : stubovi[desni];
    int i, j, k, razmak = 0;
    char tekst[3], pom[3];
    for (i = 10; i > 0; i--)
    {
        k = 0;
        for (j = 0; j < 17; j++)
        {
            strcpy(tekst, "  ");
            if (j < 16)
            {

                if ((j / 2) >= levi && (j / 2) < desni && i <= nivo) strcpy(tekst, "~~");
                else if (i == 1 && j < 19) strcpy(tekst, "__");
                if (j % 2 == 0)
                {
                    int tmp = i;
                    if (stubovi[k] >= tmp && (k == levi || k == desni))
                        strcpy(tekst, "||");
                    else if (stubovi[k] >= tmp - 1 && (k == levi || k == desni)) {
                        itoa(stubovi[k], pom, 10);
                        strcpy(tekst, strcat(pom, "m"));
                    }
                    k++;
                }
                
            }
            else if (i == 4)
            {
                printf("Povrsina: %d metara kvadratnih", povrsina);
                break;
            }
            printf("%s", tekst);
        }
        puts("");
    }
    puts("\n\n");
}
void JedanJedan(int b) {
    int max = -1, min = 10, tmp = b, pom;
    printf("\n\n****  odgovor 1  ****\n\n");
    
    while (tmp > 0)
    {
        pom = (int)(tmp % 10);
        if (pom > max) max = pom;
        if (pom < min) min = pom;
        tmp /= 10;
    }
    printf(" IZVESTAJ:\n");
    printf(" - Najmanja cifra u unetom broju je %d\n", min);
    printf(" - Najveca cifra u unetom broju je %d\n", max);
    printf(ObrniBroj(b) == b ? " - Broj je palindrom!" : " - Broj NIJE palindrom!");
}
void JedanDva(int *c) {
    int niz[10], broj=*c, i=5;
    while (broj > 0) {
        niz[i--] = broj % 10;
        broj /= 10;
    }
    *c = niz[0] * 100000 + niz[2] * 10000 + niz[4] * 1000 + niz[1] * 100 + niz[3] * 10 + niz[5] * 1;
	printf("\n\n****  odgovor 2  ****\n\n");
    printf("%d\n", PrebrojavanjeProstihBrojeva(*c));
}
void JedanTri(int a, int c, int* d)
{
    int srednje_vrednosti[2], broj = ObrniBroj(c), i;
    printf("\n\n****  odgovor 3  ****\n\n");
    
     SrednjeVrednosti(c, srednje_vrednosti);

    *d = srednje_vrednosti[0];
    printf("0: %d\n", *d);
    for (i = 1; i<7; i++)
    {
        *(d+i) = broj % 10;
        printf("%d: %d\n", i, *(d + i));
        broj /= 10;
    }
    *(d + 7) = srednje_vrednosti[1];
    printf("7: %d\n", *(d + 7));

    

}
void JedanCetiri(int d[])
{
    int i, j, k, tmp;
    char ispis[2];
    printf("\n\n****  odgovor 4  ****\n\n");
    for (i = 0; i <= 10; i++)
    {
        k = 0;
        for (j = 0; j < 16; j++)
        {
            if (j % 2 == 0)
            {
                if (i == 10)
                    printf("%d.", k++ + 1);
                else
                {
                    tmp = 10 - i;
                    if (d[k] == 0 && i == 8) printf("0m");
                    else if (d[k] >= tmp) printf("||");
                    else if (d[k] >= tmp - 1)
                    {
                        if (d[k] == 0) printf("__");
                        else printf("%dm", d[k]);
                    }
                    else
                        printf("  ");
                    k++;
                }
            }
            else if (i == 9 && j < 19) printf("__");
            else printf("  ");
        }
        puts("");
    }
    printf("\n\n");
}
void JedanPet(int d[]) {
    int *pronadjeni = NajvecaPovrsinaVisinaVode(d);
    int pLevi = *pronadjeni;
    int pDesni = *(pronadjeni+1);
    char tmp[3];
    printf("\n\n****  odgovor 5  ****\n\n");
    PrikaziSpecStubove(d, pLevi, pDesni, (pDesni - pLevi) * (d[pLevi]< d[pDesni]? d[pLevi]: d[pDesni]));
}