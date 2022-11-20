#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <chrono>

using namespace std;
void print(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
}
// function that finds the min.
int min(int L, int R)
{
    // base case
    if (L == R)
        return L;
    // recursive call
    if (L > R)
        return min(L - 1, R);
    // last resort case
    else
        return L;
}
// function that divides the array
int traverse(int A[], int L, int R)
{
    print(A, 6);
    cout << endl;
    // base case
    if (L == R)
        return (A[L]);

    int M = (L + R) / 2;
    cout << "M is " << M << "| L is " << L<< "| R is " << R<< endl;
    // recursive tail call
    return min(traverse(A, L, M), traverse(A, M + 1, R));
}
// populates array with N random numbers
int populate(int A[], int N)
{
    // allows for different random numbers every execution
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        A[i] = (rand() % 1000) + 1;
        cout << A[i] << " ";
    }
    return *A;
}

int main()
{
    //const int N = 100; // number of randomly generated numbers
    //int A[N];
    //populate(A, N); // function populates array with random numbers
    int A[] = { 4,3,7,0,24,77 };
    int N = sizeof(A) / sizeof(A[0]);

    int R = N - 1; // right most element
    int L = 0; // left most element
    
    cout << "min is " << traverse(A, L, R) << endl;
}
