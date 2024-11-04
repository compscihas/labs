class Node {
 public:
    char letter;
    Node* next;
    Node(char letter) : 
        letter(letter), next(nullptr) {}
};
 
 
class LinkedList {
 private:
    Node* head;
 public:
    // assume other functions are there needed to compile,
    //  but you will not need to use any of them for your code
 
    void merge(char afterLetter, LinkedList& toBeMergedList){
       if(toBeMergedList.head == nullptr){
        return;
       }
       Node* start = head;
       Node* prev = nullptr;
       while(head != nullptr){
        if(head -> letter == afterLetter){
            break;
        }
        prev = head;
        head = head->next;
       }
       if(head == nullptr){
        head = prev;
       }
       Node* after = head->next;
       prev = toBeMergedList.head;
       while(toBeMergedList.head != nullptr){
            Node* temp =new Node(toBeMergedList.head->letter);
            head->next = temp;
            head=head -> next;
            toBeMergedList.head = toBeMergedList.head -> next;
       }
        head->next = after;
        head = start;

        Node* prev2 = nullptr;
        while(prev != nullptr){
            prev2 = prev;
            prev = prev->next;
            delete prev2;
        }

    }
/* 
   - merge the toBeMergedList 
    - after the first instance of afterLetter in the list
    - to the end of the list if afterLetter is not on the list 
 - toBeMergedList should become an empty list
 - Do not use any other functions that might exist in 
      the linked list. 
 - You cannot use any arrays, vectors, etc.
*/
};