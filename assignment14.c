#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[1000], P[100], R[100];

    fgets(S, 1000, stdin);
    S[strcspn(S, "\n")] = '\0';     // remove newline
    scanf("%s %s", P, R);

    int ls = strlen(S), lp = strlen(P), lr = strlen(R);

    // Step 1: count occurrences of P in S
    int count = 0;
    int i = 0;
    while (i < ls) {
        if (strncmp(&S[i], P, lp) == 0) {
            count++;
            i += lp;                // skip the whole match
        } else {
            i++;
        }
    }

    // Step 2: allocate exactly the needed size
    int lt = ls + count * (lr - lp);
    char *T = malloc(lt + 1);       // +1 for '\0'

    // Step 3: build T
    int k = 0;                      // position in T
    i = 0;
    while (i < ls) {
        if (strncmp(&S[i], P, lp) == 0) {
            strncpy(&T[k], R,lr);       // copy replacement
            k += lr;
            i += lp;
        } else {
            T[k++] = S[i++];        // copy one character
        }
    }
    T[k] = '\0';

    printf("%s\n", T);
    free(T);
    return 0;
}