#include"gsBlur.h"

//opencv测--成功

using namespace std;
using namespace cv;

int main_test_opencv_start() {
	string path = "..\\source\\picSc.jpg";	//注意路径的写法(相对路径时，加上当前入口路径)
	Mat pic1 = imread(path); 
	//D:\VS2019\workplace\cudaTest\source
	namedWindow("img windows", WINDOW_FREERATIO);  //根据图片大小自动调整窗口大小
	imshow("img windows", pic1);	//将pic1图片显示到img windows中
	waitKey(1000);	//显示1000ms
	destroyAllWindows();	//关闭所有显示窗口
	return 0;
}


