#include "ft_printf.h"

int main() 
{
    unsigned int num_hex = 2;
    unsigned int num_unsigned = 42;
    int num_decimal = 42;
    unsigned long long ptr = (unsigned long long)&main;
    char c = 'A';
    int i = 0;

    while (i < 50) {
        // Test case for 'x' or 'X' format
        if (i < 5) {
            ft_printf("Hexadecimal (lowercase): %x\n", num_hex);
            ft_printf("Hexadecimal (uppercase): %X\n", num_hex);
            ft_printf("\n");
            num_hex += 20;
        }

        // Test case for 'u' format
        ft_printf("Unsigned: %u\n", num_unsigned);
        ft_printf("\n");
        if (num_unsigned > 420) {
            num_unsigned += 4200;
        } else if (num_unsigned > 10000) {
            num_unsigned += 42000;
        } else {
            num_unsigned += 200;
        }

        // Test case for 'c' format
        ft_printf("Character: %c\n", c);
        ft_printf("\n");

        // Test case for 's' format
        if (i < 1) {
            char *str = "Hello, world!";
            ft_printf("String: %s\n", str);
            ft_printf("\n");
        } else if (i < 2) {
            char *str = "Long string 1";
            ft_printf("String: %s\n", str);
            ft_printf("\n");
        } else if (i < 3) {
            char *str = "Long string 2";
            ft_printf("String: %s\n", str);
            ft_printf("\n");
        }

        // Test case for 'p' format
        if (i % 4 == 0) {
            ft_printf("Pointer: %p (num_hex) This is a pointer to num_hex\n", (void *)ptr);
            ptr = (unsigned long long)&num_hex;
        } else if (i % 4 == 1) {
            ft_printf("Pointer: %p (num_unsigned) This is a pointer to num_unsigned\n", (void *)ptr);
            ptr = (unsigned long long)&num_unsigned;
        } else if (i % 4 == 2) {
            ft_printf("Pointer: %p (num_decimal) This is a pointer to num_decimal\n", (void *)ptr);
            ptr = (unsigned long long)&num_decimal;
        } else {
            ft_printf("Pointer: %p (c) This is a pointer to c\n", (void *)ptr);
            ptr = (unsigned long long)&c;
        }
        ft_printf("\n");

        // Test case for 'd' or 'i' format
        ft_printf("Decimal: %d\n", num_decimal);
        ft_printf("\n");
        if (num_decimal > 420) {
            num_decimal += 4200;
        } else {
            num_decimal += 200;
        }

        // Test case for '%' format
        if (i < 1) {
            ft_printf("Percent: %%\n");
            ft_printf("\n");
        }

        // Cycle through the alphabet (uppercase and lowercase)
        if (c >= 'A' && c <= 'Z') {
            c++;
            if (c > 'Z') {
                c = 'a';
            }
        } else if (c >= 'a' && c <= 'z') {
            c++;
            if (c > 'z') {
                c = 'A';
            }
        }
        i++;
    }
    return 0;
}