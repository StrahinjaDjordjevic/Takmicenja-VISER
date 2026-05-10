#pragma once
#include "main.h"
#define MAX_KARAKTERA 40

void SrediString(char *s){
	int i, j=0;
	for(i=0; i<strlen(s); i++){
		if(!isdigit(s[i]))
			s[j++]=s[i];
	}
	s[j]='\0';
	strlwr(s);

}
void DvaJedan(char *s1){
	int i, j, br1=0, br2=0, *provereni;
	char str[MAX_KARAKTERA], index;
	puts("\n****  odgovor 1  ****\n");
	strcpy(str, s1);
	strlwr(str);
	provereni=(int*)malloc(sizeof(int)*strlen(str));
    for(i=0; i<strlen(str); i++){
		if(provereni[i]==1 || isdigit(str[i])) continue;
		br1=br2;
		br2=1;
		for(j=i+1; j<strlen(str); j++){
			if(provereni[j]!=1 && str[j]==str[i]){
				br2++;
				provereni[j]=1;
			}
		}
		if(i>0 && br1!=br2){
			printf("Tekst nije uravnotezen!\n");
			return;
		}
	}
	printf("Tekst je uravnotezen!\n");
}
void DvaDva(char *s1){
	int max=0, i, n=0;
	puts("\n****  odgovor 2  ****");
	for(i=0; i<strlen(s1);i++){
		if (!isdigit(s1[i])) n++;
		else{
			if (n > max)max = n;
			n=0;
		}
	}
	if (n > max)max = n;
	printf("\n%d\n", max);
}
void DvaTri(char *s2){
	int i, j, k=0, m=0, suma=0, cifre[10];
	char novi[MAX_KARAKTERA*2];
	puts("\n****  odgovor 3  ****\n");
	for(i=0; i< strlen(s2); i++){
		if(isdigit(s2[i])){
			suma+=(s2[i++]-'0');
			while(suma>0){
				cifre[m++]=suma%10;
				suma/=10;
			}
			for(j=m-1; j>=0; j--)
				novi[k++]=cifre[j]+'0';
			suma=0;
			m=0;
		}
		suma+=s2[i];
		novi[k++]=s2[i];
	}
	novi[k]='\0';
	puts(novi);
}
void DvaCetiri(char *s3){
	int i, stepen=3, c, razlika;
	for(i=0; i<strlen(s3); i++){
		switch(tolower(s3[i])){
			case 'x':
				s3[i]=islower(s3[i])?'a':'A';
				break;
			case 'y': 
				s3[i]=islower(s3[i])?'b':'B';
				break;
			case 'z':
				s3[i]=islower(s3[i])?'c':'C';
				break;
			case '7':
				s3[i]='1';
				break;
			case '8': 
				s3[i]='2';
				break;
			case '9':
				s3[i]='3';
				break;
			default:
				s3[i]+=stepen;
		}
	}
	puts("\n****  odgovor 4  ****\n");
	puts(s3);
}
void DvaPet(char *s) {
	int mapa[128] = {0}, rezultat = 0;
    char* pocetak = s, *kraj = s;
	puts("\n****  odgovor 5  ****\n");
    SrediString(s);
    while (*kraj) {
        if (mapa[*kraj]) {
            rezultat = (kraj - pocetak > rezultat) ? kraj - pocetak : rezultat;
            while (*pocetak != *kraj) {
                mapa[*pocetak] = 0;
                pocetak++;
            }
            pocetak++;
            kraj++;
        }
        else {
            mapa[*kraj] = 1;
            kraj++;
        }  
    }
    printf("%d\n",kraj-pocetak > rezultat ? kraj-pocetak : rezultat);
}


