1.什么是回溯法？
在包含问题的所有解的解空间树中，按照深度优先搜索的策略，从根结点出发深度探索解空间树。当探索到某一结点时，要先判断该结点是否包含问题的解，如果包含，
就从该结点出发继续探索下去，如果该结点不包含问题的解，则逐层向其祖先结点回溯。（其实回溯法就是对隐式图的深度优先搜索算法）。 若用回溯法求问题的所有
解时，要回溯到根，且根结点的所有可行的子树都要已被搜索遍才结束。 而若使用回溯法求任一个解时，只要搜索到问题的一个解就可以结束。

2.回溯法的通用框架

在回溯法执行时，应当：
保存当前步骤，如果是一个解就输出；
维护状态，使搜索路径（含子路径）尽量不重复。
必要时，应该对不可能为解的部分进行剪枝(pruning)。

下面介绍回溯法的一般实现框架：

bool finished = FALSE; /* 是否获得全部解? */
backtrack(int a[], int k, data input)
{
    int c[MAXCANDIDATES]; /*这次搜索的候选 */
    int ncandidates; /* 候选数目 */
    int i; /* counter */
    if (is_a_solution(a,k,input))
    process_solution(a,k,input);
    else {
        k = k+1;
        construct_candidates(a,k,input,c,&ncandidates);
        for (i=0; i<ncandidates; i++) {
            a[k] = c[i];
            make_move(a,k,input);
            backtrack(a,k,input);
            unmake_move(a,k,input);
            if (finished) return; /* 如果符合终止条件就提前退出 */
        }
    }
}

利用回溯法解决问题

问题1：求一个集合的所有子集
问题2：输出不重复数字的全排列
问题3：求解数独——剪枝的示范
问题4：给定字符串，生成其字母的全排列
问题5：求一个n元集合的k元子集
问题6：电话号码生成字符串
问题7：一摞烙饼的排序
问题8：8皇后问题
总结与探讨




复制代码
　　对于其中的函数和变量，解释如下：

　　a[]表示当前获得的部分解；

　　k表示搜索深度；

　　input表示用于传递的更多的参数；

　　is_a_solution(a,k,input)判断当前的部分解向量a[1...k]是否是一个符合条件的解

　　construct_candidates(a,k,input,c,ncandidates)根据目前状态，构造这一步可能的选择，存入c[]数组，其长度存入ncandidates

　　process_solution(a,k,input)对于符合条件的解进行处理，通常是输出、计数等

　　make_move(a,k,input)和unmake_move(a,k,input)前者将采取的选择更新到原始数据结构上，后者把这一行为撤销。

 

　　其实回溯法框架就是这么简单，通过这个框架，足以解决很多回溯法问题了。不信？下面展示一下：

　　（由于后文所有代码均为在C中编写，因此bool类型用int类型代替，其中0为FALSE，非0为TRUE。）
