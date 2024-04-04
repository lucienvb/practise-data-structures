#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    (void)trustColSize;

    if (n == 1)
        return 1;
    if (n == 2 && trustSize == 1)
        return (trust[0][1]);
    for (int i = 1; i <= n; i++) {
        bool    isJudgeCandidate = true;
        int     trustOthers = 0;

        for (int j = 0; j < trustSize; j++) {
            if (trust[j][0] == i) {
                isJudgeCandidate = false;
                break ;
            }

            if (trust[j][1] == i) {
                trustOthers++;
            }
        }
        if (isJudgeCandidate && trustOthers == n -1)
            return i;
    }
    return -1;
}

int main() {
    int len = 3;
    int **trust = malloc(len * sizeof(int *));
    if (!trust)
        return 1;

    trust[0] = malloc(2 * sizeof(int));
    if (!trust[0]) {
        free(trust);
        return 1;
    }
    trust[0][0] = 1;
    trust[0][1] = 3;

    trust[1] = malloc(2 * sizeof(int));
    if (!trust[1]) {
        free(trust);
        return 1;
    }
    trust[1][0] = 2;
    trust[1][1] = 3;

    trust[2] = malloc(2 * sizeof(int));
    if (!trust[1]) {
        free(trust);
        return 1;
    }
    trust[2][0] = 3;
    trust[2][1] = 4;

    // trust[3] = malloc(2 * sizeof(int));
    // if (!trust[1]) {
    //     free(trust);
    //     return 1;
    // }
    // trust[3][0] = 2;
    // trust[3][1] = 4;

    // trust[4] = malloc(2 * sizeof(int));
    // if (!trust[1]) {
    //     free(trust);
    //     return 1;
    // }
    // trust[4][0] = 4;
    // trust[4][1] = 3;


    printf("result: %i\n", findJudge(4, (int **)trust, 3, NULL));

    // free(trust[4]);
    // free(trust[3]);
    free(trust[2]);
    free(trust[1]);
    free(trust[0]);
    free(trust);
}