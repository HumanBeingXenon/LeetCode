#include <algorithm>
#include <iostream>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);

int main(int argc, char const *argv[])
{
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}

//BL1(A, B) TR1(C, D) BL2(E, F) TR(G, H)
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int I = max(A, E), J = max(B, F);
    int K = min(C, G), L = min(D, H);

    int area_r1 = (C - A) * (D - B);
    int area_r2 = (G - E) * (H - F);
    int area_intersect = I < K && J < L ? (K - I) * (L - J) : 0;

    return area_r1 + (area_r2 - area_intersect);
}