struct ListNode{
    string url;
    ListNode *next;
    ListNode *prev;
    ListNode(string &page):url(page), next(nullptr), prev(nullptr){}
};
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        cur = head;        
    }
    
    void visit(string url) {
        ListNode *n = new ListNode(url);
        n->prev = cur;
        cur->next = n;
        cur = n;
    }
    
    string back(int steps) {
    
        for(auto i = 1; i <= steps && cur != head; ++i)
            cur = cur->prev;
        return cur->url;
    }
    
    string forward(int steps) {
        for(auto i = 1; i <= steps && cur->next != nullptr; ++i)
            cur = cur->next;
        return cur->url;
    }
private:
    ListNode *head;
    ListNode *cur;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */