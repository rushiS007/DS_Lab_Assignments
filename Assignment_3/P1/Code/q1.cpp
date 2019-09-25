#include <bits/stdc++.h>
#include <iostream>
#include <string> // for string class
using namespace std;

enum Color
{
	RED,
	BLACK
};

/// RBTNode for red black tree
struct RBTNode
{
	int data;
	bool color;
	RBTNode *left, *right, *parent;

	/// Constructor
	RBTNode(int data)
	{
		this->data = data;
		left = right = parent = NULL;
		this->color = RED;
	}
};

/// Class to represent Red-Black Tree
class RBTree
{
private:
	///Root of Red Black Tree(RBT)
	RBTNode *root;

protected:
	/**
	* This helper function used for left rotation in RBT.
	* @param root Root of RBT.
	* @param pt RBTNode to be inserted.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void rotateLeft(RBTNode *&root, RBTNode *&pt)
	{
		RBTNode *pt_right = pt->right;

		pt->right = pt_right->left;

		if (pt->right != NULL)
			pt->right->parent = pt;

		pt_right->parent = pt->parent;

		if (pt->parent == NULL)
			root = pt_right;

		else if (pt == pt->parent->left)
			pt->parent->left = pt_right;

		else
			pt->parent->right = pt_right;

		pt_right->left = pt;
		pt->parent = pt_right;
	}

	/**
	* This helper function used for right rotation in RBT.
	* @param root Root of RBT.
	* @param pt RBTNode to be inserted.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void rotateRight(RBTNode *&root, RBTNode *&pt)
	{
		RBTNode *pt_left = pt->left;

		pt->left = pt_left->right;

		if (pt->left != NULL)
			pt->left->parent = pt;

		pt_left->parent = pt->parent;

		if (pt->parent == NULL)
			root = pt_left;

		else if (pt == pt->parent->left)
			pt->parent->left = pt_left;

		else
			pt->parent->right = pt_left;

		pt_left->right = pt;
		pt->parent = pt_left;
	}

	/**
	* This function fixes violations caused by BST insertion.
	* @param root Root of RBT.
	* @param pt RBTNode to be inserted.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void fixViolation(RBTNode *&root, RBTNode *&pt)
	{
		RBTNode *parent_pt = NULL;
		RBTNode *grand_parent_pt = NULL;

		while ((pt != root) && (pt->color != BLACK) &&
			   (pt->parent->color == RED))
		{

			parent_pt = pt->parent;
			grand_parent_pt = pt->parent->parent;

			/* Case : A 
    			Parent of pt is left child of Grand-parent of pt */
			if (parent_pt == grand_parent_pt->left)
			{

				RBTNode *uncle_pt = grand_parent_pt->right;

				/* Case : 1 
    			The uncle of pt is also red 
    			Only Recoloring required */
				if (uncle_pt != NULL && uncle_pt->color == RED)
				{
					grand_parent_pt->color = RED;
					parent_pt->color = BLACK;
					uncle_pt->color = BLACK;
					pt = grand_parent_pt;
				}

				else
				{
					/* Case : 2 
    				pt is right child of its parent 
    				Left-rotation required */
					if (pt == parent_pt->right)
					{
						rotateLeft(root, parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}

					/* Case : 3 
    				pt is left child of its parent 
    				Right-rotation required */
					rotateRight(root, grand_parent_pt);
					swap(parent_pt->color, grand_parent_pt->color);
					pt = parent_pt;
				}
			}

			/* Case : B 
    		Parent of pt is right child of Grand-parent of pt */
			else
			{
				RBTNode *uncle_pt = grand_parent_pt->left;

				/* Case : 1 
    				The uncle of pt is also red 
    				Only Recoloring required */
				if ((uncle_pt != NULL) && (uncle_pt->color == RED))
				{
					grand_parent_pt->color = RED;
					parent_pt->color = BLACK;
					uncle_pt->color = BLACK;
					pt = grand_parent_pt;
				}
				else
				{
					/* Case : 2 
    				pt is left child of its parent 
    				Right-rotation required */
					if (pt == parent_pt->left)
					{
						rotateRight(root, parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}

					/* Case : 3 
    				pt is right child of its parent 
    				Left-rotation required */
					rotateLeft(root, grand_parent_pt);
					swap(parent_pt->color, grand_parent_pt->color);
					pt = parent_pt;
				}
			}
		}

		root->color = BLACK;
	}

public:
	/// Constructor of RBT
	RBTree() { root = NULL; }

