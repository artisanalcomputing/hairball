/*
  ==============================================================================

    HairballParameterSlider.cpp
    Created: 26 May 2019 10:01:51pm
    Author:  accraze

  ==============================================================================
*/

#include "HairballParameterSlider.h"

HairballParameterSlider::HairballParameterSlider(AudioProcessorValueTreeState& stateToControl,
                                       const String& parameterId,
                                       const String& parameterLabel)
: juce::Slider(parameterLabel)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterId, *this));
}

HairballParameterSlider::~HairballParameterSlider()
{
    
}
