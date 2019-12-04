#include <allegro.h>
#include "inicia.h"
#include <cstdio>
#include <string>
#include <cstdio>
#include <fstream>
#define ANCHO 920
#define ALTO 500

using namespace std;

void load();
void money();
void records();
bool menu(bool);
char game(bool salida);
char estado(int n);
void load();
void print();
void numsco();
void puntos();
void pedir();
int cartA();
void cupier();
void usernew();
void name();
void cashp();
void fondos();

struct datos{
    BITMAP *userC[10];
    BITMAP *cupierC[10];

    int A[12];
    int B[12];
    int C[12];
    int D[12];

    int x[10];
    int scoore;
    int cash;
    int apu;

    int user;
    int cupier;

    int pj;
    int pc;

    char nameuser[50];
    char ap[5];
    char cadena[7];
    char punscore[10];
    BITMAP *name[50];
    int nom;
    int iap;

    BITMAP *INSTRUCCIONES[5];
    int ins;
    BITMAP *cashin[5];
};

datos data;
fstream file;

    BITMAP *buffer;
    BITMAP *fondo;              BITMAP *fondo1;     BITMAP *fondo3;         BITMAP *apuesta0;
    BITMAP *fondo2;             BITMAP *cursor;     BITMAP *tableDraw;      BITMAP *apuesta;
    BITMAP *table;              BITMAP *tableP;     BITMAP *tableDrawR;        BITMAP *credit;
    BITMAP *tablePP;            BITMAP *tableLose;  BITMAP *tableDrawE;     BITMAP *credits;
    BITMAP *tableLoseE;         BITMAP *tableLoseR; MIDI *music1;           MIDI *mus2;     MIDI *mlost;
    BITMAP *tableWin;           BITMAP *tableWinE;  BITMAP *user;             MIDI *cc;
    BITMAP *tableWinR;          BITMAP *tableA;     BITMAP *startc;     BITMAP *startr;   BITMAP *ins;

    BITMAP *a1;      BITMAP *b1;    BITMAP *c1;     BITMAP *d1;         BITMAP *x0;
    BITMAP *a2;      BITMAP *b2;    BITMAP *c2;     BITMAP *d2;         BITMAP *x1;
    BITMAP *a3;      BITMAP *b3;    BITMAP *c3;     BITMAP *d3;         BITMAP *x2;
    BITMAP *a4;      BITMAP *b4;    BITMAP *c4;     BITMAP *d4;         BITMAP *x3;
    BITMAP *a5;      BITMAP *b5;    BITMAP *c5;     BITMAP *d5;         BITMAP *x4;
    BITMAP *a6;      BITMAP *b6;    BITMAP *c6;     BITMAP *d6;         BITMAP *x5;
    BITMAP *a7;      BITMAP *b7;    BITMAP *c7;     BITMAP *d7;         BITMAP *x6;
    BITMAP *a8;      BITMAP *b8;    BITMAP *c8;     BITMAP *d8;         BITMAP *x7;
    BITMAP *a9;      BITMAP *b9;    BITMAP *c9;     BITMAP *d9;         BITMAP *x8;
    BITMAP *a10;     BITMAP *b10;   BITMAP *c10;    BITMAP *d10;        BITMAP *x9;
    BITMAP *aJ;      BITMAP *bJ;    BITMAP *cJ;     BITMAP *dJ;         BITMAP *ccupi;
    BITMAP *aQ;      BITMAP *bQ;    BITMAP *cQ;     BITMAP *dQ;         BITMAP *fond;
    BITMAP *aK;      BITMAP *bK;    BITMAP *cK;     BITMAP *dK;         BITMAP *uuse;

    BITMAP *n0;     BITMAP *n1;     BITMAP *n2;     BITMAP *n3;     BITMAP *n4;     BITMAP *score;
    BITMAP *n5;     BITMAP *n6;     BITMAP *n7;     BITMAP *n8;     BITMAP *n9;     BITMAP *in1;
    BITMAP *n10;    BITMAP *n11;    BITMAP *n12;    BITMAP *n13;    BITMAP *n14;    BITMAP *in2;
    BITMAP *n15;    BITMAP *n16;    BITMAP *n17;    BITMAP *n18;    BITMAP *n19;    BITMAP *in3;
    BITMAP *n20;    BITMAP *n21;    BITMAP *n22;    BITMAP *n23;    BITMAP *n24;    BITMAP *in4;
    BITMAP *n25;    BITMAP *n26;    BITMAP *n27;    BITMAP *n28;    BITMAP *n29;     BITMAP *exitr;
    BITMAP *n30;    BITMAP *nx;     BITMAP *nx1;    BITMAP *nx11;   BITMAP *cartap;

    BITMAP *a;      BITMAP *b;      BITMAP *c;      BITMAP *d;      BITMAP *e;
    BITMAP *f;      BITMAP *g;      BITMAP *h;      BITMAP *i;      BITMAP *j;
    BITMAP *q;      BITMAP *l;      BITMAP *m;      BITMAP *n;      BITMAP *o;
    BITMAP *p;      BITMAP *k;      BITMAP *r;      BITMAP *s;      BITMAP *t;
    BITMAP *u;      BITMAP *v;      BITMAP *w;      BITMAP *x;      BITMAP *y;
    BITMAP *z;

