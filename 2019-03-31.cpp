// #include <opencv2/opencv.hpp>

// int main( int argc, char** argv) {
  // // コマンドラインで指定された画面を読み込む
  // cv::Mat image = cv::imread(argv[1], -1);

  // cv::namedWindow( "Example-in", cv::WINDOW_AUTOSIZE );
  // cv::namedWindow( "Example-out", cv::WINDOW_AUTOSIZE );

  // // 入力画面をウィンドウに表示する
  // cv::imshow( "Example-in", image );

  // // 平滑化した出力を保持する画像を作成する
  // cv::Mat out;

  // // 平滑化処理をする
  // cv::GaussianBlur( image, out, cv::Size(5,5), 3, 3 );
  // // cv::GaussianBlur(   out, out, cv::Size(5,5), 3, 3 );

  // // 平滑化した画像を出力ウィンドウに表示する
  // cv::imshow( "Example-out", out );

  // cv::waitKey( 0 );
// }
 
// #include <opencv2/opencv.hpp>

// int main( int argc, char** argv) {
  // cv::Mat img1, img2;

  // cv::namedWindow("Example-in", cv::WINDOW_AUTOSIZE );
  // cv::namedWindow("Example-out", cv::WINDOW_AUTOSIZE );

  // img1 = cv::imread( argv[1] );

  // cv::imshow("Example-in", img1);

  // cv::pyrDown(img1, img2);
  // cv::imshow("Example-out", img2);

  // cv::waitKey(0);
  // return 0;
// }

#include <opencv2/opencv.hpp>

int main( int argc, char** argv ) {
  cv::Mat img_rgb, img_gry, img_cny;

  cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE );
  cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE );

  img_rgb = cv::imread(argv[1]);

  cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
  cv::imshow("Example Gray", img_gry);

  cv::Canny(img_gry, img_cny, 1, 100, 3, false);
  cv::imshow("Example Canny", img_cny);

  cv::waitKey(0);
}
