#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "../include/linearAlgebra.h"
#include "../include/basicOperations.h"
intMatrix forTest(int arr[], int i, int j){
    intMatrix newMatrix;
    newMatrix.rows = i;
    newMatrix.cols = j;
    // add check if the malloc worked
    newMatrix.data = (int*) malloc(i * j * sizeof (int));
    int size = newMatrix.rows * newMatrix.cols;
    for(int index = 0; index < size; index++){
        newMatrix.data[index] = arr[index];
    }
    return newMatrix;
}
doubleMatrix forTestDouble(double arr[], int i, int j){
    doubleMatrix newMatrix;
    newMatrix.rows = i;
    newMatrix.cols = j;
    // add check if the malloc worked
    newMatrix.data = (double *) malloc(i * j * sizeof (double));
    int size = newMatrix.rows * newMatrix.cols;
    for(int index = 0; index < size; index++){
        newMatrix.data[index] = arr[index];
    }
    return newMatrix;
}
intMatrix createIntMatrix(int i, int j){
    intMatrix newMatrix;
    newMatrix.rows = i;
    newMatrix.cols = j;
    // add check if the malloc worked
    newMatrix.data = (int*) malloc(i * j * sizeof (int));
    int size = newMatrix.rows * newMatrix.cols;
    printf("please insert %d elements to the intMatrix\n", size);
    for(int index = 0; index < size; index++){
        scanf("%d", &newMatrix.data[index]);
    }
    return newMatrix;
}
doubleMatrix createDoubleMatrix(int i, int j){
    doubleMatrix newMatrix;
    newMatrix.rows = i;
    newMatrix.cols = j;
    // add check if the malloc worked
    newMatrix.data = (double*) malloc(i * j * sizeof (double));
    int size = newMatrix.rows * newMatrix.cols;
    printf("please insert %d elements to the intMatrix\n", size);
    for(int index = 0; index < size; index++){
        scanf("%lf", &newMatrix.data[index]);
    }
    return newMatrix;
}
void freeMatrixData(void* m, MatrixType type){
    if(type == INT_MATRIX){
        intMatrix* M = (intMatrix*) m;
        free(M->data);
    }
    else if(type == DOUBLE_MATRIX) {
        doubleMatrix *M = (doubleMatrix *) m;
        free(M->data);
    }
}
int get_element(intMatrix m, int i, int j){
    if(i >= m.rows || j >= m.cols ){
        errno = EDOM;
        printf("the index is out of range\n");
        return 0;
    }
    return m.data[(i * m.rows) + j];
}
void printMatrix(void* m, MatrixType type){
    int r;
    int c;

    if(type == INT_MATRIX){
        intMatrix* M = (intMatrix*) m;
        r = M->rows;
        c = M->cols;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%d ", M->data[r * i + j]);
            }
            printf("\n");
        }
    }
    else if(type == DOUBLE_MATRIX) {
        doubleMatrix* M = (doubleMatrix *) m;
        r = M->rows;
        c = M->cols;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%lf ", M->data[r * i + j]);
            }
            printf("\n");
        }
    }
}
intMatrix matrixAddition(intMatrix m1, intMatrix m2){
    if(m1.rows != m2.rows || m1.cols != m2.cols){
        errno = EDOM;
        printf("the index is out of range returning the first intMatrix\n");
        return m1;
    }
    int size = m1.rows * m1.cols;
    intMatrix newMatrix;
    newMatrix.rows = m1.rows;
    newMatrix.cols = m1.cols;
    newMatrix.data = (int*) malloc(m1.rows * m1.cols * sizeof (int));
    for(int i = 0 ; i < size; i++){
        newMatrix.data[i] = m1.data[i] + m2.data[i];
    }
    return newMatrix;
}
doubleMatrix matrixScaling(doubleMatrix m, double x){
    int size = m.rows * m.cols;
    doubleMatrix newMatrix;
    newMatrix.rows = m.rows;
    newMatrix.cols = m.cols;
    newMatrix.data = (double*) malloc(m.rows * m.cols * (sizeof(double)));
    for(int i = 0 ; i < size; i++){
        newMatrix.data[i] = m.data[i] * x;
    }
    return newMatrix;
}
int determinant(intMatrix m,int size){
    if(size == 4){
        return ((m.data[0] * m.data[3]) - (m.data[1] * m.data[2]));
    }
    if(size == 1){
        return m.data[0];
    }
}