void load()
{
    buffer = create_bitmap(ANCHO,ALTO);
    clear_to_color(buffer, 0x999999);

    music1  = load_midi("Images/Africa.mid");
    mus2  = load_midi("Images/WinM.mid");
    cc = load_midi("Images/cc.mid");
    mlost = load_midi("Images/LostM.mid");

    q = load_bitmap("Images/Letras/q.bmp",NULL);     w = load_bitmap("Images/Letras/w.bmp",NULL);    e = load_bitmap("Images/Letras/e.bmp",NULL);     r = load_bitmap("Images/Letras/r.bmp",NULL);
    t = load_bitmap("Images/Letras/t.bmp",NULL);     y = load_bitmap("Images/Letras/y.bmp",NULL);    u = load_bitmap("Images/Letras/u.bmp",NULL);     i = load_bitmap("Images/Letras/i.bmp",NULL);
    o = load_bitmap("Images/Letras/o.bmp",NULL);     p = load_bitmap("Images/Letras/p.bmp",NULL);    a = load_bitmap("Images/Letras/a.bmp",NULL);     s = load_bitmap("Images/Letras/s.bmp",NULL);
    d = load_bitmap("Images/Letras/d.bmp",NULL);     f = load_bitmap("Images/Letras/f.bmp",NULL);    g = load_bitmap("Images/Letras/g.bmp",NULL);     h = load_bitmap("Images/Letras/h.bmp",NULL);
    j = load_bitmap("Images/Letras/j.bmp",NULL);     k = load_bitmap("Images/Letras/k.bmp",NULL);    l = load_bitmap("Images/Letras/l.bmp",NULL);     z = load_bitmap("Images/Letras/z.bmp",NULL);
    x = load_bitmap("Images/Letras/x.bmp",NULL);     c = load_bitmap("Images/Letras/c.bmp",NULL);    v = load_bitmap("Images/Letras/v.bmp",NULL);     b = load_bitmap("Images/Letras/b.bmp",NULL);
    n = load_bitmap("Images/Letras/n.bmp",NULL);     m = load_bitmap("Images/Letras/m.bmp",NULL);    credits = load_bitmap("Images/credits.bmp",NULL);  credit = load_bitmap("Images/credit.bmp",NULL);



    a1 = load_bitmap("Images/Carts/a1.bmp", NULL);    a2 = load_bitmap("Images/Carts/a2.bmp", NULL);
    a3 = load_bitmap("Images/Carts/a3.bmp", NULL);    a4 = load_bitmap("Images/Carts/a4.bmp", NULL);
    a5 = load_bitmap("Images/Carts/a5.bmp", NULL);    a6 = load_bitmap("Images/Carts/a6.bmp", NULL);
    a7 = load_bitmap("Images/Carts/a7.bmp", NULL);    a8 = load_bitmap("Images/Carts/a8.bmp", NULL);
    a9 = load_bitmap("Images/Carts/a9.bmp", NULL);    a10 = load_bitmap("Images/Carts/a10.bmp", NULL);
    aJ = load_bitmap("Images/Carts/aJ.bmp", NULL);    aQ = load_bitmap("Images/Carts/aQ.bmp", NULL);
    aK = load_bitmap("Images/Carts/aK.bmp", NULL);    cartap = load_bitmap("Images/Carts/fondo.bmp", NULL);

    b1 = load_bitmap("Images/Carts/b1.bmp", NULL);    b2 = load_bitmap("Images/Carts/b2.bmp", NULL);
    b3 = load_bitmap("Images/Carts/b3.bmp", NULL);    b4 = load_bitmap("Images/Carts/b4.bmp", NULL);
    b5 = load_bitmap("Images/Carts/b5.bmp", NULL);    b6 = load_bitmap("Images/Carts/b6.bmp", NULL);
    b7 = load_bitmap("Images/Carts/b7.bmp", NULL);    b8 = load_bitmap("Images/Carts/b8.bmp", NULL);
    b9 = load_bitmap("Images/Carts/b9.bmp", NULL);    b10 = load_bitmap("Images/Carts/b10.bmp", NULL);
    bJ = load_bitmap("Images/Carts/bJ.bmp", NULL);    bQ = load_bitmap("Images/Carts/bQ.bmp", NULL);
    bK = load_bitmap("Images/Carts/bK.bmp", NULL);

    c1 = load_bitmap("Images/Carts/c1.bmp", NULL);    c2 = load_bitmap("Images/Carts/c2.bmp", NULL);
    c3 = load_bitmap("Images/Carts/c3.bmp", NULL);    c4 = load_bitmap("Images/Carts/c4.bmp", NULL);
    c5 = load_bitmap("Images/Carts/c5.bmp", NULL);    c6 = load_bitmap("Images/Carts/c6.bmp", NULL);
    c7 = load_bitmap("Images/Carts/c7.bmp", NULL);    c8 = load_bitmap("Images/Carts/c8.bmp", NULL);
    c9 = load_bitmap("Images/Carts/c9.bmp", NULL);    c10 = load_bitmap("Images/Carts/c10.bmp", NULL);
    cJ = load_bitmap("Images/Carts/cJ.bmp", NULL);    cQ = load_bitmap("Images/Carts/cQ.bmp", NULL);
    cK = load_bitmap("Images/Carts/cK.bmp", NULL);

    d1 = load_bitmap("Images/Carts/d1.bmp", NULL);    d2 = load_bitmap("Images/Carts/d2.bmp", NULL);
    d3 = load_bitmap("Images/Carts/d3.bmp", NULL);    d4 = load_bitmap("Images/Carts/d4.bmp", NULL);
    d5 = load_bitmap("Images/Carts/d5.bmp", NULL);    d6 = load_bitmap("Images/Carts/d6.bmp", NULL);
    d7 = load_bitmap("Images/Carts/d7.bmp", NULL);    d8 = load_bitmap("Images/Carts/d8.bmp", NULL);
    d9 = load_bitmap("Images/Carts/d9.bmp", NULL);    d10 = load_bitmap("Images/Carts/d10.bmp", NULL);
    dJ = load_bitmap("Images/Carts/dJ.bmp", NULL);    dQ = load_bitmap("Images/Carts/dQ.bmp", NULL);
    dK = load_bitmap("Images/Carts/dK.bmp", NULL);

    fondo = load_bitmap("Images/Game/Start.bmp", NULL);                fondo1 = load_bitmap("Images/Game/Start1.bmp", NULL);            fondo3 = load_bitmap("Images/Game/Start3.bmp",NULL);        ins = load_bitmap("Images/Games/ins.bmp",NULL);
    fondo2 = load_bitmap("Images/Game/Start2.bmp",NULL);               cursor = load_bitmap("Images/Game/cursor.bmp", NULL);            tableDraw = load_bitmap("Images/Game/TableDraw.bmp", NULL);
    table = load_bitmap("Images/Game/Table.bmp", NULL);                tableP = load_bitmap("Images/Game/Table0.bmp", NULL);            tableDrawR = load_bitmap("Images/Game/TableDrawR.bmp", NULL);
    tablePP = load_bitmap("Images/Game/Table1.bmp", NULL);             tableLose = load_bitmap("Images/Game/TableLose.bmp", NULL);      tableDrawE = load_bitmap("Images/Game/TableDrawE.bmp", NULL);
    tableLoseE = load_bitmap("Images/Game/TableLoseE.bmp", NULL);      tableLoseR = load_bitmap("Images/Game/TableLoseR.bmp", NULL);    user = load_bitmap("Images/user.bmp",NULL);         exitr = load_bitmap("Images/rec.bmp",NULL);
    tableWinE = load_bitmap("Images/Game/TableWinE.bmp", NULL);        tableWin = load_bitmap("Images/Game/TableWin.bmp", NULL);        apuesta = load_bitmap("Images/Game/apuesta.bmp", NULL);
    tableWinR = load_bitmap("Images/Game/TableWinR.bmp", NULL);        tableA = load_bitmap("Images/Game/TableA.bmp", NULL);            startc = load_bitmap("Images/Game/StartC.bmp", NULL);            startr = load_bitmap("Images/Game/StartR.bmp", NULL);
    apuesta0 = load_bitmap("Images/Game/apuesta0.bmp", NULL);          nx1 = load_bitmap("Images/Game/x1.bmp", NULL); nx11 = load_bitmap("Images/Game/x11.bmp", NULL);

    n0 = load_bitmap("Images/Num/0.bmp", NULL);    n1 = load_bitmap("Images/Num/1.bmp", NULL);    n2 = load_bitmap("Images/Num/2.bmp", NULL);
    n3 = load_bitmap("Images/Num/3.bmp", NULL);    n4 = load_bitmap("Images/Num/4.bmp", NULL);    n5 = load_bitmap("Images/Num/5.bmp", NULL);
    n6 = load_bitmap("Images/Num/6.bmp", NULL);    n7 = load_bitmap("Images/Num/7.bmp", NULL);    n8 = load_bitmap("Images/Num/8.bmp", NULL);
    n9 = load_bitmap("Images/Num/9.bmp", NULL);    n10 = load_bitmap("Images/Num/10.bmp", NULL);    n11 = load_bitmap("Images/Num/11.bmp", NULL);
    n12 = load_bitmap("Images/Num/12.bmp", NULL);    n13 = load_bitmap("Images/Num/13.bmp", NULL);    n14 = load_bitmap("Images/Num/14.bmp", NULL);
    n15 = load_bitmap("Images/Num/15.bmp", NULL);    n16 = load_bitmap("Images/Num/16.bmp", NULL);    n17 = load_bitmap("Images/Num/17.bmp", NULL);
    n18 = load_bitmap("Images/Num/18.bmp", NULL);    n19 = load_bitmap("Images/Num/19.bmp", NULL);    n20 = load_bitmap("Images/Num/20.bmp", NULL);
    n21 = load_bitmap("Images/Num/21.bmp", NULL);    n22 = load_bitmap("Images/Num/22.bmp", NULL);    n23 = load_bitmap("Images/Num/23.bmp", NULL);
    n24 = load_bitmap("Images/Num/24.bmp", NULL);    n25 = load_bitmap("Images/Num/25.bmp", NULL);    n26 = load_bitmap("Images/Num/26.bmp", NULL);
    n27 = load_bitmap("Images/Num/27.bmp", NULL);    n28 = load_bitmap("Images/Num/28.bmp", NULL);    n29 = load_bitmap("Images/Num/29.bmp", NULL);
    n30 = load_bitmap("Images/Num/30.bmp", NULL);    nx = load_bitmap("Images/Num/x.bmp", NULL);      x0 = load_bitmap("Images/Num/x0.bmp", NULL);
    x1 = load_bitmap("Images/Num/x1.bmp", NULL);     x2 = load_bitmap("Images/Num/x2.bmp", NULL);     x3 = load_bitmap("Images/Num/x3.bmp", NULL);
    x4 = load_bitmap("Images/Num/x4.bmp", NULL);     x5 = load_bitmap("Images/Num/x5.bmp", NULL);     x6 = load_bitmap("Images/Num/x6.bmp", NULL);
    x7 = load_bitmap("Images/Num/x7.bmp", NULL);     x8 = load_bitmap("Images/Num/x8.bmp", NULL);     x9 = load_bitmap("Images/Num/x9.bmp", NULL);
    fond = load_bitmap("Images/Num/fondos.bmp", NULL);   ccupi = load_bitmap("Images/Num/cupier.bmp", NULL);    uuse = load_bitmap("Images/Num/user.bmp", NULL);
    score = load_bitmap("Images/Num/scoore.bmp", NULL);    in1 = load_bitmap("Images/Game/in1.bmp", NULL); in2 = load_bitmap("Images/Game/in2.bmp", NULL);  in3 = load_bitmap("Images/Game/in3.bmp", NULL);
    in4 = load_bitmap("Images/Game/in4.bmp", NULL);

    data.INSTRUCCIONES[1]=in1;
    data.INSTRUCCIONES[2]=in2;
    data.INSTRUCCIONES[3]=in3;
    data.INSTRUCCIONES[4]=in4;

    for(int i=0; i<=12; i++)
    {
        if(i<10)
        {
           data.A[i]=i+1;
           data.B[i]=i+1;
           data.C[i]=i+1;
           data.D[i]=i+1;
        }
        else
        {
            data.A[i]=10;
            data.B[i]=10;
            data.C[i]=10;
            data.D[i]=10;
        }
            data.userC[i]=NULL;
            data.cupierC[i]=NULL;
    }
    data.pj=0;
    data.pc=0;
    data.user=0;
    data.cupier=0;
    data.ins=0;

    data.x[0]=345;
    for(int i=1; i<11; i++)
    {
        data.x[i]=data.x[i-1]+20;
    }

    for(int i=0; i<50; i++)
    {
        data.name[i]=NULL;
    }

    data.nom=0;
    data.iap=0;

    for(int i=0; i<=5; i++)
    {
        data.cashin[i]=NULL;
    }
}

