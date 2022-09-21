class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if( max_heap.empty() && min_heap.empty() )
        {
            max_heap.push( num );
        }
        else
        {
            if( max_heap.top() < num )
                min_heap.push( num );
            else
                max_heap.push( num );
        }
        
        int n = max_heap.size();
        int m = min_heap.size();
        
        if( abs( n - m ) > 1 )
        {
            if( n > m )
            {
                int val = max_heap.top();
                max_heap.pop();
                min_heap.push( val );
            }
            else
            {
                int val = min_heap.top();
                min_heap.pop();
                max_heap.push( val );
            }
        }
    }
    
    double findMedian() 
    {
        int n = max_heap.size();
        int m = min_heap.size();
        double ans;
        
        if( ((n+m)%2 == 0 ) )
        {
            ans = ( (double)max_heap.top() + (double)min_heap.top() ) /2;             
        }
                
        if( n > m )
            ans = max_heap.top();
        else if( n < m )
        {
            ans = (double)min_heap.top();
        }
        return ans ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */