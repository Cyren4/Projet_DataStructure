#include "header.h"

const static int len = 10;

int main(void) {
	int 			*tab;
	unsigned int	i;
    
	if (!(tab = (int*)malloc(sizeof(int) * len))){
		printf("Erreur de malloc!\n");	
		return -1;
	}
	for (i = len - 1; i >= 0; i--) {
		tab[i] = i;
	}
	free(tab);
	return 0;
}
