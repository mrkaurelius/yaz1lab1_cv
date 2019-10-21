#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/text/ocr.hpp>

#include <iostream>
#include <vector>
#include <stdio.h>


int main(int argc, char const *argv[]) //argv: argument vector
{   

    // BUNU GELISTIRMEYI DUSUN
    const char *lang = "tur";
    const char *data_path = "/home/mrk1/gelistirme/yaz1lab1_cv/tesseract/tesseract-trainded";
    const char *char_whitelist = NULL;
    
    cv::Mat img;
    img = cv::imread("fisler/cropped/fis6.jpg");
    //cv::imshow("deneme",img);
    //cv::waitKey(0);

    cv::cvtColor(img,img,cv::COLOR_BGR2GRAY);
    
    std::string output_text;
    std::vector<cv::Rect> component_recs;
    std::vector<std::string> component_texts;
    std::vector<float> component_confidences;

    cv::Ptr<cv::text::OCRTesseract> ocr; 
    ocr = cv::text::OCRTesseract::create(data_path,lang,char_whitelist);
    
    
    std::string out = ocr->run(img,1);    

    //ocr->run(f->m_inpImg,output_text,&component_recs,&component_texts,&component_confidences,0);

    for (int i = 0; i < output_text.size(); i++)
    {
        std::cout << output_text[i] << ", "<< component_confidences[i] << ", "\
        <<component_recs[i].x << "," << component_recs[i].y << std::endl;
    }
    std::cout << out << std::endl;

    return 0;
}