	/**
	* A recursive function to do level order traversal.
	* @param root Root of RBT.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void inorderHelper(RBTNode *root)
	{
		if (root == NULL)
			return;

		inorderHelper(root->left);
		if (root->color == RED)
			cout << root->data << " ";
		else
		{
			cout << root->data << " ";
		}
		inorderHelper(root->right);
	}

	/**
	* A utility function to insert a new RBTNode with given key in BST.
	* @param root Root of RBT.
	* @param pt RBTNode to be inserted.
	* @author Kavya Barnwal
	* @date 20/08/2019
	*/
	RBTNode *BSTInsert(RBTNode *root, RBTNode *pt)
	{
		/* If the tree is empty, return a new RBTNode */
		if (root == NULL)
			return pt;

		/* Otherwise, recur down the tree */
		if (pt->data < root->data)
		{
			root->left = BSTInsert(root->left, pt);
			root->left->parent = root;
		}
		else if (pt->data > root->data)
		{
			root->right = BSTInsert(root->right, pt);
			root->right->parent = root;
		}

		/* return the (unchanged) RBTNode pointer */
		return root;
	}

	/**
	* A utility function to get the hieght of a RBTNode in RB Tree.
	* @param rt Node of RBT whose height is to be determined.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	int height(RBTNode *rt)
	{
		int h = 0;
		if (rt != NULL)
		{
			int hl = height(rt->left);
			int hr = height(rt->right);
			h = 1 + (hl > hr ? hl : hr);
		}
		return h;
	}

	/**
	* Function to insert a new RBTNode with given data.
	* @param data integer to be inserted.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void insert(const int &data)
	{
		RBTNode *pt = new RBTNode(data);

		// Do a normal BST insert
		root = BSTInsert(root, pt);

		// fix Red Black Tree violations
		fixViolation(root, pt);
	}

	/**
	* Function to do inorder traversals in Red Black Tree(RBT).
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void inorder() { inorderHelper(root); }

	/**
	* Helper method for method levelViseIndentation().
	* @param root Root of RBT.
	* @param l level of that  node.
	* @author Kavya Barnwal
	* @date 20/08/2019
	*/
	void levelViseIndentationHelper(RBTNode *rt, int l)
	{
		if (rt == NULL)
		{
			return;
		}
		int j = l;
		while (j-- > 0)
		{
			cout << "\t";
		}
		int h = height(rt->right) - height(rt->left);
		if (h < 0)
		{
			h *= -1;
		}
		if (h == 0)
		{
			if (rt->color == RED)
				cout << rt->data << " "
					 << "[RED]\n";
			else
			{
				cout << rt->data << " "
					 << "[BLACK]\n";
			}
		}
		else
		{
			if (rt->color == RED)
				cout << rt->data << " [" << h << "] "
					 << "[RED]\n";
			else
			{
				cout << rt->data << " [" << h << "] "
					 << "[BLACK]\n";
			}
		}

		levelViseIndentationHelper(rt->left, l + 1);
		levelViseIndentationHelper(rt->right, l + 1);
	}
	/**
	* This method will be used to print the Red Black Tree(RBT) with lavel-wise-indentation.
	* @author Kavya Barnwal
	* @date 20/08/2019
	*/
	void levelViseIndentation()
	{
		levelViseIndentationHelper(root, 0);
	}
	/**
	* Helper method for method getAllPaths().
	* @param rt Root of RB Tree.
	* @param s string containing details of nodes traversed.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void printPath(RBTNode *rt, string s)
	{
		if (rt == NULL)
		{
			cout << s << "\n";
			return;
		}
		s = s + to_string(rt->data) + " ";
		if (rt->left == NULL && rt->right == NULL)
		{
			cout << s << "\n";
			return;
		}
		printPath(rt->left, s);
		printPath(rt->right, s);
	}
	/**
	* This method will be used to print all the paths from root node to the NULL pointers of RB Tree.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void getAllPaths()
	{
		if (root == NULL)
		{
			cout << "No paths to show" << endl;
		}
		cout << "RBT Paths : \n";
		string s = "";
		printPath(root, s);
	}
};

// An AVL tree node
class Node
{
public:
	int key;
	Node *left;
	Node *right;
	int height;
};

/// Class for AVL Tree
class AVLTree
{
public:
	///Root of AVL Tree
	Node *root;

	/**
	* A utility function to get the height of the tree.
	* @param N Node of which height to be determined
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	int height(Node *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	/**
	* A utility function to get maximum of two integers.
	* @param a first integer.
	* @param b second integer.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}

	/**
	* Helper function that allocates a new node with the given key and NULL left and right pointers.
	* @param key data to be inserted.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	Node *newNode(int key)
	{
		Node *node = new Node();
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->height = 1; // new node is initially
						  // added at leaf
		return (node);
	}

	/**
	* A utility function to right rotate subtree rooted with y.
	* @param y Node about which to be rotated.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	Node *rightRotate(Node *y)
	{
		Node *x = y->left;
		Node *T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		// Update heights
		y->height = max(height(y->left),
						height(y->right)) +
					1;
		x->height = max(height(x->left),
						height(x->right)) +
					1;

		// Return new root
		return x;
	}

	/**
	* A utility function to left rotate subtree rooted with y.
	* @param x Node about which to be rotated.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	Node *leftRotate(Node *x)
	{
		Node *y = x->right;
		Node *T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		// Update heights
		x->height = max(height(x->left),
						height(x->right)) +
					1;
		y->height = max(height(y->left),
						height(y->right)) +
					1;

		// Return new root
		return y;
	}

	/**
	* Get Balance factor of node N.
	* @param N Node for which balance factor is to be determined.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	int getBalance(Node *N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	/**
	* Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree.
	* @param node Root of AVL Tree.
	* @param data integer to be inserted.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	Node *insert(Node *node, int key)
	{
		/* 1. Perform the normal BST insertion */
		if (node == NULL)
			return (newNode(key));

		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);
		else // Equal keys are not allowed in BST
			return node;

		/* 2. Update height of this ancestor node */
		node->height = 1 + max(height(node->left),
							   height(node->right));

		/* 3. Get the balance factor of this ancestor 
    		node to check whether this node became 
    		unbalanced */
		int balance = getBalance(node);

		// If this node becomes unbalanced, then
		// there are 4 cases

		// Left Left Case
		if (balance > 1 && key < node->left->key)
			return rightRotate(node);

		// Right Right Case
		if (balance < -1 && key > node->right->key)
			return leftRotate(node);

		// Left Right Case
		if (balance > 1 && key > node->left->key)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		/* return the (unchanged) node pointer */
		return node;
	}

	/**
	* A utility function to print preorder traversal of the tree. The function also prints height of every node.
	* @param root Root of AVL Tree.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void inOrder(Node *root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			cout << root->key << " ";
			inOrder(root->right);
		}
	}
	/**
	* Helper method for method levelViseIndentation().
	* @param root Root of AVL Tree.
	* @param l level of that  node.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void levelViseIndentationHelper(Node *rt, int l)
	{
		if (rt == NULL)
		{
			return;
		}
		int j = l;
		while (j-- > 0)
		{
			cout << "\t";
		}
		if (rt->height == 1)
		{
			cout << rt->key << "\n";
		}
		else
		{
			int bf = getBalance(rt);
			if (bf < 0)
			{
				bf *= -1;
			}
			cout << rt->key << "[" << bf << "]\n";
		}
		levelViseIndentationHelper(rt->left, l + 1);
		levelViseIndentationHelper(rt->right, l + 1);
	}
	/**
	* This method will be used to print the AVL Tree with lavel-wise-indentation.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void levelViseIndentation()
	{
		levelViseIndentationHelper(root, 0);
	}
	/**
	* Helper method for method getAllPaths().
	* @param rt Root of AVL Tree.
	* @param s string containing details of nodes traversed.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void printPath(Node *rt, string s)
	{
		if (rt == NULL)
		{
			cout << s << "\n";
			return;
		}
		s = s + to_string(rt->key) + " ";
		if (rt->left == NULL && rt->right == NULL)
		{
			cout << s << "\n";
			return;
		}
		printPath(rt->left, s);
		printPath(rt->right, s);
	}
	/**
	* This method will be used to print all the paths from root node to the NULL pointers of AVL Tree.
	* @author Rushiprasad
	* @date 20/08/2019
	*/
	void getAllPaths()
	{
		if (root == NULL)
		{
			cout << "No paths to show" << endl;
		}
		cout << "AVL Paths : \n";
		string s = "";
		printPath(root, s);
	}
};

