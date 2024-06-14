#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Dugum {
    int anahtar;
    struct Dugum *sol;
    struct Dugum *sag;
    int yukseklik;
} Dugum;


int yukseklik(Dugum *n) {
    if (n == NULL)
        return 0;
    return n->yukseklik;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}
int denge(Dugum *N) {
    if (N == NULL)
        return 0;
    return yukseklik(N->sol) - yukseklik(N->sag);
}

Dugum* yeniDugum(int anahtar) {
    Dugum* dugum = (Dugum*)malloc(sizeof(Dugum));
    dugum->anahtar = anahtar;
    dugum->sol = NULL;
    dugum->sag = NULL;
    dugum->yukseklik = 1; 
    return(dugum);
}
Dugum *sagaDondur(Dugum *y) {
    Dugum *x = y->sol;       
    Dugum *T2 = x->sag;      // x'in sağ alt ağacını T2 olarak tanımlarız.

    x->sag = y;              // x'in sağ çocuğu y olur.
    y->sol = T2;             // y'nin sol çocuğu T2 olur.

    // Yükseklikleri güncelleriz.
    y->yukseklik = max(yukseklik(y->sol), yukseklik(y->sag)) + 1;
    x->yukseklik = max(yukseklik(x->sol), yukseklik(x->sag)) + 1;

    return x;                // Yeni kök düğüm x olur.
}
Dugum *solaDondur(Dugum *x) {
    Dugum *y = x->sag;       // x'in sağ çocuğunu y olarak tanımlarız.
    Dugum *T2 = y->sol;      // y'nin sol alt ağacını T2 olarak tanımlarız.

    y->sol = x;              // y'nin sol çocuğu x olur.
    x->sag = T2;             // x'in sağ çocuğu T2 olur.

    // Yükseklikleri güncelleriz.
    x->yukseklik = max(yukseklik(x->sol), yukseklik(x->sag)) + 1;
    y->yukseklik = max(yukseklik(y->sol), yukseklik(y->sag)) + 1;

    return y;                // Yeni kök düğüm y olur.
}
Dugum* ekle(Dugum* dugum, int anahtar) {
    if (dugum == NULL)
        return(yeniDugum(anahtar));

    if (anahtar < dugum->anahtar)
        dugum->sol = ekle(dugum->sol, anahtar);
    else if (anahtar > dugum->anahtar)
        dugum->sag = ekle(dugum->sag, anahtar);
    else
        return dugum;

    dugum->yukseklik = 1 + max(yukseklik(dugum->sol), yukseklik(dugum->sag));
    int deng = denge(dugum);


    if (deng > 1 && anahtar < dugum->sol->anahtar)
        return sagaDondur(dugum);

    if (deng < -1 && anahtar > dugum->sag->anahtar)
        return solaDondur(dugum);

    if (deng > 1 && anahtar > dugum->sol->anahtar) {
        dugum->sol = solaDondur(dugum->sol);
        return sagaDondur(dugum);
    }

    if (deng < -1 && anahtar < dugum->sag->anahtar) {
        dugum->sag = sagaDondur(dugum->sag);
        return solaDondur(dugum);
    }

    return dugum;
}
void preorder(Dugum *kok) {
    if (kok != NULL) {
        printf("%d ", kok->anahtar);
        preorder(kok->sol);
        preorder(kok->sag);
    }
}
void inorder(Dugum *kok) {
    if (kok != NULL) {
        inorder(kok->sol);
        printf("%d ", kok->anahtar);
        inorder(kok->sag);
    }
}
void postorder(Dugum *kok) {
    if (kok != NULL) {
        postorder(kok->sol);
        postorder(kok->sag);
        printf("%d ", kok->anahtar);
    }
}

int main(int argc, char *argv[]) {
	Dugum *kok = NULL;

    kok = ekle(kok, 10);
    kok = ekle(kok, 20);
    kok = ekle(kok, 30);
    kok = ekle(kok, 40);
    kok = ekle(kok, 50);
    kok = ekle(kok, 25);

    printf("pre-order: ");
    preorder(kok);
    printf("\n");

    printf("inorder: ");
    inorder(kok);
    printf("\n");

    printf("postorder: ");
    postorder(kok);
    printf("\n");

	return 0;
}