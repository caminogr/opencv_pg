#include <opencv2/opencv.hpp>
#include <iostream>
 
using namespace std;

int main(int argc, char** argv)
{
	cv::Mat	src, dst;
 
	src = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
 
  // srcをdstへコピーする
  src.copyTo(dst);

  // ROIの範囲（長方形）を設定する
  // ROI: Region of Interest
  // * (x, y, width, height)で指定
  cv::Rect roi(50, 230, 400, 150);

  // 部分画像を生成
  // * 部分画像とその元画像は共通の画像データを参照するため、
  //   部分画像に変更を加えると、元画像も変更される。
	cout << "src:" << src << endl;
  // WHY: ここのsrcの使い方わかってない
  cv::Mat srcROI = src(roi);	// srcからroiの範囲で部分画像srcROIをつくる
  cv::Mat dstROI = src(roi); // dstからroiの範囲で部分画像dstROIをつくる

  // 部分画像srcROIをヒストグラム平坦化したものをdstROIへ書き込む
  cv::equalizeHist(srcROI, dstROI);

  cv::imshow("原画像src", src);
  cv::imshow("変換後画像dst", dst);	// dstROIの変更によってdstも変わっている
  cv::imshow("部分画像srcROI", srcROI);
  cv::imshow("部分画像dstROI", dstROI);

	cv::waitKey();
 
	return 0;
}
