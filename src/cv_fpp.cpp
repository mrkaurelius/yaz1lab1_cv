#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/text/ocr.hpp>

#include <iostream>
#include <vector>
#include <stdio.h>
#include <regex>

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
    void noiseReduction();
    void writeOutImg(const char * fileName);
    void writeInpImg(const char * fileName);
};

fpp::fpp(const char * s_imgPath)
{
    m_inpImg = cv::imread(s_imgPath, cv::IMREAD_COLOR); // jpeg
    std::cout << "file path path: " << s_imgPath << std::endl;
    std::cout << "kanal sayisi: " << m_inpImg.channels() << std::endl;

    //imshow( "constructor", m_inpImg );
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
    cv::cvtColor(m_inpImg,m_inpImg, cv::COLOR_BGR2GRAY);
}

void fpp::showScaledOut(){
    if (m_inpImg.empty())
    {
        std::cout << "out resmi yok" << std::endl;
    }
    std::cout << "kanal sayisi: " << m_inpImg.channels() << std::endl;
    cv::namedWindow("out", cv::WINDOW_NORMAL);
    cv::resizeWindow("out",1200,800);
    cv::imshow("out", m_outImg);
    cv::waitKey(0);
}
void fpp::showScaledInp(){
   
    std::cout << "kanal sayisi: " << m_inpImg.channels() << std::endl;
    std::cout << "size: " << m_inpImg.size() << std::endl;
    cv::namedWindow("inp", cv::WINDOW_NORMAL);
    cv::resizeWindow("inp",1200,800);
    cv::imshow("inp", m_inpImg);
    cv::waitKey(0);
}

void fpp::addBorder(){
    //cv::Mat tmp;
    cv::copyMakeBorder(m_outImg,m_outImg,10,10,10,10,cv::BORDER_CONSTANT,255);
}

void fpp::noiseReduction(){
    cv::Mat tmp;
}

void fpp::writeOutImg(const char * fileName){
    //cv::imwrite("path",img);
    std::string fpParam = "./cv-out/";
    fpParam.append(fileName);
    std::cout << fpParam << std::endl;
    cv::imwrite(fpParam,m_outImg);
}

void fpp::writeInpImg(const char * fileName){
    //cv::imwrite("path",img);
    std::string fpParam = "./cv-out/";
    fpParam.append(fileName);
    std::cout << fpParam << std::endl;
    cv::imwrite(fpParam,m_inpImg);
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

    // farklı reçeteler hazırla 
    // ocr'ı gelistiricek adımlar 
    // rescale to 300 dpi olayini iyi anlayana kadar bu adımı atla
    // fisin rotationundan emin ol 
    // resize ne kadar fark ettiyor onu incele
    f->writeInpImg("inp.jpg");
    cv::resize(f->m_inpImg,f->m_outImg,cv::Size(),1.25,1.25,cv::INTER_CUBIC); //etkili degil
    
    f->inp2gray();
    
    // noise removal
    cv::GaussianBlur(f->m_inpImg,f->m_outImg,cv::Size(7,7),10,10); //blur fark yarattı     

    // binarisation
    cv::adaptiveThreshold( f->m_outImg,f->m_outImg,255,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY,115,8);

    // borders 
    f->addBorder();

    f->writeOutImg("out.jpg");

    // rotation / deskewing leptonica ile daha rahat yapılailir ?

    
    return 0;
}

/*
    // resize image roiyi bulduktan sonra 1.5 carpmak 
    // resmin boyutunu kucultmek basarimi arttiriyor noise reduction adına
    cv::resize(f->m_inpImg,f->m_inpImg,cv::Size(),0.75,0.75);

    double alpha = 2; // simple contrast control
    int beta = -20; //simple brightness control

    //trackbar isini ayrı dosyada yap
    f->m_inpImg.convertTo(f->m_inpImg,-1,alpha,beta);
    f->showScaledInp();
    cv::waitKey(0);
    
    cv::bilateralFilter( f->m_inpImg,f->m_outImg,9,75,75 );
    f->inp2gray();

    cv::medianBlur(f->m_outImg,f->m_outImg,11);
    f->addBorder();
    cv::Canny(f->m_outImg,f->m_outImg,200,250);

    f->showScaledOut();
    cv::waitKey(0);
*/