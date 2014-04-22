#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <iostream>
#include <time.h>

const static bool RED = true;
const static bool BLACK = false;

class Node {
public:
	int data;
	Node *left, *right;
	bool color;

private:
};

void AddLeftNode ( Node *node, int data ) {
	if (node->left != NULL) {
	std::cout << "WARNING: something is already here" << std::endl;
	return;
	}
	Node *newnode = new Node;
	newnode->data = data;
	node->left = newnode;
	return;
}

void AddRightNode ( Node *node, int data ) {
	if (node->right != NULL) {
		std::cout << "WARNING: something is already here" << std::endl;
		return;
	}
	Node *newnode = new Node;
	newnode->data = data;
	node->right = newnode;
	return;
}

void AddNode ( Node *root, int data ) {
	Node *conductor = root, *previous;
	while ( conductor != NULL ) {
		if (data > conductor->data) {
			std::cout << "Looking for node: " << data << " is greater than " << conductor->data << std::endl;
			previous=conductor;
			conductor=conductor->right;
		}
		else {
			std::cout << "Looking for node: " << data << " is less than " << conductor->data << std::endl;
			previous=conductor;
			conductor=conductor->left;
		}
	}

	if (data > previous->data) {
		AddRightNode(previous, data);
		std::cout << "Adding right node" << std::endl;
		std::cout << "Parent Node is: " << previous->data << std::endl;
		if(previous->left)std::cout << "Left Child Node is: " << previous->left->data << std::endl; else std::cout << "No Left Node" << std::endl;
		std::cout << "Right Child Node is: " << previous->right->data << std::endl;
	}
	else {
		AddLeftNode(previous, data);
		std::cout << "Adding left node" << std::endl;
		std::cout << "Parent Node is: " << previous->data << std::endl;
		std::cout << "Left Child Node is: " << previous->left->data << std::endl;
		if(previous->right)std::cout << "Right Child Node is: " << previous->right->data << std::endl; else std::cout << "No Right Node" << std::endl;
	}
	std::cout << "-------------" << std::endl;
}

void SortNode ( Node *root ) {

}

void BFS(Node *start)
{
    std::deque<Node *> q;
    q.push_back(start);
	Node *next;
    while (q.size() != 0)
    {
        next = q.front();
        // you may want to print the current node here or do other processing
        std::cout << "Breadth First Search: " << next->data << std::endl;
        //pop the current pointer off the double-ended queue
        q.pop_front();
        if (next->left)
            q.push_back(next->left);
        if (next->right)
            q.push_back(next->right);
    }

}

void DepthSearch ( Node *root ) {
	//Visit the root node
	//Traverse the left subtree
	//Traverse the right subtree
	std::deque<Node *> list;
	Node *conductor = root, *current;
	int level=0;
	list.push_back(root);
	current = list.front();
	std::cout << "Depth SearchRoot: " << current->data << std::endl;

		while ( current->left != NULL ) {
			list.push_back(current->left);
			std::cout << "Depth SearchLeft: " << current->left->data << std::endl;
			current=current->left;
		}

		while ( list.size() != 0 ) { //check to see if any right nodes exist on the previous nodes
			current = list.front(); //we have already visited this node so don't print it
			list.pop_front();
			if ( current->right ) {
				DepthSearch(current->right); //Recursion to check & print the right nodes
			}
		}
	return;
}

 int countNodes( Node *root ) {
           // Count the nodes in the binary tree to which
           // root points, and return the answer.
        if ( root == NULL )
           return 0;  // The tree is empty.  It contains no nodes.
        else {
           int count = 1;   // Start by counting the root.
           count += countNodes(root->left);  // Add the number of nodes
                                            //     in the left subtree.
           count += countNodes(root->right); // Add the number of nodes
                                            //    in the right subtree.
           return count;  // Return the total.
        }
     } // end countNodes()

void preorderPrint( Node *root ) {
           // Print all the items in the tree to which root points.
           // The item in the root is printed first, followed by the
           // items in the left subtree and then the items in the
           // right subtree.
        if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
           std::cout << root->data << " ";      // Print the root item.
           preorderPrint( root->left );    // Print items in left subtree.
           preorderPrint( root->right );   // Print items in right subtree.
        }
} // end preorderPrint()

int main (int argc, char *argv[]) {
	int t0 = clock();
	Node *root = new Node;
	root->data = 50;
	root->left=NULL;
	root->right=NULL;
	root->color = BLACK;

	AddNode(root, 11);
	AddNode(root, 60);
	AddNode(root, 61);
	AddNode(root, 59);
	AddNode(root, 10);
	AddNode(root, 99);
	AddNode(root, 111);
	AddNode(root, 23);
	AddNode(root, 909);
	AddNode(root, 9988);
	AddNode(root, 1000);

	std::cout << "Root Right " << root->right->data << std::endl;

	int numNodes = countNodes(root);
	std::cout << "There are " << numNodes << " nodes." << std::endl;

	preorderPrint(root);
	std::cout << std::endl;

	BFS(root);

	DepthSearch(root);
	int t1 = clock() - t0;
	std::cout << "Time: " << t1 << std::endl;
	return 0;
}


