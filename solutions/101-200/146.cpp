class LinkNode {
  public:
    int val;
    int key;
    LinkNode *next;
    LinkNode *prev;

    LinkNode(int key, int val)
        : key(key), val(val), next(nullptr), prev(nullptr){};
};

class LRUCache {
  private:
    std::unordered_map<int, LinkNode *> map;
    int capacity;
    int count;
    LinkNode *root;

  public:
    LRUCache(int capacity) : capacity(capacity), count(0) {
        this->map = std::unordered_map<int, LinkNode *>();
        this->root = new LinkNode(-1, -1);
        this->root->next = this->root;
        this->root->prev = this->root;
    }

    int get(int key) {
        if (this->map.find(key) != this->map.end()) {
            LinkNode *target = this->map[key];
            // std::cout << target->key << std::endl;
            // Unlink
            target->next->prev = target->prev;
            target->prev->next = target->next;
            // Link to first use
            target->next = this->root->next;
            this->root->next->prev = target;
            this->root->next = target;
            target->prev = this->root;
            // answer
            return target->val;
        }
        return -1;
    }

    void put(int key, int value) {
        LinkNode *target;
        if (this->map.find(key) != this->map.end()) {
            target = this->map[key];
            target->val = value;
            target->next->prev = target->prev;
            target->prev->next = target->next;
        } else {
            if (this->count >= this->capacity) {
                // unlink
                LinkNode *victim = this->root->prev;
                victim->prev->next = this->root;
                this->root->prev = victim->prev;
                this->map.erase(victim->key);
                // std::cout << "delete" << victim->key << std::endl;
                delete victim;
                this->count--;
            }
            target = new LinkNode(key, value);
            this->map[key] = target;
            this->count++;
        }
        // Link
        target->next = this->root->next;
        this->root->next->prev = target;
        this->root->next = target;
        target->prev = this->root;
    }
};