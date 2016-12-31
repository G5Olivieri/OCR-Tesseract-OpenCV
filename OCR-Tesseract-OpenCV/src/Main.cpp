/*
 *
Pra este exemplo é preciso colocar o caminho de uma imagem nos argumentos do programa.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    //cout <<" asdfdsa";                                      // Wait for a keystroke in the window

	 if( argc != 2)
	    {
	     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
	     return -1;
	    }
	       Mat image;
	 	    image = cv::imread(argv[1], IMREAD_COLOR);   // Read the file

	 	    if(! image.data )                              // Check for invalid input
	 	    {
	 	        cout <<  "Could not open or find the image" << std::endl ;
	 	        return -1;
	 	    }


	 	    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
	 	    imshow( "Display window", image );                   // Show our image inside it.

	 	    waitKey(0);



    return 0;
}
*/


/*
 *
 Este programa precisa ter algumas libs inclusas,
 vá em Teste2, Properties, C/C++ Build, settings
 Veja mais em:
 https://www.youtube.com/watch?v=9ksMjQ2sBSQ

#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
*/


#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main()
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("/home/wesley/Desktop/Golden_Globe_text_logo.png");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
