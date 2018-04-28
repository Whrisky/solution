#ifndef __BINARYSEARCH__
#define __BINARYSEARCH_
#include <cstddef>
#include <queue>
using namespace std;
template <typename Key, typename Value>
class BinaryTree{
    private:
    struct Node{
        Key key;
        Value value;
        Node *lchild;
        Node *rchild;
        Node(Key key , Value value){
            this->key = key;
            this->value = value;
            this->lchild = this->rchild = NULL;
        }
    };
    Node *root;
    int count;
     Node *remove_min(Node *node){
        if(node->lchild == NULL) {
            Node *rNode = node->rchild;
            delete node;
            count--;
            return rNode;
        }
        node->lchild = remove_min(node->lchild);
        return node;
    }
    Node *remove_max(Node *node){
        if(node->rchild == NULL){
            Node *lchild = node->lchild;
            delete node;
            count --;
            return lchild;
        }
        node->rchild = remove_max(node->rchild);
    }

    void remove_node(Key key, Node *node){
        if(node != NULL){
            Node *lchild;
            Node *rchild;
            if(node->key == key){
                vector<Node *> v;
                lchild = node->lchild;
                Node *del = node;
                while(del->rchild != NULL){
                    del = del->rchild;
                }
                if(del->lchild!=NULL){
                    node->key = del->lchild->key;
                    node->value = del->lchild->value;
                }
                count -- ;
            }else if(node->key < key){
                remove_node(key, node->lchild);
            
            }else remove_node(key, node->rchild);
            node->lchild = lchild;
            node->rchild = rchild;
        }
    }
    public:
    BinaryTree(){
        root = NULL;
        count = 0;
    }
    ~BinaryTree(){

    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }
    void insert(Key key ,Value value, Node *node){
        if(node == NULL && count != 0){
            return;
        }if(node == NULL && count == 0){
            *root = new Node(key, value);
        }else{
            if(value > node->value){
                insert(key , value, node->rchild);
                *node->rchild = new Node(key, value);
                count ++;
            }else if(value < node-> value){
                insert(key, value, node->lchild);
                *node->lchild = new Node(key, value);
                count ++;
            }else{
                node->key = key;
                node->value = value;
            }
        }
    }
    void preOrd(Node *node){
        if(node == NULL){
            count << "\n";
            return;
        }else{
            count << node->key << "\t";
            preOrd(node->lchild);
            preOrd(node->rchild);
        }
    }
    void inOrd(Node *node){
        if(node == NULL){
            count << "\n";
            return;
        }else{
            inOrd(node->lchild);
            count << node->key << "\t";
            inOrd(node->rchild);
        }
    }
    void postOrd(Node *node){
        if(node == NULL){
            count << "\n";
            return;
        }else{
            postOrd(node->lchild);
            postOrd(node->rchild);
            count << "\n";
        }
    }
    void destory(Node *node){
        if(node == NULL) return;
        else{
            destory(node->lchild);
            destory(node->rchild);
            delete node;
            count --;
        }
    }
    queue<Node *> levelOrd(){
        queue<Node *> q;
        q.push(root);
        while(q != NULL){
            Node *node = q.front();
            count << node->key << "\t";
            q.pop();
            if(node->lchild != NULL) q.push(node->lchild);
            if(node->rchild != NULL) q.push(node->rchild);
        }
        return q;
    }
    Node *min_num(Node *node){
        if(node->lchild == NULL) return node;
        else min_num(node->lchild);

    }
    Node *max_num(Node *node){
        if(node->rchild == NULL) return node;
        else max_num(node->rchild);
    }
    void remove_min(){
        if(root -> lchild!=NULL)
            root = remove_min(root);
    }
    void remove_max(){
        if(root->rchild != NULL)
            root = remove_max(root);
    }
    
};
#endif