void fondos()
{
    strcpy(data.cadena,"");
    fflush(stdin);
    fflush(stdout);
    itoa(data.cash, data.cadena, 10);

    switch(data.cadena[0])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,461,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,461,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,461,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,461,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,461,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,461,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,461,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,461,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,461,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,461,438,34,33);
        break;
    }
    switch(data.cadena[1])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,481,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,481,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,481,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,481,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,481,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,481,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,481,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,481,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,481,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,481,438,34,33);
        break;
    }
    switch(data.cadena[2])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,501,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,501,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,501,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,501,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,501,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,501,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,501,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,501,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,501,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,501,438,34,33);
        break;
    }
    switch(data.cadena[3])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,521,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,521,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,521,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,521,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,521,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,521,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,521,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,521,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,521,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,521,438,34,33);
        break;
    }
    switch(data.cadena[4])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,541,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,541,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,541,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,541,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,541,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,541,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,541,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,541,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,541,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,541,438,34,33);
        break;
    }
    switch(data.cadena[5])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,561,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,561,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,561,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,561,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,561,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,561,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,561,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,561,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,561,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,561,438,34,33);
        break;
    }
    switch(data.cadena[6])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,581,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,581,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,581,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,581,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,581,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,581,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,581,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,581,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,581,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,581,438,34,33);
        break;
    }
 /*   switch(data.cadena[7])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,601,438,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,601,438,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,601,438,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,601,438,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,601,438,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,601,438,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,601,438,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,601,438,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,601,438,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,601,438,34,33);
        break;
    }
*/
}

void numsco()
{
    strcpy(data.punscore,"");
    fflush(stdin);
    itoa(data.scoore, data.punscore, 10);
    fflush(stdout);


    switch(data.punscore[0])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,734,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,734,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,734,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,734,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,734,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,734,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,734,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,734,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,734,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,734,52,34,33);
        break;
    }
    switch(data.punscore[1])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,754,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,754,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,754,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,754,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,754,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,754,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,754,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,754,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,754,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,754,52,34,33);
        break;
    }
    switch(data.punscore[2])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,774,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,774,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,774,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,774,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,774,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,774,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,774,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,774,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,774,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,774,52,34,33);
        break;
    }
    switch(data.punscore[3])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,794,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,794,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,794,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,794,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,794,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,794,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,794,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,794,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,794,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,794,52,34,33);
        break;
    }
    switch(data.punscore[4])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,814,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,814,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,814,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,814,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,814,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,814,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,814,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,814,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,814,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,814,52,34,33);
        break;
    }
    switch(data.punscore[5])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,834,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,834,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,834,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,834,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,834,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,834,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,834,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,834,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,834,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,834,52,34,33);
        break;
    }
    switch(data.punscore[6])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,854,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,854,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,854,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,854,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,854,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,854,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,854,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,854,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,854,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,854,52,34,33);
        break;
    }
 /*   switch(data.punscore[7])
    {
    case '0':
        masked_blit(n0,buffer, 0,0,874,52,34,33);
        break;
    case '1':
        masked_blit(n1,buffer, 0,0,874,52,34,33);
        break;
    case '2':
        masked_blit(n2,buffer, 0,0,874,52,34,33);
        break;
    case '3':
        masked_blit(n3,buffer, 0,0,874,52,34,33);
        break;
    case '4':
        masked_blit(n4,buffer, 0,0,874,52,34,33);
        break;
    case '5':
        masked_blit(n5,buffer, 0,0,874,52,34,33);
        break;
    case '6':
        masked_blit(n6,buffer, 0,0,874,52,34,33);
        break;
    case '7':
        masked_blit(n7,buffer, 0,0,874,52,34,33);
        break;
    case '8':
        masked_blit(n8,buffer, 0,0,874,52,34,33);
        break;
    case '9':
        masked_blit(n9,buffer, 0,0,874,52,34,33);
        break;
    }
*/
}

void money()
{
    char resp;
    int n;
do
{

    while ( !key[KEY_ENTER] )
    {
        if(key[KEY_0])
        {
            data.ap[data.iap]='0';
            data.cashin[data.iap]=x0;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_1])
        {
            data.ap[data.iap]='1';
            data.cashin[data.iap]=x1;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_2])
        {
            data.ap[data.iap]='2';
            data.cashin[data.iap]=x2;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_3])
        {
            data.ap[data.iap]='3';
            data.cashin[data.iap]=x3;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_4])
        {
            data.ap[data.iap]='4';
            data.cashin[data.iap]=x4;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_5])
        {
            data.ap[data.iap]='5';
            data.cashin[data.iap]=x5;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_6])
        {
            data.ap[data.iap]='6';
            data.cashin[data.iap]=x6;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_7])
        {
            data.ap[data.iap]='7';
            data.cashin[data.iap]=x7;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_8])
        {
            data.ap[data.iap]='8';
            data.cashin[data.iap]=x8;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_9])
        {
            data.ap[data.iap]='9';
            data.cashin[data.iap]=x9;
            data.iap++;
            rest(200);
        }
        else if(key[KEY_BACKSPACE])
        {
            if(data.iap>0)
            {
                data.ap[data.iap-1]='\0';
                data.iap--;
                data.cashin[data.iap]=NULL;
                rest(200);
            }
        }

        masked_blit(apuesta,buffer,0,0,0,0,920,500);

        cashp();
        fondos();

        masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
        masked_blit(buffer,screen, 0,0,0,0,920, 500);
    }

    n=atoi(data.ap);
    data.apu=n;
    if(n>data.cash)
    {
        resp='n';
         for(int i=0; i<=5; i++)
            {
                data.cashin[i]=NULL;
                data.ap[i]='\0';
            }
            data.iap=0;
        while(!key[KEY_SPACE])
        {
            masked_blit(apuesta0,buffer,0,0,0,0,920,500);
            masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
            masked_blit(buffer,screen, 0,0,0,0,920, 500);
        }
    }
    else
    {
        resp='s';
        data.cash-=data.apu;
    }

}while(resp!='s');

}

void cashp() //imprime numeros en pantalla
{
    if(data.cashin[0]!=NULL)
    {
        masked_blit(data.cashin[0],buffer,0,0,300,285,80,90);
    }

    if(data.cashin[1]!=NULL)
    {
        masked_blit(data.cashin[1],buffer,0,0,355,285,80,90);
    }
    if(data.cashin[2]!=NULL)
    {
        masked_blit(data.cashin[2],buffer,0,0,410,285,80,90);
    }

    if(data.cashin[3]!=NULL)
    {
        masked_blit(data.cashin[3],buffer,0,0,465,285,80,90);
    }
    if(data.cashin[4]!=NULL)
    {
        masked_blit(data.cashin[4],buffer,0,0,520,285,80,90);
    }

    if(data.cashin[5]!=NULL)
    {
        masked_blit(data.cashin[5],buffer,0,0,275,285,80,90);
    }
}

