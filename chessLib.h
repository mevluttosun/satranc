#ifndef SATRANC_C
#define SATRANC_C
int **createBoard();
void printBoard(int **);
void cleanBoard(int **);
struct poz *hareketSah(struct poz );
struct poz *hareketVezir(struct poz );
struct poz *hareketFil(struct poz );
struct poz *hareketAt(struct poz );
struct poz *hareketKale(struct poz );
struct poz *hareketPiyon(struct poz );
void addBoard(int **,struct poz ,short );
#endif // SATRANC_C
