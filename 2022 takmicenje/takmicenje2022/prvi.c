//#include<stdio.h>
//#include<math.h>
//#define N 10
//
//int PrebrojavanjeSinusVrednosti(int broj){
//	int i, brojac=0;
//	for(i=1; i<broj; i++)
//		if(sin(i*1.0)>0.96) brojac++;
//	
//	return brojac;
//}
//int PrebrojavanjeProstih(int broj){
//	int i, j, brojac=0, prost;
//	if(broj<2) return 0;
//
//	for(i=2; i<broj; i++){
//		prost=1;
//		for(j=2; j<i; j++){
//			if(i%j==0) prost=0;
//		}
//		if(prost) brojac++;
//	}
//	return brojac;
//}
//int DrugaPolovineBroja(long broj){
//	int polovina=0, i, a=broj;
//	for(i=0; i<N/2; i++){
//		polovina = pow(10.0, i)*(broj%10) + polovina;
//		broj/=10;
//	}
//	return polovina;
//}
//int ObrniBroj(long broj){
//	int novi=0;
//	while(broj>0){
//		novi=novi*10+(broj%10);
//		broj/=10;
//	}
//	return novi;
//}
//void JedanJedan(long b){
//	int min=9, max=0, cifra, palindrom=ObrniBroj(b)==b;
//	puts("****  odgovor 1 ****\n");
//	puts(" IZVESTAJ:");
//	while(b>0){
//		cifra=b%10;
//		if(cifra<min) min=cifra;
//		if(cifra>max) max=cifra;
//		b/=10;
//	}
//	printf(" - Najmanje cifra u unetom broju je %d\n", min);
//	printf(" - Najveca cifra u unetom broju je %d\n - ", max);
//	puts(palindrom?"Broj je palindrom!":"Broj NIJE palindrom!");
//}
//long JedanDva(long b){
//	int prva = (b/pow(10.0, N/2));
//	int druga = DrugaPolovineBroja(b);
//	double x=0;
//	puts("****  odgovor 1 ****\n");
//	prva=PrebrojavanjeProstih(prva);
//	druga=PrebrojavanjeSinusVrednosti(druga);
//	druga=druga<999?prva:druga;
//	return (long)prva*pow(10.0, 4)+druga;
//}
//int main(){
//	long a, b, c;
//	int d[N], f[N];
//	puts("Unesite 10-cifreni broj");
//	scanf("%ld", &a);
//	puts("****  IZLAZI  ****\n\n");
//	b=a;
//	JedanJedan(b);
//	c=JedanDva(b);
//	JedanTri(d);
//	f=d;
//	printf("Fomirani broj: %ld\n", c);
//	return 0;
//}