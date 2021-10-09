// 5.Optimum location of point to minimize total distance
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 1, b = -1, c = -3, N = 5, p = 0;
    float distance = FLT_MAX;
    int points[N][2] = {{-3, -2}, {-1, 0}, {-1, 2}, {1, 2}, {3, 4}};
    for (int i = 0; i < N; i++)
    {
        int x = points[i][0];
        int y = points[i][1];
        int top = abs(a * x + b * y + c);
        int below = sqrt(a * a + b * b);
        float distance1 = top / below;
        if (distance1 < distance)
        {
            distance = distance1;
            p = i;
        }
    }
    cout << "point {" << points[p][0] << " , " << points[p][1] << "} distance : " << distance << endl;
    return 0;
}