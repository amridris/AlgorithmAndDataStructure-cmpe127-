#include <iostream>
#include "../inc/stack.h"

namespace lab5 {
    stack::stack() : head(nullptr), size(0) {}

    stack::stack(std::string &data) {
        head = new node(data);
        size = 1;
    }

    stack::stack(const stack &original) {
        if (original.head != nullptr) {
            node *original_tmp = original.head;
            node *tmp = head = new node(original_tmp->data);
            size = original.size;

            original_tmp = original_tmp->next;
            while (original_tmp != nullptr) {
                tmp->next = new node(original_tmp->data);
                tmp = tmp->next;
                original_tmp = original_tmp->next;
            }
        } else {
            head = nullptr;
            size = 0;
        }
    }

    stack::~stack() {
        while (head != nullptr)
            pop();
    }

    stack &stack::operator=(const stack &RHS) {

        if (this != &RHS) {
            if (head != nullptr)
                delete this;
            if (RHS.head != nullptr) {
                node *RHS_tmp = RHS.head;
                node *tmp = head = new node(RHS_tmp->data);
                size = RHS.size;
                RHS_tmp = RHS_tmp->next;
                while (RHS_tmp != nullptr) {
                    tmp->next = new node(RHS_tmp->data);
                    tmp = tmp->next;
                    RHS_tmp = RHS_tmp->next;
                }
            }
        }
        return *this;
    }

    bool stack::isEmpty() const {
        return size == 0;
    }

    unsigned stack::stackSize() const {
        return size;
    }

    std::string stack::top() const {
        return head->data;
    }

    void stack::push(std::string &data) {
        //create a new node and insert data
        node *temp = new node(data);

        //If the stack is empty
        if(isEmpty())
        {
            //since it is empty point head to the new node
            head = temp;
            //since we added a node
            size++;

            return;
        }
            //if the stack is not empty
        else {

            //let the new node point to the first node
            temp = head->next;

            //let head then point to the newly created node
            head = temp;

            //since we added a node increment size
            size++;

            return;
    }

    void stack::pop() {
        node *temp;
        //check to see if the stack is empty
        if(isEmpty())
        {
            //since it is empty return an error
            std::cout<<"Error encountered! The stack is empty"<<std::endl;
            return;
        }
        else
        {
            //if there are items in the stack
            //assign temp to the leading node
            temp = head;
            //move head to the next node so we can delete the leading node
            head = head->next;
            //once head is moved to the next node, we can delete the leading node
            free(temp);
            //decrement size since we deleted a node
            size--;
        }
    }
}