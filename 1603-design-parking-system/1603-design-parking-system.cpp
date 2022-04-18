class ParkingSystem {
public:
    vector<int> space;
    ParkingSystem(int big, int medium, int small) {
        space.push_back(big);
        space.push_back(medium);
        space.push_back(small);
    }
    
    bool addCar(int carType) {
        if(space[carType-1]==0) return false;
        space[carType-1]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */