class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap_h;
    priority_queue<int> max_heap_l;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap_h.push(num);
        int minh = min_heap_h.top();
        min_heap_h.pop();
        max_heap_l.push(minh);
        if(min_heap_h.size() < max_heap_l.size()){
            int maxl = max_heap_l.top();
            max_heap_l.pop();
            min_heap_h.push(maxl);
        }
    }
    
    double findMedian() {
        if(min_heap_h.size() == max_heap_l.size()){
            return ((double)min_heap_h.top() + max_heap_l.top()) / 2;
        }
        return min_heap_h.top();
    }
};
