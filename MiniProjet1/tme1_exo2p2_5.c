#include "header.h"

int tous_diff(int **tab, int n){
  for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++)// on parcorus la matrice en prenant 2 valeurs
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if ((a != i || b != j) && (tab[a][b] == tab[i][j])) //si la premier valeur n'est pas a la même case que la seconde valeurs et que les résultats sont identiques alors c'est faux
            return 0; //return 0 si c'est faux
  return 1;           // return 1 si c'est vrai
}

int tous_diff2(int **tab, int n, int borne){
  int *t = calloc(borne, sizeof(int));//on crée un tableau allant de 0 a la borne exclu

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (t[tab[i][j]] == 1){ //si la valeur du tableau est egal a 1 alors on l'a deja vu 
        free(t); // donc on libere le tableau cree
        return 0;//et on return 0 ( faux )
      }else// si non on implemente la valeur dans le tableau cree pour indiquer que l'on l'a deja vu
        t[tab[i][j]] = 1;
    }
  free(t);
  return 1;
}

void prod_matrice_1(int **tab1, int **tab2, int **tab_retour, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      tab_retour[i][j] = 0;
      for (int k = 0; k < n; k++)
        tab_retour[i][j] += tab1[i][k] * tab2[k][j];
    }
}

void prod_matrice_2(int **tab1, int **tab2, int **tab_retour, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      tab_retour[i][j] = 0;
      for (int k = i; k < n; k++)
        if (!(k < j))
          tab_retour[i][j] += tab1[i][k] * tab2[k][j];
    }
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
  int n = 2;
  int v = 100;
  //allocation des matrices
  int **tab1 = alloue_matrice(n);
  remplir_matrice(tab1,n,v);
  //on regarde combien de temps nous prend le premier algo
  temps_initial_1 = clock();
  tous_diff(tab1,n);
  temps_final_1 = clock ();
  //pareil pour le 2eme
  temps_initial_2 = clock();
  tous_diff2(tab1,n,v);
  temps_final_2 = clock ();


  //on effectue les calculs de temps_cpu 1 et 2
  temps_cpu_1=((double) (temps_final_1 - temps_initial_1)) / CLOCKS_PER_SEC;
  temps_cpu_2=((double) (temps_final_2 - temps_initial_2)) / CLOCKS_PER_SEC;

  //pour faciliter l'utilisation du gnuplot nous regroupons les 2 donnés en une fois
  printf("%d %f %f \n",n,temps_cpu_1,temps_cpu_2);

  //on libere la memoire
  desalloue_matrice(tab1, n);
  return 0;
}
