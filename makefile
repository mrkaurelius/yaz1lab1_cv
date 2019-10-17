#kendisine sayigisi olan bir build yap
#src klasoru olustur

CC= g++ -Wall -Wextra
LDFLAGS= $(shell pkg-config --libs tesseract lept opencv)

#LIB=-L /usr/local/lib/*.1 
#3INC=-I /usr/local/include/opencv4

# kendine saygisi olan bir make dependecy yap
all: lepttsrct cvedgedetect 

lepttsrct: src/lept_tsrct.cpp
	$(CC) -o lpttsrct.exe src/lept_tsrct.cpp  $(LDFLAGS)

fpp: src/cv_fispreprocess.cpp
	$(CC) -o fpp.exe src/cv_fispreprocess.cpp  $(LDFLAGS)		

cvedgedetect: src/examples/canny_edge.cpp
	$(CC) -o cvedgedetect.exe src/examples/canny_edge.cpp  $(LDFLAGS)	

cvfindconteurs: src/examples/find_conteurs.cpp
	$(CC) -o cvfindconteurs.exe src/examples/find_conteurs.cpp  $(LDFLAGS)

cvdetectbounding: src/examples/detect_bounding.cpp
	$(CC) -o cvdetectbounding.exe src/examples/detect_bounding.cpp  $(LDFLAGS)		

cvtreshold: src/examples/threshold.cpp
	$(CC) -o cvtreshold.exe src/examples/threshold.cpp  $(LDFLAGS)		

cveetextdetect: src/examples/end_to_end_recognition.cpp
	$(CC) -o cveetextdetect.exe src/examples/end_to_end_recognition.cpp  $(LDFLAGS)		


clean: 
	rm *.exe