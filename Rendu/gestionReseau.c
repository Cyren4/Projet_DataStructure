#include "Reseau.h"

/*Creation */

Noeud*  creerNoeud(int num, double x, double y){
  Noeud*  v;

  if (!(v = malloc(sizeof(Noeud)))) {
    printf("Erreur allocation : creerNoeud\n");
    return NULL;
  }
  v->num = num;
  v->x = x;
  v->y = y;
  v->voisins = NULL;

  return v;
}


/*Allocation */

CellCommodite* alloueCommodites(char *message){
  CellCommodite* c = malloc(sizeof(CellCommodite));

  if (c == NULL){
    printf("Erreur d'allocation : Commodité - %s\n", message);
    return NULL;
  }

  c->extrA = NULL;
  c->extrB = NULL;
  c->suiv = NULL;

  return c;
}

Reseau* alloueReseau(char *message){
  Reseau* r = malloc(sizeof(Reseau));

  if (r == NULL){
    printf("Erreur d'allocation : Reseau - %s\n", message);
    return NULL;
  }

  r->nbNoeuds = 0;
  r->gamma = 0;
  r->noeuds = NULL;
  r->commodites = NULL;

  return r;
}

CellNoeud* alloueCellNoeud(char *message){
  CellNoeud* c = malloc(sizeof(CellNoeud));

  if (c == NULL){
    printf("Erreur d'allocation : CellNoeud - %s\n", message);
    return NULL;
  }
  c->nd = NULL;
  c->suiv = NULL;
  return c;
}


/* Liberer */

void    liberer_Reseau(Reseau* r){
  if (r != NULL){
    CellNoeud*      tmpN;
    CellCommodite*  tmpK;

    while (r->noeuds != NULL){
      tmpN = r->noeuds;
      r->noeuds = r->noeuds->suiv;
      free(tmpN);
    }
    while (r->commodites != NULL){
      tmpK = r->commodites;
      r->commodites = r->commodites->suiv;
      free(tmpK);
    }
    free(r);
  }
}

/*Mise a jour Reseau */

void majVoisin(Noeud* n, Noeud* nvoisin){
  if (nvoisin == NULL)
    return;

  CellNoeud* cellNtmp = n->voisins;
  Noeud* voisin;

  while (cellNtmp) {
    voisin = cellNtmp->nd;
    if (nvoisin->x == voisin->x && nvoisin->y == voisin->y)
      return;
    cellNtmp = cellNtmp->suiv;
  }

  cellNtmp = alloueCellNoeud("majVoisin");
  cellNtmp->nd = nvoisin;
  cellNtmp->suiv = n->voisins;
  n->voisins = cellNtmp;
}
