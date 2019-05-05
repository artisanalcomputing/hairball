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
        
        //    auto& params = processor.getParameters();
        //
        //    AudioParameterFloat* driveParameter = (AudioParameterFloat*) params.getUnchecked(0);
        //
        //
        
        mDriveSlider.setBounds(0, 0, 100, 100);
        mDriveSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mDriveSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        //    mDriveSlider.setRange(driveParameter->range.start, driveParameter->range.end);
        //    mDriveSlider.setValue(*driveParameter);
        addAndMakeVisible (mDriveSlider);
        driveAttachment.reset (new SliderAttachment (valueTreeState, "gain", mDriveSlider));
        
        //    AudioParameterFloat* rangeParameter = (AudioParameterFloat*) params.getUnchecked(1);
        
        mRangeSlider.setBounds(100, 0, 100, 100);
        mRangeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mRangeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        //    mRangeSlider.setRange(rangeParameter->range.start, rangeParameter->range.end);
        //    mRangeSlider.setValue(*rangeParameter);
        addAndMakeVisible(mRangeSlider);
        rangeAttachment.reset (new SliderAttachment (valueTreeState, "range", mRangeSlider));
        
        //    AudioParameterFloat* blendParameter = (AudioParameterFloat*) params.getUnchecked(2);
        
        mBlendSlider.setBounds(200, 0, 100, 100);
        mBlendSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mBlendSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        //    mBlendSlider.setRange(blendParameter->range.start, blendParameter->range.end);
        //    mBlendSlider.setValue(*blendParameter);
        addAndMakeVisible(mBlendSlider);
        blendAttachment.reset (new SliderAttachment (valueTreeState, "blend", mBlendSlider));
        
        //    AudioParameterFloat* volumeParameter = (AudioParameterFloat*) params.getUnchecked(3);
        
        mVolumeSlider.setBounds(300, 0, 100, 100);
        mVolumeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        mVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
        //    mVolumeSlider.setRange(volumeParameter->range.start, volumeParameter->range.end);
        //    mVolumeSlider.setValue(*volumeParameter);
        addAndMakeVisible(mVolumeSlider);
        blendAttachment.reset (new SliderAttachment (valueTreeState, "volume", mVolumeSlider));
//        gainLabel.setText ("Gain", dontSendNotification);
//        addAndMakeVisible (gainLabel);
//
//        addAndMakeVisible (gainSlider);
//        gainAttachment.reset (new SliderAttachment (valueTreeState, "gain", gainSlider));
//
//        invertButton.setButtonText ("Invert Phase");
//        addAndMakeVisible (invertButton);
//        invertAttachment.reset (new ButtonAttachment (valueTreeState, "invertPhase", invertButton));
//
//        setSize (paramSliderWidth + paramLabelWidth, jmax (100, paramControlHeight * 2));
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
