    
    
    #include "Event.hpp"
    #include <string>

    
    #ifdef __linux__
    
        #include <X11/Xlib.h>

    #endif



   XSetWindowAttributes  *SwuglX11EventAT(std::string *SwuglStringEventMaskWanted)
   {
    
        if (SwuglStringEventMaskWanted == nullptr)
        {
            XSetWindowAttributes TempObjAtter;
            TempObjAtter.event_mask = NoEventMask;
            return (&TempObjAtter);
        }

/// SwugkX11EventAT obj need 

       /*
        else if(*SwuglStringEventMaskWanted == "KeyBoard")
        {
        XSetWindowAttributes TempObjatter;
        TempObjatter.event_mask =  ;            



        }
        */

   }