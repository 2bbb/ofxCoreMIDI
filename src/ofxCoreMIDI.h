//
//  ofxCoreMIDI.h
//
//  Created by ISHII 2bit on 2013/08/04.
//
//

#import <Foundation/Foundation.h>

#include "ofMain.h"
#include "RCTMidiLib.h"

class ofxCoreMIDIReceiver {
public:
    virtual void receiveMidiNote(int noteNumber, int velocity, int channel, bool isNoteOn) {};
    virtual void receiveControlChange(int number, int data, int channel) {};
    virtual void receivePolyKeyPress(int noteNumber, int press, int channel) {};
    virtual void receiveChannelPress(int press, int channel) {};
    virtual void receivePitchBend(int data, int channel) {};
};

@interface PGMidiWrapper : NSObject <
    RCTMidiLibDelegate
> {
    RCTMidiLib *midi;
    ofxCoreMIDIReceiver *receiver;
}

- (instancetype)initWithMIDIReceiver:(ofxCoreMIDIReceiver *)receiver;

@end

class ofxCoreMIDI {
public:
    void setReceiver(ofxCoreMIDIReceiver *receiver) {
        wrapper = [[PGMidiWrapper alloc] initWithMIDIReceiver:receiver];
    }
private:
    PGMidiWrapper *wrapper;
};