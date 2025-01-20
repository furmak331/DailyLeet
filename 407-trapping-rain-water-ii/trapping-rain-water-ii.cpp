class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        
        // Custom comparator for min-heap based on height
        auto compareHeight = [](const array<int, 3>& a, const array<int, 3>& b) {
            return a[2] > b[2];  // Sort by height (third element)
        };
        
        // Min-heap to store cells {row, col, height}
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(compareHeight)> 
            pq(compareHeight);
            
        // Track visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Add border cells to priority queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows-1 || j == 0 || j == cols-1) {
                    pq.push({i, j, heightMap[i][j]});
                    visited[i][j] = true;
                }
            }
        }
        
        // Directions for neighboring cells
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        int totalWater = 0;
        int maxBoundaryHeight = 0;
        
        // Process cells from lowest to highest
        while (!pq.empty()) {
            auto [row, col, height] = pq.top();
            pq.pop();
            
            // Update maximum boundary height
            maxBoundaryHeight = max(maxBoundaryHeight, height);
            
            // Check all neighboring cells
            for (const auto& [dx, dy] : directions) {
                int newRow = row + dx;
                int newCol = col + dy;
                
                // Skip if out of bounds or already visited
                if (newRow < 0 || newRow >= rows || 
                    newCol < 0 || newCol >= cols || 
                    visited[newRow][newCol]) {
                    continue;
                }
                
                // Calculate water trapped at current cell
                if (heightMap[newRow][newCol] < maxBoundaryHeight) {
                    totalWater += maxBoundaryHeight - heightMap[newRow][newCol];
                }
                
                // Add cell to priority queue
                pq.push({newRow, newCol, heightMap[newRow][newCol]});
                visited[newRow][newCol] = true;
            }
        }
        
        return totalWater;
    }
};