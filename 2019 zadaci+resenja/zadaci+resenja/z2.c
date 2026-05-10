////Zadatak 2
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
main()
{
	char s[80+1], s2[80+1], s3[80+1], s4[80+1], s5[80+1], mat[10][80+1], pom[80+1], pom1[80+1], c;
	int i, j, k, l, m, pal=1,bra=0, brb=0, brc=0, brd=0, brslova, brizmena, imastr, imamat, brstr;
	puts("***** ULAZ *****\n");
	puts("Unesite string");
	gets(s);
	puts("\n***** IZLAZI *****");
	///////////////////////////
	//stavka 2.1
	puts("\n***** odgovor 1 *****\n");
	l=strlen(s);
	for(i=0;i<l;i++)
		if(tolower(s[i])!=tolower(s[l-1-i]))
		{
			pal=0;
			break;
		}
	if(pal)puts("String je palindrom");
	else puts("String nije palindrom");
	////////////////////////////////
	//stavka 2.2
	puts("\n***** odgovor 2 *****\n");
	strcpy(s2, s);
	j=0;
	for(i=0;i<l;i++)
		if(isdigit(s2[i]) && isupper(s2[i+1]) && islower(s2[i+2]))
		{
			if((s2[i+1]+(s2[i]-'0'))<='Z')s2[j++]=s2[i+1]+(s2[i]-'0');
			else s2[j++]='A'+((s2[i]-'0')-('Z'-s2[i+1]+1));
			i+=2;
		}
		else
			s2[j++]=s[i];
	s2[j]='\0';
	puts(s2);
	//////////////////////////////
	//stavka 2.3
	puts("\n***** odgovor 3 *****\n");
	strcpy(s3, s);
	//puts(s3);
	j=0;
	for(i=0;i<l;i++)
		if(isdigit(s3[i])) s3[j++]='a'+(s3[i]-'0');
		else
		{
			if(isupper(s3[i]))s3[j++]=tolower(s3[i]);
			else s3[j++]=s3[i];
		}
	s3[j]='\0';
	//puts(s3);
	for(i=0;i<j;i++)
		if(s3[i]<=103)
		{
			s3[i]='a';
			bra++;
		}
		else if(s3[i]>=104 && s3[i]<=110)
		{
			s3[i]='b';
			brb++;
		}
		else if(s3[i]>=111 && s3[i]<=117)
		{
			s3[i]='c';
			brc++;
		}
		else 
		{
			s3[i]='d';
			brd++;
		}
	//puts(s3);
	brslova=strlen(s3)/4;
	if(bra!=brslova)brizmena=abs(brslova-bra);
	if(brb!=brslova)brizmena+=abs(brslova-brb);
	if(brc!=brslova)brizmena+=abs(brslova-brc);
	if(brd!=brslova)brizmena+=abs(brslova-brd);
	printf("\nBroj izmena: %d\n", brizmena/2);
	/////////////////////////////////////////
	//stavka 2.4
	puts("\n***** odgovor 4 *****\n");
	if(!isdigit(s[0]))
	{
		strcpy(s4, "0");
		strcat(s4, s);
	}
	else
		strcpy(s4, s);
	//puts(s4);
	j=0; k=0;
	l=strlen(s4);
	for(i=0;i<l;i++)
	{
		if(isdigit(s4[i]) && i>0)
		{
			mat[j][k]='\0';
			j++;k=0;
		}
		mat[j][k++]=s4[i];
	}
	mat[j][k]='\0';
	brstr=j+1;
	//for(i=0;i<j+1;i++)
	//{
	//	puts(mat[i]);
	//}
	for(i=0;i<brstr;i++)
		for(l=i+1;l<j+1;l++)
			if(strcmp(mat[i], mat[l])>0)
			{
				strcpy(pom, mat[i]);
				strcpy(mat[i], mat[l]);
				strcpy(mat[l], pom);
			}
	strcpy(s4,"");
	for(i=0;i<j+1;i++)
		strcat(s4, mat[i]);
	puts(s4);
	//////////////////////////////
	//stavka 2.5
	puts("\n***** odgovor 5 *****\n");
	if(!isdigit(s[0]))
	{
		strcpy(s5, "0");
		strcat(s5, s);
	}
	else
		strcpy(s5, s);
	l=strlen(s5);
	//puts(s5);
	j=0; k=0;
	for(i=0;i<l;i++)
	{
		if(isdigit(s5[i]) && i>0)
		{
			mat[j][k]='\0';
			j++;k=0;
		}
		mat[j][k++]=s5[i];
	}
	mat[j++][k]='\0';
	brstr=j;
	m=0;
	for(i=1;i<strlen(mat[0]);i++)
	{
		imamat=1;
		c=mat[0][i];
		for(j=1;j<brstr;j++)
		{
			imastr=0;
			for(k=1;k<strlen(mat[j]);k++)
				if(mat[j][k]==c)
				{
					imastr=1;
					break;
				}
			if(imastr==0)
			{
				imamat=0;
				break;
			}
		}
		if(imamat)pom[m++]=c;
	}
	pom[m]='\0';
	strcpy(s5, "");
	for(i=0;i<brstr;i++)
		strcat(s5, mat[i]);
	for(i=0;i<m;i++)
	{
		k=0;
		for(j=0;j<strlen(s5);j++)
		{
			if(s5[j]==pom[i])continue;
			else s5[k++]=s5[j];	
		}
		s5[k]='\0';
	}
	puts(s5);
}