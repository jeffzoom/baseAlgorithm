#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n = 0;
//const int N = 9e6;
//int q[N];
int tmp[] = { 0 };
//如果写int tmp[]没有初始化，会报错，说1个无法解析的外部命令
//其实更好的是下面这样
//int tmp[N];

void merge_sort(int q[], int l, int r)
{
	if (l >= r) return;

	int mid = (l + r) >> 1;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);

	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
	{
		if (q[i] < q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];

	for (i = l, j = 0; i <= r; i++, j++)  q[i] = tmp[j];//错误1：之前写成i <= mid
}  //上面这个for用了i <= r，这是要把所有的数都传一遍，合理

int main()
{
	//提交
	//cin >> n;
	//for (int i = 0; i < n; i++) cin >> q[i];

	//测试
	n = 6;
	int q[] = { 6, 2, 4, 1, 3, 5 };
	for (int i = 0; i < n; i++) cout << q[i] << " " ;
	cout << endl;

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++) cout << q[i] << " " ;
	cout << endl;
	system("pause");
	return 0;
}

