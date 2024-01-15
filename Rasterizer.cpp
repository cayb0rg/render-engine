#include "Rasterizer.h"

#include "defs.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix44.h"
#include "math.h"


inline static bool isPointInTriangle(int i, int j, const Vector2& v1, const Vector2& v2, const Vector2& v3)
{
    float wv1 = ((v2.y - v3.y) * (i - v3.x) +
        (v3.x - v2.x) * (j - v3.y)) /
        ((v2.y - v3.y) * (v1.x - v3.x) +
        (v3.x - v2.x) * (v1.y - v3.y));

    float wv2 = ((v3.y - v1.y) * (i - v3.x) +
        (v1.x - v3.x) * (j - v3.y)) /
        ((v2.y - v3.y) * (v1.x - v3.x) +
        (v3.x - v2.x) * (v1.y - v3.y));

    float wv3 = 1.0f - wv1 - wv2;

    int one = (wv1 < -0.001);
    int two = (wv2 < -0.001);
    int three = (wv3 < -0.001);

    //is the point in the triangle
    return ((one == two) && (two == three));
}

void Rasterizer::initializerFramebuffer(int width, int height)
{
    fb = new Framebuffer(width, height);
}

Rasterizer::Rasterizer(int width, int height):fb(nullptr) {
    initializerFramebuffer(width, height);
}

Rasterizer::~Rasterizer()
{
    delete fb;
}

void Rasterizer::rasterizeTriangle(const Vector2& v1, const Vector2& v2, const Vector2& v3)
{
    int minx, maxx;
    int miny, maxy;

    minx = MAX(0, MIN(v1.x, MIN(v2.x, v3.x)));
    miny = MAX(0, MIN(v1.y, MIN(v2.y, v3.y)));
    maxx = MIN(fb->getWidth(), (MAX(v1.x, MAX(v2.x, v3.x))));
    maxy = MIN(fb->getHeight(), (MAX(v1.y, MAX(v2.y, v3.y))));

    for (int j = miny; j < maxy; j++)
    {
        for (int i = minx; i < maxx; i++)
        {
            if (isPointInTriangle(i, j, v1, v2, v3))
            {
                // mvprintw(i, j, FILL); // Don't render to screen!
            }
            else
            {
                // mvprintw(i, j, EMPTY); // Don't render to screen!
            }
        }
    }
}
