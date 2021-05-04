#include "header.h"

int   *alloue_tableau(int n){
  int *tab;

  if (!(tab = (int*)malloc(sizeof(int) * n))){
    printf("Erreur de malloc!\n");	
		return -1;
	}
  return tab;
}

void  desalloue_tableau(int *tab,int n){
  free(tab);
}

void  remplir_tableau(int *tab, int n, int v){
  for(int i = 0; i < n; i++)
    tab[i] = (int)(rand() % v);//on donne une valeur aleatoire au case du tableau courant
}

void  afficher_tableau(int* tab,int n){
  printf("[ ");
  for(int i = 0 ; i < n ; i++)
    printf("%d ", tab[i]);
  printf(" ]");
}

int   somme_carres_1(int *tab, int n){
  int somme = 0;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      somme += (tab[i]-tab[j]) * (tab[i]-tab[j]); // on effectue la formule demander dans l'exercice
  return somme;
}

int   somme_carres_2(int *tab, int n){
  int x = 0;
  int y = 0;
  for(int i = 0; i < n; i++){
    x += tab[i] * tab[i];
    y += tab[i];
  }
  return 2 * n * x - 2 * (y * y); // on  return la somme carres via la formule developper et amenager de la question precedente
}

int main(){
  srand(time(NULL));
  //initialisation des variables
  unsigned long temps_initial_1;
  unsigned long temps_final_1;
  unsigned long temps_initial_2;
  unsigned long temps_final_2;
  double temps_cpu_1;
  double temps_cpu_2;
  int n = 5;
  int v=300;
  int *tab = alloue_tableau(n);

  //on regarde combien de temps nous prend le premier algo
  remplir_tableau(tab, n, v);
  temps_initial_1 = clock();
  int a = somme_carres_1(tab, n);
  temps_final_1 = clock ();

  //pareil pour le 2eme
  temps_initial_2 = clock();
  int b = somme_carres_2(tab, n);
  temps_final_2 = clock ();

  //on effectue les calculs de temps_cpu 1 et 2
  temps_cpu_1=((double) (temps_final_1 - temps_initial_1)) / CLOCKS_PER_SEC;
  temps_cpu_2=((double) (temps_final_2 - temps_initial_2)) / CLOCKS_PER_SEC;

  //pour faciliter l'utilisation du gnuplot nous regroupons les 2 donnés en une fois
  printf("%d %f %f\n",n, temps_cpu_1, temps_cpu_2);

  //libération du tableau
  free(tab);
  return 0;
}
