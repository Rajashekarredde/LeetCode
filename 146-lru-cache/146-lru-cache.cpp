class LRUCache {
public:
    class node
    {
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node( int _key, int _val )
        {
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1, -1 );
    node *tail = new node(-1, -1 );
    
    unordered_map< int, node* > mp;
    int cap;
    LRUCache(int capacity) 
    {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    void addNode( node *temp )
    {
        node *store = head->next;
        head->next = temp;
        temp->prev = head;
        store->prev = temp;
        temp->next =  store;
    }
    
    void deleteNode( node *temp )
    {
        node *delPrev = temp->prev;
        node *delnext = temp->next;
        delPrev->next = delnext;
        delnext->prev = delPrev;
    }
    
    int get(int key_) 
    {
        if( mp.find(key_) != mp.end() )
        {
            node *temp = mp[key_];
            int ans = temp->val;
            mp.erase(key_);
            deleteNode( temp );
            addNode( temp );
            mp[key_] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key_, int value) 
    {
        if( mp.find( key_) != mp.end() )
        {
            node *temp = mp[key_];
            mp.erase(key_);
            deleteNode( temp );
        }
        if( mp.size() == cap )
        {
            mp.erase( tail->prev->key );
            deleteNode( tail->prev );
        }
        addNode( new node( key_, value ) );
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */