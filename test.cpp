#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void inplace_swap(char* x, char* y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;
    printf("asdsa : %\d\n", length - 1);

    for (i = 0; i <= length - 1; i++)
        result += a[i];
    return result;
}

/* Determine whether arguments can be added without overflow*/
int uadd_ok(unsigned x, unsigned y);
int uadd_ok(unsigned x, unsigned y) {
    unsigned result = x + y;
    if (result < x || result < y)
        return 0;    // overflow
    else
        return 1;    // no overflow
}

/* Determine whether arguments can be added without overflow*/
int tadd_ok(int x, int y);
int tadd_ok(int x, int y) {
    int result = x + y;
    return ((result < 0 && x > 0 && y > 0) || (result > 0 && x < 0 && y < 0));
}




int main() 
{
    // int x = 5;
    // char s[] = "012345";
    // int* p = &x;
    // printf("the length of s is: %d\n", strlen(s));
    // show_bytes((byte_pointer)s, strlen(s));

    // printf("%d\n", 0b0010 ^ 0b0101);
    // printf("%d\n", 2 ^ 5);

    /*
    printf("x = %x\n", &s[0]);
    printf("x = %x\n", &s[1]);

    inplace_swap(&s[0], &s[1]);

    for (int i = 0; i < sizeof(s); i++) {
        printf("%c", s[i]);
    }
    */

    // float c[] = { 1.0, 2.0, 3.0 };
    // printf("result is: %d\n", sum_elements(c, 0));

    // unsigned short a = 8 < 3 ? 123 : 789;
    // printf("a = %d\n", a);

    int a = (1 << 8) - 1;
    // unsigned int result = a - b;
    printf("results = %d\n", a);

    return 0;
}