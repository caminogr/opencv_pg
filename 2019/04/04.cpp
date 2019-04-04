// Reference: https://github.com/tanaka0079/cpp/blob/master/opencv/image/GrabCut.cpp
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  // roi: Region Of Interest
	Rect roi(0, 0, 500, 350);				// 前景抽出したい範囲を指定
	Mat im, im2, mask, bg, fg;
  // WHY: ↓だとうごかない 相対パスの指定の仕方がだめそう
	// im = imread("../../lenna.jpg");
  im = imread(argv[1]);

	// グラブカット処理(前景と背景を分離)
	grabCut(im, im2, roi, bg, fg,1,GC_INIT_WITH_RECT);
	compare(im2, GC_PR_FGD, mask, CMP_EQ);	// 前景のマスク画像を作成
	im.copyTo(im2, mask);					// マスク画像を用いて入力画像から前景抽出
	imshow("TEST",im2);						// 前景を表示
	waitKey();								// キー入力待機
	return 0;
}

