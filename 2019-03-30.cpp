#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int g_slider_position = 0;
int g_run = 1;
int g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide( int pos, void *) {
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
  if (!g_dontset)
    g_run = 1;
  g_dontset = 0;
}

int main(int argc, char** argv)
{
  cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
  g_cap.open(string(argv[1]));
  int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
  int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
  cout << "Video has " << frames << " frames of dimensions(" << tmpw << ", " << tmph << ")." << endl;

  cout << "g_slider_position " << g_slider_position <<  endl;
  cout << "&g_slider_position " << &g_slider_position <<  endl;

  cv::createTrackbar("Position", "example", &g_slider_position, frames, onTrackbarSlide);

  cv::Mat frame;
  for(;;) {

    if( g_run != 0 ) {
      cout << "g_run " << g_run <<  endl;
      cout << "frame.empty() " << frame.empty() <<  endl;

      g_cap >> frame; if(frame.empty()) break;
      int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
      g_dontset = 1;

      cv::setTrackbarPos("Position", "example", current_pos);
      cv::imshow( "example", frame );

      cout << "==== g_run ====" << g_run <<  endl;
			// g_run === 1 のときg_run-=1は0に →stop
      g_run-=1;
    }

    char c = (char) cv::waitKey(10);
    if( c == 's' ) // ステップ再生モード
      {g_run = 1; cout << "Single step, run = " << g_run << endl;}
    if( c == 'r' ) // 再生モード
      {g_run = -1; cout << "Run mode, run = " << g_run <<endl;}
    if( c == 27 )
      break;

  }
  return(0);
}
