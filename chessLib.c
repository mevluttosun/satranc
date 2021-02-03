#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"
int **createBoard() {
    int **v =(int **)calloc(8,sizeof(int *));
    int i;

    for (i=0; i<8; i++) {
        v[i] = (int *)calloc(8, sizeof(int));
    }

    return v;
}
void cleanBoard(int **v) {
    int i,j;

    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            v[i][j] = 0;
        }
    }
}
void printBoard(int **v) {
    int i,j;

    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            printf("%d \t",v[i][j]);
        }

        puts("");
        puts("");
    }
}

struct poz {
    short yatay;
    char dusey;
};
struct poz setPoz(char dus,short yat) {
    struct poz poz1;
    poz1.yatay=yat;
    poz1.dusey=dus;
    return poz1;
}
void addBoard(int **board,struct poz p,short val) {

    short row=8-p.yatay;
    short col=(int)(p.dusey)-65;

    if(col<0 ||row <0 || col>7 || row>7) { //controlling out of board
    } else {
        board[row][col]=val;
    }
}
struct poz *haraketSah(struct poz ilkpoz) {
    struct poz *sonuc=malloc(8*sizeof(struct poz));

    sonuc[0]=setPoz((char)(ilkpoz.dusey),ilkpoz.yatay+1);
    sonuc[1]=setPoz((char)(ilkpoz.dusey),ilkpoz.yatay-1);
    sonuc[2]=setPoz((char)(ilkpoz.dusey +1),ilkpoz.yatay);
    sonuc[3]=setPoz((char)(ilkpoz.dusey -1),ilkpoz.yatay);
    sonuc[4]=setPoz((char)(ilkpoz.dusey +1),ilkpoz.yatay+1);
    sonuc[5]=setPoz((char)(ilkpoz.dusey -1),ilkpoz.yatay-1);
    sonuc[6]=setPoz((char)(ilkpoz.dusey -1),ilkpoz.yatay+1);
    sonuc[7]=setPoz((char)(ilkpoz.dusey +1),ilkpoz.yatay-1);
    return sonuc;
}
struct poz *haraketVezir(struct poz ilkpoz) {
    struct poz *sonuc=malloc(64*sizeof(struct poz));
    int moveCount=0;
    int i,j;

    for(i=0; i<8; i++) { //dusey gitme
        if(i !=ilkpoz.yatay-1) {
            sonuc[moveCount]=setPoz(ilkpoz.dusey,i+1);
            moveCount++;
        }
    }

    for(i=0; i<8; i++) { //yatay gitme
        if(i !=(short)(ilkpoz.dusey-65)) {
            sonuc[moveCount]=setPoz((char)(i+65),ilkpoz.yatay);
            moveCount++;
        }
    }

    int birim=1;
    short control =0;

    for(i=0; i<8; i++) { //ust capraz gitme
        if(i<ilkpoz.yatay &&control !=1) {
            for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay+birim);
                moveCount++;
                birim++;
            }

            control=1;

        } else if(i>ilkpoz.yatay&&control ==1 ) {
            birim=1;

            for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay+birim);
                moveCount++;
                birim++;
            }

            control =0;
        }

    }

    birim=1;

    for(i=0; i<8; i++) { //alt capraz gitme
        if(i<ilkpoz.yatay &&control !=1) {
            for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay-birim);
                moveCount++;
                birim++;
            }

            control=1;

        } else if(i>ilkpoz.yatay&&control ==1 ) {
            birim=1;

            for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay-birim);
                moveCount++;
                birim++;
            }

            control =0;
        }

    }

    return sonuc;
}
struct poz *haraketFil(struct poz ilkpoz) {
    struct poz *sonuc=malloc(16*sizeof(struct poz));

    int moveCount=0;
    int i,j;
    int birim=1;
    int control =0;

    for(i=0; i<8; i++) { //ust capraz gitme
        if(i<ilkpoz.yatay &&control !=1) {
            for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay+birim);
                moveCount++;
                birim++;
            }

