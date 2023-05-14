#include <stdio.h>

int pn[] = {1, 2, 3, 4};
int at[] = {0, 0, 0, 0};
int bt[] = {3, 6, 4, 5};
int bt1[] = {3, 6, 4, 5q};
int n = 4;
int quantum = 2;
int tat[100];
int wt[100];
int ct = 0;
int ctime[100];
int complete[100];

void ganchat() {
    for (int i = 0; i < n; i++) {
        if (bt[i] > 0) {
            printf("p%d ", pn[i]);
            ct += quantum;
            bt[i] -= quantum;
            if (bt[i] <= 0) {
                complete[i] = 1;
                ctime[i] = ct;
            }
        }
    }
}

int isComplete() {
    for (int i = 0; i < n; i++) {
        if (complete[i] != 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    while (isComplete()) {
        int min = 100000;
        for (int i = 0; i < n; i++) {
            if (at[i] < min && complete[i] != 1) {
                min = at[i];
            }
        }
        if (ct < min) {
            ct = min;
        }
        ganchat();
    }
    for (int i = 0; i < n; i++) {
        tat[i] = ctime[i] - at[i];
        wt[i] = tat[i] - bt1[i];
    }
    printf("\npn\tat\tbt\tctime\ttat\twt");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", pn[i], at[i], bt1[i], ctime[i], tat[i], wt[i]);
    }
    return 0;
}
