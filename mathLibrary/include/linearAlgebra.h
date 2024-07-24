#ifndef MATHLIBRARY_LINEARALGEBRA_H
#define MATHLIBRARY_LINEARALGEBRA_H
typedef struct intMatrix{
    int rows;
    int cols;
    int* data;
}intMatrix;
typedef struct doubleMatrix{
    int rows;
    int cols;
    double* data;
}doubleMatrix;
typedef enum { INT_MATRIX, DOUBLE_MATRIX } MatrixType;

intMatrix createMatrix(int i, int j);
void freeMatrixData(void* m, MatrixType type);
int get_element(intMatrix m, int i, int j);
void printMatrix(intMatrix m, MatrixType type);
intMatrix matrixAddition(intMatrix m1, intMatrix m2);

#endif //MATHLIBRARY_LINEARALGEBRA_H
