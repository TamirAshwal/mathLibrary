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
typedef enum {
    ROWVECTOR,
    COLUMNVECTOR
} vectorType;
typedef struct vector{
    vectorType type;
    int size;
    double* data;
}vector;
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
int determinant(int arr[],int arrSize);
doubleMatrix matrixMultiplication (doubleMatrix m1, doubleMatrix m2);
vector forTestVector(double arr[], vectorType i, int size);
void freeDataVector(vector v);
vector vectorScaling(vector v, double x);
vector vectorAddition(vector v1, vector v2);
double linearIndependence(vector v1, vector v2);
void printVectors(vector v, vectorType type);
#endif //MATHLIBRARY_LINEARALGEBRA_H
