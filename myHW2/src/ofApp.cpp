#include "ofApp.h"


#define boid1 30
#define boid2 60
#define boid3 20


#define bgc ofColor(0,0,0,32)
#define color1 ofColor(255,182,193)
#define color2 ofColor(240,248,255)
#define color3 ofColor(147,242,147)

#define frate 100

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(frate);
	ofEnableAlphaBlending();
	ofSetBackgroundColor(0);
	ofSetBackgroundAuto(false);
	ofSetCircleResolution(64);
	ofHideCursor();
	ofSetBackgroundColor(bgc);
	active = true;

	
	birds1.reserve(boid1);
	for (int i = 0; i < boid1; i++) {
		birds1.push_back(*new bird(&birds1, i, color1, &birds2, &birds3, &nullBirds));
	}
	birds2.reserve(boid2);
	for (int i = 0; i < boid2; i++) {
		birds2.push_back(*new bird(&birds2, i, color2, &nullBirds, &birds3, &nullBirds));
	}
	birds3.reserve(boid3);
	for (int i = 0; i < boid3; i++) {
		birds3.push_back(*new bird(&nullBirds, i, color3, &nullBirds, &birds2, &nullBirds));
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (active) {
		for (int i = 0; i < birds1.size(); i++) {
			birds1[i].update();
		}
		for (int i = 0; i < birds2.size(); i++) {
			birds2[i].update();
		}
		for (int i = 0; i < birds3.size(); i++) {
			birds3[i].update();
		}
	
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(bgc);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	for (int i = 0; i < birds1.size(); i++) {
		birds1[i].draw();
	}
	for (int i = 0; i < birds2.size(); i++) {
		birds2[i].draw();
	}
	for (int i = 0; i < birds3.size(); i++) {
		birds3[i].draw();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case ' ':
		active = !active;
		break;
	case 'f':
		ofToggleFullscreen();
		break;
	case 's':
		ofShowCursor();
		break;
	case 'h':
		ofHideCursor(); 
		break;
	default:
		break;
	}
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
