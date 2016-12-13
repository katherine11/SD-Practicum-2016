#include "Tree.h"

Tree::Tree()
{
	this->root = nullptr;
}

Tree::Tree(Node* root)
{
	this->root = root;
}

Tree::Tree(const Tree& tree)
{
	copy(tree);
}

Tree& Tree::operator=(const Tree& tree)
{
	if (this != &tree)
	{
		destroy();
	}

	copy(tree);

	return *this;
}

Tree::~Tree()
{
	destroy();
}

void Tree::addChild(Node* child)
{
	if (isLeaf(root))
	{
		root = child;
	}

	for (int index = 0; index < root->subNodes.size(); ++index)
	{
		//addChild(root->subNodes[index]);
	}

}

void Tree::removeChild(Node* child)
{
}

bool Tree::isLeaf(const Node *child)
{
	return this->root->subNodes.size() == 0;
}

void Tree::convertToTree(std::string treeStructure)
{
}

void Tree::copy(const Tree &tree)
{
	this->root = tree.root;
}

void Tree::destroy()
{
	delete this->root;
}
