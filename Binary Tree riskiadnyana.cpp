#include <iostream>
using namespace std;

class Node {
	public:
		Node *left;
	    Node *right;
	    
	    int key;
	    Node(){
	    	left = right = NULL;
		}
	    
};

class BST{
	public:
		Node *root;
		
		BST() {
	    	root = NULL;
		}
		
		Node *insertRecursive(int newKey, Node *currentRoot){
			
			if (currentRoot==NULL){
				Node *newNode = new Node();
				newNode ->key = newKey;
				return newNode;
			}
			
			if (newKey < currentRoot->key){
				currentRoot->left = insertRecursive(newKey, currentRoot->left);
			}else if (newKey > currentRoot->key){
				currentRoot->right = insertRecursive(newKey, currentRoot->right);
			}
			
			return currentRoot;
		}
		
		void insert(int newKey){
			root = insertRecursive (newKey,root);
		}
		
		void preOrderRecunsive(Node *currentRoot){
			if (currentRoot!=NULL){
				cout << currentRoot->key << " ";
				preOrderRecunsive(currentRoot->left);
				preOrderRecunsive(currentRoot->right);
			}
		}
		
		void postOrderRecunsive(Node *currentRoot){
			if (currentRoot!=NULL){
				postOrderRecunsive(currentRoot->left);
				postOrderRecunsive(currentRoot->right);
				cout << currentRoot->key << " ";
			}
		}
		
		void inOrderRecunsive(Node *currentRoot){
			if (currentRoot!=NULL){
				inOrderRecunsive(currentRoot->left);
				cout << currentRoot->key << " ";
				inOrderRecunsive(currentRoot->right);
			}
		}
		
		void preOrderTraversal(){
			cout << "preOrderTraversal :";
			preOrderRecunsive(root);
			cout << endl;
		}
		
		void postOrderTraversal(){
			cout << "postOrderTraversal :";
			postOrderRecunsive(root);
			cout << endl;
    	}
    	
    	void inOrderTraversal(){
    		cout << "inOrderTranversal:";
    		inOrderRecunsive(root);
    		cout << endl;
		}
			
}; 

int main(int argc, char** argv){
	
	BST *bin1 = new BST();
	
	bin1->insert(6);
	bin1->insert(7);
	bin1->insert(4);
	bin1->insert(8);
	bin1->insert(5);
	bin1->insert(3);
	
	bin1->preOrderTraversal();
	bin1->postOrderTraversal();
	bin1->inOrderTraversal();
	
	return 0;
}
