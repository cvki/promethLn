#include"gsBlur.h"

using namespace cv;
using namespace std;

vector<vector<double>> kernel_data = { {0.0125786, 0.0251572, 0.0314465, 0.0251572, 0.0125786},
                                            {0.0251572, 0.0566038, 0.0754717, 0.0566038, 0.0251572},
                                            {0.0314465, 0.0754717, 0.0943396, 0.0754717, 0.0314465},
                                            {0.0251572, 0.0566038, 0.0754717, 0.0566038, 0.0251572},
                                            {0.0125786, 0.0251572, 0.0314465, 0.0251572, 0.0125786} };

void gauss_conv(const Mat& src, Mat& dst, const vector<vector<double>> &kernel)
{
    /*int border_x = KERNEL_SIZE / 2;
    int border_y = KERNEL_SIZE / 2;*/
    int step = 1;
    for (int img_y = 0; img_y < src.cols - KERNEL_SIZE; img_y+=step)
    {
        for (int img_x = 0; img_x < src.rows - KERNEL_SIZE; img_x += step)
        {
            //double sumx=0, sumy=0, sumz=0, avgx = 0, avgy = 0, avgz = 0;
            float sumx = 0, sumy = 0, sumz = 0;
            for (int kernel_y = 0; kernel_y < KERNEL_SIZE; kernel_y++)
            {
                for (int kernel_x = 0; kernel_x < KERNEL_SIZE; kernel_x++)
                {
                        uchar3 img_value = src.at<uchar3>(img_y + kernel_y, img_x + kernel_x);
                        double kernel_value = kernel_data[kernel_y][kernel_x];
                        sumx += img_value.x * kernel_value;
                        sumy += img_value.y * kernel_value;
                        sumz += img_value.z * kernel_value;
                }
            }

            //这里gauss核已经归一化了，所以不用再除了
			/*avgx = sumx / (KERNEL_SIZE * KERNEL_SIZE);
            avgy = sumy / (KERNEL_SIZE * KERNEL_SIZE);
            avgz = sumz / (KERNEL_SIZE * KERNEL_SIZE);*/
            // 向下取整并防止越界
            sumx = floor(sumx);
            sumy = floor(sumy);
            sumz = floor(sumz);
            if (sumx <= 0)
                sumx = 0;
            if (sumy <= 0)
                sumy = 0;
            if (sumz <= 0)
                sumz = 0;
			for (int kernel_y = 0; kernel_y < KERNEL_SIZE; kernel_y++)
            {
                for (int kernel_x = 0; kernel_x < KERNEL_SIZE; kernel_x++)
                {
                    uchar3* uptr = &dst.at<uchar3>(img_y + kernel_y, img_x + kernel_x);
                    uptr->x = sumx;
                    uptr->y = sumy;
                    uptr->z = sumz;
                }
            }
            //cout << "img_y:" << img_y << "\t" << "img_x:" << img_x << endl;
        }
        //cout << "img_y:" << img_y << endl;    //img_y=795出问题,img.rows=800,kernel_size=5（边界问题）
    }
}

//int main(int argc, char* argv[])
int main()
{
    Mat src = imread("..\\source\\picSc.jpg");
    //imshow("ss", src);
    Mat dst=Mat(src.rows, src.cols, CV_32FC3, Scalar(0, 0, 0));
    //cout <<"dst.rows:" << dst.rows << "\t" <<"dst.rows:"<< dst.cols << endl;  //rows=800,colos=1200
    /*imshow("img", src);
    waitKey(0);
    destroyAllWindows();*/

    Mat src1 = Mat(70,80, CV_32FC3);
    Mat dst1 = Mat(src1.rows, src1.cols, CV_32FC3, Scalar(90, 180, 260));

    //cout << "000" << endl;
    gauss_conv(src1, dst1, kernel_data);  
    //cout << "111" << endl;
    imshow("after gauss filter", dst1);
    waitKey(0);
    destroyAllWindows();
}