void name()
{
    if(data.name[0]!=NULL)
    {
        masked_blit(data.name[0],buffer,0,0,226,94,34,33);
    }

    if(data.name[1]!=NULL)
    {
        masked_blit(data.name[1],buffer,0,0,258,94,34,33);
    }
    if(data.name[2]!=NULL)
    {
        masked_blit(data.name[2],buffer,0,0,290,94,34,33);
    }
    if(data.name[3]!=NULL)
    {
        masked_blit(data.name[3],buffer,0,0,322,94,34,33);
    }
    if(data.name[4]!=NULL)
    {
        masked_blit(data.name[4],buffer,0,0,354,94,34,33);
    }
    if(data.name[5]!=NULL)
    {
        masked_blit(data.name[5],buffer,0,0,386,94,34,33);
    }
    if(data.name[6]!=NULL)
    {
        masked_blit(data.name[6],buffer,0,0,418,94,34,33);
    }
    if(data.name[7]!=NULL)
    {
        masked_blit(data.name[7],buffer,0,0,450,94,34,33);
    }
    if(data.name[8]!=NULL)
    {
        masked_blit(data.name[8],buffer,0,0,482,94,34,33);
    }
    if(data.name[9]!=NULL)
    {
        masked_blit(data.name[9],buffer,0,0,514,94,34,33);
    }
    if(data.name[10]!=NULL)
    {
        masked_blit(data.name[10],buffer,0,0,546,94,34,33);
    }
    if(data.name[11]!=NULL)
    {
        masked_blit(data.name[11],buffer,0,0,578,94,34,33);
    }
    if(data.name[12]!=NULL)
    {
        masked_blit(data.name[12],buffer,0,0,610,94,34,33);
    }
    if(data.name[13]!=NULL)
    {
        masked_blit(data.name[13],buffer,0,0,644,94,34,33);
    }

}

bool menu(bool salida)
{

    set_volume(230, 200);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO, ALTO, 0, 0);
    masked_blit(fondo,buffer,0,0,0,0,920,500);

    play_midi(music1,1);
     while(!salida)
       {

        if(mouse_x > 37 && mouse_x < 225 && mouse_y > 216 && mouse_y < 251)
        {
            masked_blit(fondo1,buffer,0,0,0,0,920,500);
            if(mouse_b & 1)
            {
                salida =true;
                data.cash=5000;
                data.scoore=0;
                usernew();
                rest(100);
            }
        }
        else if(mouse_x > 809 && mouse_x < 885 && mouse_y > 438 && mouse_y < 473)
        {
            masked_blit(fondo2,buffer, 0,0,0,0, 920,500);
            if(mouse_b & 1)
            {
                return false;
            }
        }
        else if(mouse_x > 704 && mouse_x < 896 && mouse_y > 221 && mouse_y < 250)
        {
            masked_blit(fondo3,buffer, 0,0,0,0, 920,500);
            if(mouse_b & 1)
            {
              int i=3;
              data.ins++;
              while(i==3)
              {
                  masked_blit(data.INSTRUCCIONES[data.ins],buffer,0,0,0,0,920,500);
                  if(mouse_x >20 && mouse_x < 141 && mouse_y > 3 && mouse_y<64)
                  {
                      masked_blit(cartap,buffer,0,0,mouse_x, mouse_y,27,39);
                      if(mouse_b & 1)
                      {
                        rest(200);
                          data.ins--;
                      }
                  }
                  else if(mouse_x >810 && mouse_x < 891 && mouse_y > 12 && mouse_y<83)
                  {
                      masked_blit(cartap,buffer,0,0,mouse_x, mouse_y,27,39);
                      if(mouse_b & 1)
                      {
                          rest(200);
                            if(data.ins==4)
                            {
                                data.ins=0;
                                break;
                            }
                          data.ins++;
                      }

                  }


                  if(data.ins==0)
                  {
                      break;
                  }

                  masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
                  masked_blit(buffer,screen, 0,0,0,0,920, 500);
              }

            }
        }
        else if(mouse_x > 795 && mouse_x < 920 && mouse_y > 0 && mouse_y <38)
        {
            masked_blit(startc,buffer,0,0,0,0,920,500);
            if(mouse_b & 1)
            {
                int u=0;
                play_midi(cc,1);
                while(u==0)
                {
                    masked_blit(credits,buffer,0,0,0,0,920,500);
                    if(mouse_x > 17 && mouse_x < 121 && mouse_y > 16 && mouse_y < 68)
                    {
                        masked_blit(credit,buffer,0,0,0,0,920,500);
                        if(mouse_b & 1)
                        {
                            break;
                        }
                    }
                    masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
                    masked_blit(buffer,screen, 0,0,0,0,920, 500);
                }
            }
            play_midi(music1,1);
        }
        else if(mouse_x > 790 && mouse_x < 897 && mouse_y > 289 && mouse_y < 328)
        {
            masked_blit(startr,buffer,0,0,0,0,920,500);
            if(mouse_b & 1)
            {
                u=0;
                masked_blit(exitr,buffer,0,0,0,0,920,500);
                records();

              while(u==0)
                {

                    if(mouse_x > 17 && mouse_x < 121 && mouse_y > 16 && mouse_y < 68)
                    {
                        masked_blit(exitr,buffer,0,0,0,0,920,500);
                        if(mouse_b & 1)
                        {
                            file.close();
                            file.open("Datos.txt",ios::out|ios::app);
                            break;
                        }
                    }

                    masked_blit(cursor,screen,0,0,mouse_x, mouse_y,27,39);
                    masked_blit(buffer,screen, 0,0,0,0,920, 500);
                }
            }
        }
        else masked_blit(fondo, buffer,0,0,0,0, 920, 500);

        masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
        masked_blit(buffer,screen, 0,0,0,0,920, 500);
       }

    return salida;
}

