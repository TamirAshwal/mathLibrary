#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include "allMathFunctions.h"

#define ASSERT(condition, message) do { \
    if (!(condition)) { \
        printf("FAILED: %s\n", message); \
        failed_tests++; \
    } else { \
        passed_tests++; \
    } \
} while (0)

#define ASSERT_DOUBLE_EQ(a, b, epsilon, message) do { \
    if (absoluteValue((a) - (b)) > (epsilon)) { \
        printf("FAILED: %s. Expected %f, got %f\n", message, (double)(b), (double)(a)); \
        failed_tests++; \
    } else { \
        passed_tests++; \
    } \
} while (0)

int passed_tests = 0;
int failed_tests = 0;

void test_basic_operations() {
    ASSERT_DOUBLE_EQ(add(5, 7), 12, EPSILON, "add(5, 7) should equal 12");
    ASSERT_DOUBLE_EQ(add(-5, 5), 0, EPSILON, "add(-5, 5) should equal 0");
    ASSERT_DOUBLE_EQ(add(DBL_MAX, 1), DBL_MAX, EPSILON, "add(DBL_MAX, 1) should equal DBL_MAX");

    ASSERT_DOUBLE_EQ(sub(10, 7), 3, EPSILON, "sub(10, 7) should equal 3");
    ASSERT_DOUBLE_EQ(sub(5, 5), 0, EPSILON, "sub(5, 5) should equal 0");
    ASSERT_DOUBLE_EQ(sub(-5, 5), -10, EPSILON, "sub(-5, 5) should equal -10");

    ASSERT_DOUBLE_EQ(multiply(5, 7), 35, EPSILON, "multiply(5, 7) should equal 35");
    ASSERT_DOUBLE_EQ(multiply(5, 0), 0, EPSILON, "multiply(5, 0) should equal 0");
    ASSERT_DOUBLE_EQ(multiply(-5, -5), 25, EPSILON, "multiply(-5, -5) should equal 25");

    ASSERT_DOUBLE_EQ(divide(10, 2), 5, EPSILON, "divide(10, 2) should equal 5");
    ASSERT_DOUBLE_EQ(divide(5, 1), 5, EPSILON, "divide(5, 1) should equal 5");
    ASSERT_DOUBLE_EQ(divide(0, 5), 0, EPSILON, "divide(0, 5) should equal 0");
    // Test division by zero (should set errno and return 0)
    errno = 0;
    ASSERT_DOUBLE_EQ(divide(5, 0), 0, EPSILON, "divide(5, 0) should return 0");
    ASSERT(errno == EDOM, "divide(5, 0) should set errno to EDOM");

    ASSERT_DOUBLE_EQ(factorial(5), 120, EPSILON, "factorial(5) should equal 120");
    ASSERT_DOUBLE_EQ(factorial(0), 1, EPSILON, "factorial(0) should equal 1");
    ASSERT_DOUBLE_EQ(factorial(1), 1, EPSILON, "factorial(1) should equal 1");

    ASSERT_DOUBLE_EQ(absoluteValue(5), 5, EPSILON, "absoluteValue(5) should equal 5");
    ASSERT_DOUBLE_EQ(absoluteValue(-5), 5, EPSILON, "absoluteValue(-5) should equal 5");
    ASSERT_DOUBLE_EQ(absoluteValue(0), 0, EPSILON, "absoluteValue(0) should equal 0");

    ASSERT_DOUBLE_EQ(roundCheck(4.4), 4, EPSILON, "round(4.4) should equal 4");
    ASSERT_DOUBLE_EQ(roundCheck(4.5), 5, EPSILON, "round(4.5) should equal 5");
    ASSERT_DOUBLE_EQ(roundCheck(4.6), 5, EPSILON, "round(4.6) should equal 5");
    ASSERT_DOUBLE_EQ(roundCheck(-4.4), -4, EPSILON, "round(-4.4) should equal -4");
    ASSERT_DOUBLE_EQ(roundCheck(-4.5), -5, EPSILON, "round(-4.5) should equal -4");
    ASSERT_DOUBLE_EQ(roundCheck(-4.6), -5, EPSILON, "round(-4.6) should equal -5");

    ASSERT_DOUBLE_EQ(square(5), 25, EPSILON, "square(5) should equal 25");
    ASSERT_DOUBLE_EQ(square(-5), 25, EPSILON, "square(-5) should equal 25");
    ASSERT_DOUBLE_EQ(square(0), 0, EPSILON, "square(0) should equal 0");

    ASSERT_DOUBLE_EQ(power(2, 3), 8, EPSILON, "power(2, 3) should equal 8");
    ASSERT_DOUBLE_EQ(power(2, 0), 1, EPSILON, "power(2, 0) should equal 1");
    ASSERT_DOUBLE_EQ(power(0, 5), 0, EPSILON, "power(0, 5) should equal 0");
    ASSERT_DOUBLE_EQ(power(-2, 3), -8, EPSILON, "power(-2, 3) should equal -8");

    ASSERT_DOUBLE_EQ(squareRoot(9), 3, EPSILON, "squareRoot(9) should equal 3");
    ASSERT_DOUBLE_EQ(squareRoot(2), 1.4142135623730951, EPSILON, "squareRoot(2) should be approximately 1.4142135623730951");
    ASSERT_DOUBLE_EQ(squareRoot(0), 0, EPSILON, "squareRoot(0) should equal 0");

    ASSERT_DOUBLE_EQ(root(8, 3), 2, EPSILON, "root(8, 3) should equal 2");
    ASSERT_DOUBLE_EQ(root(16, 4), 2, EPSILON, "root(16, 4) should equal 2");
    ASSERT_DOUBLE_EQ(root(1, 5), 1, EPSILON, "root(1, 5) should equal 1");
    ASSERT_DOUBLE_EQ(root(0, 3), 0, EPSILON, "root(0, 3) should equal 0");
    // Test positive integer exponents
    ASSERT_DOUBLE_EQ(anyPower(2, 3), 8, EPSILON, "2^3 should equal 8");
    ASSERT_DOUBLE_EQ(anyPower(5, 2), 25, EPSILON, "5^2 should equal 25");

    // Test negative integer exponents
    ASSERT_DOUBLE_EQ(anyPower(2, -2), 0.25, EPSILON, "2^(-2) should equal 0.25");
    ASSERT_DOUBLE_EQ(anyPower(10, -3), 0.001, EPSILON, "10^(-3) should equal 0.001");

    // Test fractional exponents
    ASSERT_DOUBLE_EQ(anyPower(9, 0.5), 3, EPSILON, "9^0.5 should equal 3 (square root of 9)");
    ASSERT_DOUBLE_EQ(anyPower(8, 1.0/3.0), 2, EPSILON, "8^(1/3) should equal 2 (cube root of 8)");

    // Test zero exponent
    ASSERT_DOUBLE_EQ(anyPower(5, 0), 1, EPSILON, "5^0 should equal 1");
    ASSERT_DOUBLE_EQ(anyPower(-5, 0), 1, EPSILON, "-5^0 should equal 1");

    // Test base 1 with any exponent
    ASSERT_DOUBLE_EQ(anyPower(1, 1000000), 1, EPSILON, "1^1000000 should equal 1");
    ASSERT_DOUBLE_EQ(anyPower(1, -1000000), 1, EPSILON, "1^(-1000000) should equal 1");

    // Test negative base with integer exponent
    ASSERT_DOUBLE_EQ(anyPower(-2, 3), -8, EPSILON, "(-2)^3 should equal -8");
    ASSERT_DOUBLE_EQ(anyPower(-2, 2), 4, EPSILON, "(-2)^2 should equal 4");


    ASSERT_DOUBLE_EQ(eFunction(0), 1, EPSILON, "eFunction(0) should equal 1");
    ASSERT_DOUBLE_EQ(eFunction(1), e, EPSILON, "eFunction(1) should equal e");
    ASSERT_DOUBLE_EQ(eFunction(-1), 1/e, EPSILON, "eFunction(-1) should equal 1/e");
}

