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
        setSize (450, 150);
        
        mDriveSlider.setBounds(0, 0, 100, 100);
        mDriveSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mDriveSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        //    mDriveSlider.setRange(driveParameter->range.start, driveParameter->range.end);
        //    mDriveSlider.setValue(*driveParameter);
        addAndMakeVisible (mDriveSlider);
        driveAttachment.reset (new SliderAttachment (valueTreeState, "gain", mDriveSlider));
        driveLabel.setText ("Drive", dontSendNotification);
        driveLabel.attachToComponent(&mDriveSlider, false);
        driveLabel.setBounds (30, 80, 100, 30);
        addAndMakeVisible (driveLabel);
        
        
        mRangeSlider.setBounds(100, 0, 100, 100);
        mRangeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mRangeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        addAndMakeVisible(mRangeSlider);
        rangeAttachment.reset (new SliderAttachment (valueTreeState, "range", mRangeSlider));
        rangeLabel.setText ("Range", dontSendNotification);
        rangeLabel.attachToComponent(&mRangeSlider, false);
        rangeLabel.setBounds (130, 80, 100, 30);
        addAndMakeVisible (rangeLabel);
        
        
        mBlendSlider.setBounds(200, 0, 100, 100);
        mBlendSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mBlendSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        addAndMakeVisible(mBlendSlider);
        blendAttachment.reset (new SliderAttachment (valueTreeState, "blend", mBlendSlider));
        blendLabel.setText ("Blend", dontSendNotification);
        blendLabel.attachToComponent(&mBlendSlider, false);
        blendLabel.setBounds (230, 80, 100, 30);
        addAndMakeVisible (blendLabel);
        
        
        mVolumeSlider.setBounds(300, 0, 100, 100);
        mVolumeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        addAndMakeVisible(mVolumeSlider);
        blendAttachment.reset (new SliderAttachment (valueTreeState, "volume", mVolumeSlider));
        volumeLabel.setText ("Volume", dontSendNotification);
        volumeLabel.attachToComponent(&mVolumeSlider, false);
        volumeLabel.setBounds (330, 80, 100, 30);
        addAndMakeVisible (volumeLabel);
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
    Label driveLabel;
    Slider mRangeSlider;
    Label rangeLabel;
    Slider mBlendSlider;
    Label blendLabel;
    Slider mVolumeSlider;
    Label volumeLabel;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;
    
    
    HairballAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HairballAudioProcessorEditor)
};
