/*
  ==============================================================================

    HairballLookAndFeel.h
    Created: 26 May 2019 10:35:13pm
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "HairballInterfaceDefines.h"

class HairballLookAndFeel
:    public LookAndFeel_V4
{
public:
    HairballLookAndFeel()
    {
        //button text colours
        setColour(TextButton::buttonColourId, HairballColour_1);
        setColour(TextButton::textColourOnId, HairballColour_1);
        setColour(TextButton::textColourOffId, HairballColour_1);
    }
    virtual ~HairballLookAndFeel(){};
    
    //** sliders */
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, Slider& slider) override
    {
        
        auto radius = jmin (width / 2, height / 2) - 4.0f;
        auto centreX = x + width  * 0.5f;
        auto centreY = y + height * 0.5f;
        auto rx = centreX - radius;
        auto ry = centreY - radius;
        auto rw = radius * 2.0f;
        auto angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (HairballColour_8);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (HairballColour_8);
        g.drawEllipse (rx, ry, rw, rw, 1.0f);
        
        Path p;
        auto pointerLength = radius * 0.33f;
        auto pointerThickness = 2.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        g.setColour (Colours::whitesmoke);
        g.fillPath (p);
    }
private:
};
