class Node{
public:
    int val;
    Node* next;
    Node(int v, Node* n = NULL) : val(v), next(n) {}
};
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* curr = head->next;
        int i = 0;
        while(curr != NULL){
            if(i == index){
                return curr->val;
            }
            i ++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val, head->next);
        head->next = newNode;
        if(newNode->next == NULL){
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    bool remove(int index) {
        int i = 0;
        Node* curr = head;
        while(i < index && curr != NULL){
            i++;
            curr = curr->next;
        }
        if(curr != NULL && curr->next != NULL){
            if(curr->next == tail){
                tail = curr;
            }
            Node* toDel = curr->next;
            curr->next = curr->next->next;
            delete toDel;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node* curr = head->next;
        while(curr != NULL){
            ans.push_back(curr->val);
            curr = curr->next;
        }
        return ans;
    }
};
