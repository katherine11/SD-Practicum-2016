#pragma once
#include <vector>
#include <string>

struct Node
{
	int data;
	std::vector<Node> subNodes;	

};

class Tree
{
private:
	Node *root;
	void copy(const Tree &tree);
	void destroy();
public:
	Tree();
	Tree(Node *root);
	Tree(const Tree &tree);
	Tree &operator=(const Tree &tree);
	~Tree();

	void addChild(Node *child);
	void removeChild(Node *child);
	bool isLeaf(const Node *child);

	void convertToTree(std::string treeStructure);

};
