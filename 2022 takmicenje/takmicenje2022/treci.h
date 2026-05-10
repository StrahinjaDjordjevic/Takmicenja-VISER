#pragma once
#include "main.h"
#define MAX_M 10
#define MAX_KARAKTERA 80
enum simboli { Zarazen = 'Z', Covek = 'C', Otporan = 'O', Prazno = '='};
typedef struct {
	char s;
	int x;
	int y;
} clan;
clan Z, I;
int provereni_zaraza[MAX_M][MAX_M];


void PocetnaTabla(char tabla[][MAX_M], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			tabla[i][j] = Prazno;
		
}
void TablaSaLjudima(char tabla[][MAX_M], int n, int m, int k) {
	int i, j, provera;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) {
			provera = i != Z.x || j != Z.y || i != I.x || j != I.y || tabla[i][j] != Covek;
			if (provera && sin(j * i * k * 1.0) > 0 && cos(j * i * k * 1.0) < 0)
				tabla[i-1][j-1] = Covek;
			provereni_zaraza[i-1][j-1] = 0;
		}
}
void PrikaziTablu(char tabla[][MAX_M], int n, int m) {
	int i, j;
	puts("\n");
	for (i = -1; i <= n+1; i++) {
		for (j = -1; j <= m+1; j++) {
			if (i == n + 1 && j >= 0 && j < m) printf(" %d", j + 1);
			else if (j == m + 1 && i >= 0 && i < n) printf(" %d", i + 1);
			else if ((i == -1 || i == n) && j <= m) printf("--");
			else if (j == -1 && i <= n) printf("| ");
			else if (j == m && i <= n) printf(" |");
			else if (i >= 0 && i < n && j >= 0 && j < m) printf("%c ", tabla[i][j]);
			else printf(" ");
		}
		puts("");
	}

}
//Vraca broj zarazenih od zarazenog clana
void Zaraza(char tabla[][MAX_M], int n, int m, int i, int j) {
	int k, zarazeni = 0;
	int smerovi[][2] = { { i - 1, j } , { i + 1, j }, { i, j - 1 }, { i, j + 1 },  { i - 1, j + 1 }, { i - 1, j - 1 }, { i + 1, j + 1 }, { i + 1, j - 1 } };  // gore, dole, levo, desno, dijagonale...
	if (i < 0 || i >= n || j < 0 || j >= m || provereni_zaraza[i][j])
		return;

	provereni_zaraza[i][j] = 1;
	if (tabla[i][j] == Covek || tabla[i][j] == Zarazen) {
		tabla[i][j] = Zarazen;
		if (i != Z.x || j != Z.y) zarazeni++; //ne racunamo prvog zarazenog
		for (k = 0; k < 8; k++)
			Zaraza(tabla, n, m, smerovi[k][0], smerovi[k][1]);
		
	}
}
int MogucaIzolacija(char tabla[][MAX_M], int n, int m, int I, int J) {
	int k, i, j, smerovi[][2] = { { I - 1, J } , { I + 1, J }, { I, J - 1 }, { I, J + 1 },  { I - 1, J + 1 }, { I - 1, J - 1 }, { I + 1, J + 1 }, { I + 1, J - 1 } }; 
	
	for (k = 0; k < 8; k++) {
		i = smerovi[k][0];
		j = smerovi[k][1];
		if (i >= 0 && i < n && j >= 0 && j < m && tabla[i][j]==Covek)
			return 0;
	}
	
	return 1;
}
void PozicijeIzolacijeVirusa(char tabla[][MAX_M], int n, int m) {
	int i, j, k = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (tabla[i][j] != Covek && MogucaIzolacija(tabla, n, m, i, j))
				printf("%d: (%d, %d)\n", k++, j + 1, i + 1);
			
		
}
int PrebrojiMoguceZarazene(char tabla[][MAX_M], int n, int m, int i, int j, int prvi) {
	int k, zarazeni = 0;
	int smerovi[][2] = { { i - 1, j } , { i + 1, j }, { i, j - 1 }, { i, j + 1 },  { i - 1, j + 1 }, { i - 1, j - 1 }, { i + 1, j + 1 }, { i + 1, j - 1 } };  // gore, dole, levo, desno, dijagonale...
	if (i < 0 || i >= n || j < 0 || j >= m || provereni_zaraza[i][j])
		return 0;

	provereni_zaraza[i][j] = 1;
	if (tabla[i][j] == Covek || tabla[i][j] == Zarazen || prvi) {
		if (prvi) zarazeni--; //ne racunamo pocetno polje
		zarazeni++;
		for (k = 0; k < 8; k++)
			zarazeni += PrebrojiMoguceZarazene(tabla, n, m, smerovi[k][0], smerovi[k][1], 0);
		
	}
	return zarazeni;
}
void NajvecaZaraza(char tabla[][MAX_M], int n, int m) {
	int i, j, max = -1, x, y, broj;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (tabla[i][j] == Prazno) {
				memset(provereni_zaraza, 0, sizeof(provereni_zaraza));
				broj = PrebrojiMoguceZarazene(tabla, n, m, i, j, 1);
				if (broj >= max)
				{
					max = broj;
					y = i;
					x = j;
				}


			}
		}

	printf("\t(%d, %d)\n", x + 1, y + 1);
}
void TriJedan(char tabla[][MAX_M], int n, int m) {
	puts("\n****  odgovor 1  ****");
	PocetnaTabla(tabla, n, m);
	PrikaziTablu(tabla, n, m);
}
void TriDva(char tabla[][MAX_M], int n, int m, int k) {
	puts("\n****  odgovor 2  ****");
	TablaSaLjudima(tabla, n, m, k);
	PrikaziTablu(tabla, n, m);
}
void TriTri(char tabla[][MAX_M], int n, int m) {
	puts("\n****  odgovor 3  ****\n");
	PozicijeIzolacijeVirusa(tabla, n, m);
}
void TriCetiri(char tabla[][MAX_M], int n, int m, int k) {
	TablaSaLjudima(tabla, n, m, k);
	puts("\n****  odgovor 4  ****");
	tabla[Z.x][Z.y] = Zarazen; 
	tabla[I.x][I.y] = Otporan;
	Zaraza(tabla, n, m, Z.x, Z.y);
	PrikaziTablu(tabla, n, m);
}
void TriPet(char tabla[][MAX_M], int n, int m, int k) {
	int x = Z.x, y = Z.y;
	puts("\n****  odgovor 5  ****\n");
	TablaSaLjudima(tabla, n, m, k);
	NajvecaZaraza(tabla, n, m);

}
