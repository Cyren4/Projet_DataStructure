#include "Reseau.h"
#include "Hachage.h"
#include "ArbreQuat.h"
#include "Graphe.h"

//return -1 si les arguments en ligne de commande ne sont pas valide
//return numero associé a une structure sinon
static Chaines*  check_args(int ac, char **av, int* typeStruc){
  Chaines* c = NULL;
  *typeStruc = -1;

  if (ac != 3)
    printf("Error : Nombre args Invalide.\nUsage %s <nomFichier.cha> <type_struct = [1-3]>\n", av[0]);
  else if (strcmp(av[1] + strlen(av[1]) - 4, ".cha") != 0)
    printf("Error : Nom fichier Invalide (.cha).\nUsage %s <nomFichier.cha> <type_struct = [1-3]>\n", av[0]);
  else if (atoi(av[2]) < 1 || atoi(av[2]) > 3 )
    printf("Error : Numero type Structure Invalide (1-3).\nUsage %s <nomFichier.cha> <type_struct = [1-3]>\n", av[0]);
  else{
    *typeStruc = atoi(av[2]);
    FILE *f = fopen(av[1], "r"); 
    if (f == NULL){
      printf("Error : Ouverture de fichier %s raté", av[1]);
      return NULL;
    }
    c = lectureChaines(f);
    fclose(f);
  }
  return c;
}

static void propChaine(Chaines *c){
  printf("Longueur physique de la 1ere chaine : %.2f\n", longueurChaine(c->chaines));
  printf("Longueur physique totale des chaines : %.2f\n", longueurTotale(c));
  printf("Nombre total de points : %d\n", comptePointsTotal(c));
}

static void propReseau(Reseau *r){
  printf("Nombre de commodité : %d\n", nbCommodites(r));
  printf("Nombre de liaisons : %d\n", nbLiaisons(r));
  printf("Nombre de Noeuds : %d\n", r->nbNoeuds);
}

int main(int ac, char** av){
  int typeStruc;
  Chaines *c = NULL;

  if ((c = check_args(ac, av, &typeStruc)) == NULL)
    return -1;
  Reseau *r = NULL;
  FILE*     fr = fopen("Reconstitue.res","w");


  switch (typeStruc){
  case 1:
    printf("Reconstitution Reseau avec methode : Liste\n");
    r = reconstitueReseauListe(c);
    break;
  
  case 2:
    printf("Reconstitution Reseau avec methode : Table de Hachage\n");
    r = reconstitueReseauHachage(c, 5);
    break;

  case 3:
    printf("Reconstitution Reseau avec methode : Arbre\n");
    r = reconstitueReseauArbre(c);
    break;

  default:
    break;
  }
  // ecrireReseau(r, fr);

  propChaine(c);//affiche les propriété de la chaine lu
  propReseau(r);//affiche les propriété du reseau reconstitué

  afficheReseauSVG(r, "nomInstanceReseau");
  afficheChainesSVG(c, "nomInstanceChaine");
  // Graphe* g  = creerGraphe(r);
  // printf("g : %d %d %d\n", g->gamma, g->nbcommod, g->nbsom);

  fclose(fr);
  liberer_Chaines(c);
  liberer_Reseau(r);
}
