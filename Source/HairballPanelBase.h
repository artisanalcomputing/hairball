/*
  ==============================================================================

    HairballPanelBase.h
    Created: 26 May 2019 11:17:20pm
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "HairballInterfaceDefines.h"

class HairballPanelBase
: public Component
{
public:
    HairballPanelBase(HairballAudioProcessor* inProcessor);
    ~HairballPanelBase();
    
    void mouseEnter(const MouseEvent& event) override;
    void mouseExit(const MouseEvent& event) override;
    
    void paint (Graphics &g) override;
    
protected:
    HairballAudioProcessor* mProcessor;
    
    String label = "HAIRBALL";
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HairballPanelBase);
};
