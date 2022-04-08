#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	TODO: 
	Dodaj mogućnost da se upisuje/ispisuje u fajlove

*/

#include "caesarCypher.h"

int main(int argc, char *argv[]) {
	
	int shift = 3;
	char strana = 'l';
	
	if (argc == 2 || argc > 3) {
		greska("lose ucitano");
	}
	if (argc == 3) {
		if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "-l") == 0) {
			strana = argv[1][1];
		}
		else {
			greska("lose ucitano argument");
		}
		shift = atoi(argv[2]);
	}
	
	char *poruka;
	
	int duzinaPoruke = unos(&poruka);

	char *novaPoruka = malloc((duzinaPoruke + 1) * sizeof(char));
	
	if (strana == 'l') {
		shiftuj(poruka, novaPoruka, duzinaPoruke, shift, levo);
	}
	else {
		shiftuj(poruka, novaPoruka, duzinaPoruke, shift, desno);
	}
	
	ispisi(novaPoruka, duzinaPoruke);
	
	free(poruka);
	free(novaPoruka);
	
	return 0;
}

