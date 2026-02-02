class RandomizedSet {
private:
    vector<int> nums;                     
    unordered_map<int, int> idx;           
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (idx.find(val) != idx.end())
            return false;

        nums.push_back(val);
        idx[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (idx.find(val) == idx.end())
            return false;

        int index = idx[val];
        int lastVal = nums.back();

        // swap with last element
        nums[index] = lastVal;
        idx[lastVal] = index;

        nums.pop_back();
        idx.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};