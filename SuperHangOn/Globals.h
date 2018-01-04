#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "MemLeaks.h"
#include <assert.h>
#include "SDL/include/SDL_rect.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Useful typedefs ---------
typedef unsigned int uint;

// Deletes a buffer
#define RELEASE( x ) \
    {									  \
       if( x != nullptr )   \
       {						      \
         delete x;                  \
	     x = nullptr;             \
       }                      \
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	{                              \
       if( x != nullptr )              \
       {                            \
           delete[] x;                \
	       x = nullptr;                    \
		 }                            \
                              \
	 }

// Colors ------------------
#define WHITE SDL_Color({255,255,255,255})
#define GREY_ROAD SDL_Color({206,207,173,255})
#define GREY_DARK SDL_Color({140,138,140,255})
#define BROWN_DARK SDL_Color({206,207,140,255})
#define BROWN_LIGHT SDL_Color({239,239,173,255})
#define BLUE_SKY SDL_Color({140,239,239,255});

// Configuration -----------
#define SCREEN_SIZE 1
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 450
#define FULLSCREEN false
#define VSYNC true
#define TITLE "Super Hang-On"
#define BLINK_SLOW 0.6f
#define BLINK_FAST 0.2f
#define SWAP_ANIM 0.06f
#define ACCELERATION 35
#define IDLE_SPEED 90
#define MAX_SPEED 280
#define MAX_SPEED_OUT_OF_ROAD 110
#define SEGMENT_LENGTH 240
#define SMALL_RUMBLE_PROPORTION 0.03f
#define BIG_RUMBLE_PROPORTION 0.07f
#define ROAD_WIDTH 2100
#define MAX_X 5500.0f
#define CAMERA_DEPTH 0.35f
#define FPS 60

#endif //__GLOBALS_H__