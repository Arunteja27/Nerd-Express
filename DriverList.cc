#include "DriverList.h"

DriverList::DriverList(): head(NULL), size(0){}

DriverList::~DriverList(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

}

bool DriverList::isEmpty() const{
    return head==NULL;
}

void DriverList::add(Driver* d){
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;
    if(size == 0){
        head = newNode;
        ++size;
        return;
    }

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
    ++size;
}

bool DriverList::get(const string& name, Driver** d) const{
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->matches(name)){
           break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *d = NULL;
        return false;
    }

    *d = currNode->data;
    return true;
}

bool DriverList::remove(const string& name, Driver** d){
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
        *d = NULL;
        return false;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *d = currNode->data;
    delete currNode;
    return true;
}

void DriverList::print() const{
    Node* currNode = head;

    if (currNode == NULL){
        cout <<"List empty"<<endl;
    }

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}

void DriverList::clear(){
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

bool DriverList::findRide(int rating, Size s, Location l, Driver** d){
    
    Node* currNode = head;
    Node* nextNode = NULL;
    Driver* closest = NULL;
    //set to largest integer value so first minDistance can be found
    int minDistance = 2147483647;

    while(currNode!=NULL){
        
        if(currNode->data->match(rating, s)){
            
            if(currNode->data->getDistance(l) < minDistance){
                minDistance = currNode->data->getDistance(l);
                closest = currNode->data;
            }
        }


        nextNode = currNode;
        currNode = currNode->next;
        
    }

    if(closest == NULL){
        return false;
    }

    *d = closest;
    return true;

}