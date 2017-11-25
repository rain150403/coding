/*本节的目标是研究常见的集合表示。也是搜索问题。

问题1：搜索一组数据，找到与特定项相关的信息。
搜索问题：在没有其它相关数据的情况下，如何存储一组整数？

具体问题来源：生成[0, maxval]范围内m个随机整数的有序序列，不允许重复。*/

//以下的各种实现都是依据这个c++类：
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


//方法三：
class IntSetList{
private:
	int n;
	struct node{
		int val;
		node *next;
		node( int v, node *p ) { val = v; next = p; }
	};
	
	node *head, *sentinel;
	node *rinsert( node *p, int t ){
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
		sentinel = head = new node( maxval, 0 );
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



//方法二：
class IntSetArray{
private:
	int n, *x;
public:
	IntSetArray( int maxelms, int maxval ){
		x = new int[1 + maxelms];
		n = 0;
		x[0] = maxval;
	}
	int size() { return n; }
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
			v[i] = x[i];
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
