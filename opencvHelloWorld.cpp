#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opencv2/imgproc"
#include <highgui.h>

int main(int argc, char *argv[])
{
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    int i, j, k;

    if(argc<2){
        printf("Usage: main < image-file-name>\n\7");
        exit(0);
    }

    //load an image
    img = cvLoadIMage(argv[1]);
    if(!img){
        printf("Could not load image file: %s\n", argv[1]);
        exit(0);
    }

    heigh = img->height;
    width = img->width;
    step = img->widthStep;
    channels = img->nChannels;
    data = (uchar *)img->imageData;
    printf("Processing a %dx%d image with %d channels\n", height, width, channels);

    cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("mainWin", 100, 100);

    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            for (k = 0; k < channels; k++){
                data[i * step + j * channels + k] = 255 - data[i * step + j * channels + k];
            }
        }
    }

    cvShowImage("mainWin", img);

    cvWaitKey(0);

    cvReleaseImage(&img);

    return 0;
}
