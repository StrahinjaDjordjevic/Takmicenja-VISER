#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 20
void iscrtajBastu();
void promeniBastu(int x, int y, char c);
void pomeriPsa();
void pomeriZeca();
void kretanjeZeca();
void kretanjePsa();
void definisiBastu();
void iscrtajBastuSaZecom();
void iscrtajBastuSaZecomIPsom();
void iscrtaj3();
void iscrtaj4();
float izracunajProcenat();
int abs(int x);
struct tacka{
	int x;
	int y;
};
struct tacka pas, zec;

char basta[20][20], prethodno='-';
struct tacka unistenaPoljaZec[MAX], poljaPas[MAX];
int Xp, Yp, Xz, Yz, brojPas=0, brojZec=0,  kraj=0, kretanjeZecX=0, kretanjeZecY=0, kretanjePasX=0, kretanjePasY=0;
float procenat;
main(){
	int i, j;
	definisiBastu();
	
	puts("Unesite ulazne podatke");
	scanf("%d %d", &Xp, &Yp);
	scanf("%d %d", &Xz, &Yz);
	
	
		
	//Xp=7; Yp=3; Xz=7; Yz=15;
	//Xp=10; Yp=3; Xz=5; Yz=13;
	printf("\nUneti podaci: %d %d, %d %d\n", Xp, Yp, Xz, Yz);
	pas.x=Xp; pas.y=Yp;
	zec.x=Xz; zec.y=Yz;
	poljaPas[brojPas].x=pas.x;
	poljaPas[brojPas++].y=pas.y;
	unistenaPoljaZec[brojZec].x=zec.x;
	unistenaPoljaZec[brojZec++].y=zec.y;
	puts("\n************ Odgovor 1 *************\n");
	iscrtajBastu();

	puts("\n************ Odgovor 2 *************\n");
	promeniBastu(pas.x, pas.y, 'P');
	promeniBastu(zec.x, zec.y, 'Z');
	iscrtajBastu();
	definisiBastu();


	puts("\n************ Odgovor 3 *************\n");
	kretanjeZeca();
	while(1){
		pomeriPsa();
		if(kraj>0)break;
		pomeriPsa();
		if(kraj>0)break;
		pomeriPsa();
		if(kraj>0)break;
		pomeriZeca();
		if(kraj>0)break;
	}
	//iscrtajBastuSaZecom();
	//iscrtajBastuSaZecomIPsom();
	puts("");
	definisiBastu();
	if(kraj==2)promeniBastu(pas.x, pas.y, 'W');
	else promeniBastu(pas.x, pas.y, 'L');
	iscrtaj3();
	puts("\n************ Odgovor 4 *************\n");
	definisiBastu();
	iscrtaj4();

	puts("\n************ Odgovor 5 *************\n");
	procenat=izracunajProcenat();
	printf("\nProcenat unistenih polja je %.2f\n\n\n", procenat);
	


}

void iscrtajBastu(){
	int i, j;

	for(i=0;i<MAX;i++){
		//printf("%d:", i+1);
		for(j=0;j<MAX;j++)
			printf("%c ", basta[i][j]);
		printf("\n");
	}
		
}

void promeniBastu(int x, int y, char c){
	basta[x][y]=c;
}

void pomeriPsa(){
	kretanjePsa();
	pas.x+=kretanjePasX;
	pas.y+=kretanjePasY;
	poljaPas[brojPas].x=pas.x;
	poljaPas[brojPas++].y=pas.y;
	if(pas.x==zec.x && pas.y==zec.y){
		kraj=2;
	}
	//printf("Pas: %d, %d, %d\n",pas.x, pas.y, brojPas);
}

void pomeriZeca(){
	zec.x+=kretanjeZecX;
	zec.y+=kretanjeZecY;
	if(zec.x<0 || zec.y<0 || zec.x>19 || zec.y>19){
		kraj=1;
		return;
	}
	unistenaPoljaZec[brojZec].x=zec.x;
	unistenaPoljaZec[brojZec++].y=zec.y;
	//printf("Zec: %d, %d, %d\n",zec.x, zec.y, brojZec);
	
}

