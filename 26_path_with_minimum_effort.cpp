/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/




// Binary search and DFS solution - Optimization required
class Solution {
private:
    set<pair<int, int>> visited;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void canReach(vector<vector<int>>& h, int effort, int i, int j, int r, int c, bool& reachable) {
        if (i == r-1 and j == c-1) {
            reachable = true;
            return;
        }
        visited.insert({i, j});
        for (pair<int, int>& dir : dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            if (ni >= 0 and ni < r and nj >= 0 and nj < c and visited.find({ni, nj}) == visited.end() and abs(h[ni][nj]-h[i][j]) <= effort) {
                canReach(h, effort, ni, nj, r, c, reachable);
            }
        }
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        int left = 0, right = 1e6;
        while (left < right) {
            int mid = left + (right-left) / 2;
            bool reachable = false;
            visited.clear();
            canReach(heights, mid, 0, 0, r, c, reachable);
            if (reachable)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