AVLTree AVL;

struct node
{
	int key;
	struct node *left, *right;
};

struct node *BST = NULL;

/**
* A utility function to create a new BST node.
* @param item data to be inserted.
* @author Rushiprasad
* @date 20/08/2019
*/
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

/**
* A utility function to do inorder traversal of BST.
* @param node Root of BST.
* @param key data to be inserted.
* @author Rushiprasad
* @date 20/08/2019
*/
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/**
* A utility function to insert a new node with given key in BST.
* @param node Root of BST.
* @param key data to be inserted.
* @author Rushiprasad
* @date 20/08/2019
*/
struct node *insert(struct node *node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/**
* A utility function to get the hieght of a BSTNode in Binary Search Tree.
* @param rt Node of BST whose height is to be determined.
* @author Rushiprasad
* @date 20/08/2019
*/
int height(struct node *rt)
{
	int ht = 0;
	if (rt != NULL)
	{
		int hr = height(rt->right);
		int hl = height(rt->left);
		ht = (1 + (hr > hl ? hr : hl));
	}
	return ht;
};

/**
* Helper method for method getAllPaths().
* @param rt Root of BST.
* @param s string containing details of nodes traversed.
* @author Rushiprasad
* @date 20/08/2019
*/
void printPath(node *rt, string s)
{
	if (rt == NULL)
	{
		cout << s << "\n";
		return;
	}
	s = s + to_string(rt->key) + " ";
	if (rt->left == NULL && rt->right == NULL)
	{
		cout << s << "\n";
		return;
	}
	printPath(rt->left, s);
	printPath(rt->right, s);
}
/**
* This method will be used to print all the paths from root node to the NULL pointers.
* @param BST Root of BST.
* @author Rushiprasad
* @date 20/08/2019
*/
void getAllPaths(struct node *BST)
{
	if (BST == NULL)
	{
		cout << "No paths to show" << endl;
	}
	cout << "BST Paths : \n";
	string s = "";
	printPath(BST, s);
}
/**
* Helper method for method levelViseIndentation().
* @param root Root of BST.
* @param l level of that  node.
* @author Rushiprasad
* @date 20/08/2019
*/
void levelViseIndentationHelper(node *rt, int l)
{
	if (rt == NULL)
	{
		return;
	}
	int j = l;
	while (j-- > 0)
	{
		cout << "\t";
	}
	int h = height(rt);
	if (h == 1)
	{
		cout << rt->key << "\n";
	}
	else
	{
		cout << rt->key << "[" << (h - 1) << "]\n";
	}
	levelViseIndentationHelper(rt->left, l + 1);
	levelViseIndentationHelper(rt->right, l + 1);
}
/**
* This method will be used to print the Binary Search Tree(BST) with lavel-wise-indentation.
* @param root Root of BST.
* @author Rushiprasad
* @date 20/08/2019
*/
void levelViseIndentation(node *root)
{
	levelViseIndentationHelper(root, 0);
}

/**
* This method will be used to create AVL Tree from inOrder traversal of Binary Search Tree.
* @param rt Root of the binary search tree(BST).
* @author Rushiprasad
* @date 20/08/2019
*/
void createAVLTree(struct node *rt)
{
	if (rt != NULL)
	{
		createAVLTree(rt->left);
		AVL.root = AVL.insert(AVL.root, rt->key);
		createAVLTree(rt->right);
	}
}

// Driver Code
int main()
{
	// 	1. To insert a node in the BST and in the red-black tree
	// 2. To create AVL tree from the inorder traversal of the BST
	// 3. To print the inorder traversal of the BST/AVL/red-black tree
	// 4. To display all the paths in the BST/AVL tree/red-black tree
	// 5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation (print color
	// for red-black tree)
	// 6. Exit
	RBTree RBT;
	struct node *root = NULL;

	cout << "Enter the choice :\n"
		 << "1. To insert a node in the BST and in the red-black tree\n"
		 << "2. To create AVL tree from the inorder traversal of the BST\n"
		 << "3. To print the inorder traversal of the BST/AVL/red-black tree\n"
		 << "4. To display all the paths in the BST/AVL tree/red-black tree\n"
		 << "5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation (print color for red-black tree)\n"
		 << "6. Exit" << endl;

	int k = 0;
	do
	{
		cout << "Enter the choice" << endl;
		cin >> k;

		switch (k)
		{
		case 1:
			cout << "Enter the number"
				 << "\n";
			int n;
			cin >> n;

			root = insert(root, n);
			RBT.insert(n);

			break;
		case 2:
			createAVLTree(root);
			break;
		case 3:
			cout << "InOrder Traversal of Created RBTree\n";
			RBT.inorder();
			cout << "\n";

			cout << "InOrder Traversal of Created BSTree\n";
			inorder(root);
			cout << "\n";

			cout << "InOrder Traversal of Created AVLTree\n";
			AVL.inOrder(AVL.root);
			cout << "\n";

			break;
		case 4:
			getAllPaths(root);
			AVL.getAllPaths();
			RBT.getAllPaths();
			//statements
			break;
		case 5:
			cout << "BS Tree :\n";
			levelViseIndentation(root);
			cout << "AVL Tree :\n";
			AVL.levelViseIndentation();
			cout << "RB Tree :\n";
			RBT.levelViseIndentation();
			break;
		case 6:
			cout << "Program is finished" << endl;
			break;
		default: //optional
			cout << "Invalid Option choosen" << endl;
		}

	} while (k != 6);

	return 0;
}

