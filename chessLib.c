#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"

int **createBoard() { //creating empty matrix
    int **v =(int **)calloc(8,sizeof(int *));
    int i;

    for (i=0; i<8; i++) {
        v[i] = (int *)calloc(8, sizeof(int));
    }

    return v;
}
void cleanBoard(int **v) { //cleaning the matrix
    int i,j;

    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            v[i][j] = 0;
        }
    }
}
void printBoard(int **v) { //printing board and checking the boundry
    int i,j;

    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            printf("%d    ",v[i][j]);
        }

        puts("");
        puts("");
    }
}

struct pos {   //positions
    short horizontal;
    char vertical;
};
struct pos setPos(char dus,short yat) {
    struct pos pos1;
    pos1.horizontal=yat;
    pos1.vertical=dus;
    return pos1;
}
void addBoard(int **board,struct pos p,short val) {  //adding pieces according to value with board upside down

    short row=8-p.horizontal;
    short col=(int)(p.vertical)-65;

    if(col<0 ||row <0 || col>7 || row>7) { //controlling out of board
    } else {
        board[row][col]=val;
    }
}
struct pos *moveKing(struct pos firstPos) {
    struct pos *result=malloc(8*sizeof(struct pos));

    result[0]=setPos((char)(firstPos.vertical),firstPos.horizontal+1);
    result[1]=setPos((char)(firstPos.vertical),firstPos.horizontal-1);
    result[2]=setPos((char)(firstPos.vertical +1),firstPos.horizontal);
    result[3]=setPos((char)(firstPos.vertical -1),firstPos.horizontal);
    result[4]=setPos((char)(firstPos.vertical +1),firstPos.horizontal+1);
    result[5]=setPos((char)(firstPos.vertical -1),firstPos.horizontal-1);
    result[6]=setPos((char)(firstPos.vertical -1),firstPos.horizontal+1);
    result[7]=setPos((char)(firstPos.vertical +1),firstPos.horizontal-1);
    return result;
}
struct pos *moveQueen(struct pos firstPos) {
    struct pos *result=malloc(64*sizeof(struct pos));
    int moveCount=0;
    int i,j;

    for(i=0; i<8; i++) { //vertical move
        if(i !=firstPos.horizontal-1) {
            result[moveCount]=setPos(firstPos.vertical,i+1);
            moveCount++;
        }
    }

    for(i=0; i<8; i++) { //horizontal move
        if(i !=(short)(firstPos.vertical-65)) {
            result[moveCount]=setPos((char)(i+65),firstPos.horizontal);
            moveCount++;
        }
    }

    int unit=1;
    short control =0;

    for(i=0; i<8; i++) { //up cross move
        if(i<firstPos.horizontal &&control !=1) {
            for(j=0; j<(int)(firstPos.vertical-65)  ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical-unit)),firstPos.horizontal+unit);
                moveCount++;
                unit++;
            }

            control=1;

        } else if(i>firstPos.horizontal&&control ==1 ) {
            unit=1;

            for(j=0; j<(8- ((int)(firstPos.vertical)-65)) ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical+unit)),firstPos.horizontal+unit);
                moveCount++;
                unit++;
            }

            control =0;
        }

    }

    unit=1;

    for(i=0; i<8; i++) { //down cross move
        if(i<firstPos.horizontal &&control !=1) {
            for(j=0; j<(int)(firstPos.vertical-65)  ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical-unit)),firstPos.horizontal-unit);
                moveCount++;
                unit++;
            }

            control=1;

        } else if(i>firstPos.horizontal&&control ==1 ) {
            unit=1;

            for(j=0; j<(8- ((int)(firstPos.vertical)-65)) ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical+unit)),firstPos.horizontal-unit);
                moveCount++;
                unit++;
            }

            control =0;
        }

    }

    return result;
}
struct pos *moveBishop(struct pos firstPos) {
    struct pos *result=malloc(16*sizeof(struct pos));

    int moveCount=0;
    int i,j;
    int unit=1;
    int control =0;

