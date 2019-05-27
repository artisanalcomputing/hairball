/*
  ==============================================================================

    HairballPanelBase.cpp
    Created: 26 May 2019 11:17:20pm
    Author:  accraze

  ==============================================================================
*/

#include "HairballPanelBase.h"

#include "HairballInterfaceDefines.h"

HairballPanelBase::HairballPanelBase(HairballAudioProcessor* inProcessor)
: mProcessor(inProcessor)
{
//    titleLabel.setText("HAIRBALL", dontSendNotification);
//    titleLabel.setBounds(getWidth() - (getWidth()/2) - 45, getHeight() - (getHeight()/2) - 30, 100, 30);
//    addAndMakeVisible (titleLabel);
}

HairballPanelBase::~HairballPanelBase()
{
    
}

void HairballPanelBase::mouseEnter(const MouseEvent& event)
{
    repaint();
}

void HairballPanelBase::mouseExit(const MouseEvent& event)
{
    repaint();
}

void HairballPanelBase::paint (Graphics &g)
{
//    if(isMouseOver(true)){
//        const Colour hoverColour = Colour(Colours::black).withAlpha(0.4f);
//
//        g.setColour(hoverColour);
//        g.fillAll();
//    }
    g.setColour(HairballColour_4);
    g.setFont(font_2);
    
    g.drawText(label, getWidth() - (getWidth()/2) - 45, getHeight() - (getHeight()/2) - 30, 200, 200, Justification::centred);
}
