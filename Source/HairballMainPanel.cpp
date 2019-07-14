/*
  ==============================================================================

    HairballMainPanel.cpp
    Created: 26 May 2019 11:17:35pm
    Author:  accraze

  ==============================================================================
*/

#include "HairballMainPanel.h"
#include "HairballParameters.h"

HairballMainPanel::HairballMainPanel(HairballAudioProcessor* inProcessor)
: HairballPanelBase(inProcessor)
{
    
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

    const int slider_size = 75;
    
    mDriveSlider.reset(new HairballParameterSlider(mProcessor->parameters, HairballParameterID[hParameter_Drive], HairballParameterLabel[hParameter_Drive]));
    mDriveSlider->setBounds(0, 0, slider_size, slider_size);
    mDriveSlider->setPopupDisplayEnabled(true, true, nullptr);
    addAndMakeVisible(*mDriveSlider);
    
    mRangeSlider.reset(new HairballParameterSlider(mProcessor->parameters, HairballParameterID[hParameter_Range], HairballParameterLabel[hParameter_Range]));
    mRangeSlider->setBounds(getWidth() - slider_size, 0, slider_size, slider_size);
    mRangeSlider->setPopupDisplayEnabled(true, true, nullptr);
    addAndMakeVisible(*mRangeSlider);
    
    mBlendSlider.reset(new HairballParameterSlider(mProcessor->parameters, HairballParameterID[hParameter_Blend], HairballParameterLabel[hParameter_Blend]));
    mBlendSlider->setBounds(0, getHeight() - slider_size, slider_size, slider_size);
    mBlendSlider->setPopupDisplayEnabled(true, true, nullptr);
    addAndMakeVisible(*mBlendSlider);
    
    mVolumeSlider.reset(new HairballParameterSlider(mProcessor->parameters, HairballParameterID[hParameter_Volume], HairballParameterLabel[hParameter_Volume]));
    mVolumeSlider->setBounds(getWidth() - slider_size, getHeight() - slider_size, slider_size, slider_size);
    mVolumeSlider->setPopupDisplayEnabled(true, true, nullptr);
    
    addAndMakeVisible(*mVolumeSlider);
    addMouseListener(this, true);

}

HairballMainPanel::~HairballMainPanel()
{
    removeMouseListener(this);
}


void HairballMainPanel::mouseEnter(const MouseEvent& event)
{
    if (event.eventComponent == &*mDriveSlider) {
        label = "DRIVE";
    } else if (event.eventComponent == &*mRangeSlider) {
        label = "RANGE";
    } else if (event.eventComponent == &*mBlendSlider) {
        label = "BLEND";
    } else if (event.eventComponent == &*mVolumeSlider) {
        label = "VOLUME";
    } else {
        label = "HAIRBALL";
    }
    repaint();
}

void HairballMainPanel::mouseExit(const MouseEvent& event)
{
    repaint();
}

void HairballMainPanel::paint (Graphics &g)
{
    g.setColour(HairballColour_5);
    g.setFont(font_3);
    
    g.drawText(label, getWidth() - (getWidth()/2) - 100, getHeight() - (getHeight()/2) - 30, 210, 50, Justification::centred);
}
