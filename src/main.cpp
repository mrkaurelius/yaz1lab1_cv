#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>


#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdio.h>

class tsrctWrapper
{
private:
    tesseract::TessBaseAPI* TbApi;
    std::string sTestDataPath;
public:
    tsrctWrapper();
    tsrctWrapper(const char* _sTestDataPath);
    ~tsrctWrapper();
    std::string getImgOCRString_leptonica(const char* _sImgPath);
    int writeOCRoutputToFile(const char* _sFileName,const char* _sImgPath);

    //std::vector<std::string> vImgFilePaths;
};

tsrctWrapper::tsrctWrapper()
{
    TbApi = new tesseract::TessBaseAPI();
    if(TbApi->Init(NULL,"tur")){
        fprintf(stderr,"Tesseract init edilemedi\n");
        exit(1);
    } else {
        fprintf(stderr,"Tesseract testdata olmadan init edildi\n");
    }
}

tsrctWrapper::tsrctWrapper(const char* _sTestDataPath)
{
    TbApi = new tesseract::TessBaseAPI();
    if(TbApi->Init(_sTestDataPath,"tur")){
        fprintf(stderr,"Tesseract init edilemedi\n");
        exit(1);
    } else {
        fprintf(stderr,"Tesseract testdata ile init edildi\n");
    }
}

std::string tsrctWrapper::getImgOCRString_leptonica(const char *_sImgPath){
    //Open input image with leptonica libary
    // try escape
    Pix *image = pixRead(_sImgPath);
    std::cout<< _sImgPath << std::endl;
    TbApi->SetImage(image);
    std::string sOutText = TbApi->GetUTF8Text();
    pixDestroy(&image);
    return sOutText;
}

/*
int tsrctWrapper::writeOCRoutputToFile(const char* _sFileName,const char* _sImgPath){
    // try escape
    std::string sOCRout = getImgOCRString_leptonica(_sImgPath);
    //cpp da dosya islemleri nasil yapılıyor
    std::ofstream out(_sFileName);
    out << sOCRout;
    out.close();
    return 0;
}
*/

tsrctWrapper::~tsrctWrapper()
{
    // bunun dogru yolundan emin ol
    TbApi->End();
}

class cvfis
{
private:
    /* data */
public:
    cvfis(/* args */);
    ~cvfis();
};

cvfis::cvfis(/* args */)
{
}

cvfis::~cvfis()
{
}


int main()
{
    // opencv deki tesseractı kullan ve sonucları oncekliler ile karsılastir 
    // belirgin bir fark olmaszsa opencvninkini kullan 
    // opecv icin resmi isleyen ve ocr'a sokan bir wrapper class yaz
    const char *s_imgPath = "fisler/fis2.jpg";

    cv::Mat m_image;
    m_image = cv::imread(s_imgPath, 1); //demekki imread Mat objesi donuyor
    
    cv::Mat m_grayImage;
    cv::cvtColor(m_image, m_grayImage, cv::COLOR_BGR2GRAY);

    double d_thresh = 50;
    double d_maxValue = 170;

    cv::Mat m_filteredImg;

    
    cv::adaptiveThreshold(m_grayImage,m_filteredImg,180,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,11,12);
    
    cv::namedWindow("gray image",cv::WINDOW_NORMAL);
    cv::resizeWindow("gray image",750,600);
    cv::imshow("gray image",m_filteredImg);
    
    
    cv::waitKey(0);

    return 0;
}



    /* filtered ve normal resmin farkı 
    tsrctWrapper *tWrapperTrainded = new tsrctWrapper("/home/mrk0/gelistirme/yaz1lab1/opencv_tesseract/trained-data"); // olamayan objeye referans alırım bir dal 
    const char * s_filtered = "/home/mrk0/gelistirme/yaz1lab1/opencv_tesseract/fisler/fis2_filtered.jpg";
    const char * s_normal = "/home/mrk0/gelistirme/yaz1lab1/opencv_tesseract/fisler/fis2.jpg";

    tWrapperTrainded->writeOCRoutputToFile("filtered.txt",s_filtered);
    tWrapperTrainded->writeOCRoutputToFile("normal.txt",s_normal);
    delete tWrapperTrainded;
    */
    /*
    std::string outText = tWrapper->getImgOCRString_leptonica("fisler/fis.jpg");
    std::string outTextTrainded = tWrapperTrainded->getImgOCRString_leptonica("fisler/fis.jpg");
    std::cout << outText << std::endl;
    std::cout << outTextTrainded << std::endl;
    */

    /*
    tsrctWrapper *tWrapperTrainded = new tsrctWrapper("/home/mrk0/gelistirme/yaz1lab1/opencv_tesseract/trained-data"); // olamayan objeye referans alırım bir dal 
    tsrctWrapper *tWrapper = new tsrctWrapper(); // olamayan objeye referans alırım bir dal 
    
    
    tWrapperTrainded->writeOCRoutputToFile("trained.txt",sImgPath);
    tWrapper->writeOCRoutputToFile("untrainded.txt",sImgPath);

    delete tWrapper; // you must delete anything that been allocated with new
    delete tWrapperTrainded;
    */