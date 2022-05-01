#ifndef CROSS_PLATFORM_STRING_BUILD_SETTINGS_H
#define CROSS_PLATFORM_STRING_BUILD_SETTINGS_H

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Arduino IDE

        #if defined(ARDUINO)
            #include <Arduino.h>

            #if defined(__avr__)
                #include <avr/pgmspace.h>
                #define PROGMEM_MACRO PROGMEM
            #elif defined(ESP32)
                #define PROGMEM_MACRO 
            #endif

            #define CPSTRING_VERSION "0.0.1"
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // PSoC Creator
    
        #if defined(PSOC_CREATOR)
            #include <string.h>
            #include <stdint.h>
            #define PROGMEM_MACRO
            #define CPSTRING_VERSION "0.0.1"
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Desktop C++
    
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
            #include <string>
            #include <sstream>
            #include <iostream>
            #define PROGMEM_MACRO
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Unknown System
    
        #if !defined(PROGMEM_MACRO)
            
            #error "Unknown System!!!"
            
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif//CROSS_PLATFORM_STRING_BUILD_SETTINGS_H