    for(i=0; i<8; i++) { //up cross move
        if(i<firstPos.horizontal &&control !=1) {
            for(j=0; j<(int)(firstPos.vertical-65)  ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical-unit)),firstPos.horizontal+unit);
                moveCount++;
                unit++;
            }

            control=1;

        } else if(i>firstPos.horizontal&&control ==1 ) {
            unit=1;

            for(j=0; j<(8- ((int)(firstPos.vertical)-65)) ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical+unit)),firstPos.horizontal+unit);
                moveCount++;
                unit++;
            }

            control =0;
        }

    }

    unit=1;

    for(i=0; i<8; i++) { //down cross move
        if(i<firstPos.horizontal &&control !=1) {
            for(j=0; j<(int)(firstPos.vertical-65)  ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical-unit)),firstPos.horizontal-unit);
                moveCount++;
                unit++;
            }

            control=1;

        } else if(i>firstPos.horizontal&&control ==1 ) {
            unit=1;

            for(j=0; j<(8- ((int)(firstPos.vertical)-65)) ; j++) {
                result[moveCount]=setPos((char)((int)(firstPos.vertical+unit)),firstPos.horizontal-unit);
                moveCount++;
                unit++;
            }

            control =0;
        }

    }

    return result;
}

struct pos *moveRook(struct pos firstPos) {
    struct pos *result=malloc(16*sizeof(struct pos));
    int moveCount=0;
    int i;

    for(i=0; i<8; i++) { //vertical gitme
        if(i !=firstPos.horizontal-1) {
            result[moveCount]=setPos(firstPos.vertical,i+1);
            moveCount++;
        }
    }

    for(i=0; i<8; i++) { //horizontal gitme
        if(i !=(int)(firstPos.vertical-65)) {
            result[moveCount]=setPos((char)(i+65),firstPos.horizontal);
            moveCount++;
        }
    }

    return result;
}
struct pos *movePawn(struct pos firstPos) {
    struct pos *result=malloc(1*sizeof(struct pos));
    result[0]=setPos((char)(firstPos.vertical ),firstPos.horizontal+1);
    return result;
}
struct pos *moveKnight(struct pos firstPos) {
    struct pos *result=malloc(8*sizeof(struct pos));
    result[0]=setPos((char)((int)(firstPos.vertical+2)),firstPos.horizontal+1);
    result[1]=setPos((char)((int)(firstPos.vertical-2)),firstPos.horizontal+1);
    result[2]=setPos((char)((int)(firstPos.vertical+2)),firstPos.horizontal-1);
    result[3]=setPos((char)((int)(firstPos.vertical-2)),firstPos.horizontal-1);
    result[4]=setPos((char)((int)(firstPos.vertical+1)),firstPos.horizontal+2);
    result[5]=setPos((char)((int)(firstPos.vertical+1)),firstPos.horizontal-2);
    result[6]=setPos((char)((int)(firstPos.vertical-1)),firstPos.horizontal+2);
    result[7]=setPos((char)((int)(firstPos.vertical-1)),firstPos.horizontal-2);
    return result;
}

void printMove(int **board,char pieces, struct pos firstPosition) {
    int i;
    struct pos *(*chessFuncs[6])(struct pos)= {moveKing,moveQueen,moveBishop,moveRook,movePawn,moveKnight};

    if(pieces=='K') {
        struct pos *result=chessFuncs[0](firstPosition);
        addBoard(board,firstPosition,2);

        for(i=0; i<8; i++) {
            addBoard(board,result[i],1);
        }

    }

    if(pieces=='Q') {
        struct pos *result=chessFuncs[1](firstPosition);
        addBoard(board,firstPosition,2);

        for(i=0; i<64; i++) {
            addBoard(board,result[i],1);
        }
    }

    if(pieces=='B') {
        struct pos *result=chessFuncs[2](firstPosition);
        addBoard(board,firstPosition,2);

        for(i=0; i<16; i++) {
            addBoard(board,result[i],1);
        }
    }

    if(pieces=='R') {
        struct pos *result=chessFuncs[3](firstPosition);
        addBoard(board,firstPosition,2);

        for(i=0; i<16; i++) {
            addBoard(board,result[i],1);
        }
    }

    if(pieces=='P') {
        struct pos *result=chessFuncs[4](firstPosition);
        addBoard(board,firstPosition,2);
        addBoard(board,result[0],1);

    }

    if(pieces=='k') {
        struct pos *result=chessFuncs[5](firstPosition);
        addBoard(board,firstPosition,2);

        for(i=0; i<8; i++) {
            addBoard(board,result[i],1);
        }
    }

    printBoard(board);
}
