////zadatak 3
//#include <stdio.h>
//#include<math.h>
//#define MAX_U 55
//#define MAX_F 10
//struct Figura {
//	char simbol;
//	int pozV;
//	int pozH;
//	char kretanje;
//};
//void prikaziTablu(char **tabla, int brKolona, int brRedova) {
//	int j, i;
//	printf("  ");
//	for (j = 0; j < brKolona; j++)
//		printf("%d ", j + 1);
//	printf("\n");
//	for (i = 0; i < brRedova; i++) {
//		printf("%d ", i + 1);
//		for (j = 0; j < brKolona; j++)
//			printf("%c ",tabla[i][j]);
//		printf("\n");	
//	}
//}
//char* vratiPutanje(struct Figura f, int brK, int brR) {
//	char *putanje=malloc(((brK + brR)*2), sizeof(char));
//	int poz = 0, x = f.pozH, y = f.pozV,zbir=x+y,razlika=x-y, px, py, i;
//	switch (f.kretanje) {
//	case 'X':
//		for (px = 0; px < brK; px++)
//			for (py = 0; py < brR; py++) {
//				if ((px + py) == zbir || (px - py) == razlika) {
//					putanje[poz++] = px + '0';
//					putanje[poz++] = py + '0';
//				}
//			}
//		break;
//	case '/':
//		for (px = 0; px < brK; px++)
//			for (py = 0; py < brR; py++) {
//				if ((px + py) == zbir) {
//					putanje[poz++] = px + '0';
//					putanje[poz++] = py + '0';
//				}
//			}
//		break;
//	case '\\':
//		for (px = 0; px < brK; px++)
//			for (py = 0; py < brR; py++) {
//				if ((px - py) == razlika) {
//					putanje[poz++] = px + '0';
//					putanje[poz++] = py + '0';
//				}
//			}
//		break;
//	case '+':
//		for (i = 1; i < 10; i++) {
//			if (x + i < brK) {
//				putanje[poz++] = x +i+ '0';
//				putanje[poz++] = y+ '0';
//			}
//			if (x - i >= 0) {
//				putanje[poz++] = x -i+ '0';
//				putanje[poz++] = y+ '0';
//			}
//			if (y - i >= 0) {
//				putanje[poz++] = x + '0';
//				putanje[poz++] = y-i + '0';
//			}
//			if (y + i <brR) {
//				putanje[poz++] = x + '0';
//				putanje[poz++] = y +i+ '0';
//			}
//		}
//		break;
//	}
//	return putanje;
//}
//char* vratiPolja(struct Figura f, int brK, int brR) {
//	char *polja = malloc(((brK * brR) * 2), sizeof(char));
//	int poz = 0, x = f.pozH, y = f.pozV,paran = (x + y) % 2, px, py;
//	switch (f.kretanje) {
//	case '/':
//		polja = vratiPutanje(f,brK,brR);
//		break;
//	case '\\':
//		polja = vratiPutanje(f, brK, brR);
//		break;
//	case '+':
//		for (px = 0; px < brK; px++)
//			for (py = 0; py < brR; py++)
//			{
//				polja[poz++] = px + '0';
//				polja[poz++] = py + '0';
//			}
//		break;
//	case 'X':
//		for (px = 0; px < brK; px++) 
//			for (py = 0; py < brR; py++) {
//				if ((px + py) % 2 == paran) {
//					polja[poz++] = px + '0';
//					polja[poz++] = py + '0';
//				}
//		}
//		break;
//	}
//	return polja;
//}
//void prikaziBrojPoljaPomeranja(struct Figura f, int brK, int brR, int pomeraj) {
//	char* polja;
//	int pozicija = 0,x,y,razlikaH,razlikaV,br=0, i;
//	pomeraj;
//	if (f.kretanje != '+') {
//		polja = vratiPolja(f, brK, brR);
//		for (i = 0; i < (brK + brR) * 2; i++) {
//			if (polja[pozicija] < 0)
//				break;
//			x = polja[pozicija++] - '0';
//			y = polja[pozicija++] - '0';
//			if (abs(f.pozH - x) > pomeraj || abs(f.pozV - y) > pomeraj)
//					continue;
//			br++;
//		}
//	}
//	else {
//		br++;
//		polja = vratiPutanje(f, brK, brR);
//		for (i = 0; i < (brK + brR) * 2; i++) {
//			if (polja[pozicija] < 0)
//				break;
//			x = polja[pozicija++] - '0';
//			y = polja[pozicija++] - '0';
//			if (x == f.pozH && abs(f.pozV - y) <= pomeraj)
//				br++;
//			if (y == f.pozV && abs(f.pozH - x) <= pomeraj)
//				br++;
//		}
//		if (f.pozH + 1 < brK && f.pozV + 1 < brR)
//			br++;
//		if (f.pozH - 1 >= 0 && f.pozV - 1 >=0)
//			br++;
//		if (f.pozH + 1 < brK && f.pozV - 1 >= 0)
//			br++;
//		if (f.pozH- 1 >= 0 && f.pozV + 1 < brR)
//			br++;
//	}
//	printf("%c%d ", f.simbol, br);
//}
//int main() {
//	int brKolona, brRedova, pozicija = 1,x,y,brojSlobodnihPozicija = 0, i, j, fi;
//	struct Figura figure[MAX_F];
//	char ulaz[MAX_U],**tabla,*polja, ps;
//	puts("***** ULAZ *****\n");
//	
//	gets(ulaz);
//	puts("\n***** IZLAZI *****");
//	brKolona = ulaz[0] - '0';
//	brRedova = ulaz[1] - '0';
//	tabla = (char **)malloc(brRedova * sizeof(char *));
//	for (i = 0; i<brRedova; i++)
//		tabla[i] = (char*)malloc(brKolona * sizeof(char));
//	for (i = 0; i < brRedova; i++)
//		for (j = 0; j < brKolona; j++)
//			tabla[i][j] = '=';
//	for (i = 0 ; i < MAX_F; i++) {
//		if (ulaz[++pozicija] == '\0')
//			break;
//		figure[i].simbol= ulaz[++pozicija];
//		figure[i].pozH = (ulaz[++pozicija] - '0')-1;
//		figure[i].pozV = (ulaz[++pozicija] - '0') - 1;
//		figure[i].kretanje = ulaz[++pozicija];
//		tabla[figure[i].pozV][figure[i].pozH] = figure[i].simbol;
//	}
//	puts("\n");
//	printf("***** odgovor 1 *****\n");
//	puts("\n");
//	prikaziTablu(tabla, brKolona, brRedova);
//	for (fi = 0; fi<MAX_F; fi++) {
//		if (figure[fi].pozH <0)
//			continue;
//		polja = vratiPutanje(figure[fi],brKolona, brRedova);
//		ps = figure[fi].simbol + 32;
//		pozicija = 0;
//		for (i = 0; i < (brKolona + brRedova) * 2; i++) {
//			if (polja[pozicija] < 0)
//				break;
//		    x = polja[pozicija++] - '0';
//			y = polja[pozicija++] - '0';
//			if (tabla[y][x] >= 'a' || tabla[y][x] == '@')
//				tabla[y][x] = '@';
//			else if (tabla[y][x]<'A')
//				tabla[y][x] = ps;
//		}
//	}
//	puts("\n");
//	printf("***** odgovor 2 *****\n");
//	puts("\n");
//	prikaziTablu(tabla, brKolona, brRedova);
//	puts("\n");
//	printf("***** odgovor 3 *****\n");
//	puts("\n");
//	polja = vratiPolja(figure[0],brKolona, brRedova);
//	pozicija = 0;
//	for (i = 0; i <(brKolona * brRedova) * 2; i++) {
//		if (polja[pozicija] < 0)
//			break;
//		x = polja[pozicija++] - '0';
//		y = polja[pozicija++] - '0';
//		for (fi = 1; fi < MAX_F; fi++) {
//			if (x == figure[fi].pozH && y == figure[fi].pozV)
//				printf("%c ", figure[fi].simbol);
//		}
//	}
//	for (fi = 0; fi < MAX_F; fi++) {
//		if (figure[fi].pozH < 0 || fi == 2)
//			continue;
//		pozicija = 0;
//		polja = vratiPolja(figure[fi],brKolona, brRedova);
//		for (i = 0; i < (brKolona * brRedova) * 2; i++) {
//			if (polja[pozicija] < 0)
//				break;
//			x = polja[pozicija++] - '0';
//			y = polja[pozicija++] - '0';
//			tabla[y][x] = '@';
//		}
//	}
//	pozicija = 0;
//	polja = vratiPolja(figure[2],brKolona, brRedova);
//	for (i = 0; i <(brKolona * brRedova) * 2; i++) {
//		if (polja[pozicija] < 0)
//		break;
//		x = polja[pozicija++] - '0';
//		y = polja[pozicija++] - '0';
//		if (tabla[y][x] != '@')
//			brojSlobodnihPozicija++;
//	}
//	puts("\n");
//	printf("\n***** odgovor 4 *****\n");
//	puts("\n");
//	printf("%d", brojSlobodnihPozicija);
//	puts("\n");
//	printf("\n***** odgovor 5 *****\n");
//	puts("\n");
//	for (fi = 0; fi < MAX_F; fi++) {
//		if (figure[fi].pozH < 0)
//			continue;
//		prikaziBrojPoljaPomeranja(figure[fi], brKolona, brRedova, 2);
//	}
//	gets(ulaz);
//	return 0;
//}