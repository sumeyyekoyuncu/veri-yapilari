#include <stdio.h>
#include <stdlib.h>

struct dugum {
    int katsayi;
    int derece;
    struct dugum* next;
};

struct dugum* yenidugum(int katsayi, int derece) {
    struct dugum* yeni = (struct dugum*)malloc(sizeof(struct dugum));
    yeni->katsayi = katsayi;
    yeni->derece = derece;
    yeni->next = NULL;
    return yeni;
}

int main(int argc, char *argv[]) {
    int boyut1, i;
    int katsayi, derece;
    printf("Birinci polinomun derecesini girin: ");
    scanf("%d", &boyut1);
    
    int polinom1[boyut1+1];
    printf("Birinci polinomun katsayilarini girin:\n");
    for (i = 0; i <= boyut1; ++i) {
        printf("x^%d katsayisi: ", i);
        scanf("%d", &polinom1[i]);
    }

    struct dugum* polinom2 = NULL;
    printf("\n2. polinomun katsayisi ve derecesini giriniz\n");
    printf("-1 girerek programdan cikin");
    while (1) {
        printf("\nkatsayi:");
        scanf("%d", &katsayi);
        if (katsayi == -1) {
            break;
        }
        printf("\nderece:");
        scanf("%d", &derece);
        
        struct dugum* yeni = yenidugum(katsayi, derece);
        if (polinom2 == NULL) {
            polinom2 = yeni;
        } else {
            struct dugum* gecici = polinom2;
            while (gecici->next != NULL) {
                gecici = gecici->next;
            }
            gecici->next = yeni;
        }
    }

    struct dugum* sonuc = NULL;
    for (i = 0; i <= boyut1; ++i) {
        struct dugum* gecici = sonuc;
        if (gecici == NULL) {
            sonuc = yenidugum(polinom1[i], i);
        } else {
            while (gecici->next != NULL)
                gecici = gecici->next;
            gecici->next = yenidugum(polinom1[i], i);
        }
    }

    struct dugum* dolas = polinom2;
    while (dolas != NULL) {
        struct dugum* gecici = sonuc;
        if (gecici == NULL) {
            sonuc = yenidugum(dolas->katsayi, dolas->derece);
        } else {
            while (gecici->next != NULL) {
                gecici = gecici->next;
            }
            gecici->next = yenidugum(dolas->katsayi, dolas->derece);
        }
        dolas = dolas->next;
    }
  
    printf("\nToplam polinom: ");
    struct dugum* dolas2 = sonuc;
    while (dolas2 != NULL) {
        printf("%dx^%d ", dolas2->katsayi, dolas2->derece);
        if (dolas2->next != NULL) {
            printf("+ ");
        }
        dolas2 = dolas2->next;
    }
    printf("\n");

    return 0;
}