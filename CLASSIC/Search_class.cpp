本节的目标是研究常见的集合表示。也是搜索问题。

问题1：搜索一组数据，找到与特定项相关的信息。
搜索问题：在没有其它相关数据的情况下，如何存储一组整数？

具体问题来源：生成[0, maxval]范围内m个随机整数的有序序列，不允许重复。

以下的各种实现都是依据这个c++类：
class IntSetImp{
public:
	//构造函数将集合初始化为空。该函数有两个参数，maxelements集合元素的最大个数，maxval集合元素的最大值（加一），
	//特定的实现可以忽略其中之一或者两者都忽略。
	IntSetImp( int maxelements, int maxval );  //构造函数
	void insert( int t );//插入，前提是集合中原先没有这个整数
	int size();   //返回当前的元素个数
	void report( int *v ); //按顺序将元素写入到向量v中
};



//方法六：
class IntSetBins{
private:
	int n, bins, maxval;
	struct node{
		int val;
		node *next;
		node( int v, node *p ) { val = v; next = p; }
	};
	
	node **bin, *sentinel;
	node *rinsert( node *p, int t ){
		if( p->val < t ){
			p->next = rinsert( p->next, t );
		}
		else if( p->val > t ){
			p = new node( t, p );
			n++;
		}
		return p;
	}
	
public:
	IntSetBins( int maxelms, int pmaxval ){
		bins = maxelms;
		maxval = pmaxval;
		bin =  new node *[bins];
		sentinel = new node( maxval, 0 );
		for( int i = 0; i < bins; i++ )
			bin[i] = sentinel;
		n = 0;
	}
	
	int size() { return n; }
	void insert( int t ){
		int i = t / ( 1 + maxval / bins );
		bin[i] = rinsert( bin[i], t );
	}
	void report( int *v ){
		int j = 0;
		for( int i = 0; i < bins; i++ )
			for( node *p = bin[i]; p != sentinel; p = p->next )
				v[j++] = p->val;
	}
};




//方法五：
class IntSetBitVec{
private:
	enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };
	int n, hi, *x;
	void set( int i ) { x[i>>SHIFT] |= ( 1 <<  ( i & MASK ) ); }
	void clr( int i ) { x[i>>SHIFT] &= ( 1 << ~( i & MASK ) ); }
	int test( int i ) { return x[ i >>SHIFT] & ( 1 << ( i & MASK ) ); }
public:
	IntSetBitVec( int maxelms, int maxval ){
		hi = maxval;
		x = new int[1 + hi / BITSPERWORD];
		for( int i = 0; i < hi; i++ )
			clr(i);
		n = 0;
	}
	int size() { return n; }
	void insert( int t ){
		if( test(t) )
			return;
		set(t);
		n++;
	}
	
	void report( int *v ){
		int j = 0;
		for( int i = 0; i < hi; i++ )
			if( test(i) )
				v[j++] = i;
	}
};



//方法四：

//二分搜索树，此方案避免了标准模板库所使用的复杂的平衡方案，因此稍微快一些，同时使用的空间也少一些。

//数据结构：二分搜索树

/*
优化方法：
1）一次性为所有节点分配空间（大大降低树的空间需求，从而大约能使运行时间降低三分之一）
2）将递归转化为迭代
3）使用哨兵节点（速度提高约25%）

*/
class IntSetBST{
private:
	int n, *v, vn;
	struct node{
		int val;
		node *left, *right;
		node( int v ) { val = v; left = right = 0; }
	};
	node *root;
	node *rinsert( node *p, int t ){
		if( p == 0 ){
			p = new node(t);
			n++;
		}else if( t < p->val ){
			p->left = rinsert( p->left, t );
		}else if( t > p->val ){
			p->right = rinsert( p->right, t );
		}// do nothing if p->val == t;
		return p;
	}
	
