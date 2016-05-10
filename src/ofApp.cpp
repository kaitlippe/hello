#include "ofApp.h"

#include "Poco/Base64Decoder.h"


int nextImage = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    
    setting.width  = w;
    setting.height = h;
    
    original.allocate(setting);
    
    //ksmrFX setup
    fx.setup(&original, setting);
    
    
    hello.load("hello.jpg");
    art.load("art.jpg");

}

//--------------------------------------------------------------
void ofApp::update(){    
    
    fx.getfxUnit(KSMR_FRAGFX_EDGEONTOP)->bEnable    = ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_FRINGE)->bEnable       = ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_SLANTSHIFT)->bEnable	= ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_TEXCHIP)->bEnable		= ofRandom(0,1);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (nextImage == 0) {
        original.begin();{
            ofSetColor(255);
            hello.draw(0, 0, w, h);
        }original.end();
    
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    }
    
    if (nextImage == 1) {
        original.begin();{
            ofSetColor(255);
            art.draw(0, 0, w, h);
        }original.end();
    
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    }
    

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
    if (nextImage == 0) {
        nextImage = 1;
    } else if (nextImage == 1) {
        nextImage = 0;
    }

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
