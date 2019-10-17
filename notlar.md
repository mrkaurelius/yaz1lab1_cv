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
 - t4esseractin apisin incele
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

## Opencv / Image Processing
A general image processing operator is a function that takes one or more input images and produces an output image.

### Contrast of an Image
> contrast is the difference in luminance (photometric measure of the luminous intensity) or colour that makes an object (or its representation in an image or display) distinguishable.
### Saturation / Colorfullnes
> Colorfulness is the "attribute of visual perception according to which the perceived color of an area appears to be more or less chromatic (ne dedigi cok anlasilmiyor) the colorfulness evoked by an object depends not only on its spectral reflectance but also on the strenght of the illumination, and increases with the latter unless the brightness is very high
### Chroma
> Chroma is the "colorfulness of an area judged as proportion of the brightness of a similarly illuminated area that appears white or higly transmitting". As a result, Chroma is mostly only dependent on the spectral properities,  and as such is seen to descriive the _object color_. It is how different from a grey of the same lightness such an an object color appears to be
> in basic, degree of vividness of a color or how pure it is compared to its representative on the color spectrum

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
### gimp
### imagemagick