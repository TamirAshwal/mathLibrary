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
vector forTestVector(double arr[], vectorType type, int size){
    vector v;
    v.type = type;
    v.size = size;
    v.data = (double *) malloc(size * sizeof(double));
    for(int i = 0; i < size; i++){
        v.data[i] = arr[i];
    }
    return v;
}
void freeDataVector(vector v){
    free(v.data);
}
vector vectorAddition(vector v1, vector v2){
    vector v;
    if(v1.type != v2.type || v1.size != v2.size){
        errno = EDOM;
        printf("vectors must be the same size or type returning empty vector\n");
        v.data = NULL;
        return v;
    }
    v.size = v1.size;
    v.type = v1.type;
    int vSize = v1.size;
    v.data = (double *) malloc(vSize * sizeof(double));
    for(int i = 0; i < vSize; i++){
        v.data[i] = v1.data[i] + v2.data[i];
    }
    return v;
}
vector vectorScaling(vector v, double x){
    int vSize = v.size;
    for(int i = 0; i < vSize; i++){
        v.data[i] = v.data[i] * x;
    }
    return v;
}
double linearIndependence(vector v1, vector v2){
    if(v1.type != v2.type || v1.size != v2.size){
        errno = EDOM;
        printf("vectors must be the same size returning empty vector returning 0\n");
        return 0;
    }
    else{
        double check = v1.data[0] / v2.data[0];
        for(int i = 0; i < v1.size; i++){
            if(v1.data[i] / v2.data[i] != check){
                printf("vectors are independent\n");
                return 0;
            }
        }
        return check;
    }
}
void printVectors(vector v, vectorType type){
    if(type == ROWVECTOR){
        printf("(");
        for(int i = 0; i < v.size; i++){
            printf(" %.2lf, ", v.data[i]);
        }
        printf(")\n");
    }
    else{
        for(int i = 0; i < v.size; i++){
            printf("(%.2lf)\n", v.data[i]);
        }
    }
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
int determinant(int data[],int arrSize) {
    // if we got to the base condition return
    if (arrSize == 4) {
        return ((data[0] * data[3]) - (data[1] * data[2]));
    }
    if (arrSize == 1) {
        return data[0];
    }
    // index that changes sign for every element
    int index = (-1);
    int rowSize = (int) squareRoot(arrSize);
    int det = 0;
    int i,j,k;
    // the new array which size if the new matrix to multiply each element of the row
    int newArrSize = arrSize -  (2* rowSize - 1);
    int arrIndex = 0;
    // for every element in the row create a new array
    for(i = 0; i < rowSize; i++){
        int newArr[newArrSize];
        for(j = 1; j < rowSize; j++){
            for (k = 0; k < rowSize; k++, arrIndex++) {
                if((k % rowSize) ==  i){
                    arrIndex -=1;
                    continue;
                }
                newArr[arrIndex] = data[j * rowSize + k];
            }
        }
        det+= (int) power(index, i) * data[i] * determinant(newArr, newArrSize);
        arrIndex =0;
    }
    return det;
}
//doubleMatrix matrixMultiplication (doubleMatrix m1, doubleMatrix m2){
//    doubleMatrix newMatrix;
//    if(m1.cols != m2.rows){
//        errno = EDOM;
//        printf("the multiplication is not defined returning empty matrix\n");
//        return newMatrix;
//    }
//    int numberOfElements = m1.rows * m2.cols;
//    // initialize the new matrix
//    newMatrix.rows = m1.rows;
//    newMatrix.cols = m2.cols;
//    int rowSize = newMatrix.rows;
//    int colSize = newMatrix.cols;
//    newMatrix.data = (double*) malloc(numberOfElements * (sizeof(double)));
//    int i, j, k;
//    for(i = 0 ; i < newMatrix.rows; i++){
//        for(j = 0; j < colSize; j++){
//            newMatrix.data[i * rowSize + j] += m1.data[i * rowSize + j] +
//
//        }
//    }
//
//}

