#ifndef MATHLIBRARY_GEOMETRY_H
#define MATHLIBRARY_GEOMETRY_H
typedef struct point{
    double x;
    double y;
}point;
typedef struct line{
    point a;
    point b;
}line;
typedef struct squareShape{
    point a;
    point b;
    double area;
    double perimeter;
    double side;
}squareShape;
typedef struct circle{
    point a;
    double radios;
}circle;

point createPoint(double x, double y);
point getPoint();
squareShape createSquare(point p1, point p2);
double squareArea(point p1, point p2);
double squarePerimeter(point p1, point p2);
double distance(point p1, point p2);
double squareSide(point p1, point p2);
double calculateCircleArea(circle c);
double calculateCircleCircumference(circle c);
#endif //MATHLIBRARY_GEOMETRY_H
