#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int N, sum = 0;

    // 1. Dosyayı okuma modunda aç
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Hata: input.txt dosyasi bulunamadi!\n");
        return 1;
    }

    // 2. Eleman sayısını (N) oku
    if (fscanf(inputFile, "%d", &N) != 1) {
        printf("Hata: N degeri okunamadi.\n");
        fclose(inputFile);
        return 1;
    }

    // 3. N elemanlık dinamik bellek ayır
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Hata: Bellek ayrilamadi!\n");
        fclose(inputFile);
        return 1;
    }

    // 4. Pointer kullanarak elemanları oku
    int *num = array; // num pointer'ını dizinin başına eşitle
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d", (num + i));
    }
    fclose(inputFile);

    // 5. Pointer aritmetiği ile elemanları topla
    // (Dizi indeksi [] kullanmadan)
    int *ptr = array;
    for (int i = 0; i < N; i++) {
        sum += *(ptr + i); 
    }

    printf("Dizi elemanlarinin toplami: %d\n", sum);

    // 6. Elemanları output.txt dosyasına yaz
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Hata: output.txt olusturulamadi!\n");
        free(array);
        return 1;
    }

    num = array; // Pointer'ı tekrar başa al
    for (int i = 0; i < N; i++) {
        fprintf(outputFile, "%d\n", *(num + i));
    }

    // 7. Belleği temizle ve dosyayı kapat
    fclose(outputFile);
    free(array);

    printf("Islem tamamlandi. Elemanlar output.txt dosyasina yazildi.\n");

    return 0;
}