	void traverse( node *p ){
		if ( p == 0 )
			return;
		traverse( p->left );
		v[vn++] = p->val;
		traverse( p->right );
	}
	
public:
	IntSetBST( int maxelms, int maxval ) { root = 0; n = 0; }
	int size() { return n; }
	void insert( int t ) { root = rinsert( root, t ); }
	void report( int *x ) { v = x; vn = 0; traverse( root ); }
};

/*
链表和数组都是O（n^2）两者比较：
数组插入算法搜索整个序列，以找到目标值的合适插入位置，然后再移动比它大的值。
链表插入算法只需要完成第一部分工作，不需要移动。

既然，链表只完成一半的工作，为什么却需要两倍的时间呢？

部分原因是它需要两倍的内存：大链表必须将8字节的节点读入高速缓存以访问4字节的整数；
另一部分原因是数组访问数据时具有较好的预见性，而链表的访问模式则可能导致在内存空间来回跳跃。

*/

//方法三：链表（线性结构）

//如果事先不知道集合的大小，链表是首选的数据结构，而且链表还能省去插入时元素移动的开销

/*
优化方法：
1）消除递归
2）改变存储分配（构造函数只分配一个具有m个节点的块，insert根据需要使用这些空间，而不是每次插入操作分配一个新节点）
··存储分配的时间开销要比大多数简单运算高出两个数量级。我们把m次这样的开销运算减少到一次
··如果将多个节点分配为一个块，每个节点值消耗8个字节的空间（4个用于整数，4个用于指针）
··但如果分别为这些节点分配空间，每个节点都要消耗48字节的空间
*/
class IntSetList{
private:
	int n;
	struct node{
		int val;
		node *next;
		node( int v, node *p ) { val = v; next = p; }
	};
	
	node *head, *sentinel;
	node *rinsert( node *p, int t ){     //递归实现
		if( p->val < t ) {
			p->next = rinsert( p->next, t );
		}else if( p->val > t ) {
			p = new node( t, p );
			n++;
		}
		return p;
	}
	
public:
	IntSetList( int maxelms, int maxval ){
		sentinel = head = new node( maxval, 0 );    //这里也引入了一个哨兵节点，其值大于所有实际的值
		n = 0;
	}
	
	in size() { return n; }
	void insert( int t ) { head = rinsert( head, t ); }
	void report( int *v ){
		int j = 0;
		for( node *p = head; p != sentinel; p = p->next )
			v[j++] = p->val;
	}
};



//方法二：数组（线性结构）

//如果事先知道集合的大小，那么数组是一种比较理想的结构
class IntSetArray{
private:
	int n, *x;       //n当前元素个数，向量x保存整数本身
public:
	IntSetArray( int maxelms, int maxval ){
		x = new int[1 + maxelms];    //多分配一个元素的空间给哨兵用
		n = 0;
		x[0] = maxval;
	}
	
	int size() { return n; }
	
	//将哨兵元素maxval放在已排序元素的最后（maxval比集合中的任何元素都大），这样我们就能通过寻找一个更大的元素maxval来判断是否到达了列表的末尾，从而可以简化插入，使其运行得更快
	void insert( int t ){             
		for( int i = 0; x[i] < t; i++ )
			;
		if( x[i] == t )
			return n;
		for( int j = n; j >= i; j-- )
			x[j+1] = x[j];
		x[i] = t;
		n++;
	}
	void report(int *v){
		for( int i = 0; i < n; i++ )
			v[i] = x[i];     //将所有元素（哨兵除外）复制到输出数组中
	}
};




//方法一：

//标准模板库，构造函数忽略了它的两个参数

class IntSetSTL{
private:
	set<int> S;
public:
	IntSetSTL( int maxelms, int maxval ){}
	int size() { return S.size(); }
	void insert( int t ) { S.insert(); }  //insert不会在集合中放入重复元素
	void report( int *v ){
		int j = 0;
		set<int>::iterator i;
		for( i = S.begin(); i != S.end(); ++i )
			v[j++] = *i;			
	}
};


