#kendisine sayigisi olan bir build yap
#src klasoru olustur

CC= g++ -Wall -Wextra
LDFLAGS= $(shell pkg-config --libs tesseract lept opencv)

#LIB=-L /usr/local/lib/*.1 
#3INC=-I /usr/local/include/opencv4

# kendine saygisi olan bir make dependecy yap
all: lepttsrct cvtsrct cvfpp exlepttsrct

lepttsrct: src/lept_tsrct.cpp
	$(CC) -o lepttsrct.exe src/lept_tsrct.cpp  $(LDFLAGS)

exlepttsrct: src/lept_tsrct_ex.cpp
	$(CC) -o exlepttsrct.exe src/lept_tsrct_ex.cpp  $(LDFLAGS)

cvtsrct: src/cv_tsrct.cpp
	$(CC) -o cvtsrct.exe src/cv_tsrct.cpp  $(LDFLAGS)	

cvfpp: src/cv_fpp.cpp
	$(CC) -o cvfpp.exe src/cv_fpp.cpp  $(LDFLAGS)		

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