/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#include "HairballLookAndFeel.h"
#include "HairballMainPanel.h"

//==============================================================================
/**
*/
class HairballAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    
    HairballAudioProcessorEditor (HairballAudioProcessor& p);
    
    ~HairballAudioProcessorEditor();
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    Image mBackgroundImage;
    
    HairballAudioProcessor& processor;
    
    std::unique_ptr<HairballLookAndFeel> mLookAndFeel;
    std::unique_ptr<HairballMainPanel> mMainPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HairballAudioProcessorEditor)
};
