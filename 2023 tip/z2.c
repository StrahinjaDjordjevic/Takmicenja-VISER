#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
main(){
	char s[80], mat[10][80], pom[80], testk, s4[100], c, s5[100];
	int i, j, n, m, palindrom=1, l, aski, broj, brpon[52]={0}, min, max;
	double x;

	puts("Unesite string (4 x N):");
	gets(s);
	/*strcpy(s, "XpcDE1234ffedcba");
	strcpy(s,"Ja1IDemU23SkoLU4");
	strcpy(s,"aaaassssddddffffgggg");
	puts(s);*/
	puts("\n********** odgovor 1 *************\n");
	l=strlen(s);
	printf("\nDuzina stringa: %d\n", l);
	for(i=0;i<l/2;i++)
		if(tolower(s[i])!=tolower(s[l-i-1])){
			palindrom=0;
			break;
		}
	if(palindrom) puts("Uneti string JESTE palindrom");
	else puts("Uneti string NIJE palindrom");

	puts("\n********** odgovor 2 *************\n");
	n=l/4;m=-1;
	for(i=0;i<l;i++){
		if((i%4)==0)m++;
		mat[i%4][m]=s[i];
	}
	for(i=0;i<n;i++){
		mat[i][m+1]='\0';
	}
	for(i=0;i<n;i++)
		printf("%d: %s\n", i, mat[i]);

	puts("\n********** odgovor 3 *************\n");
	
	for(i=0;i<n;i++){
		m=0;
		for(j=0;j<4;j++){
			pom[m++]=mat[i][j];
			testk=mat[i][j];
			if(testk>='0' && testk<='9')m--;
			if(testk>='a' && testk<='z')
				while(testk<='z'-10){
					pom[m++]=testk+10;
					testk+=10;
				}
			if(testk>='A' && testk<='Z')
				while(testk<='Z'-10){
					pom[m++]=testk+10;
					testk+=10;
				}
		}
		pom[m]='\0';
		strcpy(mat[i], pom);

	}

	for(i=0;i<n;i++)
		printf("%d: %s\n", i, mat[i]);

	puts("\n********** odgovor 4 *************\n");
	strcpy(s4, "");
	for(i=0;i<n;i++) strcat(s4, mat[i]);
	printf("%s\n", s4);
	for(i=0;i<strlen(s4);i++)
		if(isupper(s4[i]))brpon[s4[i]-'A']++;
		else brpon[s4[i]-'a'+26]++;
		max=brpon[0];
		min=1;
		for(i=0;i<52;i++){
			if(brpon[i]==0)continue;
			if(brpon[i]>max)max=brpon[i];
			if(brpon[i]<min)min=brpon[i];
		}
		printf("Maksimalno pojavljivanje slova je: %d\n", max);
		for(i=0;i<52;i++){
			if(i<26) c='A'+i;
			else c='a'+i-26;
			if(brpon[i]==max)printf("%c, ", c);
		}

		printf("\n\nMinimalno pojavljivanje slova je: %d\n", min);
		for(i=0;i<52;i++){
			if(i<26) c='A'+i;
			else c='a'+i-26;
			if(brpon[i]==min)printf("%c, ", c);
		}
		

	puts("\n********** odgovor 5 *************\n");
	broj=strlen(s4);
	//traženje odgovarajuce velicine matrice
	x=sqrt(broj);
	if(x==(int)x)n=(int)x;
	else n=(int)x+1;
	//popuna matrice red po red karakterima iz stringa
	l=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(l>=broj)c='#';
			else{
				if(s4[l]>='a' && s4[l]<='z') c=s4[l++]-j;
				else c=s4[l++]+j;
			} 
			mat[i][j]=c;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%c\t", mat[i][j]);
		}
		printf("\n");
	}
}