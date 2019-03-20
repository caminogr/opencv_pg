// #include <opencv2/opencv.hpp>
//
// int main(void)
// {
//   // 動画ファイルを取り込むためのオブジェクトを宣言する
//   cv::VideoCapture cap;
//   cap.open("./sample_movie.mp4");
//
//   // 動画ファイルが開けたか調べる
//   if (cap.isOpened() == false) {
//     printf("ファイルが開けません。\n");
//     return -1;
//   }
//
//   // 画像をカクノウスルオブジェクトを宣言する
//   cv::Mat frame;
//
//   for (;;) {
//     // 1フレームを取り込む
//     cap >> frame; // capからframeへ
//
//     // 画像が空の時無限ループを抜ける
//     if (frame.empty() == true) {
//       break;
//     }
//
//     // ウィンドウに画像を表示する
//     cv::imshow("再生中", frame);
//
//     // 33ms待つ
//     cv::waitKey(1);
//   }
//
//   return 0;
// }

// ====================================


// #include "opencv2/highgui/highgui.hpp"
// #include "opencv2/imgproc/imgproc.hpp"
// #include <iostream>
// #include <fstream>
//
// using namespace std;
//
// int g_slider_position = 0;
// int g_run = 1;
// int g_dontset = 0;
// cv::VideoCapture g_cap;
//
// void onTrackbarSlide( int pos, void *) {
//   g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
//   if (!g_dontset)
//     g_run = 1;
//   g_dontset = 0;
// }
//
// int main(int argc, char** argv) 
// {
//   cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
//   g_cap.open(string(argv[1]));
//   int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
//   int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
//   int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
//   cout << "Video has " << frames << " frames of dimensions(" << tmpw << ", " << tmph << ")." << endl;
//
//   cout << "g_slider_position " << g_slider_position <<  endl;
//   cout << "&g_slider_position " << &g_slider_position <<  endl;
//
//   cv::createTrackbar("Position", "example", &g_slider_position, frames, onTrackbarSlide);
//
//   cv::Mat frame;
//   for(;;) {
//
//     if( g_run != 0 ) {
//
//       g_cap >> frame; if(frame.empty()) break;
//       int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
//       g_dontset = 1;
//
//       cv::setTrackbarPos("Position", "example", current_pos);
//       cv::imshow( "example", frame );
//
//       g_run-=1;
//
//     }
//
//     char c = (char) cv::waitKey(10);
//     if( c == 's' ) // ステップ再生モード
//       {g_run = 1; cout << "Single step, run = " << g_run << endl;}
//     if( c == 'r' ) // 再生モード
//       {g_run = -1; cout << "Run mode, run = " << g_run <<endl;}
//     if( c == 27 )
//       break;
//
//   }
//   return(0);
// }
//
// ===========================================
//
