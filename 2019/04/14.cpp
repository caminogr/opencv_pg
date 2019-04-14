// Reference: http://cvwww.ee.ous.ac.jp/semi/opencv

// #include <opencv2/opencv.hpp>

// int main(void)
// {
	// // 画像を格納するオブジェクトを宣言する
	// // * CV_8UC3 : 8bit 3channel = カラー画像
  // cv::Mat image(400, 400, CV_8UC3);

	// // 画像を白色で塗りつぶす
	// // * Scalar(Blue, Green, Red)  RGB順ではないことに注意
	// image = cv::Scalar(255, 255, 255);

	// // 線を引く
	// // * line(画像, 始点座標, 終点座標, 色, 線幅, 連結)
  // cv::line(image, cv::Point(10, 10), cv::Point(390, 30), cv::Scalar(255, 0, 0), 1, cv::LINE_4);
	// cv::line(image, cv::Point(10, 20), cv::Point(390, 40), cv::Scalar(255, 0, 0), 1, cv::LINE_8);
	// cv::line(image, cv::Point(10, 30), cv::Point(390, 50), cv::Scalar(255, 0, 0), 1, cv::LINE_AA);

	// // 四角形を描く
	// // * rectangle(画像, 四角形, 色, 線幅, 連結)
	// // * 線幅 < 0 のときは四角形内を塗りつぶす
	// cv::rectangle(image, cv::Rect(10,  60, 100, 100), cv::Scalar(0, 255, 0),  1, cv::LINE_AA);
	// cv::rectangle(image, cv::Rect(120, 60, 100, 100), cv::Scalar(0, 255, 0), -1, cv::LINE_AA);

	// // 円を描く
	// // * circlee(画像, 中心座標, 半径, 色, 線幅, 連結)
	// cv::circle(image, cv::Point(60,  230), 50, cv::Scalar(0, 0, 255),  1, cv::LINE_AA);
	// cv::circle(image, cv::Point(170, 230), 50, cv::Scalar(0, 0, 255), -1, cv::LINE_AA);

	// // 楕円を描く
	// // * RotatedRect(中心座標, サイズ(x, y), 回転角度degree)
	// // * ellipse(画像, RotatedRect, 色, 線幅, 連結)
	// cv::RotatedRect rrect(cv::Point2f(60, 340), cv::Size(100, 50), 30);
	// cv::ellipse(image, rrect, cv::Scalar(255, 0, 255), 1, cv::LINE_AA);

	// // 円弧を描く
	// // * RotatedRect(中心座標, サイズ(x, y), 回転角度degree)
	// // * ellipse(画像, 中心座標, Size(x径, y径), 楕円の回転角度, 始点角度, 終点角度, 色, 線幅, 連結)
	// cv::ellipse(image, cv::Point(170, 340), cv::Size(50, 50), 0, 30, 180, cv::Scalar(255, 0, 255),  1, cv::LINE_AA);
	// cv::ellipse(image, cv::Point(280, 340), cv::Size(50, 50), 0, 30, 180, cv::Scalar(255, 0, 255), -1, cv::LINE_4);

	// cv::imshow("画像", image);

	// cv::waitKey();

	// return 0;
/* } */

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
 
int main(void)
{
	// 画像を格納するオブジェクトを宣言する
	// * CV_8UC3 : 8bit 3channel = カラー画像
	cv::Mat	image(400, 400, CV_8UC3);
 
	// 画像を白色で塗りつぶす
	// * Scalar(Blue, Green, Red)  RGB順ではないことに注意
	image = cv::Scalar(255, 255, 255);
 
	// 文字を描く
	// * putText(画像, "文字列", 座標, フォント, スケール, 色, 線幅, 連結)
	cv::putText(image, "Sample Text", cv::Point(10, 40), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 0, 0), 2, cv::LINE_AA);
 
	// ベースラインの位置を描く
	cv::line(image, cv::Point(10, 40), cv::Point(390, 40), cv::Scalar(0, 0, 255), 1, cv::LINE_4);
 
	// フォントの一覧を表示
	std::vector<std::string> font{
		"SIMPLEX", "PLAIN", "DUPLEX", "COMPLEX", "TRIPLEX", "COMPLEX_SMALL", "SCRIPT_SIMPLEX", "SCRIPT_COMPLEX"
	};
	for(int i = 0; i < font.size(); i++) {
		cv::putText(image, "FONT_HERSHEY_" + font[i], cv::Point(10, i * 40 + 80), i, 0.6, cv::Scalar::all(0), 1, cv::LINE_AA);
	}
 
	cv::imshow("画像", image);
 
	cv::waitKey();
 
	return 0;
}
