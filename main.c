#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"

int main() {
    int **board=createBoard();

    printf("********Sah**********\n");
    hareketYazdir(board,'S',setPoz('F',7)); cleanBoard(board);

    printf("\n********Vezir**********\n");
    hareketYazdir(board,'V',setPoz('C',4));cleanBoard(board);
    printf("\n********Fil**********\n");
    hareketYazdir(board,'F',setPoz('D',6));cleanBoard(board);
    printf("\n********Kale**********\n");
    hareketYazdir(board,'K',setPoz('E',4));cleanBoard(board);
    printf("\n********Piyon**********\n");
    hareketYazdir(board,'P',setPoz('A',2));cleanBoard(board);
    printf("\n********At**********\n");
    hareketYazdir(board,'A',setPoz('E',5));cleanBoard(board);

    return 0;
}
