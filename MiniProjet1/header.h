#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

int     **alloue_matrice(int n);
void    desalloue_matrice(int **tab, int n);
void    remplir_matrice(int **tab, int n, int v);
void    afficher_matrice(int **tab, int n);

void remplir_matrice_inf(int **tab, int n, int v);
void remplir_matrice_sup(int **tab, int n, int v);

#endif