void test_trigonometric_functions() {
    ASSERT_DOUBLE_EQ(sinFunction(0), 0, EPSILON, "sinFunction(0) should equal 0");
    ASSERT_DOUBLE_EQ(sinFunction(PI/2), 1, EPSILON, "sinFunction(PI/2) should equal 1");
    ASSERT_DOUBLE_EQ(sinFunction(PI), 0, EPSILON, "sinFunction(PI) should be very close to 0");
    ASSERT_DOUBLE_EQ(sinFunction(3*PI/2), -1, EPSILON, "sinFunction(3*PI/2) should equal -1");

    ASSERT_DOUBLE_EQ(cosFunction(0), 1, EPSILON, "cosFunction(0) should equal 1");
    ASSERT_DOUBLE_EQ(cosFunction(PI/2), 0, EPSILON, "cosFunction(PI/2) should be very close to 0");
    ASSERT_DOUBLE_EQ(cosFunction(PI), -1, EPSILON, "cosFunction(PI) should equal -1");
    ASSERT_DOUBLE_EQ(cosFunction(3*PI/2), 0, EPSILON, "cosFunction(3*PI/2) should be very close to 0");

    ASSERT_DOUBLE_EQ(radianToDegrees(0), 0, EPSILON, "radianToDegrees(0) should equal 0");
    ASSERT_DOUBLE_EQ(radianToDegrees(PI), 180, EPSILON, "radianToDegrees(PI) should equal 180");
    ASSERT_DOUBLE_EQ(radianToDegrees(PI/2), 90, EPSILON, "radianToDegrees(PI/2) should equal 90");

    ASSERT_DOUBLE_EQ(degreesToRadian(0), 0, EPSILON, "degreesToRadian(0) should equal 0");
    ASSERT_DOUBLE_EQ(degreesToRadian(180), PI, EPSILON, "degreesToRadian(180) should equal PI");
    ASSERT_DOUBLE_EQ(degreesToRadian(90), PI/2, EPSILON, "degreesToRadian(90) should equal PI/2");
}

