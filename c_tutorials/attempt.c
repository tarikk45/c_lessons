#include <stdio.h>
#include <stdbool.h> // bool veri tipi (true/false) için

int main() {
    int sayi;
    bool isAsal = true; // Başlangıçta sayıyı asal kabul ediyoruz

    // 1. Kullanıcıdan sayı alma
    printf("Lutfen pozitif bir tamsayi girin: ");
    scanf("%d", &sayi);

    // 2. Asal sayı kontrolü için özel durumlar
    // 0 ve 1 asal sayı değildir.
    if (sayi <= 1) {
        isAsal = false;
    } else {
        // 3. Ana kontrol döngüsü
        // Bir sayı, 2'den başlayarak kendisinin kareköküne kadar
        // (veya daha basitiyle yarısına kadar) olan hiçbir sayıya
        // bölünemiyorsa asaldır.
        // Verimlilik için i * i <= sayi kontrolü (karekökü) daha iyidir.
        for (int i = 2; i * i <= sayi; i++) {
            
            // Eğer sayı 'i'ye tam bölünüyorsa, asal değildir.
            if (sayi % i == 0) {
                isAsal = false;
                break; // Bölen bulunduğunda döngüden çık
            }
        }
    }

    // 4. Sonucu yazdırma
    if (isAsal) {
        printf("%d sayisi ASALDIR.\n", sayi);
    } else {
        printf("%d sayisi ASAL DEGILDIR.\n", sayi);
    }

    return 0;
}