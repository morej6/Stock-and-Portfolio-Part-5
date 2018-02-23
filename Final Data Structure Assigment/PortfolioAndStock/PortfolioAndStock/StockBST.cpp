#include "StockBST.h"

void StockBST::privateAdd(Node *& tree, Stock item)
{

	if (tree == NULL)
	{
		tree = new Node;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}
	else if (item.GetName() < tree->info.GetName())
	{
		privateAdd(tree->left, item);
	}
	else
	{
		privateAdd(tree->right, item);
	}
}

void StockBST::privateInorder( Node * tree)
{
	if (tree != NULL)
	{
		privateInorder(tree->left);
		
		std::cout << tree->info.GetName() << std::endl;
		privateInorder(tree->right);
	}

}

void StockBST::privatePreorder(Node * tree)
{
	if (tree != NULL)
	{
		
		std::cout << tree->info.GetName() << std::endl;
		
		privatePreorder(tree->left);
		privatePreorder(tree->right);
		
	}
}

void StockBST::privatePostorder(Node * tree)
{
	if (tree != NULL)
	{
		privatePostorder(tree->left);
		privatePostorder(tree->right);
		std::cout << tree->info.GetName() << std::endl;
	}
}

void StockBST::privateClear(Node *& tree)
{
	if (tree != NULL)
	{
		privateClear(tree->left);
		privateClear(tree->right);
		delete tree;

	}
	lenght = 0;
}

void StockBST::PrintTree(Node * tree, std::ostream & out)
{
	if (tree != NULL)
	{
		PrintTree(tree->left, out);
		out << tree->info;
		PrintTree(tree->right, out);
	}
}

void StockBST::CopyTree(Node *& copy, const Node * originalTree)
{
	if (originalTree == NULL)
		copy = NULL;
	else
	{
		copy = new Node;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}

}

bool StockBST::SearchTree(Node * tree, std::string name, double & share)
{
	if (tree != NULL)
	{
		if (tree->info.GetName() == name)
		{
			share = tree->info.GetShare();
			return true;
		}
		else if (tree->info.GetName() > name) {
			return SearchTree(tree->left, name, share);
		}
		else {
			return SearchTree(tree->right, name, share);
		}
	}
	return false;
}

StockBST::StockBST()
{
	root = NULL;
	lenght = 0;
}


StockBST::StockBST(const StockBST& rhs)
{
	lenght = rhs.lenght;
	if (rhs.root == NULL)
	{
		root = NULL;
	}
	CopyTree(root, rhs.root);
}
StockBST::~StockBST()
{
	Clear();
}

void StockBST::Clear()
{
	privateClear(root);
	root = NULL;
}

int StockBST::Size()
{
	return lenght;
}

void StockBST::Add(Stock s)
{
	privateAdd(root, s);
	lenght++;
}

void StockBST::Preorder()
{
	privatePreorder(root);
}

void StockBST::Inorder()
{
	privateInorder( root);
}

void StockBST::Postorder()
{
	privatePostorder(root);
}

bool StockBST::GetShares(std::string name, double & shares)
{
	return SearchTree(root, name, shares);
}

StockBST & StockBST::operator=(const StockBST & rhs)
{
	if (this->root == rhs.root)
	{
		return *this;
	}

	Clear();
	lenght = rhs.lenght;
	if (rhs.root == NULL)
	{
		root = NULL;
	}
	CopyTree(root, rhs.root);

}



std::ostream & operator<<(std::ostream & os, StockBST & ref)
{
	StockBST print;
	print.PrintTree(ref.root, os);
	return os;
}
