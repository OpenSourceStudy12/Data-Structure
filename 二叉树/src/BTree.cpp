#include <BTree.h>

BTree::BTree()
{
	cout << "input BTree data char\n";
	createBinTree(&root);
}
BTree::~BTree(){}

//创建二叉树(先序遍历)
void BTree:: createBinTree(BTreeNode **T)
{
	char ch;
	cin.get(ch);
	if(ch == ' ')
		*T = NULL;
	else
	{
		*T = new BTreeNode;
		(*T)->data = ch;
		createBinTree(&(*T)->lchild);
		createBinTree(&(*T)->rchild);
	}
}

/*
*函数名：getLchild
*功能：获得一个节点的左孩子
*入参：T:要找树的根节点指针，data:要查找的关键字
*返回值：找到返回左孩子的地址，未找到返回NULL;
*其他说明：无
*/
BTreeNode * BTree::getLchild(BTreeNode *T, Type data) //获得一个节点的左孩子
{
	BTreeNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data) //找到待查找节点，返回其左孩子
		return T->lchild;
	else //找到待查找节点，继续在左子树，右子树中找
	{
		p_lchild = getLchild(T->lchild, data);
		if (p_lchild != NULL) //左子树种找到则返回
			return p_lchild;
		else //左子树没有找到找右子树
		{
			p_rchild = getLchild(T->rchild, data);
			if (p_rchild != NULL) //右子树找到
				return p_rchild;
			else
				//右子树未找到
				return NULL;
		}
	}
}

BTreeNode *BTree::getRchild(BTreeNode *T, Type data)
{
	BTreeNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data)
		return T->rchild;
	else {
		p_lchild = getRchild(T->lchild, data);
		if (p_lchild != NULL)
			return p_lchild;
		else {
			p_rchild = getRchild(T->rchild, data);
			if (p_rchild != NULL)
				return p_rchild;
			else
				return NULL;
		}
	}
}

bool display(Type data)
{
	cout << data;
	return true;
}

//先序遍历
void BTree::Preorder(BTreeNode *T,VIST vist)
{
	if(!T)
		return;
	vist(T->data);
	Preorder(T->lchild,vist);
	Preorder(T->rchild,vist);
}

//中序遍历
void BTree::Inorder(BTreeNode *T,VIST vist)
{
	if(!T)
		return;
	Inorder(T->lchild,vist);
	vist(T->data);
	Inorder(T->rchild,vist);
}

//后序遍历
void BTree::Postorder(BTreeNode *T,VIST vist)
{
	if(!T)
		return;
	Postorder(T->lchild,vist);
	Postorder(T->rchild,vist);
	vist(T->data);
}


BiThrTree::BiThrTree()
{
	cout << "input BTree data char\n";
	createBinTree(&root);
}
BiThrTree::~BiThrTree(){}

BiThrNode * BiThrTree::pre = NULL;
//创建二叉树(先序遍历)
void BiThrTree::createBinTree(BiThrNode **T)
{
	char ch;
	cin.get(ch);
	if(ch == ' ')
		*T = NULL;
	else
	{
		*T = new BiThrNode;
		(*T)->data = ch;
		createBinTree(&(*T)->lchild);
		createBinTree(&(*T)->rchild);
	}
}

/*
*函数名：getLchild
*功能：获得一个节点的左孩子
*入参：T:要找树的根节点指针，data:要查找的关键字
*返回值：找到返回左孩子的地址，未找到返回NULL;
*其他说明：无
*/
BiThrNode * BiThrTree::getLchild(BiThrNode *T, Type data) //获得一个节点的左孩子
{
	BiThrNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data) //找到待查找节点，返回其左孩子
		return T->lchild;
	else //找到待查找节点，继续在左子树，右子树中找
	{
		p_lchild = getLchild(T->lchild, data);
		if (p_lchild != NULL) //左子树种找到则返回
			return p_lchild;
		else //左子树没有找到找右子树
		{
			p_rchild = getLchild(T->rchild, data);
			if (p_rchild != NULL) //右子树找到
				return p_rchild;
			else
				//右子树未找到
				return NULL;
		}
	}
}

BiThrNode *BiThrTree::getRchild(BiThrNode *T, Type data)
{
	BiThrNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data)
		return T->rchild;
	else {
		p_lchild = getRchild(T->lchild, data);
		if (p_lchild != NULL)
			return p_lchild;
		else {
			p_rchild = getRchild(T->rchild, data);
			if (p_rchild != NULL)
				return p_rchild;
			else
				return NULL;
		}
	}
}

//先序遍历
void BiThrTree::Preorder(BiThrNode *T,VIST vist)
{
	if(!T)
		return;
	vist(T->data);
	Preorder(T->lchild,vist);
	Preorder(T->rchild,vist);
}

//中序遍历
void BiThrTree::Inorder(BiThrNode *T,VIST vist)
{
	if(!T)
		return;
	Inorder(T->lchild,vist);
	vist(T->data);
	Inorder(T->rchild,vist);
}

//后序遍历
void BiThrTree::Postorder(BiThrNode *T,VIST vist)
{
	if(!T)
		return;
	Postorder(T->lchild,vist);
	Postorder(T->rchild,vist);
	vist(T->data);
}

//以线索链表为存储结构对二叉树遍历(中序)
bool BiThrTree::InOrderTraverse_Thr(BiThrNode *T,VIST vist)
{
	BiThrNode *p = T->lchild;//二叉树根节点
	while(p != T)
	{
		while(p->LTag == Link)//中序遍历访问的第一个节点
			p= p->lchild;
		if(!vist(p->data))
			return false;
		while(p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			vist(p->data);
		}
		p = p->rchild;
	}
	return true;
}

//二叉树的线索化
bool BiThrTree::InorderThreading(BiThrNode **Thrt,BiThrNode *T)
{
	if((*Thrt = new BiThrNode) == NULL)//头结点
		return false;

	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	if(!T)
	{
		(*Thrt)->lchild = (*Thrt);
		(*Thrt)->rchild = *Thrt;
	}
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T);
		pre->rchild = (*Thrt);
		pre->RTag = Thread;
		(*Thrt)->rchild = pre;
	}
	return true;
}

void BiThrTree::InThreading(BiThrNode *T)
{
	if(T)
	{
		InThreading(T->lchild);
		if(!T->lchild)
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if(!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);
	}
}
