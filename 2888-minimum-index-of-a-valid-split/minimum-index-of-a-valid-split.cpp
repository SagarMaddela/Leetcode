class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      std::unordered_map<int,int> umap;
      int max_occurance = 0, max_occured_element = -1;
      int nums_size = nums.size();

      for(int i = 0;i < nums_size;i++){
        if( umap.find(nums[i]) == umap.end() ){
            umap.insert({nums[i],1});
        }
        else {
            umap[nums[i]]++;
            if(umap[nums[i]] > max_occurance){
                max_occurance = umap[nums[i]];
                max_occured_element = nums[i];
            }
        }
      }

      std::cout << max_occured_element << " occured " << max_occurance << " times." << std::endl;

      int count = 0;
      for(int i = 0; i < nums_size;i++){
        if( nums[i] == max_occured_element ){
            count++;
            if( (count * 2 > (i+1)) && (((max_occurance - count) * 2) > (nums_size - i - 1)) ){
                return i;
            }
        }
      }
      return -1;
    }
};