char game(bool salida)
{
    int n;
    salida=false;
    char resp, exit;

    data.user=0;

    money();
     rest(50);
    pedir();
     rest(50);
    cupier();
     rest(50);
    pedir();
    masked_blit(table,buffer,0,0,0,0,920,500);
    print();
    puntos();
    rest(500);
    masked_blit(buffer,screen, 0,0,0,0,920, 500);



    do{


    while(!salida)
       {
        if(data.user >= 21)
        {
            n=2;
            salida=true;
        }

        if(mouse_x > 18 && mouse_x < 138 && mouse_y > 423 && mouse_y < 468)
        {
            masked_blit(tableP,buffer,0,0,0,0,920,500);
            if(mouse_b & 1)
            {
                salida =true;
                n=1;
            }
        }
        else if(mouse_x >706 && mouse_x < 909 && mouse_y > 423 && mouse_y < 468)
        {
            masked_blit(tablePP,buffer, 0,0,0,0, 920,500);
            if(mouse_b & 1)
            {
                salida=true;
                n=2;
            }
        }
        else masked_blit(table,buffer,0,0,0,0,920,500);
        //extras
        print();
        puntos();


        masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
        masked_blit(buffer,screen, 0,0,0,0,920, 500);
       }//end while menu pedir plantarse


       switch(n)
       {
            case 1:
                pedir();
                rest(300);
                exit='n';
                salida=false;
                break;
            case 2:
                salida=true;
                do{
                    cupier();
                    rest(1000);
                    masked_blit(table,buffer,0,0,0,0,920,500);
                    print();
                    puntos();
                    fondos();
                    rest(500);
                    masked_blit(buffer,screen, 0,0,0,0,920, 500);
                }while(data.cupier<17);
                masked_blit(table,buffer,0,0,0,0,920,500);
                print();
                puntos();
                fondos();
                masked_blit(buffer,screen, 0,0,0,0,920, 500);
                rest(1000);
                exit='s';
                break;
       }// end switch

       }while(exit != 's');

       if( (data.userC[0]==a1 || data.userC[0]==b1 || data.userC[0]==c1 || data.userC[0]==a1 ) && (data.userC[1]==aJ || data.userC[1]==aQ || data.userC[1]==aK || data.userC[1]==bJ || data.userC[1]==bQ || data.userC[1]==bK || data.userC[1]==cJ || data.userC[1]==cQ || data.userC[1]==cK || data.userC[1]==dJ || data.userC[1]==dQ || data.userC[1]==dK ) )
       {
            n=1;
            masked_blit(buffer,screen,0,0,0,0,ANCHO, ALTO);
            rest(500);
       }
       else if((data.userC[0]==aJ || data.userC[0]==aQ || data.userC[0]==aK || data.userC[0]==bJ || data.userC[0]==bQ || data.userC[0]==bK || data.userC[0]==cJ || data.userC[0]==cQ || data.userC[0]==cK || data.userC[0]==dJ || data.userC[0]==dQ || data.userC[0]==dK)&&(data.userC[1]==a1 || data.userC[1]==b1 || data.userC[1]==c1 || data.userC[1]==a1 ))
       {
            n=1;
            masked_blit(buffer,screen,0,0,0,0,ANCHO, ALTO);
            rest(500);
       }
       else if(data.user==data.cupier)
       {
           n=3;
           rest(500);;
           masked_blit(buffer,screen, 0,0,0,0,920, 500);
       }
       else if(data.user==21)
       {
           n=1;
           rest(500);;
           masked_blit(buffer,screen, 0,0,0,0,920, 500);
           if(data.cupier==21)
           {
               n=3;
           }
       }
       else if(data.cupier == 21)
       {
           n=2;
           rest(500);
           masked_blit(buffer,screen, 0,0,0,0,920, 500);
       }
       else if(data.cupier > 21)
       {
           n=1;
           rest(500);
           masked_blit(buffer,screen, 0,0,0,0,920, 500);
           if(data.user>data.cupier)
           {
               n=2;
           }

           if(data.user<data.cupier)
           {
               n=1;
           }
       }
       else if(data.user>21)
       {
           n=2;
           rest(500);
           masked_blit(buffer,screen, 0,0,0,0,920, 500);
       }
       else if(data.cupier==17)
       {
           n=2;
       }

        masked_blit(buffer,screen, 0,0,0,0,920, 500);
        rest(1000);


        if(n==1)
        {
            data.cash=data.cash+(2*data.apu);
        }
        else if(n==2)
        {
            data.cash=data.cash-data.apu;
        }
        else if(n==3)
        {
            data.cash+=data.apu;
        }

        if(data.user==21)
        {
            data.scoore+=1000;
        }
        else if(data.user==20)
        {
            data.scoore+=900;
        }
        else if(data.user==19)
        {
            data.scoore+=800;
        }
        else if(data.user==17)
        {
            data.scoore+=700;
        }
        else if(data.user==16)
        {
            data.scoore+=600;
        }
        else if(data.user==22)
        {
            data.scoore+=900;
        }
        else if(data.user==23)
        {
            data.scoore+=800;
        }
        else if(data.user==24)
        {
            data.scoore+=700;
        }
        else if(data.user==25)
        {
            data.scoore+=600;
        }
        else
        {
            data.scoore+=500;
        }

        resp=estado(n);

        if(data.cash<0)
        {
            return 'n';
            rest(1000);
        }

    return resp;

}

void print()
{
    if(data.userC[0]!=NULL)
    {
        masked_blit(data.userC[0],buffer,0,0, 345,295,73,94);
    }
    if(data.userC[1]!=NULL)
    {
        masked_blit(data.userC[1],buffer,0,0,data.x[1],300,73,94);
    }
    if(data.userC[2]!=NULL)
    {
        masked_blit(data.userC[2],buffer,0,0,data.x[2],302,73,94);
    }
    if(data.userC[3]!=NULL)
    {
        masked_blit(data.userC[3],buffer,0,0,data.x[3],304,73,94);
    }
    if(data.userC[4]!=NULL)
    {
        masked_blit(data.userC[4],buffer,0,0,data.x[4],304,73,94);
    }
    if(data.userC[5]!=NULL)
    {
        masked_blit(data.userC[5],buffer,0,0,data.x[5],304,73,94);
    }
    if(data.userC[6]!=NULL)
    {
        masked_blit(data.userC[6],buffer,0,0,data.x[6],302,73,94);
    }
    if(data.userC[7]!=NULL)
    {
        masked_blit(data.userC[7],buffer,0,0,data.x[7],306,73,94);
    }

    if(data.cupierC[0]!=NULL)
    {
        masked_blit(data.cupierC[0],buffer,0,0,365,82,73,94);
        masked_blit(cartap,buffer,0,0,data.x[2],84,73,94);
    }
    if(data.cupierC[1]!=NULL)
    {
        masked_blit(data.cupierC[1],buffer,0,0,data.x[2],84,73,94);
    }
    if(data.cupierC[2]!=NULL)
    {
        masked_blit(data.cupierC[2],buffer,0,0,data.x[3],88,73,94);
    }
    if(data.cupierC[3]!=NULL)
    {
        masked_blit(data.cupierC[3],buffer,0,0,data.x[4],93,73,94);
    }
    if(data.cupierC[4]!=NULL)
    {
        masked_blit(data.cupierC[4],buffer,0,0,data.x[5],93,73,94);
    }
    if(data.cupierC[5]!=NULL)
    {
        masked_blit(data.cupierC[5],buffer,0,0,data.x[6],88,73,94);
    }
    if(data.cupierC[6]!=NULL)
    {
        masked_blit(data.cupierC[6],buffer,0,0,data.x[7],84,73,94);
    }
    if(data.cupierC[7]!=NULL)
    {
        masked_blit(data.cupierC[7],buffer,0,0,data.x[8],82,73,94);
    }

}

void records()
{
                file.close();
                file.open("Datos.txt",ios::in);

                clear_to_color(buffer, 0x333333);
                    file.clear();    //<----------- I M P O R T A N T E
                    file.seekg( 0 );
                    string nom;
                    char nom1[30];
                    int naru=60, dinero, marcador;

                    while(file >> nom >> dinero >> marcador )
                    {
                        strcpy(nom1,nom.c_str());

                        textprintf(buffer, font, 200, naru, palette_color[12],"Player: %s", nom1);
                        textprintf(buffer, font, 460, naru, palette_color[12],"Money: %d", dinero);
                        textprintf(buffer, font, 680, naru, palette_color[12],"Score: %d", marcador);
                        naru+=20;

                        rest(100);
                        if(naru > 500 ){
                            break;
                            }
                    }


}

