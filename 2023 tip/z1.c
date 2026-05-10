#include<stdio.h>
main(){
	int a, b, c, niza[5], nizb[5], nizc[5], cifre[]={0,0,0,0,0,0,0,0,0,0}, d[10], mat[11][11], pomm[11][11], i, j, k, n, m, suma1=0, suma2=0, sumak=0, poma, pomb, pom, pomc, ip;
	float srvr1, srvr2;
	puts("Unesite dva petocifrena broja");
	scanf("%d%d", &a, &b);
	puts("\n\n******** odgovor 1 ***********\n");
	poma=a;
	pomb=b;
	for(i=0;i<5;i++){
		suma1+=a%10;
		a/=10;
		suma2+=b%10;
		b/=10;
	}
	srvr1=suma1/5.;
	srvr2=suma2/5.;
	
	printf("\nSrednja vrednost cifara broja %d je %.2f\n", poma, srvr1);
	printf("\nSrednja vrednost cifara broja %d je %.2f\n", pomb, srvr2);

	puts("\n\n******** odgovor 2 ***********\n");
	a=poma;
	b=pomb;
	pom=1;
	c=0;
	for(i=0;i<5;i++){
		n=a%10+b%10;
		if(n>9)n%=10;
		c+=n*pom;
		a/=10;
		b/=10;
		pom*=10;
	}
	printf("\nNovonastali broj c je %d\n", c);

	puts("\n\n******** odgovor 3 ***********,\n");
	pomc=c;
	for(i=0;i<5;i++){
		cifre[c%10]++;
		c/=10;
	}
	c=pomc;
	for(i=9;i>0;i-=2){
		d[i]=c%10;
		d[i-1]=cifre[c%10];
		c/=10;
	}
	for(i=0;i<10;i++)
		printf("%d\t", d[i]);
	puts("\n\n******** odgovor 4 ***********\n");
	for(i=0;i<10;i++){
		for(j=0;j<10;j++)
			mat[i][j]=d[j];
		pom=d[0];
		for(j=0;j<9;j++)
			d[j]=d[j+1];
		d[9]=pom;
	}
	for(i=0;i<10;i++){
		sumak=0;
		for(j=0;j<10;j++)
			if((i+j)>=9)sumak+=mat[i][j];
		mat[10][i]=sumak;
	}

	for(i=0;i<11;i++){
		for(j=0;j<10;j++)
			printf("%d\t", mat[i][j]);
		puts("");
	}
	puts("");
	puts("\n\n******** odgovor 5 ***********\n");
	for(i=0;i<11;i++){
		for(j=0;j<10;j++)
			pomm[i][j]=mat[i][j];
	}
	for(i=0;i<10;i++)        
        for(j=0;j<11;j++)        
            mat[i][j] = pomm[j][10-1-i];
	for(i=0;i<10;i++){
		for(j=0;j<11;j++)
			printf("%d\t", mat[i][j]);
		puts("");
	}

}