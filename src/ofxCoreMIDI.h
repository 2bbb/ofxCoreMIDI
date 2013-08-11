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
- (NSArray *)getDeviceList;
- (void)connectAllSources;
- (void)connect:(NSString *)deviceName;

@end

class ofxCoreMIDI {
public:
    void setReceiver(ofxCoreMIDIReceiver *receiver) {
        wrapper = [[PGMidiWrapper alloc] initWithMIDIReceiver:receiver];
    }
    
    vector<string> getDevices(bool verbose = false) {
        NSArray *deviceList = [wrapper getDeviceList];
        vector<string> devices;
        
        for(NSDictionary *device in deviceList) {
            if(verbose) {
                NSLog(@"%@", device);
            }
            NSString *deviceName = [device objectForKey:@"name"];
            devices.push_back([deviceName cStringUsingEncoding:NSUTF8StringEncoding]);
        }
        
        return devices;
    }
    
    void connect() {
        [wrapper connectAllSources];
    }
    
    void connect(string deviceName) {
        [wrapper connect:[NSString stringWithCString:deviceName.c_str()
                                            encoding:NSUTF8StringEncoding]];
    }
private:
    PGMidiWrapper *wrapper;
};