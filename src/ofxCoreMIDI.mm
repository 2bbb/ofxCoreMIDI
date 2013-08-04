//
//  ofxCoreMIDI.m
//
//  Created by ISHII 2bit on 2013/08/04.
//
//

#import "ofxCoreMIDI.h"

@implementation PGMidiWrapper

- (instancetype)initWithMIDIReceiver:(ofxCoreMIDIReceiver *)_receiver {
    self = [super init];
    if(self) {
        receiver = _receiver;
        midi = [[RCTMidiLib alloc] init];
        [midi setDelegate:self];
        
        [midi connectAllSources];
    }
    return self;
}

#pragma mark -- delegate method : midi recieve process --
/*
 midi recieve  delegate method
 */
-(void)noteOnFlag:(BOOL)onFlag
           noteNo:(Byte)number
         velocity:(Byte)velocity
          channel:(Byte)channel
{
    receiver->receiveMidiNote(number, velocity, channel, onFlag);
}

-(void)controlChangeWithNumber:(Byte)number
                          data:(Byte)data
                      channnel:(Byte)channel
{
    receiver->receiveControlChange(number, data, channel);
}

-(void)polyKeyPressNoteNo:(Byte)noteNumber
                    press:(Byte)press
                  channel:(Byte)channel
{
    receiver->receivePolyKeyPress(noteNumber, press, channel);
}

-(void)channelPress:(Byte)press
            channel:(Byte)channel
{
    receiver->receiveChannelPress(press, channel);
}

-(void)pitchBendData:(UInt16)data
             channel:(Byte)channel
{
    receiver->receivePitchBend(data, channel);
}

#pragma mark -- delegate method : midi notification --
/*
 midi notification  delegate  method
 */

//MIDI Device Connect
-(void)connectMidiSource:(NSDictionary *)sourceProperty
                  device:(NSDictionary *)deviceProperty
{
    NSLog(@"  connect source: %@", sourceProperty);
    NSLog(@"          device: %@", deviceProperty);
}

//MIDI Device Disconnect
-(void)disconnectMidiSource:(NSDictionary *)sourceProperty
                     device:(NSDictionary *)deviceProperty
{
    NSLog(@"  disconnect source: %@", sourceProperty);
    NSLog(@"             device: %@", deviceProperty);
}

@end