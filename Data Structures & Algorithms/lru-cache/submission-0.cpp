struct Node {
    Node* next=nullptr;
    Node* prev=nullptr;
    int k;
    int v;
    Node() {}
    Node(int key, int val) : k(key), v(val){}
};

class LRUCache {
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void removeNode(Node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void addNode(Node* n, Node* prev){
        Node* next = prev->next;
        prev->next = n;
        n->next = next;
        next->prev = n;
        n->prev = prev;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)==0)
            return -1;

        Node* n = mp[key];
        removeNode(n);
        addNode(n, head);
        return n->v;
    }
    
    void put(int key, int value) {
        Node* n;
        if(mp.count(key)){
            n = mp[key];
            n->v = value;
            removeNode(n);
        } else {
            n = new Node(key, value);
            if(mp.size()==cap){
                Node* to_remove = tail->prev;
                removeNode(to_remove);
                mp.erase(to_remove->k);
                delete to_remove;
            }
        }
        mp[key] = n;
        addNode(n, head);
    }
};
