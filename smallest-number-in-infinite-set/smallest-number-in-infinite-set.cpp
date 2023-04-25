class SmallestInfiniteSet {
public:
    set<int> s;
    int m;
    SmallestInfiniteSet() {
        s.insert(1);
        m = 1;
    }
    
    int popSmallest() {
        if (s.size() == 1)
        {
            m = *(s.begin())+1;
            s.insert(m);
        }
        int ret = *(s.begin());
        s.erase(s.begin());
        return ret;
    }
    
    void addBack(int num) {

        if (num<m){s.insert(num);}
    }
};