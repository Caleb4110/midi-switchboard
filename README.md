# Midi Switchboard
This is A MIDI controller I've specifically designed for the Hologram Electronics Chroma Console.
As some parameters are hidden behind a button press (or combination of two buttons pressed together), 
you cannot press them with your feet, which is essential on stage when playing a gig. 

This device allows parameters such as individual effect module volumes to be available directly via potentiometers,
and allows you to turn on and off individual modules using footswitches.

## How it works
Instead of using pre-written MIDI libraries for Arduino, I've written one myself that allows you to send MIDI signals over
the serial port (when connected up to a 5-pin DIN connector). 

The Arduino then reads potentiometer and switch values, and will only send messages when a value has been updated. 

### Potentiometers 
These control each effect modules volume allowing for quick adjustments without having to go into the second menu layer

### FootSwitches 
These allow you to switch between each effect for a module in a round robin fasion. This means no more kneeling down to change effect.
You can also hold down a footswitch turn off a preset, and then you are able to press it to turn it back on (similar function to the
module buttons on the Chroma Console unit itself).

## Further considerations
It would be nice to have footswitches turning modules on and off on each press, and being able to change which module's effect
is being toggled. 

Something else to note is this is quite customisable and could be adapted to control anything else with MIDI in capabilites. One 
could even add more controls relatively easily.