#include "../algos/linkedList.h"

Node::Node()
	:m_value(0.), m_next(nullptr)
{}
Node::Node(const double& val)
	: m_value(val), m_next(nullptr)
{}
Node::Node(const Node const* val)
	: m_value(val->getValue()), m_next(val->getNext())
{}
Node::~Node()
{
	delete m_next;
}

Node& Node::operator=(const Node& other)
{
	m_next = other.getNext();
	m_value = other.getValue();
	return *this;
}

Llist::Llist(const double& val)
	: m_start(new Node(val)), m_size(1)
{}
Llist::Llist(const Llist& val)
	: m_start(new Node(*(val.getStart()))), m_size(val.getSize())
{}
Llist::~Llist()
{
	delete m_start;
}
void fun(std::vector<Node*>& data)
{
	Node* beforeFirst = new Node(data[1]);
	Node* afterLast = new Node(data[2]);
	data[0]->setNext(data[2]);
	data[2]->setNext(data[1]);
	data[1]->setNext(data[3]);
}
Llist* Llist::swapPairs(Llist* head)
{
	/*24. Swap Nodes in Pairs
	Given a linked list, swap every two adjacent nodes and return its head.
	You may not modify the values in the list's nodes, only nodes itself may be changed.
    Given 1->2->3->4, you should return the list as 2->1->4->3.*/
	Llist* res = new Llist(*head);
	Node* beforeFirst = new Node();
	Node* afterLast = new Node();
	Node* tmp_firstToSwap = res->getStart();
	Node* tmp_lastToSwap = tmp_firstToSwap->getNext();
	Node* tmp_end = tmp_lastToSwap->getNext();
	std::vector<Node*> deadNodeStorage = { tmp_firstToSwap, tmp_firstToSwap ,tmp_lastToSwap, tmp_end }; // Tarantino's reference 
	fun(deadNodeStorage);
	head->display();
	while (tmp_firstToSwap != nullptr)
	{
		Node* tmp_start = res->getStart();
		tmp_lastToSwap->setNext(tmp_firstToSwap);
		tmp_firstToSwap->setNext(tmp_end);
		tmp_start->setNext(tmp_lastToSwap);// je bouge toute la liste 
		// Everyone to the right
		tmp_start = tmp_end;
		if (tmp_start != nullptr)
		    tmp_firstToSwap = tmp_start->getNext();
		if(tmp_firstToSwap != nullptr)
		    tmp_lastToSwap = tmp_firstToSwap->getNext();
		if(tmp_lastToSwap != nullptr)
		    tmp_end = tmp_lastToSwap->getNext();
	}
	//delete tmp_start;
	delete tmp_firstToSwap;
	delete tmp_lastToSwap;
	delete tmp_end;
	return res;
}
void Llist::addNode(const double& val)
{
	Node* tmp = m_start;
	while (tmp->getNext() != nullptr)
	{
		tmp = tmp->getNext();
	}
	Node* res = new Node(val);
	tmp->setNext(res);
	m_size++;
}

void Llist::display() const
{
	std::cout << "[ ";// << std::endl;
	Node* tmp = m_start;
	while (tmp != nullptr)
	{
		std::cout << tmp->getValue() << "; ";// << std::endl;
		tmp = tmp->getNext();
	}
	std::cout << " ] " << std::endl;
}

void Llist::insert(const double& val, const size_t& index)
{
	if (index >= m_size || index <= 0)
	{
		std::cout << "rank too high, will be inserted in the end" << std::endl;
		addNode(val);
		return;
	}
	Node* res = new Node(val);
	Node* tmp = m_start;
	if (tmp != nullptr)
	{
		size_t i(1);
		while (i <= index - 1 && tmp != nullptr)
		{
			tmp = tmp->getNext();
			i++;
		}
		Node* tmp_tmp = tmp->getNext();
		res->setNext(tmp_tmp);
		tmp->setNext(res);
	}
	else
		return;
}

void Llist::erase(const size_t& i)
{
	if (i > m_size)
		"Llist::erase its too high!! \n"; return;
	int count = 0;
	Node* tmp = this->getStart();
	while (count != i - 1)
	{
		tmp = tmp->getNext();
	}
	Node* nodeToErase = tmp->getNext();
	tmp->setNext(tmp->getNext()->getNext());
	delete nodeToErase;
	m_size--;
} 

double Llist::Sum() const
{
	return 0.0;
}

void Llist::reverseLinkedList()
{
	// pas testé en vrai et pas traité le cas vide ou presque
	Node* newNodeStarter(m_start);
	if (m_size <= 1)
		return;
	Node* preNodeIterator(m_start->getNext());
	Node* NodeIterator = preNodeIterator->getNext();


	int compteur = 0;

	while (compteur < m_size)
	{
		while (NodeIterator->getNext() != nullptr)
		{
			preNodeIterator = preNodeIterator->getNext();
			NodeIterator = preNodeIterator->getNext();
		}
		if (compteur == 0)
			newNodeStarter = NodeIterator;
		NodeIterator->setNext(preNodeIterator);
		preNodeIterator->setNext(nullptr);
	}
	m_start = newNodeStarter;
}

