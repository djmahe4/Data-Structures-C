#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixElement;

void readSparseMatrix(SparseMatrixElement sparse[], int *num) {
    printf("Enter number of non-zero elements: ");
    scanf("%d", num);

    printf("Enter row, column, and value of each non-zero element:\n");
    for (int i = 0; i < *num; i++) {
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
}

void printSparseMatrix(SparseMatrixElement sparse[], int num) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

void addSparseMatrices(SparseMatrixElement a[], int n1, SparseMatrixElement b[], int n2, SparseMatrixElement result[], int *n3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            result[k++] = b[j++];
        } else {
            result[k] = a[i];
            result[k++].value = a[i++].value + b[j++].value;
        }
    }

    while (i < n1) {
        result[k++] = a[i++];
    }

    while (j < n2) {
        result[k++] = b[j++];
    }

    *n3 = k;
}

int main() {
    SparseMatrixElement a[MAX], b[MAX], result[MAX];
    int n1, n2, n3;

    printf("Enter elements of first sparse matrix:\n");
    readSparseMatrix(a, &n1);

    printf("Enter elements of second sparse matrix:\n");
    readSparseMatrix(b, &n2);

    addSparseMatrices(a, n1, b, n2, result, &n3);

    printf("Resultant sparse matrix after addition:\n");
    printSparseMatrix(result, n3);

    return 0;
}
