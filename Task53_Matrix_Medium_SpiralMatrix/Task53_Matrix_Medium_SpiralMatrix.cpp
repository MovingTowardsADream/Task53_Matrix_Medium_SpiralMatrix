#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size() - 1, m = matrix[0].size() - 1;
        int index = std::min(n, m) / 2;
        std::vector<int> result;
        for (int i = 0;i <= index;i++) {
            for (int j = i;j <= m - i;j++) {
                result.push_back(matrix[i][j]);
            }
            for (int j = i + 1;j <= n - i - 1;j++) {
                result.push_back(matrix[j][m - i]);
            }
            if (n - i == i) {
                break;
            }
            for (int j = m - i;j >= i;j--) {
                result.push_back(matrix[n - i][j]);
            }
            if (m - i == i) {
                break;
            }
            for (int j = n - i - 1;j >= i + 1;j--) {
                result.push_back(matrix[j][i]);
            }
        }
        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = { {7},{9},{6} };
    for (int& i : Solution::spiralOrder(matrix)) {
        std::cout << i << " ";
    }
}
