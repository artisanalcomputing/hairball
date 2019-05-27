/*
  ==============================================================================

    HairballParameterSlider.h
    Created: 26 May 2019 10:01:51pm
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class HairballParameterSlider
:    public Slider
{
public:
    HairballParameterSlider(AudioProcessorValueTreeState& stateToControl,
                       const String& parameterId,
                       const String& parameterLabel);
    ~HairballParameterSlider();
private:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HairballParameterSlider);
};
