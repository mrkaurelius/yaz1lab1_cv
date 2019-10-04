#include <stdio.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

#include <opencv2/text/ocr.hpp>

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

int tsrctWrapper::writeOCRoutputToFile(const char* _sFileName,const char* _sImgPath){
    // try escape
    std::string sOCRout = getImgOCRString_leptonica(_sImgPath);
    //cpp da dosya islemleri nasil yapılıyor
    std::ofstream out(_sFileName);
    out << sOCRout;
    out.close();
    return 0;
}

tsrctWrapper::~tsrctWrapper()
{
    TbApi->End();
}

int main()
{
    //opencv deki tesseractı kullan ve sonucları oncekliler ile karsılastir 
    tsrctWrapper *tWrapperTrainded = new tsrctWrapper("/home/mrk0/gelistirme/yaz1lab1/opencv_tesseract/trained-data"); // olamayan objeye referans alırım bir dal 
    tsrctWrapper *tWrapper = new tsrctWrapper(); // olamayan objeye referans alırım bir dal 
    
    const char *sImgPath = "fisler/fis.jpg";
    
    tWrapperTrainded->writeOCRoutputToFile("trained.txt",sImgPath);
    tWrapper->writeOCRoutputToFile("untrainded.txt",sImgPath);

    delete tWrapper; // you must delete anything that been allocated with new
    delete tWrapperTrainded;
    return 0;
}

    
   
    /*
    std::string outText = tWrapper->getImgOCRString_leptonica("fisler/fis.jpg");
    std::string outTextTrainded = tWrapperTrainded->getImgOCRString_leptonica("fisler/fis.jpg");
    std::cout << outText << std::endl;
    std::cout << outTextTrainded << std::endl;
    */