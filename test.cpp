#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n = 0;
//const int N = 9e6;
//int q[N];
int tmp[] = { 0 };
//���дint tmp[]û�г�ʼ�����ᱨ��˵1���޷��������ⲿ����
//��ʵ���õ�����������
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

	for (i = l, j = 0; i <= r; i++, j++)  q[i] = tmp[j];//����1��֮ǰд��i <= mid
}  //�������for����i <= r������Ҫ�����е�������һ�飬����

int main()
{
	//�ύ
	//cin >> n;
	//for (int i = 0; i < n; i++) cin >> q[i];

	//����
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

