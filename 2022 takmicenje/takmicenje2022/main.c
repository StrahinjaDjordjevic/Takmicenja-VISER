#include "prvi.h"
#include "drugi.h"
#include "treci.h"
void PrviZadatak(){
	int a, b, c, d[MAX_STUBOVA];
	printf("****  ULAZ  ****\n\n");
	printf("Unesite 6-cifreni broj\n");
	scanf("%d", &a);
	printf("\n\n****  IZLAZI  ****\n");
	b = a;
	JedanJedan(b);
	c = a;
	JedanDva(&c);
	JedanTri(a, c, d);
	JedanCetiri(d);
	JedanPet(d);
}
void DrugiZadatak() {
	char s1[MAX_KARAKTERA], s2[MAX_KARAKTERA], s3[MAX_KARAKTERA], s4[MAX_KARAKTERA];
	char *s5;
	puts("****  ULAZ  ****\n");
	gets(s1);
	puts("\n****  IZLAZI  ****");
	DvaJedan(s1);
	DvaDva(s1);
	strcpy(s2, s1);
	DvaTri(s2);
	strcpy(s3, s1);
	DvaCetiri(s3);
	strcpy(s4, s1);
	DvaPet(s4);
}
void TreciZadatak(){
	int n, m, k;
	char tabla[MAX_M][MAX_M], unos[MAX_KARAKTERA+1], *parametri;
	puts("****  ULAZ  ****");
	gets(unos);
	parametri = strtok(unos, " ");
	while (parametri != NULL)
	{
		switch (parametri[0]) {
			case Zarazen:
				Z.x = parametri[2] - '0' - 1;
				Z.y = parametri[1] - '0' - 1;
				Z.s = Zarazen;
				break;
			case Otporan:
				I.x = parametri[2] - '0' - 1;
				I.y = parametri[1] - '0' - 1;
				I.s = Otporan;
				break;
			case '-':
				k= parametri[1] - '0';
				break;
			default:
				n = parametri[1] - '0';
				m = parametri[0] - '0';
		}
		parametri = strtok(NULL, " ");
	}
	printf("\n****  IZLAZI  ****\n");
	TriJedan(tabla, n, m);
	TriDva(tabla, n, m, k);
	TriTri(tabla, n, m);
	TriCetiri(tabla, n, m, k);
	TriPet(tabla, n, m, k);

}


int main(){
	int unos = 0;
	while (1) {
		printf("1. Prvi zadatak\n2. Drugi zadatak\n3. Treci zadatak\n4. Kraj\n");
		puts("Unesite opciju:");
		scanf("%d", &unos);
		if (unos == 4) break;
		fflush(stdin);
		switch (unos)
		{
			case 1:
				PrviZadatak();
				break;
			case 2:
				DrugiZadatak();
				break;
			case 3:
				TreciZadatak();
				break;
			default:
				printf("\nGreska\n");
				break;
		}
		puts("\n\n");
		system("pause");
		system("cls");
		
	}
	printf("\nKraj programa.\n");
	return 0;
}



