#include <stdio.h>
#include <math.h>

#define MAX 10

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int i, j, sum[MAX][MAX];
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void saddlePoint(int a[MAX][MAX], int n) {
    int i, j, k, min, col, found = 0;

    for(i=0;i<n;i++) {
        min = a[i][0];
        col = 0;

        for(j=1;j<n;j++) {
            if(a[i][j] < min) {
                min = a[i][j];
                col = j;
            }
        }

        for(k=0;k<n;k++) {
            if(a[k][col] > min)
                break;
        }

        if(k == n) {
            printf("Saddle Point = %d\n", min);
            found = 1;
        }
    }

    if(!found)
        printf("No Saddle Point found\n");
}

void inverse2x2(float a[2][2]) {
    float det = (a[0][0]*a[1][1]) - (a[0][1]*a[1][0]);

    if(det == 0) {
        printf("Inverse not possible (determinant = 0)\n");
        return;
    }

    printf("Inverse Matrix:\n");
    printf("%.2f %.2f\n", a[1][1]/det, -a[0][1]/det);
    printf("%.2f %.2f\n", -a[1][0]/det, a[0][0]/det);
}

void magicSquare(int a[MAX][MAX], int n) {
    int i, j, sum=0, temp;

    for(j=0;j<n;j++)
        sum += a[0][j];

    for(i=1;i<n;i++) {
        temp = 0;
        for(j=0;j<n;j++)
            temp += a[i][j];
        if(temp != sum) {
            printf("Not a Magic Square\n");
            return;
        }
    }

    for(j=0;j<n;j++) {
        temp = 0;
        for(i=0;i<n;i++)
            temp += a[i][j];
        if(temp != sum) {
            printf("Not a Magic Square\n");
            return;
        }
    }

    int d1=0, d2=0;
    for(i=0;i<n;i++) {
        d1 += a[i][i];
        d2 += a[i][n-i-1];
    }

    if(d1 == sum && d2 == sum)
        printf("It is a Magic Square\n");
    else
        printf("Not a Magic Square\n");
}

int main() {
    int choice, r, c, n, i, j;
    int a[MAX][MAX], b[MAX][MAX];
    float mat2[2][2];

    printf("----- MENU -----\n");
    printf("1. Addition of Matrices\n");
    printf("2. Saddle Point\n");
    printf("3. Inverse (2x2 Matrix Only)\n");
    printf("4. Magic Square\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r, &c);

            printf("Enter first matrix:\n");
            for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                    scanf("%d", &a[i][j]);

            printf("Enter second matrix:\n");
            for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                    scanf("%d", &b[i][j]);

            printf("Result:\n");
            addMatrices(a, b, r, c);
            break;

        case 2:
            printf("Enter order of square matrix: ");
            scanf("%d", &n);

            printf("Enter matrix:\n");
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    scanf("%d", &a[i][j]);

            saddlePoint(a, n);
            break;

        case 3:
            printf("Enter 2x2 matrix:\n");
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    scanf("%f", &mat2[i][j]);

            inverse2x2(mat2);
            break;

        case 4:
            printf("Enter order of square matrix: ");
            scanf("%d", &n);

            printf("Enter matrix:\n");
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    scanf("%d", &a[i][j]);

            magicSquare(a, n);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
