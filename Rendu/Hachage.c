#include "Hachage.h"
#include "Reseau.h"

int     fonctionClef(double x, double y){
    return (int)(y + (x + y)*(x + y + 1) / 2);
}

int     fonctionHachage(int cle, int m){
  double a = (sqrt(5) - 1) / 2;
  return (m * (cle * a - (int)(cle * a)));
}


int     fonctionClef2(double x, double y){
  double a = (sqrt(5)-1) / 2;
  return a;
}

TableHachage* creerTable(int m){
  TableHachage* t;
  if (!(t = malloc(sizeof(TableHachage)))){
    printf("Erreur d'allocation : creerTable\n");
    return NULL;
  }
  t->m = m;
  t->nbE = 0;

  CellNoeud** c = malloc(m * sizeof(CellNoeud*));
  for(int i = 0 ; i < m ; i++){
    c[i] = NULL;
  }
  t->noeuds = c;
  return t;
}

Noeud* rechercheCreeNoeudHachage(Reseau* R, TableHachage*H, double x, double y){
  int index = fonctionHachage(fonctionClef(x,y),H->m);
  CellNoeud* tmpCellNoeud = H->noeuds[index];

  while(tmpCellNoeud){
    if (tmpCellNoeud->nd->x == x && tmpCellNoeud->nd->y == y)
      return tmpCellNoeud->nd;
    tmpCellNoeud = tmpCellNoeud->suiv;
  }

  H->nbE++;
  R->nbNoeuds++;

  Noeud* n = creerNoeud(R->nbNoeuds, x, y);
  Noeud* nH = creerNoeud(R->nbNoeuds, x, y);
  tmpCellNoeud = alloueCellNoeud("rechercheCreeNoeudHachage");
  CellNoeud* tmpCH = alloueCellNoeud("rechercheCreeNoeudHachage");

  tmpCellNoeud->nd = n;
  tmpCellNoeud->suiv = R->noeuds;
  R->noeuds = tmpCellNoeud;

  tmpCH->nd = n;
  tmpCH->suiv = H->noeuds[index];
  H->noeuds[index] = tmpCH;

  return n;
}

/* free  a corriger */
/*
void freeCellNoeud(CellNoeud* c){
  free(c->nd);
  free(c);
}

void freeCellCommodite(CellCommodite* c){
  free(c->extrA);
  free(c->extrB);
  free(c);
}


void freeHachage(TableHachage* t){
  for (int i = 0; i < t->m; i++) {
    freeCellNoeud(t->noeuds[i]);
  }
  free(t->noeuds);
  free(t);
}
*/


Reseau* reconstitueReseauHachage(Chaines *C, int M){
  Reseau* r = alloueReseau("reconstitueReseauHachage");
  CellCommodite* cC;
  TableHachage* t = creerTable(M);
  CellChaine* tmpC;
  CellPoint* tmpP;
  Noeud* n,*nSuiv,*nPrec;
  r->nbNoeuds = 0;
  r->gamma = C->gamma;
  int premier = 0;

  for (tmpC = C->chaines; tmpC != NULL; tmpC = tmpC->suiv) {
    cC = alloueCommodites("reconstitueReseauHachage");
    cC->extrA = rechercheCreeNoeudHachage(r, t, tmpC->points->x, tmpC->points->y);

    for (tmpP = tmpC->points; tmpP != NULL; tmpP = tmpP->suiv) {
      n = rechercheCreeNoeudHachage(r, t, tmpP->x, tmpP->y);
      if (tmpP->suiv != NULL)
        nSuiv = rechercheCreeNoeudHachage(r, t, tmpP->suiv->x, tmpP->suiv->y);
      if (premier == 0) {
        if (tmpP->suiv != NULL)
          majVoisin(n,nSuiv);
        premier = 1;
        nPrec = n;

      } else {
        majVoisin(n,nPrec);
        majVoisin(n,nSuiv);
        nPrec = n;
      }
    }
    premier = 0;

    cC->extrB = n;
    /*printf("%f %f\n",cC->extrA->x, cC->extrA->y);*/
    cC->suiv = r->commodites;
    r->commodites = cC;
  }
  // freeHachage(t);
  return r;
}
