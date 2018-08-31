# 树的分类
    1 二叉树  
        1.1 完全二叉树  
        1.2 满二叉树  
    2 平衡树  
        2.2 平衡树之 AVL 树  
        2.3 平衡树之红黑树  

# 一 树
- 基本概念
	- 节点  
	- 节点的度：节点拥有的分支树
	- 叶子节点：度为零的节点
	- 树的度：节点的度的最大值
	- 孩子：节点子树的根为该节点的孩子，该节点为子树的双亲
	- 兄弟：同一双亲的孩子互称兄弟
	- 堂兄弟：双亲在同一层的孩子堂兄弟
	- 深度：树的最大层次称为深度
	- 有序树：树中节点是有顺序的，不能互换
	- 无序树
- 存储结构  
	- 1 顺序存储结构
		- 双亲表示法
![双亲存储结构](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/双亲存储结构.png)
	- 2 链式存储结构  
		- 孩子链表表示法
![双亲存储结构](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/孩子链表存储结构.png)
		- 孩子兄弟链表表示法
![双亲存储结构](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/孩子--兄弟链表存储结构.png)
- 树的基本操作  
	- InitTree(&T);//构造空树  
	- DestroyTree(&T);//销毁树T  
	- CreateTree(&T,definition);//按definition定义构造树  
	- ClearTree(&T);//将树T清空  
	- TreeEmpty(&T);//判断树是否为空树  
	- TreeDepth(&T);//返回树的深度  
	- Root(&T);//返回T的根   
	- Value(T,cur_e);//若T存在,cur_e为T中某个节点，返回cur_e的值  
	- Assign(&T,cur_e,value);//将cur_e结点赋值为value  
	- Parent(T,cur_e);//若cur_e是T的非根节点，则返回cur_e的双亲，否则返回空    
	- LeftChild(T,cur_e);//若cur_e是T的非叶子节点，则返回cur_e的左孩子  
	- RightSibling(T,cur_e);//若cur_e有右兄弟，则返回它的右兄弟，否则返回空  
	- InsertChild(&T,&p,i,c);//p指向T中某结点，1<= i <=p所指结点的度+1，非空树C与T不相交，则插入c为T中p结点的第i棵子树  
	- DeleteChild(&T,&p,i);//p指向T中某结点，1<= i <= p结点的度，删除T中p节点的第i棵子树   
	- TraverseTree(T,VIST());//按某种次序对T的每个结点调用函数VIST()一次且至多一次，一旦VIST()失败，则操作失败  
	
# 二 二叉树
## 1.1 二叉树
- 定义：树中每个节点至多有两个子树，为有序树
- 性质：  
  1. 在二叉树的第 i 层上至多有 (2^(i-1)) 个节点(i >= 1)
  2. 深度为 k 的二叉树 至多有 (2^k-1) 个节点(k>=1)
  3. 任意二叉树，其度为零的节点数为n0,度为2的节点为n2,则n0 = n2 + 1。  
    
- 二叉树的存储结构  
  - 1 顺序存储结构  
![完全二叉树](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/完全二叉树.png)  
![完全二叉树存储](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/完全二叉树存储.png)  
	 顺序存储适合于完全二叉树  
![二叉树1](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/二叉树1.png)   
![二叉树的顺序存储](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/二叉树的顺序存储.png)   
  - 2 链式存储结构  
  	- 二叉链表  
![二叉树链表表示](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/二叉树链表表示.png)  
![二叉树链表存储结构](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/二叉树链表存储结构.png)
  	- 三叉链表  
  	在二叉链表节点中增加一个指向双亲的指针，就构成三叉链表  
![三叉树链表表示](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/三叉树链表表示.png)  
![三叉树链表存储结构](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/三叉树链表存储结构.png)
  	- 线索链表  
	
- 二叉树遍历  
- ![image1](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/image1.jpg)

  - 先序遍历：根--左--右  
  - 中序遍历：左--根--右  
  - 后序遍历：左--右--根

## 1.2 完全二叉树
- 定义：深度为k,有n个结点的二叉树，当且仅当其每一个结点都与深度为k的满二叉树中编号从1到n的结点一一对应时，称为完全二叉树
- 性质:
	1. 具有n个结点的完全二叉树的深度为[log2 n]+1.
	2. n个结点的完全二叉树，进行编号，若i=1,则结点i是根结点，若i>1,则其双亲结点标号为[i/2]，如果2i>n,则结点i无左孩子，否则其左孩子为2i. 如果2i+1>n,则结点i无右孩子，否则结点右孩子为2i+1

## 1.3 满二叉树
- 定义：深度为 k 且有 2^k-1 个结点的二叉树为满二叉树





 
