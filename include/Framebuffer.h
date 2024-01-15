#ifndef INCLUDE_FRAMEBUFFER_H
#define INCLUDE_FRAMEBUFFER_H

#include "defs.h"

typedef uint8_t depthbuffer_t;
typedef uint16_t colorbuffer_t; // holds two bytes of information: the character and the color of the pixel 
#define MAX_DEPTH_VALUE 0xFF // because max bit of an 8 bit integer is 0xFF

class Framebuffer {
    public: 
        Framebuffer(int width, int height);
        int getWidth() {return width;}
        int getHeight() {return height;};
        ~Framebuffer();

        void recreate(int width, int height);

        void setPixel(int x, int y, colorbuffer_t pixelcolor, depthbuffer_t, depth);
    private:
        int width, height;

        depthbuffer_t* depthbuffer;
        colorbuffer_t* colorbuffer;

};

#endif