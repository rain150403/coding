/*
时间限制：1秒 空间限制：32768K

题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

//运行时间：1ms 占用内存：500K

//一种很聪明的实现方法
/*
//非递归 
//非递归也是一个基于递归的思想：
//左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
//最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
//即可，即使到达了左子树左子树也可以看出由左右子树组成的树还想右子树那样处理
 
//对于左子树回到了原问题，对于右子树，左子树的所有值都比右子树的根小可以暂时把他看出右子树的左子树
//只需看看右子树的右子树是否符合要求即可
*/

class Solution{
public:
	bool VerifySquenceOfBST( vector<int> sequence ){
		int length = sequence.size();
		if( length == 0 )
			return false;
		int i = 0;
		while( --length ){
			while( sequence[i++] < sequence[length] );
			while( sequence[i++] > sequence[length] );
			if( i < length )
				return false;
			i = 0;
		}
		return true;
	}
};
