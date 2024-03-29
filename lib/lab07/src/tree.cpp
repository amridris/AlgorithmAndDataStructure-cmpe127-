#include "../inc/tree.h"
#include <iostream>
#include <vector>

namespace lab7 {

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ AUXILIARY FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    node *print_least_greatest(node *root) {
        if (root == nullptr) {
            return root;
        } else {
            print_least_greatest(root->left);
            std::cout << root->data << std::endl;
            print_least_greatest(root->right);
        }

        return root;

    }

//Auxiliary function (insert)
    node *insert_node(int key, node *root) {
        //empty tree or subtree, also acts like a base case for the recursion method
        if (root == nullptr) {
            root = new node(key);
        } else {

            // move through tree until you find a empty space
            if (key < root->data) {

                root->left = insert_node(key, root->left);
            }

                // move through tree until you find a empty space
            else if (key > root->data) {

                root->right = insert_node(key, root->right);
            } else if (key == root->data) {
                root->frequency++;
            }

        }
        return root;
    }


//auxiliary function (f_min)
    node *f_min(node *root) {
        //empty
        if (root == nullptr) {
            return 0;
        }
            //empty slot of left subtree
        else if (root->left == nullptr) {
            return root;
        }
            //recursively move to find the minimum
        else {
            return f_min(root->left);
        }

    }


//auxiliary function remove_node
    node *remove_node(node *root, int key) {
        node *temp;
        //base case for the recursion calls
        if (root == nullptr) {
            return 0;
        } else if (key < root->data) {
            //keep traversing till key is found!
            root->left = remove_node(root->left, key);
        }
            //continue traversing the right subtree till key is found
        else if (key > root->data) {
            root->right = remove_node(root->right, key);
        } else if (root->left && root->right) {
            temp = f_min(root->right);
            root->data = temp->data;
            root->right = remove_node(root->right, root->data);
        } else {
            temp = root;
            if (root->left == nullptr) {
                root = root->left;
            } else if (root->right == nullptr) {
                root = root->right;
            }
            delete temp;
        }

        return root;

    }

    int find_level(node *root, int key, int level) {
        //empty tree
        if (root == nullptr) {
            return 0;
        }
        if (root->data == key) {
            return level;
        } else {
            //traverse left subtree to find key
            if (key < root->data) {
                return find_level(root->left, key, (level + 1));
            }
                //traverse right subtree to find key
            else {
                return find_level(root->right, key, (level + 1));
            }
        }
    }

    unsigned find_size(node *root) {
        //empty tree or subtree
        if (root == nullptr) {
            return 0;
        }

        //check and count all the nodes of binary tree
        return (1 + find_size(root->left) + find_size(root->right));

    }

    bool find_key(node *root, int key) {
        //case 1: root is null (empty) or key is found in root data
        if (root == nullptr) {
            return false;
        } else if (root->data == key) {
            return true;
        }
            //case 2: key is less than root data ... check left subtree
        else if (key < root->data) {
            return find_key(root->left, key);
        }
            //case 3: Key is greater than root data .. check right subtree
        else if (key > root->data) {
            return find_key(root->right, key);
        }
            //Case 4: key not found
        else {
            return false;
        }
    }

    int frequency_value(node *root, int key) {
        if (root == nullptr) {
            //base case for the recursion
            return 0;
        } else {
            if (key < root->data) {
                //keep traversing since key was not yet found
                frequency_value(root->left, key);
            } else if (key > root->data) {
                //keep traversing since key was not yet found
                frequency_value(root->right, key);
            }
                //key was found return the frequency value of that key
            else {
                return root->frequency;
            }

        }

    }

    unsigned find_depth(node *root) {
        //empty tree
        if (root == nullptr) {
            return 0;
        }
        //find the left tree depth recurively
        int depth_left = find_depth(root->left);

        //find the right tree depth recurively
        int depth_right = find_depth(root->right);

        if (depth_left > depth_right) {
            return depth_left + 1;
        } else {
            return depth_right + 1;
        }


    }


    bool tPath(node *root, std::vector<int> &arr, int x) {
        // empty tree
        if (!root)
            return false;

        // push the value to array
        arr.push_back(root->data);

        //true if there is path
        if (root->data == x)
            return true;

        // else check whether the required node lies in the left subtree or right subtree of the current node
        if (tPath(root->left, arr, x) ||
            tPath(root->right, arr, x))
            return true;

        // required node does not lie either in the left or right subtree of the current node Thus, remove current node's value from'arr'and then return false
        arr.pop_back();
        return false;
    }


    void print_Path(node *root, int x) {
        // vector to store the path
        std::vector<int> arr;

        // if required node 'x' is present
        // then print the path
        if (tPath(root, arr, x)) {
            for (int i = 0; i < arr.size() - 1; i++)
                std::cout << arr[i] << "->";
            std::cout << arr[arr.size() - 1];
        }

            // 'x' is not present in the binary tree
        else
            std::cout << "No Path";
    }


    void clear(node *to_clear);

    void node_print_gtl(node *to_print);

    // Construct an empty tree
    tree::tree() {
        root = nullptr;
    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {
        root = insert_node(value, root);
    }

    // Remove key
    bool tree::remove(int key) {
        root = remove_node(root, key);
    }

    // What level is key on?
    int tree::level(int key) {
        int level;

        level = find_level(root, key, level);

        return level;
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        print_Path(root, key);
    }

    // Number of items in the tree
    unsigned tree::size() {
        unsigned size_counter;
        size_counter = find_size(this->root);
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        find_depth(root);
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        //function helper that return true of key found
        find_key(root, key);
    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        //function helper that returns key frequency in binary tree
        int frequency = frequency_value(root, key);
    }

    // Print the tree least to greatest, Include duplicates
    void tree::print() {
        print_least_greatest(root);
    }

    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }

    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

        void clear(node *to_clear) {
            if (to_clear == nullptr) return;
            if (to_clear->left != nullptr) clear(to_clear->left);
            if (to_clear->right != nullptr) clear(to_clear->right);
            delete to_clear;
        }
    }
