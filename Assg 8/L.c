#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    float x, y;
}Point;

int cmpX(const void* a, const void* b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int cmpY(const void* a, const void* b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
}


float bruteForce(Point P[], int n)
{
    float mininum = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < mininum)
                mininum = dist(P[i], P[j]);
    return mininum;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float stripClosest(Point strip[], int size, float d) 
{ 
    float min = d;  // Initialize the minimum distance as d
    qsort(strip, size, sizeof(Point), cmpY);

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}

float closestUtil(Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n/2;
    Point midPoint = P[mid];

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);
    // Find the smaller of two distances
    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j++] = P[i];

    return min(d, stripClosest(strip, j, d)); 
} 

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), cmpX);
    return closestUtil(P, n);
}

int main()
{
    int n; scanf("%d", &n);
    Point P[n];
    for(int i=0; i<n; i++)
    {
        float a, b;
        scanf("%f, %f", &a, &b);
        P[i].x = a;
        P[i].y = b;
    }
    printf("%f\n ", closest(P, n));
    return 0;
}