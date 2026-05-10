#include<stdio.h>
#include<math.h>
struct Tacka{
	int x;
	int y;
	char ime;
};
char mat[20][20]; 
int  n;
struct Tacka niz[10];
void stampa();
main()
{
	char t1, t2, t3;
	int i,j,z, minp=0, maxt=0, maxx, miny, minx, maxy;
	float maxr=0, pom;
	puts("******* ULAZ *******");
	puts("Unesite broj tacaka (3-10)");
	scanf("%d", &n);
	//Unos taèaka u zadatom formatu
	for(i=0;i<n;i++)
	{
		printf("Unesite tacku %d (x koordinata, y koordinata, ime)\n", i+1);
		scanf("%d,%d,%c", &niz[i].x, &niz[i].y, &niz[i].ime);
	}
	puts("******* odgovor 1 *******");
	puts("");
	//formiranje koordinatnog sistema u vidu matrice sa poèetnim vrednostima
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		{
			if(i==0)
				mat[i][j]='-';
			else if(j==0)
				mat[i][j]='|';
			else
				mat[i][j]='.';
			mat[0][0]='0';

		}
	//Ubacivanje taèaka u koordinatni sistem
	for(i=0;i<n;i++)
		mat[niz[i].y][niz[i].x]=niz[i].ime;
	stampa();
	puts("");
	puts("******* odgovor 2 *******");
	//traženje najdužeg rastojanja izmeðu dve taèke metodom lažne pretpostavke
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			pom=sqrt(pow((niz[i].x-niz[j].x),2)+pow((niz[i].y-niz[j].y),2));
			if(pom>maxr)//obezbeðivanje da se zapamte najranije unete taèke
			{
				maxr=pom;
				t1=niz[i].ime;
				t2=niz[j].ime;
			}
		}
	printf("\nNajduze rastojanje je izmedju %c i %c, i iznosi %.2f\n", t1, t2, maxr);
	puts("");
	puts("******* odgovor 3 *******");

	minp=421;//Maksimalna površina na osnovu ulaznih parametara
	//traženje najmanje površine pravougaonika koji se može formirati
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			pom=abs((niz[i].x-niz[j].x)*(niz[i].y-niz[j].y));
			if(pom<minp && ((niz[i].x!=niz[j].x) && (niz[i].y!=niz[j].y)))
			{
				minp=pom;
				t1=niz[i].ime;
				t2=niz[j].ime;
			}
		}
	printf("\nNajmanja povrsina pravougaonika je izmedju %c i %c, i iznosi %d\n", t1, t2, minp);
	puts("");
	puts("******* odgovor 4 *******");
	//Traženje broja trouglova na osnovu uslova da im je površina veæa od 0
	maxt=0;
	for(i=0;i<n-2;i++)
		for(j=i+1;j<n-1;j++)
			for(z=j+1;z<n;z++)
				{
					pom=fabs((((float)niz[j].x-niz[i].x)*(niz[j].y+niz[i].y)+(niz[z].x-niz[j].x)*(niz[z].y+niz[j].y)+(niz[i].x-niz[z].x)*(niz[i].y+niz[z].y))/2.);
					if(pom>0)maxt++;
	
				}
	printf("\nTacke mogu da formiraju %d trouglova\n",maxt);
	puts("");
	puts("******* odgovor 5 *******");
	//Traženje graniènih vrednosti za pravougaonik
	maxx=minx=niz[0].x;
	miny=maxy=niz[0].y;
	for(i=0;i<n;i++)
	{
		if(niz[i].x>maxx) maxx=niz[i].x;
		if(niz[i].x<minx) minx=niz[i].x;
		if(niz[i].y<miny)miny=niz[i].y;
		if(niz[i].y>maxy)maxy=niz[i].y;
	}
	//Ubacivanje pravougaonika u matricu
	for(i=miny;i<=maxy;i++)
		for(j=minx;j<=maxx;j++)
			if(mat[i][j]=='.')
				if(i==miny || i==maxy || j==minx || j==maxx) mat[i][j]='*';
	stampa();
	puts("\n");
}
	


void stampa()
{
	//Štampanje matrice
	int i,j;
	for(i=19;i>=0;i--)
	{
		for(j=0;j<20;j++)
		{
			printf("%c ",mat[i][j]);
		}
		printf("\n");
	}
}