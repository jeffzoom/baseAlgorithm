#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
using namespace std;

//const int N = 9e6;
//int q[N];

void quickSort(int q[], int l, int r)//l和r是本次排序卡着的边界，i和r是移动的标记点，递归
{
	if (l >= r) return;
	int i = l - 1, j = r + 1, x = q[(l+r)/2];//x是左边界//x不能再取左右边界了
	//怎么理解取中间点的时间复杂度会低于取起点呢？不是时间复杂度低了，而是如果取边界且整体基本有序的时候，快排退化为冒泡
	
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);//如果i小于j，说明不用换位置，错误1：写成了if (q[i] > q[j]) swap(q[i], q[j]);
	}
	quickSort(q, l, j);
	quickSort(q, j+1, r);
}
/*下面注释中l和r排序函数初始边界改为大写L和R，容易看
本来if (q[i] > q[j])这么写就不对，算法思想是首先i一直是在L左边界，j从右边界R和x比较，再移动直到找到q[j]<x，j停止
然后q[i]=x，q[j]<x，如果i在j的左侧，那么要交换顺序swap(q[i], q[j])，交换完之后i++，j--接着找，直到i和j相遇或i>j,就是i=j or i=j+1
那么此时i的左侧均小于等于x，j的右侧均大于等于x
	之后递归，先递归的给i左边排，再递归的给j右边排   {L  ji  R}

之后再给j的左侧排一个顺序，入口参数变为L和j
	在这个排序中，从L到j开始找没有排好接着排，就是递归，这就是递归；i j相遇或交错后
	之后先递归的给i左边排，再递归的给j右边排
	再递归

之后再给j的左侧排一个顺序，入口参数变为j+1和R
	在这个排序中，从j+1到R开始找，i j相遇或交错后
	之后先递归的给i左边排，再递归的给j右边排
	再递归

之后记住用j就好，用别的还得算参数，可能会有边界问题
*/

int main()
{
	int i = 0, n = 0;
	/*cout << "input the number:" << endl;
	scanf("%d", &n);
	cout << "input all number:" << endl;
	for (i = 0; i < n; i++) scanf("%d", &q[i]);*/
	
	n = 10;
	int q[10] = { 5, 3, 9, 4, 6, 1, 8,10,66,0 };
	cout << "input number is:" ;
	for (i = 0; i < n; i++) printf("%d ", q[i]); printf("\n");

	quickSort(q, 0, n-1);
	cout << "sort  number is:" ;
	for (i = 0; i < n; i++) printf("%d ", q[i]); printf("\n");

	system("pause");
	return 0;
}
