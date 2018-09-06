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
		是一种二叉链表表示 
		将树表示为孩子兄弟链表是可以转换为二叉树  
		森林和树可以和二叉树相互转换   
![孩子兄弟表示](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/孩子兄弟表示.png)  
![孩子兄弟链表表示](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/孩子兄弟链表表示.png)  
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
  		性质：有n个节点的二叉链表中必定存在n+1个空链域  
![二叉链表表示](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/二叉链表表示.png)  
![二叉链表存储结构](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/二叉链表存储结构.png)
  	- 三叉链表  
  	在二叉链表节点中增加一个指向双亲的指针，就构成三叉链表  
![三叉链表表示](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/三叉链表表示.png)  
![三叉链表存储结构](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/三叉链表存储结构.png)
  	- 线索链表  
![线索链表存储](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/线索链表存储.png) 	
	
- 二叉树遍历  
- ![image1](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/image1.png)

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

## 1.4 二叉排序（搜索/查找）树  
- 性质：  
	- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；   
	- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；   
	- 它的左、右子树也分别为二叉排序树  

## 1.5 平衡二叉树   
- 性质：  
	- 1.左右两棵子树的高度差不超过1
	- 2.左右两颗子树都是平衡二叉树
### 实现算法：   
### 1.5.1 平衡树之 AVL 树   
- AVL树是一种特殊类型的二叉树，它的每个结点都保存一份额外的信息：结点的平衡因子。
	- 结点的平衡因子 = 左子树的高度 - 右子树的高度  
	- 插入和删除操作都会导致AVL树的自我调整（自我平衡），使得所有结点的平衡因子保持为+1、-1或0。
		当子树的根结点的平衡因子为+1时，它是左倾斜的（left-heavy)。
		当子树的根结点的平衡因子为 -1时，它是右倾斜的(right-heavy)。
		一颗子树的根结点的平衡因子就代表该子树的平衡性。
		保持所有子树几乎都处于平衡状态，AVL树在总体上就能够基本保持平衡。
		AVL树的基本查找、插入结点的操作和二叉树的操作一样。但是，当向AVL树中插入一个结点后，还有一些额外的工作要做。首先，必须计算因插入操作对平衡因子带来的改变。其次，如果任何平衡因子变成了+/-2，就必须从这个结点开始往下重新平衡这颗树，这个重新平衡的过程就称为旋转。
	- AVL的旋转：  
		为方便理解在何时执行哪一种旋转，设x代表刚插入AVL树中的结点，设A为离x最近且平衡因子更改为2的绝对值的祖先。  
	   	- LL旋转：  
			如下图所示，当x位于A的左子树的左子树上时，执行LL旋转。
			设left为A的左子树，要执行LL旋转，将A的左指针指向left的右子结点，left的右指针指向A，将原来指向A的指针指向left。
			旋转过后，将A和left的平衡因子都改为0。所有其他结点的平衡因子没有发生变化。  
![AVL-LL旋转](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/AVL-LL旋转.png)  
	    - LR旋转：  
			当x位于A的左子树的右子树上时，执行LR旋转。
			设left是A的左子结点，并设A的子孙结点grandchild为left的右子结点。
			要执行LR旋转，将left的右子结点指向grandchild的左子结点，grandchild的左子结点指向left，A的左子结点指向grandchild的右子结点，再将grandchild的右子结点指向A，最后将原来指向A的指针指向grandchild。
			执行LR旋转之后，调整结点的平衡因子取决于旋转前grandchild结点的原平衡因子值。
			如果grandchild结点的原始平衡因子为+1，就将A的平衡因子设为-1，将left的平衡因子设为0。
			如果grandchild结点的原始平衡因子为0，就将A和left的平衡因子都设置为0。
			如果grandchild结点的原始平衡因子为-1，就将A的平衡因子设置为0，将left的平衡因子设置为+1。
			在所有的情况下，grandchild的新平衡因子都是0。所有其他结点的平衡因子都没有改变。
![AVL-LR旋转](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/AVL-LR旋转.png)  
		- RL旋转：  
			当x位于A的右子树的左子树上时，执行RL旋转。RL旋转与LR旋转是对称的关系。
			设A的右子结点为right，right的左子结点为grandchild。要执行RL旋转，将right结点的左子结点指向grandchild的右子结点，将grandchild的右子结点指向right，将A的右子结点指向grandchild的左子结点，将grandchild的左子结点指向A，最后将原来指向A的指针指向grandchild。
			执行RL旋转以后，调整结点的平衡因子取决于旋转前grandchild结点的原平衡因子。这里也有三种情况需要考虑：
			如果grandchild的原始平衡因子值为+1，将A的平衡因子更新为0，right的更新为-1；
			如果grandchild的原始平衡因子值为  0，将A和right的平衡因子都更新为0；
			如果grandchild的原始平衡因子值为-1，将A的平衡因子更新为+1，right的更新为0；
			在所有情况中，都将grandchild的新平衡因子设置为0。所有其他结点的平衡因子不发生改变。    
![AVL-RL旋转](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/AVL-RL旋转.png)    
		- RR旋转：   
			当x位于A的右子树的右子树上时，执行RR旋转。
			RR旋转与LL旋转是对称的关系。
			设A的右子结点为Right。要执行RR旋转，将A的右指针指向right的左子结点，right的左指针指向A，原来指向A的指针修改为指向right。
			完成旋转以后，将A和left的平衡因子都修改为0。所有其他结点的平衡因子都没有改变。    
![AVL-RR旋转](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/AVL-RR旋转.png)   
 
### 1.5.2 平衡树之红黑树 STL 

![RB_tree](https://github.com/OpenSourceStudy12/Data-Structure/blob/master/Image/RB_tree.png)    

	红黑树是每个节点都带有颜色属性的二叉查找树，颜色或红色或黑色。
- 性质：  
	1.节点是红色或黑色。  
	2.根节点是黑色。  
	3.每个叶节点（NIL节点，空节点）是黑色的。  
	4.每个红色节点的两个子节点都是黑色。(从每个叶子到根的所有路径上不能有两个连续的红色节点)  
	5.从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点。  

	这些约束强制了红黑树的关键性质: 从根到叶子的最长的可能路径不多于最短的可能路径的两倍长。结果是这个树大致上是平衡的。
	因为操作比如插入、删除和查找某个值的最坏情况时间都要求与树的高度成比例，这个在高度上的理论上限允许红黑树在最坏情况下都是高效的，
	而不同于普通的二叉查找树。  

时间复杂度：o(lgn) 
 
- 应用：  
	1.JAVA:TreeSet TreeMap  
	2.C++ : STL(set/map)  
	3.linux :虚拟内存的管理  

### 1.5.3 Treap

### 1.5.4 伸展树
 
  
## 1.6 B树  



 
