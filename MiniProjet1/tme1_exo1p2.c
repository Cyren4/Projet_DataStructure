#include "header.h"

typedef struct adresse {
	int		numero;
	char	*rue;
	int		code_postal;
} 	Adresse;

Adresse		*creer_adresse(int n, char* r, int c) {
	Adresse	*new; 
	if (!(new = (Adresse*) malloc(sizeof(Adresse)))){
		printf("Erreur de malloc!\n");	
		return NULL;
	}

	new->numero = n;
	strcpy(new->rue, r);
	new->code_postal = c;

	return new;
}

int 	main(void){
	Adresse	*maison = creer_adresse(12, "manoeuvre", 15670);

	printf("Adresse courante : %d rue %s %d France\n", maison->numero, maison->rue, maison->code_postal);
	free(maison);
	return 0;
}
