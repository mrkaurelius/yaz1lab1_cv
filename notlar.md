# Ukte 
## opencv 
 - resmi opencvde isleyip tesseracta verebilirim yada opencv deki tesseractı kullanırım
 - resmi fisin sinirlarindan croplayip ocr'a ver 
 > dusundugunden daha zor
 > gaussian blur ?
 - ROI'leri tesseracta gonderme  (buyuk ihtimal bunu yapmayacagim)
 > east text detector  kotu performans sergiledi neden olacagini dusun (v4.1.1) buyuk ihtimal kullanmayacagim
 - resme border ekleme +
 - contrast ? kesinlikle birseyleri etkiliyor
 - bilateral filter
 - resizing image

 ## tesseract
 - kullandıgım tesseract kutuphanesinin v4 oldugundan lstm kullandigindan emin ol
 - https://stackoverflow.com/questions/28935983/preprocessing-image-for-tesseract-ocr-with-opencv
 > ocr icin zemin beyaz karatler siyah olmalı, arka planın renginin ocr'a etkisi 
 - satırların duzluguun ocr'ın cıktısına onemi, bunu nasil test edebiliriz?
 - 300 dpi ?

 ## C++
 - std veri yapılarını kullanmaya calis mesaha unordered hash map

# Notlar
 - eog ile fis resimleri incelenebilir
 - relative path kullanmaya calis

 ## C++
 ### statick cast
 ```code
   float f = 3.5; 
   int b = static_cast<int>(f); 
 ```

## opencv/image process
- denoising
- contrast enhancement 
- downsampling ?
- morphological operations ?

# Terminoloji
 - mask matrix: kernel
 - yazar kasa fisi: sales slip
  

# Utils

### ld_config
```sh
  $ pkg-config --libs --cflags opencv 
 ```
- --cflags pre-processor ve compile flaglarını dondurur 
- --libs aynı cflags gibi bu sefer link flagslarını dondurur
 
### file 

### imagemagick
 

 