Bnode::Bnode()
	:m_val(0.), m_left(nullptr), m_right(nullptr)
{
}
Bnode::Bnode(const double& val)
	: m_val(val), m_left(nullptr), m_right(nullptr)
{
}
Bnode::Bnode(const double& val, Bnode* right, Bnode* left)
	: m_val(val), m_left(left), m_right(right)
{
	if (left->getVal() > right->getVal())
	{
		m_left = right;
		m_right = left;
	}
}
Bnode::Bnode(const Bnode& node)
	:m_val(node.getVal()), m_left(new Bnode), m_right(new Bnode)
{
	/*Bnode* m_left = new Bnode();
	Bnode* m_right = new Bnode(node.getValRight());*/
}
Bnode::~Bnode()
{
	delete m_right;
	delete m_left;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void Bnode::addnode(const double& val)
{
	if (this->getVal() >= val)
	{
		if (this->getNodeLeft())
		{
			this->getNodeLeft()->addnode(val);
			return;
		}
	}
	else
		if (this->getNodeRight())
		{
			this->getNodeRight()->addnode(val);
			return;
		}
	this->SetNodeToEmpty(val);
}
///////////////////////////////////////////////////////////////////////////////////////////////
void Bnode::SetNodeToEmpty(const double& val)
{
	if (this->getVal() >= val)
	{
		if (this->getNodeLeft())
		{
			std::cout << "Bnode::addnode -- the Left son must be null to add \n";
			return;
		}
		else
		{
			Bnode* tmp = new Bnode(val);
			this->SetNode(tmp);
		}
	}
	else
	{
		if (this->getNodeRight())
		{
			std::cout << "Bnode::addnode -- the Left son must be null to add \n";
			return;
		}
		Bnode* tmp = new Bnode(val);
		this->SetNode(tmp);
	}

}
///////////////////////////////////////////////////////////////////////////////////////////////
void Bnode::SetNode(Bnode* other)
{
	if (this->getVal() >= other->getVal())
		m_left = other;
	else
		m_right = other;
}
///////////////////////////////////////////////////////////////////////////////////////////////
double Bnode::Sum() const
{
	double res(m_val);
	if (this->getNodeLeft())
		res += getNodeLeft()->Sum();
	if (this->getNodeRight())
		res += getNodeRight()->Sum();
	return res;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void BinaryTree::SortedListFromTree()
{
	//std::vector<double> res;
	//std::vector<Bnode*> memoryNode;
	//Bnode* tmpNode(m_root);
	//while (tmpNode->getNodeLeft())
	//{
	//	memoryNode.push_back(tmpNode);
	//	tmpNode = tmpNode->getNodeLeft();
	//}
	//res.push_back(tmpNode->getValLeft());
	//if(!tmpNode->getNodeRight())
	//	res.push_back(tmpNode->getValRight());
	//std::vector<Bnode*>::reverse_iterator ritMemory = memoryNode.rbegin();
	//for (; ritMemory != memoryNode.end(); ++ritMemory)
	//{
	//	tmpNode = *ritMemory;

	//}
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void BinaryTree::MetAGauche() const
{
	// Left all 
	std::vector<double> res;
	std::vector<Bnode*> memoryNode;
	Bnode* tmpNode(m_root);
	while (tmpNode->getNodeLeft())
	{
		memoryNode.push_back(tmpNode);
		tmpNode = tmpNode->getNodeLeft();
	}

	res.push_back(tmpNode->getValLeft());
	if (!tmpNode->getNodeRight())
		res.push_back(tmpNode->getValRight());
	// take  move up and
	tmpNode = memoryNode[memoryNode.size() - 1];

}
///////////////////////////////////////////////////////////////////////////////////////////////
void Bnode::SortBranchFromNode(Bnode* startPoint, std::vector<double>& res) const
{
	// Left all 
	std::vector<Bnode*> memoryNode;
	Bnode* tmpNode(startPoint);
	while (tmpNode->getNodeLeft())
	{
		memoryNode.push_back(tmpNode);
		tmpNode = tmpNode->getNodeLeft();
	}
	if (tmpNode->getNodeLeft())
		res.push_back(tmpNode->getValLeft());
	if (!tmpNode->getNodeRight())
		res.push_back(tmpNode->getValRight());
	// take  move up and
	tmpNode = memoryNode[memoryNode.size() - 1];

}
void Bnode::Sort(std::vector<double>& out) const
{
	if (this->getNodeLeft())
		this->getNodeLeft()->Sort(out);
	out.push_back(this->m_val);
	if (this->getNodeRight())
		this->getNodeRight()->Sort(out);
}

BinaryTree::BinaryTree(const double& val)
	:m_root(new Bnode(val))
{
}

BinaryTree::~BinaryTree()
{
	delete m_root;
}
void BinaryTree::Sort(std::vector<double>& out) const
{
	if (m_root)
		m_root->Sort(out);
	else
		return;
}

void BinaryTree::addNode(const double& val) const
{
	Bnode* tmp = new Bnode(*m_root);
	if (m_root->getVal() >= val)
	{
		if (m_root->getNodeLeft() != nullptr)
		{
			//tmp->getNodeLeft()->setVal(val);
			m_root->getNodeLeft()->addnode(val);
			delete tmp;
		}

		else
		{
			Bnode* tpmp = new Bnode(val);
			m_root->SetNode(tpmp);
			delete tmp;
		}

	}
	else
		if (m_root->getNodeRight() != nullptr)
		{
			//m_root->getNodeRight()->setVal(val);
			m_root->getNodeRight()->addnode(val);
			delete tmp;
		}
		else
		{
			Bnode* tpmp = new Bnode(val);
			m_root->SetNode(tpmp);
			delete tmp;
		}

}

double BinaryTree::Sum() const
{
	return m_root->Sum();
}
