#include <stdio.h>
#include <string.h>
#include <GL/glu.h>
#include <windows.h>
#include <stdlib.h>

void afiseazaCategoriiProduse(int *optiune_m1,char numeoptiune_m1[][20]);
void deschidereFisier(FILE** f, char fisiernume[][20], const char mod, int* optiune);
void afiseazaProdus();
void afisareMeniu2(int* optiune_m2);
void optiuniM2(int* optiune_m2);
//Stringuri
//Sortare dupa pret crescator si descrescator
//un sturct
//totalul cosului
//Grafica
//kjhkh

char fisiere_nume[7][20] = {
		{"telefoane.txt"},
		{"televizoare.txt"},
		{"masinidespalat.txt"},
		{"aparatedecafea.txt"},
		{"laptop.txt"},
		{"smartwatch.txt"}
};

char nume_optiune_m1[7][20] = {
		{"Telefoane"},
		{"Televizoare"},
		{"Masini de spalat"},
		{"Aparate de cafea"},
		{"Laptop"},
		{"Smartwatch"}
};


int optiune_m1;
int optiune_m2;
FILE *f;


int main(){

	do
	{
		afiseazaCategoriiProduse(&optiune_m1,nume_optiune_m1);
		afiseazaProdus();
		do
		{
			afisareMeniu2(&optiune_m2);

		}while(optiune_m2 != 0);
	}while(optiune_m1 != 0);
	return 0;
}

void optiuniM2(int* optiune_m2){

//	switch(*optiune_m2){
//	case s1:	adaugareCos();
//	break;
//	case 2: ordonare();
//	break;
//	case 3: intervalPret();
//  default: printf("Numarul %d nu este o optiune!",*optiune_m2);
//}
}

void afisareMeniu2(int* optiune_m2){
	printf("\n1. Adauga in cos\n");
	printf("2. Ordoneaza(Descrecator/Crescator)\n");
	printf("3. Selecteaza intervalul de pret\n");
	printf("0. Acasa\nSelecteaza o optiune: ");
	fflush(stdout);
	scanf("%d",optiune_m2);
}

void deschidereFisier(FILE** f, char fisiernume[][20], const char mod, int* optiune) {
	*f = fopen(fisiernume[*optiune - 1], &mod);
	if (*f == NULL && *optiune != 0) {
		printf("\nFisierul %s nu s-a deschis!", fisiernume[*optiune - 1]);
	}
	else if (*optiune == 0){
		printf("\nMultumim pentru cumparaturi!");
	}
}

void afiseazaProdus(){
	char linie[100];

	deschidereFisier(&f, fisiere_nume, 'r', &optiune_m1);

	if (f != NULL) {
		int i = 1;
		while (fgets(linie, sizeof(linie), f)) {
			printf("%s", linie);
			fflush(stdout);
			i++;
		}
		printf("\n");
		fclose(f);
	}
}


void afiseazaCategoriiProduse(int *optiune_m1,char numeoptiune_m1[][20]){
	printf("\n");
	printf("Bine ati venit in magazinul nostru!\n");
	printf("Acestea sunt produsele disponibile!\n");
	printf("1. Telefoane\n");
	printf("2. Televizoare\n");
	printf("3. Masini de spalat\n");
	printf("4. Aparate de cafea\n");
	printf("5. Laptop-uri\n");
	printf("6. Smartwatch-uri\n");
	printf("0. Iesire\n");
	printf("Selecteaza o optiune: ");
	fflush(stdout);
	scanf("%d", optiune_m1);

	if (*optiune_m1 >= 1 && *optiune_m1 <= 7) {
		printf("\n----- %s -----\n",numeoptiune_m1[*optiune_m1-1]);
		fflush(stdout);
	}

}

//	void adaugaInCos(const char * produs) {
//		FILE * cos = fopen("cos.txt", "a");
//		if (cos == NULL) {
//			printf("Eroare la deschiderea fisierului cos.txt\n");
//			return;
//		}
//
//		fprintf(cos, "%s\n", produs);
//
//		fclose(cos);
//
//		printf("Adauga in cos: %s\n", produs);
//	}
//}

