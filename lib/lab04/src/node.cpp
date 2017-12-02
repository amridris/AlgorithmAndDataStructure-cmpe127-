
#include "../inc/node.h"
#include <iostream>

namespace lab4 {
    // Take in value and create a node
    node::node(int input) {

        node *temp = this;
        temp->data = input;
        temp->next = nullptr;
    }

    // Takes in an array of values and creates the appropriate nodes
    node::node(int values[], int length) {

        //this node(first) data will be equal to values[0]
        node *temp = this;
        temp->data = values[0];

        //loop through the new nodes by assign values and making next point to the next node inline // ++i to start from 1
        for (int i = 1; i < length; i++) {
            temp->next = new node(values[i]);
            temp = temp->next;
        }
    }

    // Default destructor
    node::~node() {
        // Hint: You don't want to just delete the current node. You need to keep track of what is next

    }

    // Add a value to the end node
    void node::append(int input) {

        node *temp = this;
        if (temp->next == nullptr) {
            node *newnode = new node(input);
            temp->next = newnode;
        } else {


            while (temp->next != nullptr) {
                temp = temp->next;
            }
            node *newnode = new node(input);
            temp->next = newnode;
        }
    }

        // Add an array of values to the end as separate nodes
        void node::append(int inputs[], int length) {

            node *temp;
            temp = this;

            while (temp->next != nullptr) {
                temp = temp->next;
            }
            int i = 0;

            temp->next = new node(inputs, length);

        }


        // Insert a new node after the given location
        node *node::insert(int location, int value) {
            // Must return head pointer location
            int i;
            node *temp, *before, *after;
            after = this;
            for (i = 1; i < location; i++) {
                before = after;
                after = after->next;
            }
            temp = new node;
            temp->data = value;
            before->next = temp;
            before = temp;
            before->next = after;

        }

        // Remove a node and link the next node to the previous node
        node *node::remove(int location) {
            // Must return head pointer location
            int i;
            node *temp, *before, *after, *del;
            after = this;


            for(i=0; i<location; i++)
            {
                before = after;
                after = after->next;
                del = after;
            }

            after = after->next;
            delete del;
            before->next = after;

            return this;
        }

        // Print all nodes
        void node::print() {

            node *temp = this;

            while(temp!= nullptr)
            {
                std::cout<<temp->data<<std::endl;
                temp = temp->next;
            }


        }

        //Print the middle node
        void node::print_middle() {
            // HINT: Use a runner to traverse through the linked list at two different rates, 1 node per step
            //       and two nodes per step. When the faster one reaches the end, the slow one should be
            //       pointing to the middle

            node *temp = this;
            node *faster_temp = this;

            while(faster_temp!= nullptr)
            {
                faster_temp = faster_temp->next;
                faster_temp = faster_temp->next;
                temp = temp->next;

            }

            std::cout<<temp->data<<std::endl;
        }

        // Get the value of a given node
        int node::get_value(int location) {

            node* temp = this;
            int check =1;

            for(check =1; check<location; check++)
            {
                temp = temp->next;
                if(temp == nullptr)
                {
                    std::cout<<"Oops. You're out of range. Exiting!"<<std::endl;
                    exit(1);
                }
            }

            return temp->data;

        }

        // Overwrite the value of a given node
        void node::set_data(int location, int value) {
            node *temp = this;
            int count =1;

            while(temp!= nullptr)
            {
                if(count == location)
                {
                    temp->data = value;
                    return;
                }
                count++;
                temp = temp->next;
            }
        }

}
