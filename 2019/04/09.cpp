// Reference: http://cvwww.ee.ous.ac.jp/semi/opencv/#3.1

// #include <opencv2/opencv.hpp>

// int main(int argc, char** argv)
// {
  // // 画像をカクノウスルオブジェクトを宣言する
  // cv::Mat src, dst1, dst2, dst3, dst4;
  // src = cv::imread(argv[1]);

  // // 平均値フィルタ
	// // * Size(x, y)でx方向、y方向のフィルタサイズを指定する
  // cv::blur(src, dst1, cv::Size(100, 100));

  // // 中央値フィルタ
  // cv::medianBlur(src, dst2, 7);

	// // ガウシアンフィルタ
  // cv::GaussianBlur(src, dst3, cv::Size(7, 7), 0.0);

	// // バイラテラルフィルタ
  // cv::bilateralFilter(src, dst4, 20, 200, 20);

	// // ウィンドウに画像を表示する
	// cv::imshow("原画像", src);
	// cv::imshow("平均値フィルタ", dst1);
	// cv::imshow("中央値フィルタ", dst2);
	// cv::imshow("ガウシアンフィルタ", dst3);
	// cv::imshow("バイラテラルフィルタ", dst4);

	// cv::waitKey();

	// return 0;
// }


#include <opencv2/opencv.hpp>
 
int main(int argc, char** argv)
{
	// 画像を格納するオブジェクトを宣言する
	cv::Mat	src, dst1, dst2, dst3, dst4, dst5, dst6;
 
	// 画像ファイルから画像データを読み込む
	// * 第2引数に IMREAD_GRAYSCALE を指定すると、グレイスケール画像に変換する
  src = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

	// ラプラシアンフィルタ 二次微分によるエッジ検出
  cv::Laplacian(src, dst1, -1);
 
	// Sobelフィルタ 一次微分によるエッジ検出
  // x方向
	cv::Sobel(src, dst2, -1, 1, 0);
  // y方向
	cv::Sobel(src, dst3, -1, 0, 1);
 
	// Cannyフィルタ
	cv::Canny(src, dst4, 60.0, 150.0);
	
	// ウィンドウに画像を表示する
	cv::imshow("原画像", src);
	cv::imshow("ラプラシアンフィルタ", dst1);
	// cv::imshow("Sobelフィルタ x方向", dst2);
	cv::imshow("Sobelフィルタ y方向", dst3);
	// cv::imshow("Cannyフィルタ", dst4);
	
	cv::waitKey();
 
	return 0;
}
