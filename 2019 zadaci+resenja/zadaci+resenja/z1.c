//Zadatak 1
//#include<stdio.h>
//main()
//{
//	int a, b, c, d[10], z, f[5][5], cifre[10], suma=0, i, j, k, pom[5], deljiv=0, brpon[]={0,0,0,0,0,0,0,0,0,0}, matpom[16], zpom, poc, kraj, broj, brel;
//	puts("***** ULAZ *****\n");
//	printf("\nUnesite 10-cifreni broj\n");
//	scanf("%d", &a);
//	printf("\nUnesite broj rotiranja\n");
//	scanf("%d", &z);
//	puts("\n***** IZLAZI *****");
//	///////////////////////////////
//	//Stavka 1.1
//	printf("\n***** odgovor 1 *****\n");
//	b=a;
//	i=9;
//	while(b>=1)
//	{
//		suma+=b%10;
//		b/=10;
//	}
//	printf("\nSrednja vrednost svih cifara je: %.2f\n", (float)suma/10);
//	///////////////////////////////
//	//Stavka 1.2
//	printf("\n***** odgovor 2 *****\n");
//	c=a;
//	while(c>=1)
//	{
//		cifre[i--]=c%10;
//		c/=10;
//	}
//	j=0;
//	for(i=0;i<5;i++)
//		pom[j++]=cifre[i]*10+cifre[9-i];
//	for(i=0;i<5;i++)
//	{
//		deljiv=0;
//		for(j=2;j<pom[i]-1;j++)
//			if(pom[i]%j==0) deljiv=1;
//		if(deljiv==0)printf("\nBroj %d je prost broj\n", pom[i]);
//	}
//	/////////////////////////////
//	//stavka 1.3
//	printf("\n***** odgovor 3 *****\n");
//	for(i=0;i<10;i++)
//		brpon[cifre[i]]++;
//	for(i=0;i<10;i++)
//		if(brpon[i]!=0)d[i]=brpon[i];
//		else d[i]=cifre[i];
//	for(i=0;i<10;i++)
//		printf("%d: %d\n", i, d[i]);
//	///////////////////////////////
//	//stavka 1.4
//	printf("\n***** odgovor 4 *****\n");
//	j=0;k=0;
//	for(i=0;i<10;i++)
//	{
//		f[j][k++]=d[i];
//		if(i==4)
//		{
//			j++;k=0;
//		}
//	}
//	for(i=2;i<5;i++)
//		for(j=0;j<5;j++)
//			f[i][j]=f[i-1][j]+f[i-2][j];
//	for(i=0;i<5;i++)
//	{
//		suma=0;
//		for(j=0;j<5;j++)
//			suma+=f[j][i];
//		f[i][i]=suma;
//	}
//	for(i=0;i<5;i++)
//	{
//		for(j=0;j<5;j++)
//			printf("%d\t", f[i][j]);
//		printf("\n");
//	}
//	//////////////////////////////
//	//stavka 1.5
//	printf("\n***** odgovor 5 *****\n");
//	
//	for(i=0;i<z;i++)
//	{
//		k=0;
//		poc=0;
//		kraj=4;
//		broj=0;
//		while(broj<2)
//		{
//			for(j=poc;j<=kraj;j++)
//				matpom[k++]=f[poc][j];
//			for (j=poc+1;j<kraj;j++)
//				matpom[k++]=f[j][kraj];
//			for(j=kraj;j>=poc;j--)
//				matpom[k++]=f[kraj][j];
//			for(j=kraj-1;j>=poc+1;j--)
//				matpom[k++]=f[j][poc];
//			brel=k;
//			zpom=matpom[0];
//			for(j=0;j<brel-1;j++)
//				matpom[j]=matpom[j+1];
//			matpom[k-1]=zpom;
//			k=0;
//			for(j=poc;j<=kraj;j++)
//				f[poc][j]=matpom[k++];
//			for (j=poc+1;j<kraj;j++)
//				f[j][kraj]=matpom[k++];
//			for(j=kraj;j>=poc;j--)
//				f[kraj][j]=matpom[k++];
//			for(j=kraj-1;j>=poc+1;j--)
//				f[j][poc]=matpom[k++];
//			broj++;
//			poc++;
//			kraj--;
//			k=0;
//		}
//	}
//	for(i=0;i<5;i++)
//	{
//		for(j=0;j<5;j++)
//			printf("%d\t", f[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}

