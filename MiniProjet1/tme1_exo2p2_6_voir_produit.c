#include "header.h"

#define TAILLE 2
#define BORNE 4

int   tous_diff(int ** tab,int n){
  for(int a = 0; a < n; a++)
    for(int b = 0; b < n; b++)
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          if((a != i || b != j) && (tab[a][b] == tab[i][j]))
            return 0; //return 0 si c'est faux
  return 1; // return 1 si c'est vrai
}

int   tous_diff2(int **tab, int n, int borne){
  int   *t = calloc(borne, sizeof(int));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (t[tab[i][j]] == 1){
        free(t);
        return 0;
      } else
        t[tab[i][j]] = 1;
    }
    free(t);
    return 1;
}

void prod_matrice_1(int **tab1,int **tab2,int** tab_retour,int n){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      tab_retour[i][j] = 0;
      for(int k = 0; k < n; k++)
        tab_retour[i][j] += tab1[i][k] * tab2[k][j];
    }
}
void prod_matrice_2(int **tab1, int **tab2, int **tab_retour, int n){
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      tab_retour[i][j]=0;
      for(int k=i;k<n;k++){
        if(!(k < j))
          tab_retour[i][j] += tab1[i][k] * tab2[k][j];
      }
    }
}

int main(){
  srand(time(NULL));
  int n = TAILLE;
  int v = BORNE;
  int **tab1 = alloue_matrice(n);
  int **tab2 = alloue_matrice(n);
  int **tab_retour = alloue_matrice(n);

  remplir_matrice_sup(tab1, n, v);
  remplir_matrice_inf(tab2, n, v);
  remplir_matrice(tab_retour, n, v);
  printf("On considere ici une matrice triangulaire superieure et une matrice triangulaire inférieure,\n");
  printf("afin que les 2 algo produisent le meme resultat.\n");
  printf("Affichage de matrice carre avec n = %d et v = %d\n\n", n, v);
  printf("Matrice superieur\n");
  afficher_matrice(tab1, n);
  printf("Matrice inferieur\n");
  afficher_matrice(tab2, n);
  printf("---------------------\n\n");
  printf("Le produit des 2 matrices donne alors:\n\n");
  printf("  - Algo 1 :\n");
  prod_matrice_1(tab1, tab2, tab_retour, n);
  afficher_matrice(tab_retour, n);
  printf("  - Algo 2 :\n");
  prod_matrice_2(tab1, tab2, tab_retour, n);
  afficher_matrice(tab_retour, n);

  desalloue_matrice(tab1, n);
  desalloue_matrice(tab2, n);
  desalloue_matrice(tab_retour, n);

  return 0;
}
