#include <stdio.h>
#include <string.h>
#include <GL/glu.h>
#include <windows.h>
#include <stdlib.h>

//Stringuri
//Sortare dupa pret crescator si descrescator
//un sturct
//totalul cosului
//Grafica


 int index_fisier;
 int index_produs;
const int constanta_linii = 11;
char linie_aleasa[100];
int optiune;
int test[11];
int inrage=0,outrange=0;

char fisiere_nume[7][20] = {
    {"telefoane.txt"},
    {"televizoare.txt"},
    {"masinidespalat.txt"},
    {"aparatedecafea.txt"},
    {"laptop.txt"},
    {"smartwatch.txt"}
  };


void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.25f, -0.25f);
		glVertex2f( 0.25f, -0.25f);
		glVertex2f( 0.25f, 0.25f);
		glVertex2f(-0.25f, 0.25f);
		glEnd();
		glFlush();

}



void adaugaInCos(const char * produs);

void afiseazaProduse(const char * numeFisier);

void cautaSiCitesteNumar(FILE* fisier, int* rezultat);

void interschimbare(int* a, int* b);

int partitionare(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);


void afisareArray(int arr[], int size) {
    static int currentIndex = 0;
    FILE *f;
    f = fopen(fisiere_nume[optiune - 1], "r");

    if (f == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    	test[currentIndex] = arr[currentIndex];
    	printf("%d",arr[currentIndex]);
        fflush(stdout);
        currentIndex++;




    fclose(f);
    printf("\n");
}


int main(int argc, char** argv) {
  int optiune2;
  int meniuPrincipal = 1;
  int min,max;
  int pret_produs[11];

  while (meniuPrincipal) {
    printf("\nBine ati venit in magazinul nostru!\n");
    printf("Acestea sunt produsele disponibile!\n");
    printf("1. Telefoane\n");
    printf("2. Televizoare\n");
    printf("3. Masini de spalat\n");
    printf("4. Aparate de cafea\n");
    printf("5. Laptop-uri\n");
    printf("6. Smartwatch-uri\n");
    printf("Selecteaza o optiune: ");
    fflush(stdout);
    scanf("%d", & optiune);

    if (optiune >= 1 && optiune <= 7) {
      switch (optiune) {
      case 1:
        printf("\n----- Telefoane -----\n");
        afiseazaProduse(fisiere_nume[0]);
        break;
      case 2:
        printf("\n----- Televizoare -----\n");
        afiseazaProduse(fisiere_nume[1]);
        break;
      case 3:
        printf("\n----- Masini de spalat -----\n");
        afiseazaProduse(fisiere_nume[2]);
        break;
      case 4:
        printf("\n----- Aparate de cafea -----\n");
        afiseazaProduse(fisiere_nume[3]);
        break;
      case 5:
        printf("\n----- Laptop-uri -----\n");
        afiseazaProduse(fisiere_nume[4]);
        break;
      case 6:
        printf("\n----- Smartwatch-uri -----\n");
        afiseazaProduse(fisiere_nume[5]);
        break;
      }

      optiune2 = 5;
      fflush(stdout);
      while (optiune2 != 0) {
        printf("\n");
        printf("\n1. Adauga in cos\n2. Ordoneaza(Descrecator/Crescator)\n3. Selecteaza intervalul de pret\n0. Acasa\nSelecteaza o optiune: ");
        fflush(stdout);
        scanf("%d", & optiune2);

        if (optiune2 == 1) {
          int produs_cos;
          printf("Selectati care produs il doriti: ");
          fflush(stdout);
          scanf("%d", & produs_cos);

          if (produs_cos >= 1 && produs_cos <= 11) {
            index_fisier = optiune - 1;
            index_produs = produs_cos - 1;
            FILE * fisier_citit = fopen(fisiere_nume[index_fisier], "r");

            if (fisier_citit == NULL) {
              printf("Eroare la deschiderea fisierului %s\n", fisiere_nume[index_fisier]);
              continue;
            }


            int i = 0;

            while (fgets(linie_aleasa, sizeof(linie_aleasa), fisier_citit)) {
              if (i == index_produs) {
                printf("\n%s\n", linie_aleasa);
                adaugaInCos(linie_aleasa);
                break;
              }
              i++;
            }

            fclose(fisier_citit);
            printf("\n%d a fost bagat in cos", produs_cos);
            fflush(stdout);
          } else {
            printf("Optiunea selectata nu exista. Te rog sa reintroduci optiunea.\n");
          }
        }
        FILE *f;
        int i=0;
        index_fisier = optiune-1;
        f= fopen(fisiere_nume[index_fisier],"r");


        for(i = 0; i < constanta_linii;i++){
        	cautaSiCitesteNumar(f,&pret_produs[i]);
        }
        int marime_pret_produs= sizeof(pret_produs)/sizeof(pret_produs[0]);
        quickSort(pret_produs, 0, marime_pret_produs- 1);
        printf("\nProduse sortate: \n");
        if(optiune2 == 2){

      	 for(int i= 0;i < constanta_linii;i++)
      	 afisareArray(pret_produs, marime_pret_produs);

      	  fflush(stdout);
      	  }

        if(optiune2 == 3){
        	for(i = 0; i < constanta_linii;i++){
        		cautaSiCitesteNumar(f,&pret_produs[i]);
        	}

        	printf("Pret minim: ");
        	fflush(stdout);
        	scanf("%d",&min);
        	printf("Pret maxim*: ");
        	fflush(stdout);
        	scanf("%d",&max);
        	for(i=0;i < constanta_linii;i++){
        	if(pret_produs[i] > max && pret_produs[i] < min){
        		outrange++;
        	}
        	else if(pret_produs[i] < max && pret_produs[i] > min){
        		inrage++;
        	}
        	}
        	printf("in: %d, out: %d\n",inrage,outrange);
        	        	fflush(stdout);
        	glutInit(&argc, argv);
        		glutInitWindowSize(500, 500);
        		glutInitWindowPosition(50, 50);
        		glutCreateWindow("OpenGL Setup Test");
        		glutDisplayFunc(display);
        		glutMainLoop();

        }
        fclose(f);


      }
    } else {
      printf("Optiunea selectata nu exista. Te rog sa reintroduci optiunea.\n");
    }
  }


  return 0;
}

void adaugaInCos(const char * produs) {
  FILE * cos = fopen("cos.txt", "a");
  if (cos == NULL) {
    printf("Eroare la deschiderea fisierului cos.txt\n");
    return;
  }

  fprintf(cos, "%s\n", produs);

  fclose(cos);

  printf("Adauga in cos: %s\n", produs);
}

void afiseazaProduse(const char * numeFisier) {
  FILE * fisier = fopen(numeFisier, "r");
  if (fisier == NULL) {
    printf("Eroare la deschiderea fisierului %s\n", numeFisier);
    return;
  }

  char linie[100];
  int i = 1;
  while (fgets(linie, sizeof(linie), fisier)) {
    printf("%d. %s", i, linie);
    i++;
  }

  fclose(fisier);
}

void cautaSiCitesteNumar(FILE* fisier, int* rezultat) {
  char line[100];
  int i = 0;

  while (fgets(line, sizeof(line), fisier)) {
      *rezultat = atoi(line);
      break;
    i++;
  }


}
void interschimbare(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionare(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            interschimbare(&arr[i], &arr[j]);
        }
    }
    interschimbare(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionare(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



