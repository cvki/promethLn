#include"gsBlur.h"

using namespace std;
using namespace cv;

__global__ void kernel_fun_gs(const Mat& img1,Mat& img2,Mat& img3) {
	//img1 from cpu,img3; img2 from gpu
	//1. cuda malloc img2,img3
	//2. copy img1 to img2
	//3. img2 <--> thread(x,y) inflection
	//4. cope img2 with gs kernel(make gs kernel a contant)
	//5. img3=copty(img2，from gpu to cpu)

	return;
}



int MAXV = 150;
int Light[] = { 10,20 };	//Light若为const，被调时会报错
Mat src,res,mtmp;

void onChange(int, void*) {//trackbar回调函数
	// 填充算子
	//mtmp = Mat::ones(img.size(), img.type());
	//相加的话会偏亮，颜色也由三色合成的强分量方向改变。注意这里必须用Light，也就是监听函数的参数
	mtmp = Scalar(Light[1], Light[0], Light[0]);	
	add(src, mtmp, res);	//加法，亮度增强
	imshow("show", res);//输出语句要放在回调函数中，否则拖拉bar时不起作用(因为回调函数会被反复执行，而trackbar函数只被调用一次)
}

void trackbar_test(Mat &img) {
	namedWindow("show", WINDOW_AUTOSIZE);
	mtmp = Mat::zeros(img.size(), img.type());	//这里必须给全局变量分配空间，否则出问题
	res = Mat::zeros(img.size(), img.type());
	src=img.clone();
	//建立TrackBar监听
	createTrackbar("bar", "show", Light, MAXV, onChange);
	//onChange(10, 0);	//初始时的bar值(light=10)，可加可不加
}


void onChange_pro(int val, void* img) {//trackbar回调函数
	Mat src = *((Mat*)img);
	Mat tmp = Mat::zeros(src.size(), src.type());
	Mat res = Mat::zeros(src.size(), src.type());
	tmp = Scalar(val,val,val);
	add(src, tmp,res);
	//namedWindow("res", WINDOW_AUTOSIZE);	//该处可以省略,window放在点击事件中
	imshow("res", res);
}

void trackbar_test_pro(Mat& img) {	//利用好creatTrackBar的参数传递
	int val=10; 
	namedWindow("res", WINDOW_AUTOSIZE);	//这个不能省略，且"res"要和下面的窗口名一致
	createTrackbar("bar", "res", &val, 150, onChange_pro, (void*)&img);
	//onChange_pro(10, &img);
}



int mainxx() {
	//string path = "..\\source\\picSc.jpg";	//注意路径的写法(相对路径时，加上当前入口路径)
	//Mat img = imread(path);	//可以设置读入方式，灰度图，HSV颜色空间，含透明通道等
	//if (img.empty()) {		//如果路径不对或者为全黑图
	//	cerr << "Maybe the img path is false." << endl;
	//	return -1;
	//}
	//D:\VS2019\workplace\cudaTest\source
	//namedWindow("img windows", WINDOW_FREERATIO);  //根据图片大小自动调整窗口大小
	//imshow("img windows", pic1);	//将pic1图片显示到img windows中
	//imshow("img", img);
	//waitKey(3000);	//显示3000ms,即3s
	//destroyAllWindows();	//关闭所有显示窗口


	// trackBarTest
	/*string path = "..\\source\\picSc.jpg";
	Mat img = imread(path);
	trackbar_test(img);
	waitKey(0);
	destroyAllWindows(); */


	//TrackBar优化
	/*string path = "..\\source\\picSc.jpg";
	Mat img = imread(path);
	trackbar_test_pro(img);*/

	//测试颜色
	/*Mat tmp = Mat::zeros(Size(100, 100),CV_8UC3);
	tmp = Scalar(40, 40, 200);
	imshow("tmp", tmp);*/



	waitKey(0);
	destroyAllWindows();

	return 0;
}





