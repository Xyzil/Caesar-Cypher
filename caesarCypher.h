#ifndef CAESAR_CYPHER
#define CAESAR_CYPHER

#define CHUNK 20

void greska(const char *);

char levo(const char, const char, const int, const int);

char desno(const char, const char, const int, const int);

void shiftuj(char *, char *, const int, const int,
			char (*)(const char, const char, const int, const int));
			
int unos(char **);

void ispisi(const char *, const int);

#endif
