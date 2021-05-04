#include "header.h"

int tous_diff(int ** tab,int n){
  for(int a=0;a<n;a++){
    for(int b=0;b<n;b++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if((a!=i||b!=j)&&(tab[a][b]==tab[i][j]))
            return 0; //return 0 si c'est faux
  }
  return 1; // return 1 si c'est vrai
}

int   tous_diff2(int **tab, int n, int borne){
  int *t = calloc(borne,sizeof(int));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (t[tab[i][j]] == 1){
        free(t);
        return 0;
      }
      else
        t[tab[i][j]] = 1;
    }
    free(t);
    return 1;
}

void prod_matrice_1(int **tab1,int **tab2,int** tab_retour,int n){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      tab_retour[i][j]=0;//par securite on met la valeur du tableau de retour a 0;
      for(int k = 0; k < n; k++)
        tab_retour[i][j] += tab1[i][k] * tab2[k][j];// on fai la somme de la ligne(du premeir tableau) * la colonne (du deuxieme tableau) que l'on met dans le tableau de retour en [i][j]
    }
}

void prod_matrice_2(int **tab1, int **tab2, int **tab_retour, int n){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      tab_retour[i][j] = 0;
      for(int k = i; k < n; k++){//pour ne prendre uniquement les valeurs de la matrice 1 en la considerant comme superieur
        if(!(k < j))//pour ne prendre uniquement les valeurs de la matrice 2 en la considerant comme inferieure
          tab_retour[i][j] += tab1[i][k]*tab2[k][j];// on fai la somme de la ligne(du premeir tableau) * la colonne (du deuxieme tableau) que l'on met dans le tableau de retour en [i][j]
      }
    }
}
int main(){
  //initialisation des variables
  srand(time(NULL));
  unsigned long temps_initial_1;
  unsigned long temps_final_1;
  unsigned long temps_initial_2;
  unsigned long temps_final_2;
  double temps_cpu_1;
  double temps_cpu_2;
  int n=2000;
  int v=1000;
  //allocation des matrices
  int** tab1=alloue_matrice(n);
  int** tab2=alloue_matrice(n);
  int** tab_retour=alloue_matrice(n);
  remplir_matrice(tab1,n,v);
  remplir_matrice(tab2,n,v);
  remplir_matrice(tab_retour,n,v);


  //on regarde combien de temps nous prend le premier algo
  temps_initial_1 = clock();
  prod_matrice_1(tab1,tab2,tab_retour,n);
  temps_final_1 = clock ();

  //pareil pour le 2eme
  temps_initial_2 = clock();
  prod_matrice_2(tab1,tab2,tab_retour,n);
  temps_final_2 = clock ();

  //on effectue les calculs de temps_cpu 1 et 2
  temps_cpu_1=((double) (temps_final_1 - temps_initial_1)) / CLOCKS_PER_SEC;
  temps_cpu_2=((double) (temps_final_2 - temps_initial_2)) / CLOCKS_PER_SEC;
  //pour faciliter l'utilisation du gnuplot nous regroupons les 2 donnés en une fois
  printf("%d %f %f \n",n,temps_cpu_1,temps_cpu_2);

  //on libere la memoire
  desalloue_matrice(tab1,n);
  desalloue_matrice(tab2,n);
  desalloue_matrice(tab_retour,n);

  return 0;
}
