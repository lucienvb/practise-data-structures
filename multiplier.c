#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int char_to_digit(char c) 
{
    return c - '0';
}

char digit_to_char(int digit) 
{
    return digit + '0';
}

void multiply_strings(const char *str1, const char *str2) 
{
    // lengths per string and total
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len_result = len1 + len2;

    // result variable to store the multiplied strings in
    int *result = (int *)malloc(len_result * sizeof(int));
	int	i = 0;
    // bzero
	while (i < len_result)
		result[i++] = 0;

    // if negative, print dash sign
    int is_negative = (str1[0] == '-' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '-');
    if (is_negative) 
        write(1, "-", 1);

    // str[0] == '-' to make sure it start at the right index concerning a possible dash sign
    int start1 = str1[0] == '-';
    int start2 = str2[0] == '-';
    i = len1 - 1;
    while (i >= start1)
	{
        int j = len2 - 1;
        while (j >= start2) 
		{
            int mul = char_to_digit(str1[i]) * char_to_digit(str2[j]);
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
            j--;
        }
        i--;
    }
    int start_index = 0;
	
    // set start_index by skipping all zero at the beginning of the integer array
    while (start_index < len_result && result[start_index] == 0)
        start_index++;

    char    c;
    i = start_index;
    while (i < len_result) {
        c = digit_to_char(result[i++]);
        write (1, &c, 1);
    }
    write (1, "\n", 1);
    free(result);
}

int main(int argc, char **argv) 
{
	(void)argc;

    multiply_strings(argv[1], argv[2]);

    return 0;
}
