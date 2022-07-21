struct Node {
    Node* child[26];
    bool end;
    
    
    bool containsKey(char c) {
        return (child[c-'a']!=NULL);
    }
    
    void putKey(char c, Node *root) {
        child[c-'a'] = root;
    }
    
    Node* get(char c) {
        return child[c-'a'];
    }
    
    void setEnd() {
        end = true;
    }
    
    bool isEnd() {
        return end;
    }
};

class Trie {
private:
    Node *root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        int n = word.size();
        
        for(int i=0;i<n;i++) {
            if(!node->containsKey(word[i])) node->putKey(word[i], new Node());
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        int n = word.size();
        
        for(int i=0;i<n;i++) {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        int n = prefix.size();
        
        for(int i=0;i<n;i++) {
            if(!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */