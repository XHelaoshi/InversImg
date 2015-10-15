#include "highgui.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
/**
 * inverse image's color
 * @param  src source image,this will change source image
 * @return     0
 */
int inversImg(Mat &src)
{
	uchar pixValue;
	//seperate image's channel(1or3)
	switch (src.channels())
	{
	case 1:
		for (int i = 0; i < src.cols; i++) {
			for (int j = 0; j < src.rows; j++) {
				uchar &intensity = src.at<uchar>(j, i);
					// calculate pixValue
					intensity = 255 - intensity;
			}
		}
		break;
	case 3:
		for (int i = 0; i < src.cols; i++) {
			for (int j = 0; j < src.rows; j++) {
				Vec3b &intensity = src.at<Vec3b>(j, i);
				for (int k = 0; k < src.channels(); k++) {
					// calculate pixValue
					intensity.val[k] = 255 - intensity.val[k];
				}
			}
		}
		break;
	default:
		break;
	}
	printf("channals:%d\n", src.channels());
	return 0;
}
int main()
{
	Mat src = imread("E://1.jpg");
	Mat dst,dstt;
	cvtColor(src, dst, CV_BGR2GRAY);
	dstt = dst.clone();
	inversImg(dst);
	imshow("0", src);
	imshow("1", dstt);
	imshow("2", dst);
	waitKey(0);
	//system("pause");
	return 0;
}