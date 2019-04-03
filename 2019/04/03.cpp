#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

  cv::VideoCapture capture(argv[1]);

  double fps = capture.get( cv::CAP_PROP_FPS );
  cv::Size size(
		// 型の指定の仕方わかってない
    (int) capture.get( cv::CAP_PROP_FRAME_WIDTH ),
    (int) capture.get( cv::CAP_PROP_FRAME_HEIGHT )
  );
	cout << "fps:" << fps << endl;

  cv::VideoWriter writer;
  // × CV_FOURCC
	// ○ cv::VideoWriter::fourcc
  writer.open(argv[2], cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

  cv::Mat logpolar_frame, bgr_frame;
  for(;;) {
    
    capture >> bgr_frame;
    if(bgr_frame.empty()) break;
    cv::imshow("Example", bgr_frame);

		// Log-Polor変換
    // 画像を対数極座標空間に写像
    cv::logPolar(
      bgr_frame,
      logpolar_frame,
      cv::Point2f(
        bgr_frame.cols/2,
        bgr_frame.rows/2
      ),
      40,
      cv::WARP_FILL_OUTLIERS
    );

		cv::imshow("Log_Polar", logpolar_frame);
		writer << logpolar_frame;

		char c = (char) cv::waitKey(33);
		if(c == 27) break;
  }

  capture.release();
  writer.release();
}