void kretanjeZeca(){
	int razdaljine[4]={0}, i, min, razdaljina1=-1,razdaljina2=-1 ,broj=0;
	razdaljine[0]=abs(zec.x - 0);
	razdaljine[1]=abs(zec.y - (20 - 1));
	razdaljine[2]=abs(zec.x - (20 - 1));
	razdaljine[3]=abs(zec.y - 0);
	//for(i=0;i<4;i++)
	//	printf("%d  ", razdaljine[i]);
	min=razdaljine[0];
	for(i=0;i<4;i++)
		if(razdaljine[i]<min)min=razdaljine[i];
	//printf("\n%d\n", min);
	for(i=0;i<4;i++)
		if(razdaljine[i]==min){
			if(razdaljina1==-1)razdaljina1=i;
			else razdaljina2=i;
		}
	//printf("\n%d %d\n", razdaljina1, razdaljina2);		
	if(razdaljina2!=-1){
		if((razdaljina1==0 && razdaljina2==1) || (razdaljina1==1 && razdaljina2==0))razdaljina1=1;
		if((razdaljina1==1 && razdaljina2==2) || (razdaljina1==2 && razdaljina2==1))razdaljina1=2;
		if((razdaljina1==2 && razdaljina2==3) || (razdaljina1==3 && razdaljina2==2))razdaljina1=3;
		if((razdaljina1==3 && razdaljina2==0) || (razdaljina1==0 && razdaljina2==3))razdaljina1=0;

	}
	//printf("\n%d %d\n", razdaljina1, razdaljina2);	
	switch(razdaljina1){
	case 0:
		kretanjeZecX=-1;
		kretanjeZecY=0;
		break;
	case 1:
		kretanjeZecX=0;
		kretanjeZecY=1;
		break;
	case 2:
		kretanjeZecX=1;
		kretanjeZecY=0;
		break;
	case 3:
		kretanjeZecX=0;
		kretanjeZecY=-1;
		break;
	}



}

void kretanjePsa(){
	int razlikaX, razlikaY;
	razlikaX=pas.x-zec.x;
	razlikaY=pas.y-zec.y;
	if(razlikaX==0)kretanjePasX=0;
	if(razlikaX>0)kretanjePasX=-1;
	if(razlikaX<0)kretanjePasX=1;
	if(razlikaY==0)kretanjePasY=0;
	if(razlikaY>0)kretanjePasY=-1;
	if(razlikaY<0)kretanjePasY=1;
}
void definisiBastu(){
	int i, j;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++)
			promeniBastu(i, j, '-');
	}
}
int abs(int x) {
    return (x < 0) ? -x : x; 
}
void iscrtajBastuSaZecom(){
	int i, j;
	
	for(i=0;i<brojZec;i++)
		if(basta[unistenaPoljaZec[i].x][unistenaPoljaZec[i].y]=='-')promeniBastu(unistenaPoljaZec[i].x, unistenaPoljaZec[i].y, 'O');
	/*
	promeniBastu(pas.x, pas.y, 'P');
	promeniBastu(zec.x, zec.y, 'Z');*/
	for(i=0;i<MAX;i++){
		//printf("%d:", i+1);
		for(j=0;j<MAX;j++)
			printf("%c ", basta[i][j]);
		printf("\n");
	}
		
}

void iscrtajBastuSaZecomIPsom(){
	int i, j;
	
	for(i=0;i<brojPas;i++)
		promeniBastu(poljaPas[i].x, poljaPas[i].y, 'X');
	for(i=0;i<brojZec;i++)
		promeniBastu(unistenaPoljaZec[i].x, unistenaPoljaZec[i].y, 'O');
	
	/*promeniBastu(pas.x, pas.y, 'P');
	promeniBastu(zec.x, zec.y, 'Z');*/
	for(i=0;i<MAX;i++){
		//printf("%d:", i+1);
		for(j=0;j<MAX;j++)
			printf("%c ", basta[i][j]);
		printf("\n");
	}
		
}

void iscrtaj3(){
	int i, j;
	for(i=0;i<MAX;i++){
		//printf("%d:", i+1);
		for(j=0;j<MAX;j++)
			printf("%c ", basta[i][j]);
		printf("\n");
	}
		
}

void iscrtaj4(){
	int i, j;
	definisiBastu();
	for(i=0;i<brojZec;i++)
		if(basta[unistenaPoljaZec[i].x][unistenaPoljaZec[i].y]=='-')promeniBastu(unistenaPoljaZec[i].x, unistenaPoljaZec[i].y, 'O');
	for(i=0;i<brojPas;i++)
		if(basta[poljaPas[i].x][poljaPas[i].y]=='-')promeniBastu(poljaPas[i].x, poljaPas[i].y, 'X');
		else promeniBastu(poljaPas[i].x, poljaPas[i].y, 'Y');
	for(i=0;i<MAX;i++){
		//printf("%d:", i+1);
		for(j=0;j<MAX;j++)
			printf("%c ", basta[i][j]);
		printf("\n");
	}		
}

float izracunajProcenat(){
	int i, j;
	float procenat,ukupnoPolja;
	definisiBastu();
	for(i=0;i<brojZec;i++)
		promeniBastu(unistenaPoljaZec[i].x, unistenaPoljaZec[i].y, 'O');
	for(i=0;i<brojPas;i++)
		if(basta[poljaPas[i].x][poljaPas[i].y]=='-')promeniBastu(poljaPas[i].x, poljaPas[i].y, 'X');
	//iscrtajBastuSaZecomIPsom();
	brojPas=0;
	brojZec=0;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++){
			if(basta[i][j]=='X')brojPas++;
			if(basta[i][j]=='O' || basta[i][j]=='Y')brojZec++;
		}
	//printf("\nPas: %d\nZec: %d\n\n", brojPas, brojZec);		
		
	ukupnoPolja=(float)brojZec+brojPas/2.;
	//printf("\nBroj polja: %.2f\n\n", ukupnoPolja);	
	procenat=ukupnoPolja/4;
	return procenat;
}




