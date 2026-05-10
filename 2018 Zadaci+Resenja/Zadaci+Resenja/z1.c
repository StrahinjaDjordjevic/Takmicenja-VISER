#include<stdio.h>
#include<math.h>
main()
{
	int N, a[50], b[50], c[50],d[50],f[50][51], y, x, z, i, j, k, pom, suma=0,  najblizi=0;
	float srvr, min;
	////////////////////////
	//Ulaz
	puts("********* ULAZ **********");
	//Unos ulaznih podataka sa proverom opsega
	do{
		puts("Unesite broj elemenata niza N");
		scanf("%d", &N);
		if(N<5 || N>50)puts("Broj nije u opsegu");
	}while(N<5 || N>50);
	puts("Unesite elemente niza");
	for(i=0;i<N;i++)
		scanf("%d", &a[i]);
	do{
		puts("Unesite celobrojnu vrednost x");
		scanf("%d", &x);
		if(x<-50 || x>50)puts("Broj nije u opsegu");
	}while(x<-50 || x>50);
	do{
		puts("Unesite broj izmena y");
		scanf("%d", &y);
		if(y<1 || y>10)puts("Broj nije u opsegu");
	}while(y<1 || y>10);
	puts("Unesite broj rotacija z");
	scanf("%d", &z);

	////////////////////////////////
	// 1
	puts("\n******* odgovor 1 ********");

	for(i=0;i<N;i++)
		b[i]=a[i];
	//Sortiranje u neopadajuæi poredak
	for(i=0;i<N-1;i++)
		for(j=i+1;j<N;j++)
			if(b[i]>=b[j])
			{
				pom=b[i];b[i]=b[j];b[j]=pom;
			}
	//Ubacivanje elementa na odgovarajuæe mesto
	for(pom=N,i=N-1;i>=0;i--, pom--)
	{
		if(b[i]<x)
		{
			b[pom]=x;
			break;
		}
		b[pom]=b[i];
	}
	for(i=0;i<=N;i++)
		printf("%d ", b[i]);
	puts("\n");
	//////////////////////////////
	// 2
	puts("\n******* odgovor 2 ********");
	for(i=0;i<N;i++)
		c[i]=a[i];
	//Traženje neparnog elementa sa parnim indeksom i njegova promena vrednosti
	for(i=0;i<N;i++)
		if(((i%2)==0) && ((c[i]%2)!=0)) c[i]=c[i]^i;
	//Suma
	for(i=0;i<N;i++)
		suma+=c[i];
	//srednja vrednost
	srvr=(float) suma/N;
	//traženje najbližeg elementa srednjoj vrednosti niza
	min=fabs(c[0]-srvr);
	najblizi=0;
	for(i=0;i<N;i++)
	{
		if(fabs(c[i]-srvr)<min)
		{
			min=fabs(c[i]-srvr); 
			najblizi=i;
		}
	}	
	//Izbacivanje elementa
	pom=0;
	for(i=0;i<N;i++)
	{
		if(i==najblizi) continue;
		c[pom++]=c[i];
	}
	for(i=0;i<N-1;i++)
		printf("%d ", c[i]);
	puts("\n");
	//////////////
	// 3
	puts("\n******* odgovor 3 ********");
	//kreiranje niza po zahtevima iz zadatka
	for(i=0;i<N;i++)
	{
		d[i]=a[i]%10;
		if(d[i]<0)d[i]*=-1;
	}
	//izmena cifre najveæe težine ako je 0
	if(d[0]==0)d[0]=1;
	//traženje broja palindroma
	for(i=0;i<N/2;i++)
	{
		if(y>0)
		{
			if(d[i]==d[N-i-1])continue;
			if(d[i]<d[N-i-1])d[i]=d[N-i-1];
			else d[N-i-1]=d[i];
			y--;
		}
		else
			break;
	}
	//Maksimizacija broja ako je ostalo još više od jedne izmene
	for(i=0;i<N/2;i++)
		if(y>=2)
		{
			if(d[i]!=9)
			{
				d[i]=9;d[N-i-1]=9;
				y-=2;
			}
		}
		else 
			break;
	//Maksimizacija broja ako je ostala još jedna izmena i broj ima neparan broj cifara
	if(y>0 && (N%2)!=0) 
	{
		if(d[N/2]!=9)
		{
			d[N/2]=9;
			y--;
		}
	}
	//Provera da li je rezultujuæi broj broj palindrom
	pom=1;
	for(i=0;i<N/2;i++)
		if(d[i]!=d[N-i-1]) pom=0;
	if(pom)
	{
		for(i=0;i<N;i++)
			printf("%d ", d[i]);
		printf("\nPreostali broj izmena: %d", y);
	}
	else
		puts("Nije moguce napraviti palindrom sa datim brojem izmena");
	puts("\n");
	//////////////
	// 4
	puts("\n******* odgovor 4 ********");
	//odreðivanje sume i prvog reda matrice
	suma=0;
	for(i=0;i<N;i++)
		suma+=a[i];
	f[0][0]=suma;
	for(i=0;i<N;i++)
		f[0][i+1]=a[i];
	//odreðivanje ostalih elemenata matrice red po red
	for(i=1;i<N;i++)
	{
		suma+=N;
		for(j=0;j<=N;j++)
		{
			if(j==0)f[i][j]=suma;
			else f[i][j]=f[i-1][j]+1;	
		}
	}
	//Štampa 
	for(i=0;i<N;i++)
	{
		for(j=0;j<=N;j++)
			printf("%d\t",f[i][j]);
		printf("\n");
	}
	//////////////
	// 5
	puts("\n******* odgovor 5 ********");
	//rotacija matrice po zahtevima iz zadatka
	for(k=0;k<z;k++)
		for(i=0;i<=N;i++)
		{
			if((i%2)==0)
			{
				pom=f[N-1][i];
				for(j=N-1;j>0;j--)
				{
					f[j][i]=f[j-1][i];
				}
				f[0][i]=pom;
			}
			else
			{
				pom=f[0][i];
				for(j=0;j<N-1;j++)
				{
					f[j][i]=f[j+1][i];
				}
				f[N-1][i]=pom;
			}
		}

	for(i=0;i<N;i++)
	{
		for(j=0;j<=N;j++)
			printf("%d\t",f[i][j]);
		printf("\n");
	}
	puts("\n");
}