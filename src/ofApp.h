#pragma once

#include "ofMain.h"
#include "ofxOpenNI.h"

#define CAMERA_WIDTH 640
#define CAMERA_HEIGHT 480

class ofApp : public ofBaseApp{

    private:
        ofxOpenNI kinect;
        ofTrueTypeFont font;
        unsigned short distance;
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
