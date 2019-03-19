// Reference: http://cvwww.ee.ous.ac.jp/semi/opencv/

#include <opencv2/opencv.hpp>
#include <iostream>
 
// int main(void)
// {
// 	// 画像を格納するオブジェクトを宣言する
// 	cv::Mat	image;
//   // cv::Mat → http://opencv.jp/cookbook/opencv_mat.html
// 
// 	// 画像ファイルから画像データを読み込む
// 	image = cv::imread("./lenna.jpg");
// 
// 	// 表示するウィンドウを準備する（省略可）
// 	// ウィンドウにつける名前は自由
// 	cv::namedWindow("imagewindow");
// 
// 	// ウィンドウに画像を表示する
// 	cv::imshow("imagewindow", image);
// 
// 	// 何かキーが押されるまで待つ
// 	cv::waitKey();
// 
// 	return 0;
// }
//
//
//

//
// int main(void)
// {
//   cv::Mat src, dst;
//   src = cv::imread("./lenna.jpg");
//
//   // グレイスケール画像に変換
//   cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
//
//
//   // 次元数（画像なので縦・横の2次元）
//   std::cout << "src dims: " << src.dims << std::endl; // 2
//   std::cout << "dst dims: " << dst.dims << std::endl; // 2
//   // チャンネル数
//   std::cout << "src channels: " << src.channels() << std::endl; // 3
//   std::cout << "dst channels: " << dst.channels() << std::endl; // 3
//
//   cv::imshow("原画像", src);
//   cv::imshow("変換画像", dst);
//
// 	// 画像を保存する
// 	// * ファイルフォーマットは拡張子で自動判別される
// 	cv::imwrite("変換画像.jpg", dst);
// 
// 	// 何かキーが押されるまで待つ
// 	cv::waitKey();
// 
// 	return 0;
// }

//
// #include <opencv2/opencv.hpp>
//
// int main(void)
// {
// 	// 画像を格納するオブジェクトを宣言する
// 	cv::Mat	src, dst;
//
// 	// 画像ファイルから画像データを読み込む
// 	src = cv::imread("./lenna.jpg");
//
// 	// 画像を反転する
// 	// * 0:上下反転, 1:左右反転
// 	cv::flip(src, dst, 0);
//	
// 	// ウィンドウに画像を表示する
// 	cv::imshow("原画像",   src);
// 	cv::imshow("反転画像", dst);
//
// 	// 何かキーが押されるまで待つ
// 	cv::waitKey();
//
// 	return 0;
// }
//
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  cv::Mat src_img = cv::imread("./lenna.jpg", 0);
  // cv::Mat src_img = cv::imread("./lenna.jpg", 0);
  // std::cout << "read:" << src_img.empty() << std::endl;
  if(src_img.empty()) return -1;
  // std::cout << "read:" << std::endl;

  // NOT演算
  cv::Mat dst_img = ~src_img;


  cv::namedWindow("src image", cv::WINDOW_AUTOSIZE|cv::WINDOW_FREERATIO);
  cv::namedWindow("dst image", cv::WINDOW_AUTOSIZE|cv::WINDOW_FREERATIO);
  cv::imshow("src image", src_img);
  cv::imshow("dst image", dst_img);
  cv::waitKey(0);
}
