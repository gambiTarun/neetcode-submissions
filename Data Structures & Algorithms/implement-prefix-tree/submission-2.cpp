class Node{
public:
    Node* next[26] = {nullptr};
    bool end=false;
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* n = root;
        for(char c: word){
            if(n->next[c - 'a'] == nullptr)
                n->next[c - 'a'] = new Node();
            n = n->next[c - 'a'];
        }
        n->end = true;
    }
    
    bool search(string word) {
        Node* n = root;
        for(char c: word){
            if(n->next[c-'a']==nullptr)
                return false;
            n = n->next[c - 'a'];
        }
        return n->end;
    }
    
    bool startsWith(string prefix) {
        Node* n = root;
        for(char c: prefix){
            if(n->next[c-'a']==nullptr)
                return false;
            n = n->next[c - 'a'];
        }
        return true;
    }
};
