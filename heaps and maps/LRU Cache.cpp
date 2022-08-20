// https://www.interviewbit.com/problems/lru-cache/

/*

Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
         
         */



map<int,pair<int,int>>mp;
set<pair<int,int>>st;
int lru,cap;
LRUCache::LRUCache(int capacity) {
    lru=0;
    cap=capacity;
    mp.clear();
    st.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)!=mp.end()){
        st.erase({mp[key].first,key});
        st.insert({++lru,key});
        mp[key].first=lru;
        return mp[key].second;
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    if(mp.find(key)!=mp.end()){
        st.erase({mp[key].first,key});
        st.insert({++lru,key});
        mp[key].first=lru;
        mp[key].second=value;
    }
    else{
        if(mp.size()==cap){
            int t=(*st.begin()).second;
            mp.erase(t);
            st.erase(st.begin());
        }
        mp[key]={++lru,value};
        st.insert({lru,key});
    }
}
