#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
using namespace cv;
using namespace std;

/* ЗАДАНИЕ:
 *Добавить в изображение шум ‘соль и перец’ рандомно.
 * Затем убрать шумы с усредняющим фильтом маской 15X15
 * 1)По пиксельно
 * 2) Готовыми функциями OpenCV. Перевести изображение 8 битный монохром
 * */
void add_salt_pepper(Mat in,int r){

    for(int i =0; i < in.rows; i++){//Рисует границы
        for(int k = 0; k <in.cols; k ++){
            int random = rand() % r+1;//Рандомное число от 1 до r
            if(random==1){
                in.at<uchar>(i,k) = 255;
            }
            if(random==2){
                in.at<uchar>(i,k) = 0;
            }

        }

    }
}
void my_box_filter(Mat in,int size){//Мой бокс фильтр
    int sum;

    for(int i =0; i < in.rows; i++){
        for(int k = 0; k <in.cols; k ++){
            for(int j = size/-2;j<=size/2;j++){
                for(int l = size/-2;l<=size/2;l++){
                    sum = sum+in.at<uchar>(i+j,k+l);

                }
            }
            in.at<uchar>(i,k) = sum/(size*size);
            sum = 0;

        }
    }
}


int main() {
    Mat src;
    src = imread("/home/tokjan/ClionProjects/Practic3_Salt-and-Pepper_filter/lena.jpg",CV_8U);
    imshow("lena_8bit",src);
   // Mat salt;
    Mat out;

    add_salt_pepper(src,25);//Мой метод добавления шума соль и перец, чем больше число,тем меньше шума
    imshow("salt_pepper",src);
    //medianBlur(src,out,5);// Готовый метод openCV

    boxFilter(src, out, -1, Size(15,15));// Готовый метод openCV,
    my_box_filter(src,15); //!Маска 15x15 слишком размывает рисунок!
    imshow("box_filter_OPENCV",out);
    imshow("MY_box_filter",src);

    waitKey(0);
    return(0);
}