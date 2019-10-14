#kendisine sayigisi olan bir build yap
#src klasoru olustur

CC= g++ -Wall -Wextra
LDFLAGS= $(shell pkg-config --libs tesseract lept opencv)

#LIB=-L /usr/local/lib/*.1 
#3INC=-I /usr/local/include/opencv4


# kendine saygisi olan bir make dependecy yap
all: cvtesseract cvedgedetect cvfindconteurs cvdetectbounding cvtreshold

cvtesseract: src/main.cpp
	$(CC) -o cvtesseract.exe src/main.cpp  $(LDFLAGS)

cvedgedetect: src/canny_edge.cpp
	$(CC) -o cvedgedetect.exe src/canny_edge.cpp  $(LDFLAGS)	

cvfindconteurs: src/find_conteurs.cpp
	$(CC) -o cvfindconteurs.exe src/find_conteurs.cpp  $(LDFLAGS)

cvdetectbounding: src/detect_bounding.cpp
	$(CC) -o cvdetectbounding.exe src/detect_bounding.cpp  $(LDFLAGS)		

cvtreshold: src/threshold.cpp
	$(CC) -o cvtreshold.exe src/threshold.cpp  $(LDFLAGS)		

cveetextdetect: src/end_to_end_recognition.cpp
	$(CC) -o cveetextdetect.exe src/end_to_end_recognition.cpp  $(LDFLAGS)		

deneme: src/cv_fispreprocess.cpp
	$(CC) -o cvfispreprocess.exe src/cv_fispreprocess.cpp  $(LDFLAGS)		
