/*
  ==============================================================================

    HairballMainPanel.h
    Created: 26 May 2019 11:17:35pm
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "HairballPanelBase.h"
#include "HairballParameterSlider.h"

class HairballMainPanel
: public HairballPanelBase
{
public:
    HairballMainPanel(HairballAudioProcessor* inProcessor);
    ~HairballMainPanel();
    
    void mouseEnter(const MouseEvent& event) override;
    void mouseExit(const MouseEvent& event) override;
    
    void paint (Graphics &g) override;
private:
    std::unique_ptr<HairballParameterSlider> mDriveSlider;
    std::unique_ptr<HairballParameterSlider> mRangeSlider;
    std::unique_ptr<HairballParameterSlider> mBlendSlider;
    std::unique_ptr<HairballParameterSlider> mVolumeSlider;
    String label = "HAIRBALL";
    
};
