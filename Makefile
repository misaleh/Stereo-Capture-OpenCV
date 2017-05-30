all:  capture

capture: capture_stereo.cpp
		g++ capture_stereo.cpp `pkg-config --cflags --libs opencv`  -o capture
clean:
		rm capture calib right*.png left*.png
run:
		./capture

		
