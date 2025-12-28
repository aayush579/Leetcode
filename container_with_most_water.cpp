class Solution {
public:
    int maxArea(vector<int>& height) {
        int min_h = height[0];
        int max_h = height[height.size()-1];
        int min_idx = 0;
        int max_idx =  height.size()-1;
        if(max_h < min_h){
            min_h = max_h;
            min_idx = max_idx;
            max_h = height[0];
            max_idx = 0;
        }
        int w = height.size()- 1;
        int max_area = min_h*w;
        while(w > 0){
            int idx = min_idx;
            while(height[idx] <= min_h){
                if(min_idx < max_idx)
                    idx++;
                else
                    idx--;
                w--;
                if(w < 1)
                    break;
            }
            if(height[idx] > max_h){
                min_h = max_h;
                min_idx = max_idx;
                max_idx = idx;
                max_h = height[idx];
            }
            else{
                min_idx = idx ;
                min_h = height[idx];

            }
            max_area = max(max_area, w*min_h);
        }
        return max_area;
    }
};
