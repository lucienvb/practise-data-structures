#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findBiggest(char *input) {
    int biggest = 0;
    char *temp = malloc(20 * sizeof(char));
    if (!temp)
        return 1;
    for (int i = 0; i < 20; i++)
        temp[i] = '\0';

    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] != '-' && input[i] != ' ')
            temp[j++] = input[i];
        else {
            int current = atoi(temp);
            if (current > biggest)
                biggest = current;
            for (int i = 0; i < 20; i++)
                temp[i] = '\0';
            j = 0;
        }         
    }
    int current = atoi(temp);
    if (current > biggest)
        biggest = current;
    free(temp);
    return biggest;
}

// getFirst(char *link) {
// char first[];
// char second[];
// 

// }

int main() {
    char input[] = "1-2 3-2 1-3 2-4";
    char instance[10];

    int biggest = findBiggest(input);
    printf("biggest: %i\n", biggest);

    int matrix[biggest+1][biggest+1];
    for (int i = 0; i <= biggest; i++) {
        for (int j = 0; j <= biggest; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("input: %s\n", input);

    int j = 0;
    int first = 0;
    int second = 0;

    for (size_t i = 0; i <= strlen(input); i++) {
        printf("input[%zu]: %i\n", i, input[i]);
        if (input[i] == '-') {
            instance[j] = '\0';
            first = atoi(instance);
            printf("first: %i\n", first);
            printf("instance: %s\n", instance);
            j = 0;
            continue;
        }
        else if (input[i] == ' ' || input[i] == '\0') {
            instance[j] = '\0';
            second = atoi(instance);
            printf("second: %i\n", second);
            printf("instance: %s\n", instance);
            j = 0;
            matrix[first][second] = 1;
            matrix[second][first] = 1;
            continue;
        }
        instance[j] = input[i];
        j++;
    }

    printf("B\n");

    for (int i = 1; i <= biggest; i++) {
        printf("\nmatrix[%i]: ", i);
        for (int j = 0; j < biggest; j++) {
            printf("%i", matrix[i][j]);
        }
    }
    printf("\n");
    return 0;
}