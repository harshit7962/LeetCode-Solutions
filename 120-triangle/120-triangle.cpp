class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
	// we are starting from level 1 till the bottom-most level. 
	// & each time we determine the best path to arrive at current cell
	    for(int level = 1; level < size(triangle); level++) 
        for(int i = 0; i <= level; i++)  
        // for the current level 
        // we can either come from previous level and same index
        // or the previous level and index-1
        triangle[level][i] += min(triangle[level - 1][min(i, (int)size(triangle[level - 1]) - 1)], triangle[level - 1][max(i - 1, 0)]); 
	    // finally return the last element of the bottom level
    	return *min_element(begin(triangle.back()), end(triangle.back())); 
   }
};