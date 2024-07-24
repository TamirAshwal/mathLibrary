#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "../include/linearAlgebra.h"
#include "../include/basicOperations.h"
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

    int r = m->rows;
    int c = m.cols;
    if(type == INT_MATRIX) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%d ", m.data[r * i + j]);
            }
            printf("\n");
        }
    }
    else if(type == DOUBLE_MATRIX){
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%lf ", m.data[r * i + j]);
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
intMatrix matrixScaling(intMatrix m, double x);