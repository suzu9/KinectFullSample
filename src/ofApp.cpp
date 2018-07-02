#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
    ofSetWindowShape(CAMERA_WIDTH * 2, CAMERA_HEIGHT);
    ofSetFrameRate(60);
    font.load("Arial.ttf", 20);
    
    // Kinectのセットアップ開始
    kinect.setup();
    kinect.setRegister(true);
    // 映像を左右反転
    kinect.setMirror(true);
    
    // 深度センサを追加
    kinect.addDepthGenerator();
    // カメラを追加
    kinect.addImageGenerator();
    // カメラと深度センサのズレを修正
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    // 骨格認識を追加
    kinect.addUserGenerator();
    // 認識可能な最大人数を設定
    kinect.setMaxNumUsers(1);
    // Kinectを開始
    kinect.start();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    // Kinectの更新
    kinect.update();
    
    // 深度情報のRawデータを取得
    unsigned short *depthData = kinect.getDepthRawPixels().getData();
    // マウスカーソルの位置の距離を取得
    distance = depthData[mouseY * CAMERA_WIDTH + mouseX];
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    // 深度情報の描画
    kinect.drawDepth(0, 0, CAMERA_WIDTH, CAMERA_HEIGHT);
    // カメラの描画
    kinect.drawImage(CAMERA_WIDTH, 0, CAMERA_WIDTH, CAMERA_HEIGHT);
    // 骨格情報の描画
    kinect.drawSkeletons(CAMERA_WIDTH, 0, CAMERA_WIDTH, CAMERA_HEIGHT);
    // 距離の表示
    ofSetColor(255, 127, 127);
    font.drawString(ofToString(distance), 20, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
