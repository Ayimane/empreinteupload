#include "mbed.h"
#include "Application.hpp"

DigitalInOut P13(p13);
DigitalInOut P14(p14);
DigitalOut P24(p24);
DigitalOut P25(p25);
int main() {
    
    Application app;
    app.run();//lance Application d'empreinte 
}