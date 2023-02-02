#include <CPString.h>

CPString::string Str;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");

    {
        uint8_t counter = 0;
        do
        {
            if(counter <= 0xF){Serial.print(0);}
            Serial.print(CPString::string(counter++,16));
            if(counter%32 == 0){Serial.println();}
            else{Serial.print(", ");}
        }
        while(counter);
    }

    Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");

    {
        int8_t counter = INT8_MIN;
        do
        {
            if(counter >= 0){Serial.print(' ');}
            if(abs(counter) <= 0xF){Serial.print(' ');}
            Serial.print(CPString::string(counter++,16));
            if(counter%16 == 0){Serial.println();}
            else{Serial.print(", ");}
        }
        while(counter != INT8_MIN);
    }

    Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");

    {
        uint16_t counter = 0;
        do
        {
            if(counter <= 0xF){Serial.print(0);}
            if(counter <= 0xFF){Serial.print(0);}
            if(counter <= 0xFFF){Serial.print(0);}
            Serial.print(CPString::string(counter++,16));
            if(counter%16 == 0){Serial.println();}
            else{Serial.print(", ");}
        }
        while(counter);
    }

    Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
}

void loop() {
  // put your main code here, to run repeatedly:

}