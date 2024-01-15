#include "Framebuffer.h"
#include <memory.h>

Framebuffer::Framebuffer(int width, int height) :width(width), height(height) {
    recreate(width, height);
}

void Framebuffer::recreate(int width, int height) :width(width), height(height) {
    this->width = width;
    this->height = height;

    colorbuffer = new colorbuffer_t[width * height];
    depthbuffer = new depthbuffer_t[width * height];
}

void Framebuffer::clear(int clearColor) {
    memset(colorbuffer, clearColor, sizeof(colorbuffer_t) * width * height);
    memset(depthbuffer, MAX_DEPTH_VALUE, sizeof(depthbuffer_t) * width * height);
    // if pixel is less than MAX_DEPTH_VALUE, than it renders the pixel
}

void Framebuffer::setPixel(int x, int y, colorbuffer_t pixelcolor, depthbuffer_t, depth)
{
    int index = (y * width) + x;
    int index = (y * width) + x;
}

Framebuffer::~Framebuffer() {
    delete[] colorbuffer;
    delete[] depthbuffer;
}