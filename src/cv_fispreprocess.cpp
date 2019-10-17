#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>
#include <stdio.h>

class fpp // fis preprocess
{
private:
    /* data */
public:
    cv::Mat m_inpImg;
    cv::Mat m_outImg;

    fpp(/* args */);
    fpp(const char * s_imgPath);
    ~fpp();
    void inp2gray();
    void showScaledOut();
    void showScaledInp();

    void addBorder();
};

fpp::fpp(const char * s_imgPath)
{
    std::cout << "fp: " << s_imgPath << std::endl;
    m_inpImg = cv::imread(s_imgPath, cv::IMREAD_COLOR); // jpeg
    //imshow( "deneme", m_inpImg );
    //cv::waitKey(0);
}

fpp::fpp(/* args */)
{
    std::cout << "merhaba yalan dunya" << std::endl;
}

fpp::~fpp()
{
}

void fpp::inp2gray(){
    cv::cvtColor(m_inpImg,m_outImg, cv::COLOR_BGR2GRAY);
}

void fpp::showScaledOut(){
    cv::namedWindow("out", cv::WINDOW_NORMAL);
    cv::resizeWindow("out",1200,800);
    cv::imshow("out", m_outImg);
    cv::waitKey(0);
}
void fpp::showScaledInp(){
    cv::namedWindow("out", cv::WINDOW_NORMAL);
    cv::resizeWindow("out",1200,800);
    cv::imshow("out", m_inpImg);
    cv::waitKey(0);
}

void fpp::addBorder(){
    cv::Mat tmp;
    cv::copyMakeBorder(m_outImg,m_outImg,5,5,5,5,cv::BORDER_CONSTANT,0);
}

int main(int argc, char const *argv[]) //argv: argument vector
{   
    fpp *f;

    if (argc == 2)
    {
        // argv deki stringden dosyayi ac
        f = new fpp(argv[1]);
        if (f->m_inpImg.empty())
        {
            std::cout << "resim acilamadi" << std::endl;
            return -1;
        }
        
    }
    else
    {
        std::cout << "hatalı kullanım" << std::endl;
    }


    // !!! NELER YAPACAGINI DUSUN
    // best caseler uzerinden roi olusturup duzelt
    // sonra optimizasyona gec 
     
    // resize image roiyi bulduktan sonra 1.5 carpmak 
    // resmin boyutunu kucultmek basarimi arttiriyor
    cv::resize(f->m_inpImg,f->m_inpImg,cv::Size(),0.75,0.75);

    double alpha = 2; // simple contrast control
    int beta = -20; //simple brightness control

    //trackbar isini ayrı dosyada yap
    f->m_inpImg.convertTo(f->m_inpImg,-1,alpha,beta);
    f->showScaledInp();
    cv::waitKey(0);
    
    cv::bilateralFilter( f->m_inpImg,f->m_outImg,9,75,75 );
    f->inp2gray();

    cv::adaptiveThreshold( f->m_outImg,f->m_outImg,255,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY,115,4);
    cv::medianBlur(f->m_outImg,f->m_outImg,11);
    f->addBorder();
    cv::Canny(f->m_outImg,f->m_outImg,200,250);

    f->showScaledOut();
    cv::waitKey(0);
    
    return 0;
}
