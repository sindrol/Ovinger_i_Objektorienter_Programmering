#pragma once

#include <memory>
#include <iostream>
#include <string>



namespace LinkedList {

template<typename T>
class Node {
private:
    const T value;    // The data held by the LinkedList
    std::unique_ptr<Node<T>> next; // unique_ptr to the next node
    Node<T>* prev;                 // raw (non-owning) ptr to the previous node
public:
    Node() : value(), next(nullptr), prev(nullptr) {}
    // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node

    Node(const T& value, std::unique_ptr<Node<T>> next, Node<T>* prev)
        : value(value)
        , next(std::move(next))
        , prev(prev)
    {}
    // We can use the default destructor, since unique_ptr takes care of deleting memory
    ~Node() = default;
    // return the value of the node
    T getValue() const { return value; }

    // return a raw (non-owning) pointer to the next node
    Node<T>* getNext() const { return next.get(); }
    // return a raw (non-owning) pointer to the previous node
    Node<T>* getPrev() const { return prev; }

    // write the value of the node to the ostream
    friend std::ostream& operator<<(std::ostream& os, const Node<T>& node){
        return os<<node.value;
    }

    template<typename S>
    friend class LinkedList;
};

template<typename S>
class LinkedList {
private:
    // ptr to the first node
    std::unique_ptr<Node<S>> head;
    // a raw pointer to the last node, the last node is always a dummy node
    // this is declared as a const ptr to a Node, so that tail never can
    // point anywhere else
    Node<S>* const tail;
public:
    //create the dummy node, and make tail point to it
    LinkedList()
        : head(std::make_unique<Node<S>>())
        , tail(head.get())
    {}
    ~LinkedList() = default;

    //if next is a nullptr (i.e. head is the dummy node), the list is emtpy
    bool isEmpty() const { return !head->next; }


    //return a pointer to first element
    Node<S>* begin() const { return head.get(); }
    //return a pointer to beyond-end element
    Node<S>* end() const { return tail; }

    // The insert function takes a pointer to node (pos) and a string (value). It creates a new
    // node which contains value. The new node is inserted into the LinkedList BEFORE the
    // node pointed to by pos. Returns a pointer to the new Node
    Node<S>* insert(Node<S>*pos, const S& value){
        if(pos->prev == nullptr){ //Samme som "!(pos->prev)" ?
            //Flytter head (som er unique) til newNode sin next
            std::unique_ptr<Node<S>> newNode = std::make_unique<Node<S>>(value, std::move(head), nullptr);
            pos->prev = newNode.get(); //pos->prev er nå newNode, siden newNode er plassert før pos
            head = std::move(newNode); //newNode er nå nye head
            return head.get();  //Pointer til det nye objektet newNode, som da altså head peker på
        }
        else{
            //pos->prev->next er en unique_ptr til pos, som vi da skal gi til newNode
            std::unique_ptr<Node<S>> newNode = std::make_unique<Node<S>>(value, std::move(pos->prev->next),pos->prev);
            pos->prev = newNode.get(); //Setter pos->prev til å peke på den nye node, som da ligger bak pos
            newNode->prev->next = std::move(newNode); //Flytter unique_ptr til *newNode til forrige elements next
            //newNode er nå tom
            return pos->prev;  //Funker med newNode likevel? NEI!
        }
    }

    // The find function traverses the linked list and returns a pointer to the first node
    // that contains the value given.
    // If the value isn't in the list, find returns a pointer to the dummy node at the end
    // of the list.
    Node<S>* find(const S& value){
        for (Node<S>* nextPtr = head.get(); nextPtr!=tail; nextPtr=nextPtr->next.get()){
            if(nextPtr->value == value){
                return nextPtr;
            }
        }
        return tail; //Returnerer tail hvis ingener funnet
    }

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node<S>* remove(Node<S>* pos){
        Node<S>* returnValue = pos->next.get();

        if (pos==head.get()){
            pos->next->prev = nullptr; //Gjør neste element sin prev til forrige element
            head = move(pos->next); //Flyttet forrige elements next til neste element
            //return head.get();
        }
        else{
            pos->next->prev = pos->prev; //Gjør neste element sin prev til forrige element
            pos->prev->next = move(pos->next); //Flyttet forrige elements next til neste element
            
        }
        
        return returnValue;
    }

    // The remove function takes a string and removes the first node which contains the value.
    void remove(const S& value){
        Node<S>* removeNode = LinkedList::find(value);
        removeNode = LinkedList::remove(removeNode);
    }

    // write a string representation of the list to the ostream
    friend  std::ostream & operator<<(std::ostream & os, const LinkedList& list){
        Node<S>* nextPtr= list.begin();       //Starter å peke på første element
        while(nextPtr!=list.end()){        //Så lenge den ikke peker på siste element (tail)
            os<<*nextPtr<<std::endl;
            nextPtr=nextPtr->getNext();    //Begynner å peke på neste element
        }
        return os;
    }
};
}// namespace LinkedList


