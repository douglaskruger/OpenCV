// *************************************************************************************
// Original Src: https://eximia.co/hello-opencv-with-c-using-visual-studio-2017-and-vcpkg/
// *************************************************************************************
// This was built under Windows 10 with Visual Studio Community Edition 2019 and VCpkg
// and OpenCV V4.5.3 an
// This simple program requires a Video Camera to function and will create three windows
// Original in color, second in black and white, and the third in 'canny' (outline)
// 23-Aug-2021
// *************************************************************************************
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl;

	cv::namedWindow("raw", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("canny", cv::WINDOW_AUTOSIZE);

	// Connect to the Video Capture Device
	cv::VideoCapture cap;
	cap.open(0);

	if (!cap.isOpened())
	{
		std::cerr << "Couldn't open video capture device." << std::endl;
		return -1;
	}

	cv::UMat bgr_frame, gray, canny;

	// Do Forever
	for (;;)
	{
		cap >> bgr_frame;
		if (bgr_frame.empty()) break;

		cv::imshow("raw", bgr_frame);

		cv::cvtColor(bgr_frame, gray, cv::COLOR_BGR2GRAY);
		cv::imshow("gray", gray);

		cv::Canny(gray, canny, 10, 100, 3, true);
		cv::imshow("canny", canny);

		char c = cv::waitKey(10);
		if (c == 27) break;
	}

	cap.release();
	
	return 0;
}