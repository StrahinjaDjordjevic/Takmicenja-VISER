//ZADATAK 2
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
main()
{
	char s[80+1], s1[80+1], s2[80+1],s3[80+1], mat[20][20], prikaz[5][27],c;
	int i, j, k, broj, brojslova=0, n, pom,niz[26];
	double x;
	puts("********* ULAZ **********");
	puts("Unesite string");
	gets(s);
	puts("\n");
	puts("********* odgovor 1 **********");
	//Izbacivanje iz stringa karaktera koji ne zadovoljavaju uslov
	n=0;
	for(i=0;i<strlen(s);i++)
		if(s[i]>=100 && s[i]<=110)s1[n++]=s[i];
	s1[n]='\0';
	puts(s1);
	puts("\n");
	puts("********* odgovor 2 **********");
	//Zamena karaktera po zahtevima iz zadatka
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>=97 && s[i]<=100)s2[i]='a';
		if(s[i]>=101 && s[i]<=104)s2[i]='b';
		if(s[i]>=105 && s[i]<=108)s2[i]='c';
		if(s[i]>=109 && s[i]<=112)s2[i]='d';
		if(s[i]>=113 && s[i]<=116)s2[i]='e';
		if(s[i]>=117 && s[i]<=120)s2[i]='f';
		if(s[i]>120) s2[i]='x';
	}
	s2[i]='\0';
	puts(s2);
	puts("\n");
	puts("********* odgovor 3 **********");
	strcpy(s3,s);
	broj=strlen(s3);
	//traženje odgovarajuæe velièine matrice
	x=sqrt(broj);
	if(x==(int)x)n=(int)x;
	else n=(int)x+1;
	//popuna matrice red po red karakterima iz stringa
	pom=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(pom>=broj)c='#';
			else c=s3[pom++];
			mat[i][j]=c;
		}
	}
	//popuna stringa karakterima iz matrice kolona po kolona
	pom=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			s3[pom++]=mat[j][i];
	s3[pom]='\0';
	puts(s3);
	puts("\n");
	puts("********* odgovor 4 **********");
	//prebrojavanje broja ponavljanja karaktera
	for(i=0;i<26;i++)
		niz[i]=0;
	for(i=0;i<broj;i++)
		niz[s[i]-'a']++;
	//Štampanje broja ponavljanja karaktera
	for(i=0;i<26;i++)
		if(niz[i]!=0)printf("%c: %d\n", i+'a', niz[i]);
	puts("");
	puts("********* odgovor 5 **********\n");
	//kreiranje matrice za prikaz i popunjavanje poèetnim vrednostima
	for(i=0;i<4;i++)
		for(j=0;j<27;j++)
			prikaz[i][j]=' ';
	//popunjavanje brojeva 1, 2, 3
	for(i=1;i<4;i++)
		prikaz[i][0]=i+'0';
	//popunjavanje slova a-z
	for(i=0;i<26;i++)
		prikaz[0][i+1]=i+'a';
	//popunjavanje histograma sa *
	for(i=0;i<4;i++)
	{
		for(j=0;j<26;j++)
			if(niz[j]>i)prikaz[i+1][j+1]='*';		
	}
	//popunjavanje histograma sa +
	for(j=0;j<26;j++)
	{
		if(niz[j]>3)prikaz[3][j+1]='+';
	}
	for(i=3;i>=0;i--)
	{
		for(j=0;j<27;j++)
		{
			printf("%c ", prikaz[i][j]);
		}
		printf("\n");
	}
	puts("\n");
	
}