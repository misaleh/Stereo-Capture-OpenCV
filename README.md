This code captures stereo images with OpenCV and also creates file stereo_calib.xml which used as an input for OpenCV stereo calibration example in addition with the stereo images.




To compile type `make`

To capture stereo images type `make run`, then press `a` to capture images and ESC bottom to close the program, **DO NOT TRY TO KILL IT FROM TERMINAL.** as stereo_calib.xml will not be written correctly. 

The output is stereo images named as left(number) right(number) starting from 0, and file stereo_calib.xml which is input to the calibration process.
