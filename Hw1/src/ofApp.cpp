#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    counter = 0;
    ofBackground(255,255,255);
    sound.load("Loop2.wav");
    sound.play();
    sound.setLoop(true);
    
    gui.setup();
    gui.add(volume.set("volume",0.5,0.0,1.0));
    gui.add(decay.set("decay",0.5,0.0,1.0));
    
    fft = new float[218];
    for(int i=0 ; i < 218; i++){
        fft[i] = 0;
    }
    bands = 100;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    counter = counter + 0.033f;
    ofSoundUpdate();
    
    sound.setVolume(volume);
    soundSpectrum = ofSoundGetSpectrum(bands);
    for(int i =0; i< bands; i++){
        fft[i] *= decay;
        if(fft[i]< soundSpectrum[i]){
            fft[i] = soundSpectrum[i];
        }
    }
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    // ---------- hair lines
    ofFill();
    // alpha is usually turned off - for speed puposes.  let's turn it on!
    ofEnableAlphaBlending();
    ofSetColor(255,0,0,(int)(counter * 10.0f) % 255);   // red, variable transparent
    ofDrawEllipse(400,580,100,33);
    ofDisableAlphaBlending();

    for (int i = 0; i < 20; i++){
         ofSetColor(255,0,0);
         ofDrawLine(249,64 + (i*5),800, 250 + (i*10));
         
    for(int i = 0; i < bands; i++){
        ofDrawCircle(ofGetWidth()/3.5,ofGetHeight()/2,fft[i]*500);
        ofNoFill();
        ofSetColor(255, 130, 0);
        ofDrawCircle(ofGetWidth()/3.5,ofGetHeight()/2,fft[i]*800);
        ofSetColor(120, 40, 200);
        
        ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,fft[i]*500);
        ofNoFill();
        ofSetColor(255, 130, 0);
        ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,fft[i]*800);
        ofSetColor(120, 40, 200);
        
       
      
        
       
        }

        
        

       }
    
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
