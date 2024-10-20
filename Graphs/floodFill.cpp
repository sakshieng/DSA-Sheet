// https://www.naukri.com/code360/problems/flood-fill-algorithm_1089687
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


void flood(int i, int j, vector<vector<int>> &image, int oldColor, int newColor, int n, int m)
{

    if (i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor)
        return;

    image[i][j] = newColor;

    flood(i + 1, j, image, oldColor, newColor, n, m);

    flood(i - 1, j, image, oldColor, newColor, n, m);

    flood(i, j + 1, image, oldColor, newColor, n, m);

    flood(i, j - 1, image, oldColor, newColor, n, m);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor = image[x][y];

    if (oldColor == newColor)
        return image;

    int n = image.size(), m = image[0].size();

    // recursion call
    flood(x, y, image, oldColor, newColor, n, m);

    return image;
}

/*
    time complexity: O(M * N)
    space complexity: O(M * N)
*/