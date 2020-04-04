CXX = g++
CXXFLAGS = `pkg-config --cflags --libs opencv4`
# LDFLAGS = -L/usr/local/Cellar/opencv/4.1.1_2/lib/
# LDLIBS =  -lopencv_core -lopencv_highgui -lopencv_imgcodecs
CXXVERSION = -std=c++11

main: q1.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(CXXVERSION) $(LDFLAGS) $(LDLIBS)

clean :
	rm main