            control=1;

        } else if(i>ilkpoz.yatay&&control ==1 ) {
            birim=1;

            for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay+birim);
                moveCount++;
                birim++;
            }

            control =0;
        }

    }

    birim=1;

    for(i=0; i<8; i++) { //alt capraz gitme
        if(i<ilkpoz.yatay &&control !=1) {
            for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay-birim);
                moveCount++;
                birim++;
            }

            control=1;

        } else if(i>ilkpoz.yatay&&control ==1 ) {
            birim=1;

            for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay-birim);
                moveCount++;
                birim++;
            }

            control =0;
        }

    }

    return sonuc;
}

struct poz *haraketKale(struct poz ilkpoz) {
    struct poz *sonuc=malloc(16*sizeof(struct poz));
    int moveCount=0;
    int i;

    for(i=0; i<8; i++) { //dusey gitme
        if(i !=ilkpoz.yatay-1) {
            sonuc[moveCount]=setPoz(ilkpoz.dusey,i+1);
            moveCount++;
        }
    }

    for(i=0; i<8; i++) { //yatay gitme
        if(i !=(int)(ilkpoz.dusey-65)) {
            sonuc[moveCount]=setPoz((char)(i+65),ilkpoz.yatay);
            moveCount++;
        }
    }

    return sonuc;
}
struct poz *haraketPiyon(struct poz ilkpoz) {
    struct poz *sonuc=malloc(1*sizeof(struct poz));
    sonuc[0]=setPoz((char)(ilkpoz.dusey ),ilkpoz.yatay+1);
    return sonuc;
}
struct poz *haraketAt(struct poz ilkpoz) {
    struct poz *sonuc=malloc(8*sizeof(struct poz));
    sonuc[0]=setPoz((char)((int)(ilkpoz.dusey+2)),ilkpoz.yatay+1);
    sonuc[1]=setPoz((char)((int)(ilkpoz.dusey-2)),ilkpoz.yatay+1);
    sonuc[2]=setPoz((char)((int)(ilkpoz.dusey+2)),ilkpoz.yatay-1);
    sonuc[3]=setPoz((char)((int)(ilkpoz.dusey-2)),ilkpoz.yatay-1);
    sonuc[4]=setPoz((char)((int)(ilkpoz.dusey+1)),ilkpoz.yatay+2);
    sonuc[5]=setPoz((char)((int)(ilkpoz.dusey+1)),ilkpoz.yatay-2);
    sonuc[6]=setPoz((char)((int)(ilkpoz.dusey-1)),ilkpoz.yatay+2);
    sonuc[7]=setPoz((char)((int)(ilkpoz.dusey-1)),ilkpoz.yatay-2);
    return sonuc;
}

void hareketYazdir(int **board,char tas, struct poz ilkPozisyon) {
    int i;
    struct poz *(*satrancFonksiyonlari[6])(struct poz)= {haraketSah,haraketVezir,haraketFil,haraketKale,haraketPiyon,haraketAt};

    if(tas=='S') {
        struct poz *result=satrancFonksiyonlari[0](ilkPozisyon);
        addBoard(board,ilkPozisyon,2);

        for(i=0; i<8; i++) {
            addBoard(board,result[i],1);
        }

    }

    if(tas=='V') {
        struct poz *result=satrancFonksiyonlari[1](ilkPozisyon);
        addBoard(board,ilkPozisyon,2);

        for(i=0; i<64; i++) {
            addBoard(board,result[i],1);
        }
    }

    if(tas=='F') {
        struct poz *result=satrancFonksiyonlari[2](ilkPozisyon);
        addBoard(board,ilkPozisyon,2);

        for(i=0; i<16; i++) {
            addBoard(board,result[i],1);
        }
    }

    if(tas=='K') {
        struct poz *result=satrancFonksiyonlari[3](ilkPozisyon);
        addBoard(board,ilkPozisyon,2);

        for(i=0; i<16; i++) {
            addBoard(board,result[i],1);
        }
    }

    if(tas=='P') {
        struct poz *result=satrancFonksiyonlari[4](ilkPozisyon);
        addBoard(board,ilkPozisyon,2);
        addBoard(board,result[0],1);

    }

    if(tas=='A') {
        struct poz *result=satrancFonksiyonlari[5](ilkPozisyon);
        addBoard(board,ilkPozisyon,2);

        for(i=0; i<8; i++) {
            addBoard(board,result[i],1);
        }
    }

    printBoard(board);
}
