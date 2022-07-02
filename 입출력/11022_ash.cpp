#include <stdio.h>

int main() {
    int num, A, B;
    scanf_s("%d", &num); //visual studio에서는 scanf_s로 써야하고 scanf라 써야함... 어쩌란거지

    for (int i = 0; i < num; i++) {
        scanf_s("%d %d", &A, &B);
        printf("Case #%d: %d + %d = %d \n", i+1, A, B, A + B);
    }
    return 0;
}