#include<iostream>
#include<iomanip>

using namespace std;


void juzhenReverse1()
{//����ת��
	int a[10][10];
	int b[10][10];
	int m, n;
	cout << "Enter mxn juzhen(m and n):" << endl;
	//����
	cin >> m >> n;
	cout << "Enter all elements:" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	//ת��
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			b[j][i] = a[i][j];
		}
	cout << endl << "juzhen a:";
	for (int i = 0; i < m; i++)
	{//���a����
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << right;
			cout << a[i][j];
		}
	}
	cout << endl << endl << "juzhen b:";
	for (int i = 0; i < n; i++)
	{//���b����
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << right;
			//���ﲻ��ʡ�ԣ���Ȼ����������ʽ�Ĺ������������õ�����
			cout << b[i][j];
		}
	}
}
void jzReverse(int**a,int m,int n) //����void jzReverse(int** &a,int m,int n)Ҳ��ʵ�� //ע�����ָ�����õ�д�������÷��ŵ�λ�á�int& **a�Ǵ����
{//�Ƿ���δ�õ�
	for (int i = 0; i < m;i++)
		for (int j = 0; j <n-(m-i) ; j++)
			//ע�������ѭ��������ת����˵��ת��һ���ϻ������ǣ��������ж�Ҫ����������i��0��m��ÿ��ת��Ԫ�صĸ���(������Ϊ��)�Ǵӵ�0����ʼ����0��ת��0������1��ת��1��...�Դ����ƣ���n-1�л�λn-1��Ԫ�ء�����j��ѭ������i�йأ���ÿ�еĻ�λ��Ŀ��λ�ú����йأ�����j��ѭ������i����
		{//ֻ�з����������������ᷢ��Խ��
			int tem = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tem;
		}
}
void juzhenReverse2()
{//����ת�ã���̬���飩
	int m, n;
	cout << "Enter mxn juzhen(m and n):" << endl;
	//����
	cin >> m >> n;
	int** a; //����ָ�루�����ά���飩
	a = new int* [m];// ��ָ�루ʹ��ָ�����飩
	cout << "Enter all elements:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(a + i) = new int[n];//ÿ����ָ��ָ���Ӧ���ٶѿռ䣨�γɾ������ݵĴ洢��Ԫ��
			//cin >> *(*(a + i) + j);//ע�⣬�����ﲻ�ܱ߿��ٱ����룬��Ϊ�������ݴ洢�ռ���ÿ��n����������������ʱ��һ�����������о���Ԫ�صġ�����һ��һ�е����룬���ٶ������ݿռ䣬������ٸ����ִ����롣�������������̫�鷳��
		}
	}
	for (int i = 0; i < m; i++)
	{//������ռ�������������
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			//*(a + i) = new int[n];
			cin >> *(*(a + i) + j);
		}
	}
	cout << "ԭ����Ϊ��";
	for (int i = 0; i < m; i++)
	{//�������
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << right << setw(3);
			cout << a[i][j] << "\t";
			//cout << *(*(a + i) + j) << "\t";
		}
	}
	
	cout << endl<<"ת�ú�ľ���Ϊ��";

	if (m == n)
	{//���������������о���ת��
		jzReverse(a, m, n);//����ֻ�з������a[i][j]��a[j][i]������������ȲŲ��ᷢ��Խ�������
		for (int i = 0; i < m; i++)
		{//�������
			cout << endl;
			for (int j = 0; j < n; j++)
			{
				cout << right << setw(3);
				cout << a[i][j] << "\t";
				//cout << *(*(a + i) + j) << "\t";
			}
		}
	}
	else
	{//�Ƿ��������б仯����Ȼ�÷������ڷ���Ҳ����
		for (int i = 0; i < n; i++)//�������
		{//�������(ʵ����δ����ת�ò�����ֻ������ı�Ϊת�ú��˳��)������ָ���ָ����ڴ�ռ���ȷ�����ˣ��������ڵײ����ת�ã�����Ҫ�ı���洢�ռ�ṹ��Ҳ������ı�ָ��ָ���ÿ����ָ����ָ��ռ��С����������⿪���¿ռ䡣���������д洢�ռ䲻�������£�ֻ�ܽ�������ϵĸı䣬��Ӧת�õ�Ҫ��
			cout << endl;
			for (int j = 0; j < m; j++)
			{
				cout << right << setw(3);//��������������������ʽ����Ч���ϸ�ѭ�����õĸ�ʽ������������ѭ����ʧЧ
				cout << a[j][i] << "\t";//ע����a[��][��]
				//cout << *(*(a + i) + j) << "\t";
			}
		}
	}
}