void puntos()
{
    masked_blit(ccupi,buffer,0,0,14,57,92,41);
    masked_blit(uuse,buffer,0,0,19,131,77,33);
    masked_blit(fond,buffer,0,0,338,438,77,33);
    masked_blit(score,buffer,0,0,761,11,92,41);

    fondos();
    numsco();

    fflush(stdin);
    switch(data.user)
    {
    case 0: masked_blit(n0,buffer,0,0,100,131,34,33);
        break;
    case 1: masked_blit(n1,buffer,0,0,100,131,34,33);
        break;
    case 2: masked_blit(n2,buffer,0,0,100,131,34,33);
        break;
    case 3: masked_blit(n3,buffer,0,0,100,131,34,33);
        break;
    case 4: masked_blit(n4,buffer,0,0,100,131,34,33);
        break;
    case 5: masked_blit(n5,buffer,0,0,100,131,34,33);
        break;
    case 6: masked_blit(n6,buffer,0,0,100,131,34,33);
        break;
    case 7: masked_blit(n7,buffer,0,0,100,131,34,33);
        break;
    case 8: masked_blit(n8,buffer,0,0,100,131,34,33);
        break;
    case 9: masked_blit(n9,buffer,0,0,100,131,34,33);
        break;
    case 10: masked_blit(n10,buffer,0,0,100,131,34,33);
        break;
    case 11: masked_blit(n11,buffer,0,0,100,131,34,33);
        break;
    case 12: masked_blit(n12,buffer,0,0,100,131,34,33);
        break;
    case 13: masked_blit(n13,buffer,0,0,100,131,34,33);
        break;
    case 14: masked_blit(n14,buffer,0,0,100,131,34,33);
        break;
    case 15: masked_blit(n15,buffer,0,0,100,131,34,33);
        break;
    case 16: masked_blit(n16,buffer,0,0,100,131,34,33);
        break;
    case 17: masked_blit(n17,buffer,0,0,100,131,34,33);
        break;
    case 18: masked_blit(n18,buffer,0,0,100,131,34,33);
        break;
    case 19: masked_blit(n19,buffer,0,0,100,131,34,33);
        break;
    case 20: masked_blit(n20,buffer,0,0,100,131,34,33);
        break;
    case 21: masked_blit(n21,buffer,0,0,100,131,34,33);
        break;
    case 22: masked_blit(n22,buffer,0,0,100,131,34,33);
        break;
    case 23: masked_blit(n23,buffer,0,0,100,131,34,33);
        break;
    case 24: masked_blit(n24,buffer,0,0,100,131,34,33);
        break;
    case 25: masked_blit(n25,buffer,0,0,100,131,34,33);
        break;
    case 26: masked_blit(n26,buffer,0,0,100,131,34,33);
        break;
    case 27: masked_blit(n27,buffer,0,0,100,131,34,33);
        break;
    case 28: masked_blit(n28,buffer,0,0,100,131,34,33);
        break;
    case 29: masked_blit(n29,buffer,0,0,100,131,34,33);
        break;
    case 30: masked_blit(n30,buffer,0,0,100,131,34,33);
        break;
    default: masked_blit(nx,buffer,0,0,100,131,34,33);
        break;
    }

     switch(data.cupier)
    {
    case 0: masked_blit(n0,buffer,0,0,112,58,34,33);
        break;
    case 1: masked_blit(n1,buffer,0,0,112,58,34,33);
        break;
    case 2: masked_blit(n2,buffer,0,0,112,58,34,33);
        break;
    case 3: masked_blit(n3,buffer,0,0,112,58,34,33);
        break;
    case 4: masked_blit(n4,buffer,0,0,112,58,34,33);
        break;
    case 5: masked_blit(n5,buffer,0,0,112,58,34,33);
        break;
    case 6: masked_blit(n6,buffer,0,0,112,58,34,33);
        break;
    case 7: masked_blit(n7,buffer,0,0,112,58,34,33);
        break;
    case 8: masked_blit(n8,buffer,0,0,112,58,34,33);
        break;
    case 9: masked_blit(n9,buffer,0,0,112,58,34,33);
        break;
    case 10: masked_blit(n10,buffer,0,0,112,58,34,33);
        break;
    case 11: masked_blit(n11,buffer,0,0,112,58,34,33);
        break;
    case 12: masked_blit(n12,buffer,0,0,112,58,34,33);
        break;
    case 13: masked_blit(n13,buffer,0,0,112,58,34,33);
        break;
    case 14: masked_blit(n14,buffer,0,0,112,58,34,33);
        break;
    case 15: masked_blit(n15,buffer,0,0,112,58,34,33);
        break;
    case 16: masked_blit(n16,buffer,0,0,112,58,34,33);
        break;
    case 17: masked_blit(n17,buffer,0,0,112,58,34,33);
        break;
    case 18: masked_blit(n18,buffer,0,0,112,58,34,33);
        break;
    case 19: masked_blit(n19,buffer,0,0,112,58,34,33);
        break;
    case 20: masked_blit(n20,buffer,0,0,112,58,34,33);
        break;
    case 21: masked_blit(n21,buffer,0,0,112,58,34,33);
        break;
    case 22: masked_blit(n22,buffer,0,0,112,58,34,33);
        break;
    case 23: masked_blit(n23,buffer,0,0,112,58,34,33);
        break;
    case 24: masked_blit(n24,buffer,0,0,112,58,34,33);
        break;
    case 25: masked_blit(n25,buffer,0,0,112,58,34,33);
        break;
    case 26: masked_blit(n26,buffer,0,0,112,58,34,33);
        break;
    case 27: masked_blit(n27,buffer,0,0,112,58,34,33);
        break;
    case 28: masked_blit(n28,buffer,0,0,112,58,34,33);
        break;
    case 29: masked_blit(n29,buffer,0,0,112,58,34,33);
        break;
    case 30: masked_blit(n30,buffer,0,0,112,58,34,33);
        break;
    }

}

void pedir()
{
    int cart;
    int slot;
    bool resp;

    while(!resp)
    {
        cart=0+rand()%(12-0+1);
        rest(50);
        slot=1+rand()%(4-1+1);
        cart=cart;

        switch(slot)
			{
				case 1:
					if(data.A[cart]==NULL)
					{
						resp=false;
					}
					else
					{
						if(cart==0)
                        {
                            data.user+=cartA();
                            data.A[cart]=NULL;
                        }
                        else
                        {
                            data.user+=data.A[cart];
                            data.A[cart]=NULL;
                        }
						switch(cart)
						{
                            case 0:
                                    data.userC[data.pj]=a1;
                                break;
                            case 1:
                                    data.userC[data.pj]=a2;
                                break;
                            case 2:
                                    data.userC[data.pj]=a3;
                                break;
                            case 3:
                                    data.userC[data.pj]=a4;
                                break;
                            case 4:
                                    data.userC[data.pj]=a5;
                                break;
                            case 5:
                                    data.userC[data.pj]=a6;
                                break;
                            case 6:
                                    data.userC[data.pj]=a7;
                                break;
                            case 7:
                                    data.userC[data.pj]=a8;
                                break;
                            case 8:
                                    data.userC[data.pj]=a9;
                                break;
                            case 9:
                                    data.userC[data.pj]=a10;
                                break;
                            case 10:
                                    data.userC[data.pj]=aJ;
                                break;
                            case 11:
                                    data.userC[data.pj]=aQ;
                                break;
                            case 12:
                                    data.userC[data.pj]=aK;
                                break;
						}

						resp=true;
					}
					break;
				case 2:
					if(data.B[cart]==NULL)
					{
						resp=false;
					}
					else
					{
						if(cart==0)
                        {
                            data.user+=cartA();
                            data.B[cart]=NULL;
                        }
                        else
                        {
                            data.user+=data.B[cart];
                            data.B[cart]=NULL;
                        }

						switch(cart)
						{
                            case 0:
                                    data.userC[data.pj]=b1;
                                break;
                            case 1:
                                    data.userC[data.pj]=b2;
                                break;
                            case 2:
                                    data.userC[data.pj]=b3;
                                break;
                            case 3:
                                    data.userC[data.pj]=b4;
                                break;
                            case 4:
                                    data.userC[data.pj]=b5;
                                break;
                            case 5:
                                    data.userC[data.pj]=b6;
                                break;
                            case 6:
                                    data.userC[data.pj]=b7;
                                break;
                            case 7:
                                    data.userC[data.pj]=b8;
                                break;
                            case 8:
                                    data.userC[data.pj]=b9;
                                break;
                            case 9:
                                    data.userC[data.pj]=b10;
                                break;
                            case 10:
                                    data.userC[data.pj]=bJ;
                                break;
                            case 11:
                                    data.userC[data.pj]=bQ;
                                break;
                            case 12:
                                    data.userC[data.pj]=bK;
                                break;
						}

						resp=true;
					}
					break;
				case 3:
					if(data.C[cart]==NULL)
					{
						resp=false;
					}
					else
					{
						if(cart==0)
                        {
                            data.user+=cartA();
                            data.C[cart]=NULL;
                        }
                        else
                        {
                            data.user+=data.C[cart];
                            data.C[cart]=NULL;
                        }
						switch(cart)
						{
                            case 0:
                                    data.userC[data.pj]=c1;
                                break;
                            case 1:
                                    data.userC[data.pj]=c2;
                                break;
                            case 2:
                                    data.userC[data.pj]=c3;
                                break;
                            case 3:
                                    data.userC[data.pj]=c4;
                                break;
                            case 4:
                                    data.userC[data.pj]=c5;
                                break;
                            case 5:
                                    data.userC[data.pj]=c6;
                                break;
                            case 6:
                                    data.userC[data.pj]=c7;
                                break;
                            case 7:
                                    data.userC[data.pj]=c8;
                                break;
                            case 8:
                                    data.userC[data.pj]=c9;
                                break;
                            case 9:
                                    data.userC[data.pj]=c10;
                                break;
                            case 10:
                                    data.userC[data.pj]=cJ;
                                break;
                            case 11:
                                    data.userC[data.pj]=cQ;
                                break;
                            case 12:
                                    data.userC[data.pj]=cK;
                                break;
						}

						resp=true;
					}
					break;
				case 4:
					if(data.D[cart]==NULL)
					{
						resp=false;
					}
					else
					{
						if(cart==0)
                        {
                            data.user+=cartA();
                            data.D[cart]=NULL;
                        }
                        else
                        {
                            if(cart==12)
                            {
                                data.user+=10;
                                data.D[12]=NULL;
                            }
                            else
                            {
                                data.user+=data.D[cart];
                                data.D[cart]=NULL;
                            }
                        }
						switch(cart)
						{
                            case 0:
                                    data.userC[data.pj]=d1;
                                break;
                            case 1:
                                    data.userC[data.pj]=d2;
                                break;
                            case 2:
                                    data.userC[data.pj]=d3;
                                break;
                            case 3:
                                    data.userC[data.pj]=d4;
                                break;
                            case 4:
                                    data.userC[data.pj]=d5;
                                break;
                            case 5:
                                    data.userC[data.pj]=d6;
                                break;
                            case 6:
                                    data.userC[data.pj]=d7;
                                break;
                            case 7:
                                    data.userC[data.pj]=d8;
                                break;
                            case 8:
                                    data.userC[data.pj]=d9;
                                break;
                            case 9:
                                    data.userC[data.pj]=d10;
                                break;
                            case 10:
                                    data.userC[data.pj]=dJ;
                                break;
                            case 11:
                                    data.userC[data.pj]=dQ;
                                break;
                            case 12:
                                    data.userC[data.pj]=dK;
                                break;
						}

						resp=true;
					}
					break;
			}

    }
    data.pj++;
}

