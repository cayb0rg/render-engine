#ifndef INCLUDE_RASTERIZER_H
#define INCLUDE_RASTERIZER_H

#include "Framebuffer.h"

class Vector2;
class Vector3;
class Vector4;
class Matrix44;
class Rasterizer
{
    public:
        Rasterizer(int width, int height);
        virtual ~Rasterizer();

        void rasterizeTriangle(const Vector2& v1, const Vector2& v2, const Vector2& v3);

        inline Framebuffer* getFramebuffer() const {return fb;}
    private:
        Framebuffer* fb;
        void initializerFramebuffer(int width, int height);
};

#endif