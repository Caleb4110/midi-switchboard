#ifndef COMMON_H
#define COMMON_H

// MIDI Configuration
#define MIDI_CHANNEL 0 // 0-indexed channel number
#define NUM_MODULES 1

// Possible MIDI CC Message Types
enum MessageType {
  NoteOff,
  NoteOn,
  PolyAftertouch,
  ControlChange,
  ProgramChange,
  ChannelAftertouch,
  PitchWheel,
  SystemMessage
};

//=============== PIN NUMBERS ===============
// Module toggle switches
#define CHAR_SW_PIN 5
#define MOV_SW_PIN  6
#define DIFF_SW_PIN 7
#define TEX_SW_PIN  8

// Module volume pots
#define CHAR_VOL_PIN A0
#define MOV_VOL_PIN  A1
#define DIFF_VOL_PIN A2
#define TEX_VOL_PIN  A3
//===========================================

//=========== CONTROL CC NUMBERS ============
// Module toggle switches
#define CHAR_SW_CC 16
#define MOV_SW_CC  17
#define DIFF_SW_CC 18
#define TEX_SW_CC  19

// Module volume pots
#define CHAR_VOL_CC 73
#define MOV_VOL_CC  75
#define DIFF_VOL_CC 77
#define TEX_VOL_CC  79
//===========================================

#endif // COMMON_H