int cartA()
{
    bool salida=false;
    int n;
    masked_blit(tableA,buffer,0,0,0,0,920,500);

     while(!salida)
       {
            if(mouse_x > 354 && mouse_x < 395 && mouse_y > 245 && mouse_y < 280)
        {
            print();
            puntos();
            masked_blit(nx1,buffer,0,0,0,0,920,500);
            if(mouse_b & 1)
            {
                n=1;
                salida =true;
            }
        }
        else if(mouse_x > 524 && mouse_x < 565 && mouse_y > 245 && mouse_y < 280)
        {
            print();
            puntos();
            masked_blit(nx11,buffer, 0,0,0,0,920,500);
            if(mouse_b & 1)
            {
                n=11;
                salida=true;
            }
        }
        else masked_blit(tableA, buffer,0,0,0,0, 920, 500);

        print();
        puntos();

        masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
        masked_blit(buffer,screen, 0,0,0,0,920, 500);
       }

    return n;
}

void cupier()
{
    int cart;
    int slot;
    bool resp;

    while(!resp)
    {
        cart=0+rand()%(12-0+1);
        rest(50);
        slot=1+rand()%(4-1+1);
        cart=cart;

        switch(slot)
			{
				case 1:
					if(data.A[cart]==NULL)
					{
						resp=false;
					}
					else
					{
                        if(cart==0)
                        {
                            if((data.cupier+11)>21)
                            {
                                data.cupier+=1;
                                data.A[cart]=NULL;
                            }
                            else
                            {
                                data.cupier+=11;
                                data.A[cart]=NULL;
                            }
                        }
                        else
                        {
                            data.cupier+=data.A[cart];
                            data.A[cart]=NULL;
                        }

						switch(cart)
						{
                            case 0:
                                    data.cupierC[data.pc]=a1;
                                break;
                            case 1:
                                    data.cupierC[data.pc]=a2;
                                break;
                            case 2:
                                    data.cupierC[data.pc]=a3;
                                break;
                            case 3:
                                    data.cupierC[data.pc]=a4;
                                break;
                            case 4:
                                    data.cupierC[data.pc]=a5;
                                break;
                            case 5:
                                    data.cupierC[data.pc]=a6;
                                break;
                            case 6:
                                    data.cupierC[data.pc]=a7;
                                break;
                            case 7:
                                    data.cupierC[
                                    data.pc]=a8;
                                break;
                            case 8:
                                    data.cupierC[data.pc]=a9;
                                break;
                            case 9:
                                    data.cupierC[
                                    data.pc]=a10;
                                break;
                            case 10:
                                    data.cupierC[
                                    data.pc]=aJ;
                                break;
                            case 11:
                                    data.cupierC[data.pc]=aQ;
                                break;
                            case 12:
                                    data.cupierC[
                                    data.pc]=aK;
                                break;
						}//end switch

						resp=true;
					}//endl if
					break;
				case 2:
					if(data.B[cart]==NULL)
					{
						resp=false;
					}
					else
					{
						if(cart==0)
                        {
                            if((data.cupier+11)>21)
                            {
                                data.cupier+=1;
                                data.B[cart]=NULL;
                            }
                            else
                            {
                                data.cupier+=11;
                                data.B[cart]=NULL;
                            }
                        }
                        else
                        {
                            data.cupier+=data.B[cart];
                            data.B[cart]=NULL;
                        }

						switch(cart)
						{
                            case 0:
                                    data.cupierC[
                                    data.pc]=b1;
                                break;
                            case 1:
                                    data.cupierC[data.pc]=b2;
                                break;
                            case 2:
                                    data.cupierC[data.pc]=b3;
                                break;
                            case 3:
                                    data.cupierC[data.pc]=b4;
                                break;
                            case 4:
                                    data.cupierC[data.pc]=b5;
                                break;
                            case 5:
                                    data.cupierC[data.pc]=b6;
                                break;
                            case 6:
                                    data.cupierC[data.pc]=b7;
                                break;
                            case 7:
                                    data.cupierC[data.pc]=b8;
                                break;
                            case 8:
                                    data.cupierC[data.pc]=b9;
                                break;
                            case 9:
                                    data.cupierC[data.pc]=b10;
                                break;
                            case 10:
                                    data.cupierC[data.pc]=bJ;
                                break;
                            case 11:
                                    data.cupierC[data.pc]=bQ;
                                break;
                            case 12:
                                    data.cupierC[data.pc]=bK;
                                break;
						}

						resp=true;
					}
					break;
				case 3:
					if(data.C[cart]==NULL)
					{
						resp=false;
					}
					else
					{
						if(cart==0)
                        {
                            if((data.cupier+11)>21)
                            {
                                data.cupier+=1;
                                data.C[cart]=NULL;
                            }
                            else
                            {
                                data.cupier+=11;
                                data.C[cart]=NULL;
                            }
                        }
                        else
                        {
                            data.cupier+=data.C[cart];
                            data.C[cart]=NULL;
                        }
						switch(cart)
						{
                            case 0:
                                    data.cupierC[data.pc]=c1;
                                break;
                            case 1:
                                    data.cupierC[data.pc]=c2;
                                break;
                            case 2:
                                    data.cupierC[data.pc]=c3;
                                break;
                            case 3:
                                    data.cupierC[data.pc]=c4;
                                break;
                            case 4:
                                    data.cupierC[data.pc]=c5;
                                break;
                            case 5:
                                    data.cupierC[data.pc]=c6;
                                break;
                            case 6:
                                    data.cupierC[data.pc]=c7;
                                break;
                            case 7:
                                    data.cupierC[data.pc]=c8;
                                break;
                            case 8:
                                    data.cupierC[data.pc]=c9;
                                break;
                            case 9:
                                    data.cupierC[data.pc]=c10;
                                break;
                            case 10:
                                    data.cupierC[data.pc]=cJ;
                                break;
                            case 11:
                                    data.cupierC[data.pc]=cQ;
                                break;
                            case 12:
                                    data.cupierC[data.pc]=cK;
                                break;
						}

						resp=true;
					}
					break;
				case 4:
					if(data.D[cart]==NULL)
					{
						resp=false;
					}
					else
					{
						if(cart==0)
                        {
                            if((data.cupier+11)>21)
                            {
                                data.cupier+=1;
                                data.D[cart]=NULL;
                            }
                            else
                            {
                                data.cupier+=11;
                                data.D[cart]=NULL;
                            }
                        }
                        else
                        {
                             if(cart==12)
                            {
                                data.cupier+=10;
                                data.D[12]=NULL;
                            }
                            else
                            {
                                data.cupier+=data.D[cart];
                                data.D[cart]=NULL;
                            }
                        }
						switch(cart)
						{
                            case 0:
                                    data.cupierC[data.pc]=d1;
                                break;
                            case 1:
                                    data.cupierC[data.pc]=d2;
                                break;
                            case 2:
                                    data.cupierC[data.pc]=d3;
                                break;
                            case 3:
                                    data.cupierC[data.pc]=d4;
                                break;
                            case 4:
                                    data.cupierC[data.pc]=d5;
                                break;
                            case 5:
                                    data.cupierC[data.pc]=d6;
                                break;
                            case 6:
                                    data.cupierC[data.pc]=d7;
                                break;
                            case 7:
                                    data.cupierC[data.pc]=d8;
                                break;
                            case 8:
                                    data.cupierC[data.pc]=d9;
                                break;
                            case 9:
                                    data.cupierC[data.pc]=d10;
                                break;
                            case 10:
                                    data.cupierC[data.pc]=dJ;
                                break;
                            case 11:
                                    data.cupierC[data.pc]=dQ;
                                break;
                            case 12:
                                    data.cupierC[data.pc]=dK;
                                break;
						}

						resp=true;
					}
					break;
			}

    }
    data.pc++;
}

