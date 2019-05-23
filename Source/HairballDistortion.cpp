/*
  ==============================================================================

    HairballDistortion.cpp
    Created: 23 May 2019 8:32:03am
    Author:  accraze

  ==============================================================================
*/

#include "HairballDistortion.h"
#include "JuceHeader.h"


HairballDistortion::HairballDistortion()
{
    
}

HairballDistortion::~HairballDistortion()
{
    
}

void HairballDistortion::processDistort(float* inAudio,
                            float inDrive,
                            float inRange,
                            float inBlend,
                            float inVolume,
                            float* outAudio,
                            int inNumSamplesToRender)
{
    for(int i = 0; i < inNumSamplesToRender; i++)
    {
        float cleanSig = inAudio[i];
        
        inAudio[i] *= inDrive * inRange;
        
        outAudio[i] = ((( (2.f / float_Pi) * atan(inAudio[i]) * inBlend) +
                      (cleanSig * (1.f - inBlend))) / 2.f) * inVolume;
    }
}
