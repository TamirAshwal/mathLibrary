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

intMatrix createIntMatrix(int i, int j);
doubleMatrix createDoubleMatrix(int i, int j);
void freeMatrixData(void* m, MatrixType type);
int get_element(intMatrix m, int i, int j);
void printMatrix(void* m, MatrixType type);
intMatrix matrixAddition(intMatrix m1, intMatrix m2);
intMatrix forTest(int arr[], int i, int j);
doubleMatrix forTestDouble(double arr[], int i, int j);
doubleMatrix matrixScaling(doubleMatrix m, double x);
int determinant(intMatrix m,int size);
#endif //MATHLIBRARY_LINEARALGEBRA_H
