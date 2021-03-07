#include <wiringPi.h>

struct Device {
    Device(int pinIn) : pin(pinIn){}
    int pin = 0;
} ;

struct InputDevice : public Device {
    InputDevice(int pinIn) : Device(pinIn){
        pinMode(pin, INPUT);
    }
};

struct OutputDevice : public Device {
    OutputDevice(int pinIn) : Device(pinIn){
        pinMode(pin, OUTPUT);
    }
};

struct Button : public InputDevice {
    Button(int pinIn) : InputDevice(pinIn) {}

    int getValue() {
         
        int returnvalue = digitalRead(pin);
        return returnvalue;
    }
    bool isPressed() {
        return getValue() == LOW;
    }

};

struct Led : public OutputDevice {
Led(int pinIn) : OutputDevice(pinIn){}
void turnOn() {
	digitalWrite(pin, HIGH);
}
void turnOff() {
	digitalWrite(pin, LOW);
}

void toggle() {
    digitalWrite(pin, !digitalRead(pin));
}

};