#include "ArbreQuat.h"
#include "Reseau.h"

//retourn la section auquels les coordonnées (x,y) appartiennent

ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY){
    ArbreQuat* abrQ;

    if (!(abrQ = malloc(sizeof(ArbreQuat)))){
        printf("Erreur allocation : creerArbreQuat\n");
        return NULL;
    }
    abrQ->xc = xc;
    abrQ->yc = yc;
    abrQ->coteX = coteX;
    abrQ->coteY = coteY;
    abrQ->noeud = NULL;
    abrQ->so = NULL;
    abrQ->se = NULL;
    abrQ->no = NULL;
    abrQ->ne = NULL;
    return abrQ;
}


CellNoeud*   ajoutNoeudReseau(Reseau* R, double x, double y){
  CellNoeud* tmpCN = alloueCellNoeud("ajoutNoeudReseau");
  R->nbNoeuds++;
  tmpCN->nd = creerNoeud(R->nbNoeuds, x, y);

  tmpCN->suiv = R->noeuds;
  R->noeuds = tmpCN;
  return tmpCN;
}

// void      libererArbre(ArbreQuat* abrQ){
//   if (abrQ == NULL)
//     return;
//   if (abrQ->noeud)
//     free(abrQ->noeud);
//   if (abrQ->ne) 
//     libererArbre(abrQ->ne);
//   if (abrQ->no) 
//     libererArbre(abrQ->no);
//   if (abrQ->se) 
//     libererArbre(abrQ->se);
//   if (abrQ->so) 
//     libererArbre(abrQ->so);
//   free(abrQ);
// }