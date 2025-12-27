class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       /* //Non Optimal solution
        vector<int>result;
        for(auto it1 = nums.begin(); it1 != nums.end(); ++it1){
            auto it2 = find(it1+1, nums.end(), target - *it1);
            if(it2 != nums.end()){
                result.push_back(it1 - nums.begin());
                result.push_back(it2 - nums.begin());
                break;
            }
        }*/
        unordered_map<int, int> _map;  //Optimal Aolution using HashMap
        for(int i = 0; i< nums.size(); ++i){
            int num = nums[i];
            int comp = target - num ;
            auto it = _map.find(comp);
            if (it != _map.end()){
                return {it ->second, i};
            }
            _map[num] = i;
        }
        return {};
    }

};
