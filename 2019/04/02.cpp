// #include <opencv2/opencv.hpp>

// int main( int argc, char** argv ) {
  // cv::Mat img_rgb, img_gry, img_pyr, img_pyr2, img_cny;

  // cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE );
  // cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE );

  // img_rgb = cv::imread(argv[1]);

  // // cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
  // // cv::imshow("Example Gray", img_gry);
  // cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY);
  // cv::pyrDown( img_gry, img_pyr );
  // cv::pyrDown( img_gry, img_pyr2 );
  // cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );

  // // cv::Canny(img_gry, img_cny, 1, 100, 3, false);
  // cv::imshow("Example Canny", img_cny);

  // cv::waitKey(0);
// }

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv) {
  cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);

  cv::VideoCapture cap;

  cout << "argc" << argc << endl;
  cout << "argc == 1:" << (argc == 1) << endl;
  if (argc==1) {
    cap.open(0);
  } else {
    cap.open(argv[1]);
  }
  if (!cap.isOpened()) {
    std::cerr << "Couldn`t open capture." << std::endl;
    return -1;
  }
  

  cv::Mat frame;
  for(;;) {
    cap >> frame;
    if (frame.empty()) break;
    cv::imshow("Example", frame);
    if ((char) cv::waitKey(33) >= 0) break;
  }

  return 0;
}
