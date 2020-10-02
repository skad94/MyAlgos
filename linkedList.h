#pragma once
#include <iostream>
#include <vector>
class vector;
class Node
{
// Just a key value (to be templated) and a pointer to another node to form a linked list Llist
private:
	double m_value;
	Node* m_next;
public:
	Node();
	Node(const double& val);
	Node(const Node const* val);
	~Node();
	Node* getNext() const { return m_next; };
	double getValue() const { return m_value; };
	void setValue(const double& l) { m_value = l; };
	void setNext(Node* next) { m_next = next; };
	Node& operator=(const Node& other);

};
class Llist
{
	Node* m_start;
	int m_size;
public:
	Llist(const double& val);
	Llist(const Llist& val);
	~Llist();
	Llist* swapPairs(Llist* head);
	void addNode(const double& val);
	int getSize() const { return m_size; };
	Node* getStart() const { return m_start; };
	void setStart(Node* val) { m_start = val; };
	void display() const;
	void insert(const double& val, const size_t& i);
	void erase(const size_t& i);
	double Sum() const;
	void reverseLinkedList();
};

class Bnode
{
private:
	double m_val;
	Bnode* m_right;
	Bnode* m_left;
	Bnode();
public:

	Bnode(const double& val);
	Bnode(const double& val, Bnode*, Bnode*);
	Bnode(const Bnode& node);
	double getVal() const { return m_val; }
	Bnode* getNodeRight() const { return m_right; }
	Bnode* getNodeLeft() const { return m_left; }
	double getValRight() const { return getNodeRight()->getVal(); }
	double getValLeft() const { return getNodeLeft()->getVal(); }
	~Bnode();
	void addnode(const double& val);
	void SetNodeToEmpty(const double& val);
	void SetNode(Bnode* Nodd);
	void setVal(const double& Nodd) { m_val = Nodd; }
	double Sum() const;
	void SortBranchFromNode(Bnode* startPoint, std::vector<double>& res) const;

	void Sort(std::vector<double>& out) const;


};
class BinaryTree
{
private:
	Bnode* m_root;
	void SortedListFromTree();
public:
	BinaryTree(const double& val);
	~BinaryTree();
	void Sort(std::vector<double>& out) const;
	void addNode(const double& val) const;
	void MetAGauche() const;
	double Sum() const;
};