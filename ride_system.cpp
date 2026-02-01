class RideSharingSystem {

private:queue<int>drivers;
        queue<int>riders;
        unordered_set<int>waitingriders;
public:
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        waitingriders.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int>ans;

        while(!riders.empty() && !waitingriders.count(riders.front())){
            riders.pop();
        }

        if(riders.empty()||drivers.empty()) return{-1,-1};

        int driver = drivers.front();
        drivers.pop();
        int rider = riders.front();
        riders.pop();

        waitingriders.erase(rider);
        ans.push_back(driver);
        ans.push_back(rider);

        return ans;

    }
    
    void cancelRider(int riderId) {
        if(waitingriders.count(riderId)){
            waitingriders.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */