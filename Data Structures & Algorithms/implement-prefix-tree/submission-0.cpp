class Node {
public:
    Node* next[26];
    bool end=false;
    Node() {
        for(int i=0;i<26;i++)
            next[i] = nullptr;
    }
};

class PrefixTree {
private:
    Node* root;
public:

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char c:word){
            if(node->next[c - 'a']==nullptr)
                node->next[c - 'a'] = new Node();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char c: word){
            if(node->next[c - 'a']==nullptr){
                return false;
            }
            node = node->next[c - 'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c: prefix){
            if(node->next[c - 'a']==nullptr){
                return false;
            }
            node = node->next[c - 'a'];
        }
        return true;
    }
};
