#include "CustomerList.h"

CustomerList::CustomerList(): head(NULL){}

CustomerList::~CustomerList(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

}

bool CustomerList::isEmpty() const{
    return head==NULL;
}

void CustomerList::add(Customer* c){
    Node* newNode = new Node();
    newNode->data = c;
    newNode->next = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        if (newNode->data->lessThan(*currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == NULL){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;
}

bool CustomerList::get(const string& name, Customer** c) const{
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->matches(name)){
           break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *c = NULL;
        return false;
    }
    //currNode is not NULL
    *c = currNode->data;
    return true;
}

bool CustomerList::remove(const string& name, Customer** c){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->matches(name)){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *c = NULL;
        return false;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *c = currNode->data;
    delete currNode;
    return true;
}

void CustomerList::print() const{
    Node* currNode = head;

    if (currNode == NULL){
        cout <<"List empty"<<endl;
    }

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}

void CustomerList::clear(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
    currNode = NULL;
    nextNode = NULL;
    head = NULL;
}