/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class HairballAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    
    HairballAudioProcessorEditor (HairballAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState (vts)
    {
        setSize (500, 200);
        
        mDriveSlider.setBounds(0, 0, 100, 100);
        mDriveSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mDriveSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        //    mDriveSlider.setRange(driveParameter->range.start, driveParameter->range.end);
        //    mDriveSlider.setValue(*driveParameter);
        addAndMakeVisible (mDriveSlider);
        driveAttachment.reset (new SliderAttachment (valueTreeState, "gain", mDriveSlider));
        
        mRangeSlider.setBounds(100, 0, 100, 100);
        mRangeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mRangeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        addAndMakeVisible(mRangeSlider);
        rangeAttachment.reset (new SliderAttachment (valueTreeState, "range", mRangeSlider));
        
        mBlendSlider.setBounds(200, 0, 100, 100);
        mBlendSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mBlendSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        addAndMakeVisible(mBlendSlider);
        blendAttachment.reset (new SliderAttachment (valueTreeState, "blend", mBlendSlider));
        
        mVolumeSlider.setBounds(300, 0, 100, 100);
        mVolumeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        addAndMakeVisible(mVolumeSlider);
        blendAttachment.reset (new SliderAttachment (valueTreeState, "volume", mVolumeSlider));
    }
    ~HairballAudioProcessorEditor() {}

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioProcessorValueTreeState& valueTreeState;
    
    Slider mDriveSlider;
    Slider mRangeSlider;
    Slider mBlendSlider;
    Slider mVolumeSlider;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;
    
    
    HairballAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HairballAudioProcessorEditor)
};
