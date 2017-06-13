#include <iostream>
#include <fstream>



using namespace std;

template <class T>
struct Node
{
	T element;
	Node<T> *left, *right, *pparent;
};

template <class T>
class BST {
private:
	Node<T> *root;
	int count;
public:
	BST();
	~BST();
	void deleteTree(Node<T> *Tree);
	void show(ostream&cout, const Node<T> *Tree) const;
	void add(const T&);
	bool search(const T&, Node<T> *Tree) const;
	void input(const string& file);
	void output(const string& file) const;
	Node<T>* MinElement(Node<T>* min);
	Node<T>* getroot() const;
	int getcount() const;
	Node<T>* del(Node<T>* parent, Node<T>* current, const T& val);
	bool delVal(const T& val);


};


template <typename T> BST<T>::BST() {
	root = NULL;
	count = 0;
}

template <typename T> BST<T>::~BST() {
	deleteTree(root);
}

template <typename T>void BST<T>::deleteTree(Node<T> *Tree) {
	if (!Tree)
		return;
	if (Tree->left) {
		deleteTree(Tree->left);
		Tree->left = nullptr;
	}

	if (Tree->right) {
		deleteTree(Tree->right);
		Tree->right = nullptr;
	}
	delete Tree;
}


template <typename T> void BST<T>::show(ostream&cout, const Node<T> *Tree) const{
	if (Tree != NULL) {

		cout << Tree->element << endl;;
		show(cout, Tree->left);
		show(cout, Tree->right);

	}
}

template <typename T> void BST<T>::add(const T &x) {
	Node<T>* daughter = new Node<T>;
	daughter->element = x;
	daughter->left = daughter->right = nullptr;
	Node<T>* parent = root;
	Node<T>* temp = root;

	while (temp)
	{
		parent = temp;
		if (x < temp->element)
			temp = temp->left;
		else temp = temp->right;
	}

	if (!parent)
		root = daughter;
	else {
		if (x < parent->element)
			parent->left = daughter;
		else
			parent->right = daughter;
	}
	count++;
}


template <typename T> Node<T>* BST<T>::getroot() const {
	return root;
}

template <typename T> int BST<T>::getcount() const {
	return count;
}

template <typename T> void BST<T>::input(const string& file) {
ifstream fin(file);
	
		int temp;
		while (!fin.eof());
		{

			fin >> temp;
			add(temp);
			

		}
		fin.close();
	}
	
}

template <typename T> void BST<T>::output(const string& file) const {
	ofstream fout(file);
	show(fout, root);
	fout.close();
}

template <typename T> bool BST<T>::search(const T&x, Node<T>* Tree) const {
	if (Tree == nullptr)
		return false;
	if (x == Tree->element) {
		return true;
	}
	else if (x < Tree->element) {
		search(x, Tree->left);
	}
	else search(x, Tree->right);
}

template <typename T> Node<T>* BST<T>::MinElement(Node<T>* min) {
	if (min->left == nullptr)
		return min;
	else
		return MinElement(min->left);


}

template <typename T>
Node<T>* BST<T>::del(Node<T>* parent, Node<T>* current, const T& val)
{
	if (!current) return false;

	if (current->element == val)
	{
		if (current->left == NULL || current->right == NULL)
		{
			Node<T>* temp = current->left;
			if (current->right) temp = current->right;
			if (parent)
			{
				if (parent->left == current)
				{
					parent->left = temp;
				}
				else
				{
					parent->right = temp;
				}
			}
			else
			{
				this->root = temp;
			}
		}

		else
		{
			Node<T>* validSubs = current->right;
			while (validSubs->left)
			{
				validSubs = validSubs->left;
			}
			T temp = current->element;
			current->element = validSubs->element;
			validSubs->element = temp;
			return del(current, current->right, temp);

		}
		delete current;
		count--;
		return true;
	}

	if (current->element > val)

		return del(current, current->left, val);

	else

		return del(current, current->right, val);
}


template <typename T>
bool BST<T>::delVal(const T& val) {
	return this->del(NULL, root, val);
}
