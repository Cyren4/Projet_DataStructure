#include "Graphe.h"

Graphe*     creerGraphe(Reseau* r){
    Graphe *g;

    if (!(g = malloc(sizeof(Graphe)))){
        printf("Erreur allocation : creerGraphe\n");
        return NULL;
    }
    g->gamma = r->gamma;
    if (!(g->T_commod = malloc(sizeof(Commod) * nbCommodites(r)))){
        printf("Erreur allocation : creerGraphe\n");
        return NULL;
    }
    if (!(g->T_som = malloc(sizeof(Sommet) * r->nbNoeuds))){
        printf("Erreur allocation : creerGraphe\n");
        return NULL;
    }
    //creation des sommet avec liste voisins vide
    for (CellNoeud *n = r->noeuds; n != NULL; n = n->suiv){
        g->T_som[n->nd->num - 1] = creerSommet(n, n->nd->num - 1);
        g->nbsom++;
    }

    //creation des commodités
    for (CellCommodite *c = r->commodites; c != NULL; c = c->suiv){
        g->T_commod[g->nbcommod].e1 = c->extrA->num;
        g->T_commod[g->nbcommod].e2 = c->extrB->num;
        g->nbcommod++;
    }

    //creation liste de voisins avec arretes des sommets v
    for (CellNoeud *n = r->noeuds; n != NULL; n = n->suiv)
        g->T_som[n->nd->num - 1]->L_voisin = ajoutArrete(n, n->nd->num - 1);
    majArrete(g); //ajouts des arretes dans liste des sommets u 
    return g;
}

//allocation sommet et informations necessaires
Sommet*     creerSommet(CellNoeud *n, int num){
    Sommet* s;

    if (!(s = malloc(sizeof(Sommet)))){
        printf("Erreur allocation : creerSommet\n");
        return NULL;
    }
    s->num = num;
    s->x = n->nd->x;
    s->y = n->nd->y;
    s->L_voisin = NULL;

    return s;
}

//parcours liste noeuds et ajout des arretes (dans un sens seulement) 
// avec u < v
Cellule_arete*  ajoutArrete(CellNoeud* n, int num){
    Cellule_arete* ar = NULL;

    for(CellNoeud* tmpN = n->nd->voisins; tmpN != NULL; tmpN = tmpN->suiv){
        if (tmpN->nd->num - 1 < num)
            ar = insererArrete(ar, tmpN->nd->num - 1, num);
    }
    return ar;
}

//cree une celluleArrete et une arrete {u,v} et l'insere en tete de L_voisin
Cellule_arete*  insererArrete(Cellule_arete* L_voisin, int u, int v){
    Cellule_arete* new;
    // printf("%d %d\n", u, v);

    if (!(new = malloc(sizeof(Cellule_arete)))){
        printf("Erreur allocation : insererArrete\n");
        return NULL;
    }
    if (!(new->a = malloc(sizeof(Arete)))){
        printf("Erreur allocation : insererArrete\n");
        return NULL;
    }
    new->a->u = u;
    new->a->v = v;
    new->suiv = L_voisin;
    return new;
}

//ajoute les arrete dans la liste des voisins u
void    majArrete(Graphe* g){
    Cellule_arete* new = NULL; //arrete temporaire

    for (int i = 0; i < g->nbsom; i++) // parcours sommets
        for (Cellule_arete* v = g->T_som[i]->L_voisin; v != NULL; v = v->suiv) //parcours liste voisins
            if (g->T_som[i]->num == v->a->v)
                g->T_som[v->a->u]->L_voisin = enteteArrete(g->T_som[v->a->u]->L_voisin, v->a);
}

// ajoute arrete en tete d'une liste de voisins sans l'allouer
Cellule_arete*  enteteArrete(Cellule_arete* tete, Arete* a){
    Cellule_arete* new;

    if (!(new = malloc(sizeof(Cellule_arete)))){
        printf("Erreur allocation : enteteArrete\n");
        return NULL;
    }
    new->a = a;
    new->suiv = tete;
    return new;
}