char estado(int n)
{
    bool s=false;

    switch(n)
    {
        case 1:
            play_midi(mus2,1);
            while(!s)
            {
                if(mouse_x > 20 && mouse_x < 219 && mouse_y > 436 && mouse_y < 477)
                {
                    masked_blit(tableWinR,buffer,0,0,0,0,920,500);
                    if(mouse_b & 1)
                    {
                        return 's';
                    }
                }
                else if(mouse_x >804 && mouse_x < 899 && mouse_y > 432 && mouse_y < 476)
                {
                    masked_blit(tableWinE,buffer, 0,0,0,0, 920,500);
                    if(mouse_b & 1)
                    {
                        return 'n';
                    }
                }
                else masked_blit(tableWin,buffer,0,0,0,0,920,500);

                print();
                puntos();

                masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
                masked_blit(buffer,screen, 0,0,0,0,920, 500);

                if(data.cash<=0)
                {
                    rest(2000);
                    return 'n';
                }
            }

            break;
        case 2:
            play_midi(mlost,1);
             while(!s)
            {
                if(mouse_x > 20 && mouse_x < 219 && mouse_y > 436 && mouse_y < 477)
                {
                    masked_blit(tableLoseR,buffer,0,0,0,0,920,500);
                    if(mouse_b & 1)
                    {
                        return 's';
                    }
                }
                else if(mouse_x >804 && mouse_x < 899 && mouse_y > 432 && mouse_y < 476)
                {
                    masked_blit(tableLoseE,buffer, 0,0,0,0, 920,500);
                    if(mouse_b & 1)
                    {
                        return 'n';
                    }
                }
                else masked_blit(tableLose,buffer,0,0,0,0,920,500);

                puntos();


                masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
                masked_blit(buffer,screen, 0,0,0,0,920, 500);

                if(data.cash<=0)
                {
                    rest(2000);
                    return 'n';
                }
            }
            break;
        case 3:
             while(!s)
            {
                if(mouse_x > 20 && mouse_x <219 && mouse_y > 436 && mouse_y < 477)
                {
                    masked_blit(tableDrawR,buffer,0,0,0,0,920,500);
                    if(mouse_b & 1)
                    {
                        return 's';
                    }
                }
                else if(mouse_x >804 && mouse_x < 899 && mouse_y > 432 && mouse_y < 476)
                {
                    masked_blit(tableDrawE,buffer, 0,0,0,0, 920,500);
                    if(mouse_b & 1)
                    {
                        return 'n';
                    }
                }
                else masked_blit(tableDraw,buffer,0,0,0,0,920,500);

                print();
                puntos();

                masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
                masked_blit(buffer,screen, 0,0,0,0,920, 500);

                if(data.cash<=0)
                {
                    rest(2000);
                    return 'n';
                }
            }
            break;
    }

    return 0;
}

void usernew()
{

    while ( !key[KEY_ENTER] )
    {
        if(key[KEY_Q])
        {
            data.nameuser[data.nom]='q';
            data.name[data.nom]=q;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_W])
        {
            data.nameuser[data.nom]='w';
            data.name[data.nom]=w;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_E])
        {
            data.nameuser[data.nom]='e';
            data.name[data.nom]=e;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_R])
        {
            data.nameuser[data.nom]='r';
            data.name[data.nom]=r;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_T])
        {
            data.nameuser[data.nom]='t';
            data.name[data.nom]=t;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_Y])
        {
            data.nameuser[data.nom]='y';
            data.name[data.nom]=y;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_U])
        {
            data.nameuser[data.nom]='u';
            data.name[data.nom]=u;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_I])
        {
            data.nameuser[data.nom]='i';
            data.name[data.nom]=i;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_O])
        {
            data.nameuser[data.nom]='o';
            data.name[data.nom]=o;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_P])
        {
            data.nameuser[data.nom]='p';
            data.name[data.nom]=p;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_A])
        {
            data.nameuser[data.nom]='a';
            data.name[data.nom]=a;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_S])
        {
            data.nameuser[data.nom]='s';
            data.name[data.nom]=s;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_D])
        {
            data.nameuser[data.nom]='d';
            data.name[data.nom]=d;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_F])
        {
            data.nameuser[data.nom]='f';
            data.name[data.nom]=f;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_G])
        {
            data.nameuser[data.nom]='g';
            data.name[data.nom]=g;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_H])
        {
            data.nameuser[data.nom]='h';
            data.name[data.nom]=h;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_J])
        {
            data.nameuser[data.nom]='j';
            data.name[data.nom]=j;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_K])
        {
            data.nameuser[data.nom]='k';
            data.name[data.nom]=k;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_L])
        {
            data.nameuser[data.nom]='l';
            data.name[data.nom]=l;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_Z])
        {
            data.nameuser[data.nom]='z';
            data.name[data.nom]=z;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_X])
        {
            data.nameuser[data.nom]='x';
            data.name[data.nom]=x;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_C])
        {
            data.nameuser[data.nom]='c';
            data.name[data.nom]=c;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_V])
        {
            data.nameuser[data.nom]='v';
            data.name[data.nom]=v;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_B])
        {
            data.nameuser[data.nom]='b';
            data.name[data.nom]=b;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_N])
        {
            data.nameuser[data.nom]='n';
            data.name[data.nom]=n;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_M])
        {
            data.nameuser[data.nom]='m';
            data.name[data.nom]=m;
            data.nom++;
            rest(200);
        }
        else if(key[KEY_BACKSPACE])
        {
            if(data.nom>0)
            {
                data.nameuser[data.nom-1]='\0';
                data.nom--;
                data.name[data.nom]=NULL;
                rest(200);
            }
        }
        else if(key[KEY_SPACE])
        {
            data.nameuser[data.nom]=' ';
            data.nom++;
            rest(200);
        }

        masked_blit(user,buffer,0,0,0,0,920,500);

        name();

        masked_blit(cursor,buffer,0,0,mouse_x, mouse_y,27,39);
        masked_blit(buffer,screen, 0,0,0,0,920, 500);
    }

    rest(500);
}


int main ()
{
    srand(time(0));
    file.open("Datos.txt",ios::out|ios::app);

    inicia_allegro(ANCHO,ALTO);
    inicia_audio(70,70);
    install_mouse();

    set_volume(230, 200);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO, ALTO, 0, 0);

    char resp;
    bool salida;
    salida=false;
if ( !file )  // verifica que el archivo se abrio con exito
{
    buffer = create_bitmap(ANCHO,ALTO);
    clear_to_color(buffer, 0x999999);
    textout_centre_ex(buffer, font, "No se pudo abrir el archivo", ANCHO/2, ALTO/2, 0xFFFFFF, 0xDF1680);

}
else
{

    load();
        play_midi(cc,1);
      while(!key[KEY_ENTER])
      {
          blit(credits,buffer,0,0,0,0,920,500);
          blit(buffer,screen,0,0,0,0,920,500);
      }


   do{
       resp= 'n';

       load();

       salida=menu(salida);

       if(!salida)
            break;

        resp=game(salida);

        if(resp == 'n')
        {
            resp='s';
            salida=false;
            file << data.nameuser <<" "<<data.cash<<" "<<data.scoore<<endl;   //funcion que agregua datos al archivo
        }


   }while(resp == 's');

}//end else comprobacion de abrir archivo
    file.close();
    destroy_bitmap(buffer);

    return 0;
}END_OF_MAIN ()
