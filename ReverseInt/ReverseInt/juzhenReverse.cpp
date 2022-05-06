#include<iostream>
#include<iomanip>

using namespace std;


void juzhenReverse1()
{//矩阵转置
	int a[10][10];
	int b[10][10];
	int m, n;
	cout << "Enter mxn juzhen(m and n):" << endl;
	//输入
	cin >> m >> n;
	cout << "Enter all elements:" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	//转置
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			b[j][i] = a[i][j];
		}
	cout << endl << "juzhen a:";
	for (int i = 0; i < m; i++)
	{//输出a矩阵
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << right;
			cout << a[i][j];
		}
	}
	cout << endl << endl << "juzhen b:";
	for (int i = 0; i < n; i++)
	{//输出b矩阵
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << right;
			//这里不能省略，虽然上面的输出格式改过，但不会作用到这里
			cout << b[i][j];
		}
	}
}
void jzReverse(int**a,int m,int n) //或者void jzReverse(int** &a,int m,int n)也能实现 //注意二重指针引用的写法，引用符号的位置。int& **a是错误的
{//非方阵未用到
	for (int i = 0; i < m;i++)
		for (int j = 0; j <n-(m-i) ; j++)
			//注意这里的循环条件，转置来说是转的一个上或下三角，是所有行都要操作，所以i从0到m，每列转换元素的个数(下三角为例)是从第0个开始，第0行转换0个，第1行转换1个...以此类推，第n-1行换位n-1个元素。所以j的循环数与i有关，即每列的换位数目和位置和行有关，这里j的循环需用i控制
		{//只有方阵才能这样，否则会发生越界
			int tem = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tem;
		}
}
void juzhenReverse2()
{//矩阵转置（动态数组）
	int m, n;
	cout << "Enter mxn juzhen(m and n):" << endl;
	//输入
	cin >> m >> n;
	int** a; //二重指针（构造二维数组）
	a = new int* [m];// 行指针（使用指针数组）
	cout << "Enter all elements:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(a + i) = new int[n];//每个行指针指向对应开辟堆空间（形成具体数据的存储单元）
			//cin >> *(*(a + i) + j);//注意，在这里不能边开辟边输入，因为开辟数据存储空间是每次n个，但是输入数据时是一次性输入所有矩阵元素的。除非一行一行的输入，开辟多少数据空间，输入多少个，分次输入。但这样输入操作太麻烦。
		}
	}
	for (int i = 0; i < m; i++)
	{//开辟完空间后输入具体数据
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			//*(a + i) = new int[n];
			cin >> *(*(a + i) + j);
		}
	}
	cout << "原矩阵为：";
	for (int i = 0; i < m; i++)
	{//输出数据
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << right << setw(3);
			cout << a[i][j] << "\t";
			//cout << *(*(a + i) + j) << "\t";
		}
	}
	
	cout << endl<<"转置后的矩阵为：";

	if (m == n)
	{//方阵可以用这个进行矩阵转置
		jzReverse(a, m, n);//这里只有方阵才能a[i][j]和a[j][i]互换，行列相等才不会发生越界情况。
		for (int i = 0; i < m; i++)
		{//输出数据
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
	{//非方阵从输出中变化，当然该方法对于方阵也可以
		for (int i = 0; i < n; i++)//按列输出
		{//输出数据(实际上未进行转置操作，只是输出改变为转置后的顺序)。由于指针的指向和内存空间是确定的了，若必须在底层进行转置，则需要改变其存储空间结构，也就是需改变指针指向和每个行指针所指向空间大小。则必须另外开辟新空间。所以在已有存储空间不变的情况下，只能进行输出上的改变，适应转置的要求
			cout << endl;
			for (int j = 0; j < m; j++)
			{
				cout << right << setw(3);//这里必须重新设置输出格式才生效，上个循环设置的格式，在跳出上面循环后失效
				cout << a[j][i] << "\t";//注意是a[行][列]
				//cout << *(*(a + i) + j) << "\t";
			}
		}
	}
}