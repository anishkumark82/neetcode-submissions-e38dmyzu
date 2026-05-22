struct ListNode{
    string url;
    ListNode *prev;
    ListNode *next;
    ListNode():url(""), prev(nullptr), next(nullptr){};
    ListNode(string &u):url(u), prev(nullptr), next(nullptr){}; 
};

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        cur = head;
        tail = head;
    }
    
    void visit(string url) {
        ListNode *node = new ListNode(url);
           
        if(cur != tail)
        {
            tail = cur;
            // Clear all elements after the current node
            ListNode *temp = tail->next;
            while(temp)
            {
                ListNode *t2 = temp;
                temp = temp->next;
                delete t2;
            }
        }
        cur->next = node;
        node->prev = cur;
        cur = cur->next;
        tail = cur; 
    }
    
    string back(int steps) {
        for(auto i = 0; i < steps && cur->prev != nullptr; ++i)
            cur = cur->prev;
        return cur->url;
    }
    
    string forward(int steps) {
        for(auto i = 0; i < steps && cur->next != nullptr; ++i)
            cur = cur->next;
        return cur->url;
    }
    ListNode *head;
    ListNode *tail;
    ListNode *cur;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */