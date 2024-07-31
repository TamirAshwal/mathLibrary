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
    int arr4[4] = {1, 2, 3, 4};
    intMatrix m4 = forTest(arr4, 2, 2);
    int det = determinant(m4, 4);
    ASSERT(det == -2, "Determinant of 2x2 matrix should be -2");

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
}

int main() {
    test_basic_operations();
    test_trigonometric_functions();
    test_linear_algebra();

    printf("Tests passed: %d\n", passed_tests);
    printf("Tests failed: %d\n", failed_tests);

    return failed_tests;
}