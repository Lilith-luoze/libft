#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int test1 = isalpha('A');                     // good: normal char
    int test2 = isalpha(-5);                      // bad: not unsigned char, not EOF
    int test3 = isalpha((unsigned char)-5);       // fixed: forced into 0..255
    int test4 = isalpha(EOF);                     // good: EOF

    printf("isalpha('A') = %d\n", test1);             // expect: non-zero (true)
    printf("isalpha(-5) = %d\n", test2);              // undefined, may be random
    printf("isalpha((unsigned char)-5) = %d\n", test3); // expect: 0 or 1, safe
    printf("isalpha(EOF) = %d\n", test4);             // expect: 0

    return 0;
}
