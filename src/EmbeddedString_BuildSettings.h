#ifndef EMBEDDED_STRING_BUILD_SETTINGS_H
#define EMBEDDED_STRING_BUILD_SETTINGS_H

    #include <stdint.h>
    #include <stdlib.h>

    #include "EmbeddedString_CompileSetup.h"

    ///////////////////////////////////////////////////////////////////////////////////
    // Arduino IDE

    #ifdef ARDUINO
        #include <Arduino.h>
        #define PROGMEM_MACRO PROGMEM
    #endif

    ///////////////////////////////////////////////////////////////////////////////////
    // PSOC Creator

    #ifdef PSOC_CREATOR
    
        /*
        #ifdef __cplusplus
            extern "C" {
                #include "project.h"   
            }
        #else
            #include "project.h"
        #endif
        
        */
        
        #include <stdio.h>
        #include <stdint.h>

        #define PROGMEM_MACRO
    #endif

    ///////////////////////////////////////////////////////////////////////////////////
    // C++

    #ifdef __MACOS_X__
        #include <iostream>
        #include <chrono>

        #define PROGMEM_MACRO
    #endif

#endif//EMBEDDED_STRING_BUILD_SETTINGS_H