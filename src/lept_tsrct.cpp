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
    std::string getImgOCRString(const char* _sImgPath);
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

std::string tsrctWrapper::getImgOCRString(const char *_sImgPath){
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
    std::string sOCRout = getImgOCRString(_sImgPath);
    std::ofstream out(_sFileName);
    out << sOCRout;
    out.close();
    return 0;
}


tsrctWrapper::~tsrctWrapper()
{
    // bunun dogru yolundan emin ol
    TbApi->End();
}


int main(int argc, char const *argv[]){
    // bunu kullanacagim
    // tesseract apisini incele 

    //tesseract::TessBaseAPI* TbApi = new tesseract::TessBaseAPI();
    
    if (argc != 2)
    {
        std::cout << "hatalı kullanım" << std::endl;
    }
    
    // 2 tane api cagir biri isimler icin biri fiyatlar icin

    const char *s_imgPath = argv[1];
    tsrctWrapper *tw_name = new tsrctWrapper("tesseract/tesseract-trainded/"); 
    tsrctWrapper *tw_number = new tsrctWrapper(); 

    std::cout << "name" << std::endl;
    std::cout << tw_name->getImgOCRString(s_imgPath) << std::endl;
    std::cout << "number" << std::endl;
    std::cout << tw_number->getImgOCRString(s_imgPath) << std::endl;

    delete tw_name;
    delete tw_number;

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
    std::string outText = tWrapper->getImgOCRString("fisler/fis.jpg");
    std::string outTextTrainded = tWrapperTrainded->getImgOCRString("fisler/fis.jpg");
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