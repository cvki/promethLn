#include"gsBlur.h"

//opencv��--�ɹ�

using namespace std;
using namespace cv;

int main_test_opencv_start() {
	string path = "..\\source\\picSc.jpg";	//ע��·����д��(���·��ʱ�����ϵ�ǰ���·��)
	Mat pic1 = imread(path); 
	//D:\VS2019\workplace\cudaTest\source
	namedWindow("img windows", WINDOW_FREERATIO);  //����ͼƬ��С�Զ��������ڴ�С
	imshow("img windows", pic1);	//��pic1ͼƬ��ʾ��img windows��
	waitKey(1000);	//��ʾ1000ms
	destroyAllWindows();	//�ر�������ʾ����
	return 0;
}


