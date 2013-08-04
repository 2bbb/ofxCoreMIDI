#pragma once

#include "ofMain.h"
#include "ofxCoreMIDI.h"

class MyMidiReceiver : public ofxCoreMIDIReceiver {
public:
    void receiveMidiNote(int number, int velocity, int channel, bool isNoteOn) {
        cout << "receive: note " << number << ", velocity" << velocity << ", ch : " << channel << endl;
    }
};

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
private:
    ofxCoreMIDI midi;
    MyMidiReceiver receiver;
};
