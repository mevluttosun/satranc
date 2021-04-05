#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"

int main() {
    int **board=createBoard();

    printf("********King**********\n\n");
    printMove(board,'K',setPos('F',7)); cleanBoard(board);

    printf("\n********Queen**********\n\n");
    printMove(board,'Q',setPos('C',4));cleanBoard(board);

    printf("\n********Bishop**********\n\n");
    printMove(board,'B',setPos('D',6));cleanBoard(board);

    printf("\n********Rook**********\n\n");
    printMove(board,'R',setPos('E',4));cleanBoard(board);

    printf("\n********Pawn**********\n\n");
    printMove(board,'P',setPos('A',2));cleanBoard(board);

    printf("\n********Knight**********\n\n");
    printMove(board,'k',setPos('E',5));cleanBoard(board);

    return 0;
}
