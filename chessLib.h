#ifndef SATRANC_C
#define SATRANC_C
int **createBoard();
void printBoard(int **);
void cleanBoard(int **);
struct pos *moveKing(struct pos );
struct pos *moveQueen(struct pos );
struct pos *moveBishop(struct pos );
struct pos *moveKnight(struct pos );
struct pos *moveRook(struct pos );
struct pos *movePawn(struct pos );
void addBoard(int **,struct pos ,short );
#endif // SATRANC_C
