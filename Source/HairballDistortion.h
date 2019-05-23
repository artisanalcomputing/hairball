/*
  ==============================================================================

    HairballDistortion.h
    Created: 23 May 2019 8:32:03am
    Author:  accraze

  ==============================================================================
*/

#pragma once


class HairballDistortion
{
public:
    HairballDistortion();
    ~HairballDistortion();
    
    void processDistort (float* inAudio,
        float inDrive,
        float inRange,
        float inBlend,
        float inVolume,
        float* outAudio,
        int inNumSamplesToRender);
private:
};
