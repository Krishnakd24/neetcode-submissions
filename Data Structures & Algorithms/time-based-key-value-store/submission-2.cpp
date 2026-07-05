class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end()) return "";

        int l=0;
        int r=store[key].size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(store[key][mid].first<=timestamp) l=mid+1;
            else r=mid-1;
        }
        if(r==-1) return "";
        return store[key][r].second;


    }
};
