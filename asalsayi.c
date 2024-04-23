#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Fonksiyon prototipleri
bool asal_mi(int sayi);
void basamak_asal_sayilari_bul(int basamak_sayisi);

int main() {
    int basamak_sayisi;
    printf("Basamak sayisini giriniz (ornek: 4 icin 1000-9999 arasi): ");
    scanf("%d", &basamak_sayisi);

    basamak_asal_sayilari_bul(basamak_sayisi);

    return 0;
}

bool asal_mi(int sayi) {
    if (sayi < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(sayi); ++i) {
        if (sayi % i == 0) {
            return false;
        } 
    }
    return true;
}

void basamak_asal_sayilari_bul(int basamak_sayisi) {
    if (basamak_sayisi < 1) {
        printf("Gecersiz giris. Basamak sayisi en az 1 olmalidir.\n");
        return;
    }

    int baslangic = pow(10, basamak_sayisi - 1);
    int bitis = pow(10, basamak_sayisi);

    printf("%d basamakli asal sayilar:\n", basamak_sayisi);
    int count = 0;
    for (int sayi = baslangic; sayi < bitis; ++sayi) {
        if (asal_mi(sayi)) {
            printf("%d ", sayi);
	    count++;
      // if (sayi == 33331) {
      //   printf("bu sayi asal %d", sayi);
      //
      // break;
      // }
        }
    }
    printf("\n Toplam asal sayi sayisi: %d\n", count);
}

