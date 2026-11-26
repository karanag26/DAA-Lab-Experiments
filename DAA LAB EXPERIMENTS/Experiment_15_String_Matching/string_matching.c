#include <stdio.h>
#include <string.h>

void naive(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern);

    printf("Naive:\n");

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;

        if (j == m)
            printf("Match at index %d\n", i);
    }
}

void rabinKarp(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern);
    int p = 0, t = 0;

    printf("Rabin-Karp:\n");

    for (int i = 0; i < m; i++) {
        p += pattern[i];
        t += text[i];
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;

            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            if (j == m)
                printf("Match at index %d\n", i);
        }

        if (i < n - m)
            t = t - text[i] + text[i + m];
    }
}

void KMP(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern);
    int lps[m], len = 0, i = 1;

    lps[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    i = 0;
    int j = 0;

    printf("KMP:\n");

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Match at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char text[] = "ABABCABAB";
    char pattern[] = "ABAB";

    naive(text, pattern);
    rabinKarp(text, pattern);
    KMP(text, pattern);

    return 0;
}