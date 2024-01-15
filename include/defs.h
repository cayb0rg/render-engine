#include <ncurses.h>
#include <stdint.h>
#include <Vector2.h>
#include <Vector3.h>
#include <Vector4.h>
#include <Matrix22.h>
#include <Matrix33.h>
#include <Matrix44.h>

#define WH (LINES)
#define WW (COLS)
#define PI (3.141592653f)
#define FILL ("#")
#define EMPTY (".")

#define MAX(a, b) (((a)>(b))? (a) : (b))
#define MIN(a, b) (((a)<(b))? (a) : (b))
