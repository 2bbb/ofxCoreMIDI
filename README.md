# ofxCoreMIDI (OSX)

## How to use

1. Add CoreMIDI.framework to your project
2. Include ofxCoreMIDI/src ofxCoreMIDI/RCTMidiLib
3. Open Project Setting -> TARGETS -> Build Phases -> Compile Sources, and add flag "-x objective-c++" for all file of .cpp
4. Create subclass of ofxCoreMIDIReceiver.

## API

### ofxCoreMIDI

* void setReceiver(ofxCoreMIDIReceiver *receiver)

### ofxCoreMIDIReceiver (interface)

* void receiveMidiNote(int noteNumber, int velocity, int channel, bool isNoteOn)
* void receiveControlChange(int number, int data, int channel)
* void receivePolyKeyPress(int noteNumber, int press, int channel)
* void receiveChannelPress(int press, int channel)
* void receivePitchBend(int data, int channel)

## Update history

### 2013/08/05 ver 0.01 beta release

## License

MIT License.

## Author

* ISHII 2bit [bufferRenaiss co., ltd.]
* ishii[at]buffer-renaiss.com

# About "RCTMidiLib"

Copyright (c) 2011 recotana/osamu funada

http://recotana.com/

https://github.com/recotana/RCTMidiLib

