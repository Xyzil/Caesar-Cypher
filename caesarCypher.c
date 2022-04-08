#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "caesarCypher.h"

void greska(const char *error) {
	fprintf(stderr, "%s\n", error);
	exit(EXIT_FAILURE);
}

char levo(const char poruka, const char oznaka,
		  const int mesta, const int modulo) {
			  
	return (poruka - oznaka + mesta) % modulo + oznaka;
}

char desno(const char poruka, const char oznaka,
		   const int mesta, const int modulo) {
			   
	return (poruka - oznaka + (modulo - mesta)) % modulo + oznaka;
}

void shiftuj(char *poruka, char *novaPoruka, const int n, const int mesta, 
			 char (*fja)(const char, const char, const int, const int)) {
	
	char oznaka;
	int modulo = 26;
	
	for (int i = 0; i < n; ++i) {
		
		if (isupper(poruka[i])) {
			oznaka = 'A';
		}
		else if (islower(poruka[i])) {
			oznaka = 'a';
		}
		else if (isdigit(poruka[i])) {
			oznaka = '0';
			modulo = 10;
		}
		else if(poruka[i] < ' ') {
			greska("greskica");
		}
		else {
			novaPoruka[i] = poruka[i];
			continue;
		}
		
		novaPoruka[i] = fja(poruka[i], oznaka, mesta, modulo);
	}
}
int unos(char **poruka) {
	
	char c = EOF;
	int alocirano = CHUNK, duzinaPoruke = 0;
	
	*poruka = (char *) malloc(CHUNK * sizeof(char));
	if (*poruka == NULL) {
		greska("poruka je null");
	}
	//getc(stdin);
	while (c) {
		
		c = getc(stdin);
		if (c == '\n' || c == EOF) {
			c = 0;
			break;
		}
		
		if (duzinaPoruke == alocirano) {
			alocirano += CHUNK;
			(*poruka) = realloc(poruka, alocirano);
			if ((*poruka) == NULL) {
				greska("lose realokacija");
			}
		}
		
		(*poruka)[duzinaPoruke] = c;
		++duzinaPoruke;
	}
	
	(*poruka)[duzinaPoruke] = '\0';
	
	return duzinaPoruke;
}

void ispisi(const char *poruka, const int duzinaPoruke) {
	
	for (int i = 0; i < duzinaPoruke; ++i) {
		printf("%c", poruka[i]);
	}
	printf("\n");
	
}
