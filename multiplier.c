#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_to_digit(char c) {
    return c - '0';
}

char digit_to_char(int digit) {
    return digit + '0';
}

void multiply_strings(const char *str1, const char *str2) {

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len_result = len1 + len2;

    int *result = (int *)malloc(len_result * sizeof(int));
	int	i = 0;
	while (i < len_result)
		result[i++] = 0;

    int is_negative = (str1[0] == '-' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '-');
    if (is_negative) {
        printf("-");
    }

    for (int i = len1 - 1; i >= (str1[0] == '-'); i--) {
        for (int j = len2 - 1; j >= (str2[0] == '-'); j--) {
            int mul = char_to_digit(str1[i]) * char_to_digit(str2[j]);
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    int start_index = 0;
    while (start_index < len_result && result[start_index] == 0) {
        start_index++;
    }

    for (int i = start_index; i < len_result; i++) {
        printf("%c", digit_to_char(result[i]));
    }

    printf("\n");
    free(result);
}

int main(int argc, char **argv) {
	(void)argc;

    multiply_strings(argv[1], argv[2]);

    return 0;
}
