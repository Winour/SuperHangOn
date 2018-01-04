#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "Globals.h"

class Segment {

public:
    float wX, wY, wZ;   // World
    float sX, sY, sZ;   // Screen
    float scale, curve, cc;

    Segment() {
        wX = wY = wZ = sX = sY = sZ = scale = curve = cc = 0;
    }

    Segment(float _wX, float _wY = 0.0f, float _wZ = 0.0f, float _sX = 0.0f, float _sY = 0.0f, float _sZ = 0.0f, float _scale = 0.0f, float _curve = 0.0f, float _cc = 0.0f) :
        wX(_wX), wY(_wY), wZ(_wZ), sX(_sX), sY(_sY), sZ(_sZ), scale(_scale), curve(_curve), cc(_cc) {}

};


#endif // !__SEGMENT_H__