void test_linear_algebra() {
    // Test matrix creation and element access
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    intMatrix m = forTest(arr, 3, 3);
    ASSERT(m.rows == 3 && m.cols == 3, "Matrix dimensions should be 3x3");
    ASSERT(m.data[0] == 1 && m.data[8] == 9, "Matrix elements should be correctly set");

    // Test matrix addition
    int arr2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    intMatrix m2 = forTest(arr2, 3, 3);
    intMatrix sum = matrixAddition(m, m2);
    for (int i = 0; i < 9; i++) {
        ASSERT(sum.data[i] == 10, "Sum matrix elements should all be 10");
    }

    // Test matrix scaling
    double arr3[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    doubleMatrix dm = forTestDouble(arr3, 3, 3);
    doubleMatrix scaled = matrixScaling(dm, 2.0);
    for (int i = 0; i < 9; i++) {
        ASSERT_DOUBLE_EQ(scaled.data[i], dm.data[i] * 2.0, EPSILON, "Scaled matrix elements should be doubled");
    }

    // Test determinant
    int arr7[16] = {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15, 16};
    int det_4x4 = determinant(arr7, 16);
    printf("Determinant of 4x4 matrix: %d\n", det_4x4);
    ASSERT(det_4x4 == 0, "Determinant of this 4x4 matrix should be 0");

    // 5x5 matrix
    int arr9[25] = {2, 1, 3, 4, 5,
                    1, 2, 3, 4, 5,
                    1, 2, 3, 4, 5,
                    1, 2, 3, 4, 5,
                    1, 2, 3, 4, 6};
    int det_5x5 = determinant(arr9, 25);
    printf("Determinant of 5x5 matrix with linearly dependent rows: %d\n", det_5x5);
    ASSERT(det_5x5 == 0, "Determinant of this 5x5 matrix should be 0 due to linear dependence");

    // If you want to test a 5x5 matrix with a non-zero determinant, here's an example:
    int arr10a[25] = {2, 0, 0, 0, 0,
                     0, 2, 0, 0, 0,
                     0, 0, 2, 0, 0,
                     0, 0, 0, 2, 0,
                     0, 0, 0, 0, 2};
    int det_5x5_nonzero = determinant(arr10a, 25);
    printf("Determinant of 5x5 diagonal matrix: %d\n", det_5x5_nonzero);
    ASSERT(det_5x5_nonzero == 32, "Determinant of this 5x5 diagonal matrix should be 32");

    // 6x6 matrix
    int arr10[36] = {1, 2, 3, 4, 5, 6,
                     7, 8, 9, 10, 11, 12,
                     13, 14, 15, 16, 17, 18,
                     19, 20, 21, 22, 23, 24,
                     25, 26, 27, 28, 29, 30,
                     31, 32, 33, 34, 35, 36};
    int det_6x6 = determinant(arr10, 36);
    printf("Determinant of 6x6 matrix: %d\n", det_6x6);
    ASSERT(det_6x6 == 0, "Determinant of this 6x6 matrix should be 0");

    // Test with a known 3x3 matrix determinant
    int arr11[9] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int det_3x3_known = determinant(arr11, 9);
    printf("Determinant of known 3x3 matrix: %d\n", det_3x3_known);
    ASSERT(det_3x3_known == 0, "Determinant of this known 3x3 matrix should be 0");

    // Test with another known 3x3 matrix determinant
    int arr12[9] = {6, 1, 1,
                    4, -2, 5,
                    2, 8, 7};
    int det_3x3_known2 = determinant(arr12, 9);
    printf("Determinant of another known 3x3 matrix: %d\n", det_3x3_known2);
    ASSERT(det_3x3_known2 == -306, "Determinant of this known 3x3 matrix should be -306");


    // Test edge cases
    int zeros[9] = {0};
    intMatrix zero_matrix = forTest(zeros, 3, 3);
    intMatrix zero_sum = matrixAddition(m, zero_matrix);
    for (int i = 0; i < 9; i++) {
        ASSERT(zero_sum.data[i] == m.data[i], "Adding zero matrix should not change the original matrix");
    }

    doubleMatrix dm_zero = forTestDouble(zeros, 3, 3);
    doubleMatrix scaled_zero = matrixScaling(dm_zero, 5.0);
    for (int i = 0; i < 9; i++) {
        ASSERT_DOUBLE_EQ(scaled_zero.data[i], 0.0, EPSILON, "Scaling zero matrix should result in zero matrix");
    }
    printf("Starting vector tests...\n");

    // Test vector creation
    double arr_row[] = {1.0, 2.0, 3.0};
    vector v1 = forTestVector(arr_row, ROWVECTOR, 3);
    ASSERT(v1.type == ROWVECTOR, "v1 should be a row vector");
    ASSERT(v1.size == 3, "v1 should have size 3");
    ASSERT_DOUBLE_EQ(v1.data[0], 1.0, EPSILON, "First element of v1 should be 1.0");
    ASSERT_DOUBLE_EQ(v1.data[2], 3.0, EPSILON, "Last element of v1 should be 3.0");

    double arr_col[] = {4.0, 5.0, 6.0};
    vector v2 = forTestVector(arr_col, COLUMNVECTOR, 3);
    ASSERT(v2.type == COLUMNVECTOR, "v2 should be a column vector");
    ASSERT(v2.size == 3, "v2 should have size 3");

    // Test vector addition
    vector sum1 = vectorAddition(v1, v2);
    ASSERT(sum1.data == NULL, "Addition of incompatible vectors should return an empty vector");

    // Test vector addition with compatible vectors
    vector v1_copy = forTestVector(arr_row, ROWVECTOR, 3);
    vector sum_compatible = vectorAddition(v1, v1_copy);
    ASSERT(sum_compatible.size == 3, "Sum vector should have size 3");
    ASSERT_DOUBLE_EQ(sum_compatible.data[0], 2.0, EPSILON, "First element of sum should be 2.0");
    ASSERT_DOUBLE_EQ(sum_compatible.data[2], 6.0, EPSILON, "Last element of sum should be 6.0");

    // Test vector scaling
    vector scaled1 = vectorScaling(v1, 2.0);
    ASSERT_DOUBLE_EQ(scaled1.data[0], 2.0, EPSILON, "First element of scaled vector should be 2.0");
    ASSERT_DOUBLE_EQ(scaled1.data[2], 6.0, EPSILON, "Last element of scaled vector should be 6.0");

    // Test linear independence
    double result = linearIndependence(v1, v2);
    ASSERT_DOUBLE_EQ(result, 0, EPSILON, "v1 and v2 should be linearly independent");

    double arr_dependent[] = {1.0, 2.0, 3.0};
    vector v_dependent = forTestVector(arr_dependent, ROWVECTOR, 3);
    result = linearIndependence(v1, v_dependent);
    ASSERT_DOUBLE_EQ(result, 2.0, EPSILON, "v1 and v_dependent should be linearly dependent with factor 2");

    // Test printing (this will just call the function, actual output needs manual verification)
    printf("Printing row vector v1:\n");
    printVectors(v1, ROWVECTOR);
    printf("Printing column vector v2:\n");
    printVectors(v2, COLUMNVECTOR);

    // Clean up
    freeDataVector(v1);
    freeDataVector(v2);
    freeDataVector(v_dependent);
    freeDataVector(sum_compatible);
//    freeDataVector(scaled1);

    printf("Vector tests completed.\n");
    //test complex numbers
}
void testComplexNumbers(){
    complexNumber num1 = createNum(4,2);
    complexNumber num2 = createNum(5,1);
    complexNumber num3 = createNum(4,-2);
    complexNumber num4 = createNum(1,0);
    complexNumber num5 = createNum(0,0);
    complexNumber num6 = createNum(0,1);
    complexNumber num7 = createNum(0,-1);
    complexNumber num8 = createNum(-1,0);
    complexNumber num9 = createNum(5,-1);

    printNum(num1);
    printNum(num2);
    printNum(num3);
    printNum(num4);
    printNum(num5);
    printNum(num6);
    printNum(num7);
    printNum(num7);
    printNum(num8);
    printNum(num9);
    complexNumber a1 = createNum(3, 4);
    complexNumber a2 = createNum(1, 2);
    complexNumber sum = addComplexNumber(a1, a2);
    ASSERT_DOUBLE_EQ(sum.real, 4, EPSILON, "Real part of (3+4i) + (1+2i) should be 4");
    ASSERT_DOUBLE_EQ(sum.imaginary, 6, EPSILON, "Imaginary part of (3+4i) + (1+2i) should be 6");

    // Test addition with zero
    complexNumber a3 = createNum(0, 0);
    sum = addComplexNumber(a1, a3);
    ASSERT_DOUBLE_EQ(sum.real, 3, EPSILON, "Real part of (3+4i) + 0 should be 3");
    ASSERT_DOUBLE_EQ(sum.imaginary, 4, EPSILON, "Imaginary part of (3+4i) + 0 should be 4");

    // Test addition with negative numbers
    complexNumber a4 = createNum(-2, -3);
    sum = addComplexNumber(a1, a4);
    ASSERT_DOUBLE_EQ(sum.real, 1, EPSILON, "Real part of (3+4i) + (-2-3i) should be 1");
    ASSERT_DOUBLE_EQ(sum.imaginary, 1, EPSILON, "Imaginary part of (3+4i) + (-2-3i) should be 1");

    // Test subtraction
    complexNumber s1 = createNum(5, 6);
    complexNumber s2 = createNum(2, 1);
    complexNumber diff = subtractComplexNumber(s1, s2);
    ASSERT_DOUBLE_EQ(diff.real, 3, EPSILON, "Real part of (5+6i) - (2+i) should be 3");
    ASSERT_DOUBLE_EQ(diff.imaginary, 5, EPSILON, "Imaginary part of (5+6i) - (2+i) should be 5");

    // Test subtraction with zero
    complexNumber s3 = createNum(0, 0);
    diff = subtractComplexNumber(s1, s3);
    ASSERT_DOUBLE_EQ(diff.real, 5, EPSILON, "Real part of (5+6i) - 0 should be 5");
    ASSERT_DOUBLE_EQ(diff.imaginary, 6, EPSILON, "Imaginary part of (5+6i) - 0 should be 6");

    // Test subtraction with negative numbers
    complexNumber s4 = createNum(-3, -4);
    diff = subtractComplexNumber(s1, s4);
    ASSERT_DOUBLE_EQ(diff.real, 8, EPSILON, "Real part of (5+6i) - (-3-4i) should be 8");
    ASSERT_DOUBLE_EQ(diff.imaginary, 10, EPSILON, "Imaginary part of (5+6i) - (-3-4i) should be 10");

    // Test addition that results in zero
    complexNumber a5 = createNum(1, 1);
    complexNumber a6 = createNum(-1, -1);
    sum = addComplexNumber(a5, a6);
    ASSERT_DOUBLE_EQ(sum.real, 0, EPSILON, "Real part of (1+i) + (-1-i) should be 0");
    ASSERT_DOUBLE_EQ(sum.imaginary, 0, EPSILON, "Imaginary part of (1+i) + (-1-i) should be 0");

    // Test subtraction that results in zero
    complexNumber s5 = createNum(2, 3);
    complexNumber s6 = createNum(2, 3);
    diff = subtractComplexNumber(s5, s6);
    ASSERT_DOUBLE_EQ(diff.real, 0, EPSILON, "Real part of (2+3i) - (2+3i) should be 0");
    ASSERT_DOUBLE_EQ(diff.imaginary, 0, EPSILON, "Imaginary part of (2+3i) - (2+3i) should be 0");

    // Test addition with large numbers
    complexNumber a7 = createNum(1e15, 1e15);
    complexNumber a8 = createNum(1, 1);
    sum = addComplexNumber(a7, a8);
    ASSERT_DOUBLE_EQ(sum.real, 1e15 + 1, EPSILON, "Real part of (1e15+1e15i) + (1+i) should be 1e15 + 1");
    ASSERT_DOUBLE_EQ(sum.imaginary, 1e15 + 1, EPSILON, "Imaginary part of (1e15+1e15i) + (1+i) should be 1e15 + 1");

    // Test subtraction with large numbers
    complexNumber s7 = createNum(1e15, 1e15);
    complexNumber s8 = createNum(1, 1);
    diff = subtractComplexNumber(s7, s8);
    ASSERT_DOUBLE_EQ(diff.real, 1e15 - 1, EPSILON, "Real part of (1e15+1e15i) - (1+i) should be 1e15 - 1");
    ASSERT_DOUBLE_EQ(diff.imaginary, 1e15 - 1, EPSILON, "Imaginary part of (1e15+1e15i) - (1+i) should be 1e15 - 1");
    complexNumber c1 = createNum(3, 4);
    complexNumber conj = conjugate(c1);
    ASSERT_DOUBLE_EQ(conj.real, 3, EPSILON, "Real part of conjugate(3+4i) should be 3");
    ASSERT_DOUBLE_EQ(conj.imaginary, -4, EPSILON, "Imaginary part of conjugate(3+4i) should be -4");

    // Test complex multiplication
    complexNumber m1 = createNum(1, 2);
    complexNumber m2 = createNum(3, 4);
    complexNumber product = complexMultiplication(m1, m2);
    ASSERT_DOUBLE_EQ(product.real, -5, EPSILON, "Real part of (1+2i) * (3+4i) should be -5");
    ASSERT_DOUBLE_EQ(product.imaginary, 10, EPSILON, "Imaginary part of (1+2i) * (3+4i) should be 10");

    // Test complex multiplication with zero
    complexNumber m3 = createNum(0, 0);
    product = complexMultiplication(m1, m3);
    ASSERT_DOUBLE_EQ(product.real, 0, EPSILON, "Real part of (1+2i) * 0 should be 0");
    ASSERT_DOUBLE_EQ(product.imaginary, 0, EPSILON, "Imaginary part of (1+2i) * 0 should be 0");

    // Test complex multiplication with i
    complexNumber i = createNum(0, 1);
    product = complexMultiplication(m1, i);
    ASSERT_DOUBLE_EQ(product.real, -2, EPSILON, "Real part of (1+2i) * i should be -2");
    ASSERT_DOUBLE_EQ(product.imaginary, 1, EPSILON, "Imaginary part of (1+2i) * i should be 1");

    // Basic division test
    complexNumber d1 = createNum(1, 2);
    complexNumber d2 = createNum(3, 4);
    complexNumber quotient = divideComplexNumbers(d1, d2);
    ASSERT_DOUBLE_EQ(quotient.real, 0.44, 0.01, "Real part of (1+2i) / (3+4i) should be approximately 0.44");
    ASSERT_DOUBLE_EQ(quotient.imaginary, 0.08, 0.01, "Imaginary part of (1+2i) / (3+4i) should be approximately 0.08");

    // Division by 1
    complexNumber one = createNum(1, 0);
    quotient = divideComplexNumbers(d1, one);
    ASSERT_DOUBLE_EQ(quotient.real, 1, EPSILON, "Real part of (1+2i) / 1 should be 1");
    ASSERT_DOUBLE_EQ(quotient.imaginary, 2, EPSILON, "Imaginary part of (1+2i) / 1 should be 2");

    // Division by i
    quotient = divideComplexNumbers(d1, i);
    ASSERT_DOUBLE_EQ(quotient.real, 2, EPSILON, "Real part of (1+2i) / i should be 2");
    ASSERT_DOUBLE_EQ(quotient.imaginary, -1, EPSILON, "Imaginary part of (1+2i) / i should be -1");

    // Division of a real number by a complex number
    complexNumber real = createNum(5, 0);
    quotient = divideComplexNumbers(real, d2);
    ASSERT_DOUBLE_EQ(quotient.real, 0.6, 0.01, "Real part of 5 / (3+4i) should be approximately 0.6");
    ASSERT_DOUBLE_EQ(quotient.imaginary, -0.8, 0.01, "Imaginary part of 5 / (3+4i) should be approximately -0.8");

    // Division resulting in a real number
    complexNumber c = createNum(3, 4);
    complexNumber d = createNum(3, -4);
    quotient = divideComplexNumbers(c, d);
    ASSERT_DOUBLE_EQ(quotient.real, -7.0/25, EPSILON, "Real part of (3+4i) / (3-4i) should be -7/25");
    ASSERT_DOUBLE_EQ(quotient.imaginary, 24.0/25, EPSILON, "Imaginary part of (3+4i) / (3-4i) should be 24/25");

    // Division by a small number (potential for large results)
    complexNumber small = createNum(0.1, 0.1);
    quotient = divideComplexNumbers(one, small);
    ASSERT_DOUBLE_EQ(quotient.real, 5, 0.01, "Real part of 1 / (0.1+0.1i) should be approximately 5");
    ASSERT_DOUBLE_EQ(quotient.imaginary, -5, 0.01, "Imaginary part of 1 / (0.1+0.1i) should be approximately -5");

    // Division of zero by a complex number
    complexNumber zero = createNum(0, 0);
    quotient = divideComplexNumbers(zero, d2);
    ASSERT_DOUBLE_EQ(quotient.real, 0, EPSILON, "Real part of 0 / (3+4i) should be 0");
    ASSERT_DOUBLE_EQ(quotient.imaginary, 0, EPSILON, "Imaginary part of 0 / (3+4i) should be 0");

    // Division by zero (this should be handled in your implementation)
    quotient = divideComplexNumbers(d1, zero);
    // You might want to handle division by zero in your function. For now, let's check if it doesn't crash
    printf("Division by zero test completed.\n");

    // Test conjugateMultiplication
    double conjMult = conjugateMultiplication(createNum(3, 4));
    ASSERT_DOUBLE_EQ(conjMult, 25, EPSILON, "Conjugate multiplication of 3+4i should be 25");

    printf("Complex number tests completed.\n");




}
void test_geometry() {
    // Test point creation
    point p1 = createPoint(0, 0);
    point p2 = createPoint(3, 3);  // Corrected to make a proper square diagonal
    ASSERT_DOUBLE_EQ(p1.x, 0, EPSILON, "p1.x should be 0");
    ASSERT_DOUBLE_EQ(p1.y, 0, EPSILON, "p1.y should be 0");
    ASSERT_DOUBLE_EQ(p2.x, 3, EPSILON, "p2.x should be 3");
    ASSERT_DOUBLE_EQ(p2.y, 3, EPSILON, "p2.y should be 3");

    // Test distance calculation (diagonal of the square)
    double diagonal = distance(p1, p2);
    ASSERT_DOUBLE_EQ(diagonal, 3 * squareRoot(2), EPSILON, "Diagonal between (0,0) and (3,3) should be 3√2");

    // Test square side calculation
    double side = squareSide(p1, p2);
    ASSERT_DOUBLE_EQ(side, 3, EPSILON, "Square side for diagonal points (0,0) and (3,3) should be 3");

    // Test square area calculation
    double area = squareArea(p1, p2);
    ASSERT_DOUBLE_EQ(area, 9, EPSILON, "Square area for diagonal points (0,0) and (3,3) should be 9");

    // Test square perimeter calculation
    double perimeter = squarePerimeter(p1, p2);
    ASSERT_DOUBLE_EQ(perimeter, 12, EPSILON, "Square perimeter for diagonal points (0,0) and (3,3) should be 12");

    // Test square creation
    squareShape square = createSquare(p1, p2);
    ASSERT_DOUBLE_EQ(square.side, 3, EPSILON, "Created square side should be 3");
    ASSERT_DOUBLE_EQ(square.area, 9, EPSILON, "Created square area should be 9");
    ASSERT_DOUBLE_EQ(square.perimeter, 12, EPSILON, "Created square perimeter should be 12");

    // Test with negative coordinates
    point p3 = createPoint(-2, -2);
    point p4 = createPoint(2, 2);
    squareShape square2 = createSquare(p3, p4);
    ASSERT_DOUBLE_EQ(square2.side, 4, EPSILON, "Square2 side should be 4");
    ASSERT_DOUBLE_EQ(square2.area, 16, EPSILON, "Square2 area should be 16");
    ASSERT_DOUBLE_EQ(square2.perimeter, 16, EPSILON, "Square2 perimeter should be 16");

    // Test with points in different order
    squareShape square3 = createSquare(p2, p1);
    ASSERT_DOUBLE_EQ(square3.side, 3, EPSILON, "Square3 side should be 3");
    ASSERT_DOUBLE_EQ(square3.area, 9, EPSILON, "Square3 area should be 9");
    ASSERT_DOUBLE_EQ(square3.perimeter, 12, EPSILON, "Square3 perimeter should be 12");

    // Test with diagonal in different quadrant
    point p5 = createPoint(1, 1);
    point p6 = createPoint(4, 4);
    squareShape square4 = createSquare(p5, p6);
    ASSERT_DOUBLE_EQ(square4.side, 3, EPSILON, "Square4 side should be 3");
    ASSERT_DOUBLE_EQ(square4.area, 9, EPSILON, "Square4 area should be 9");
    ASSERT_DOUBLE_EQ(square4.perimeter, 12, EPSILON, "Square4 perimeter should be 12");

    // Test with very small square
    point p7 = createPoint(0, 0);
    point p8 = createPoint(0.1, 0.1);
    squareShape square5 = createSquare(p7, p8);
    ASSERT_DOUBLE_EQ(square5.side, 0.1, 1e-6, "Square5 side should be 0.1");
    ASSERT_DOUBLE_EQ(square5.area, 0.01, EPSILON, "Square5 area should be 0.01");
    ASSERT_DOUBLE_EQ(square5.perimeter, 0.4, 1e-6, "Square5 perimeter should be 0.4");

    printf("Geometry tests completed.\n");
}
int main() {
    test_basic_operations();
    test_trigonometric_functions();
    test_linear_algebra();
    testComplexNumbers();
    test_geometry();

    printf("Tests passed: %d\n", passed_tests);
    printf("Tests failed: %d\n", failed_tests);

    return failed_tests;
}