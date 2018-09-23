#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){ 
    /*your code here*/
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
    /*your code here*/
    Node* temp = new Node(ndata);
    temp->prev = tail_->prev;
    temp->next = tail_;
    tail_->prev->next = temp;
    tail_->prev = temp;
    length_++;
}

/**
 * Modifies the Chain by moving a contiguous subset of len Nodes
 * dist nodes toward the end of the chain beginning from startPos
 * (maintaining the sentinel at the end). Their order is
 * not changed in the move. You may assume that the startPos and
 * len parameters are kind: startPos + len -1 <= length. If there
 * are not enough nodes to shift by dist, just shift as many as
 * possible.
 */
void Chain::moveBack(int startPos, int len, int dist){
    // Walks from head_, grabbing the first node to move 
    Node* startBack = walk(head_, startPos);
    // Walks from first node to be moved to last node to be moved
    Node* endBack = walk(startBack, len - 1);

    Node* startFront = endBack->next;
    Node* endFront = walk(startFront, dist - 1);

    startFront->prev = startBack->prev;
    endBack->next = endFront->next;
    startBack->prev->next = startFront;
    endFront->next->prev = endBack;
    
    endFront->next = startBack;
    startBack->prev = endFront;
}

/**
 * Rolls the current Chain by k nodes: removes the last
 * k nodes from the Chain and attaches them, in order, at
 * the start of the chain (maintaining the sentinel at the front).
 */
void Chain::roll(int k){
    /*your code here*/
    Node* startNode = walk(head_, length_ - k + 1);
    Node* endNode = tail_->prev;

    Node* last = walk(head_, length_ - k);
    Node* front = head_->next;

    endNode->next = front;
    tail_->prev = last;

    front->prev = endNode;
    endNode->next = front;

    head_->next = startNode;
    startNode->prev = head_; 
}

/**
 * Modifies the current chain by reversing the subchain
 * between pos1 and pos2, inclusive. The positions are
 * 1-based. You may assume that pos1 and pos2 are valid
 * locations in the Chain, and that pos2 >= pos1.
 */
void Chain::reverseSub(int pos1, int pos2){
    /*your code here */
        
    Node* beforeSub = walk(head_, pos1 - 1);
    Node* afterSub = walk(head_, pos2 + 1);

    Node* temp = NULL;
    Node* current = walk(head_, pos1);
    for (int i = pos1; i <=pos2; i++) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    }

    beforeSub->next->next = afterSub;
    afterSub->prev->prev = beforeSub;

    temp = beforeSub->next;
    beforeSub->next = afterSub->prev;
    afterSub->prev = temp;
}



/*
* Modifies both the current and input chains by removing
* nodes from other, and interleaving them between the Nodes
* from the current Chain. The nodes from the other Chain
* should occupy the even locations in the result. length
* of the resulting chain should be the sums of the lengths
* of current and the other. The other chain should have only
* two sentinels and no data nodes at the end of the operation.
* the weave fails and the original
* chains should be unchanged if block sizes are different.
* in that case, the result of the function should be:
* cout << "Block sizes differ." << endl;
*/
void Chain::weave(Chain & other) { // leaves other empty.
    /*your code here */
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */

void Chain::clear() {
    /*your code here*/
    delete head_;
    delete tail_;
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {
    /*your code here*/
    length_ = other.length_;
    height_ = other.height_;
    width_ = other.width_;

    head_ = new Node(*(other.head_));
    tail_ = new Node(*(other.tail_));
}

