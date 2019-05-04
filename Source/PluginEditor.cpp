/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HairballAudioProcessorEditor::HairballAudioProcessorEditor (HairballAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
    
    auto& params = processor.getParameters();
    
    AudioParameterFloat* driveParameter = (AudioParameterFloat*) params.getUnchecked(0);
    
    mDriveSlider.setBounds(0, 0, 100, 100);
    mDriveSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mDriveSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    mDriveSlider.setRange(driveParameter->range.start, driveParameter->range.end);
    mDriveSlider.setValue(*driveParameter);
    addAndMakeVisible(mDriveSlider);
    
    AudioParameterFloat* rangeParameter = (AudioParameterFloat*) params.getUnchecked(1);
    
    mRangeSlider.setBounds(100, 0, 100, 100);
    mRangeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mRangeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    mRangeSlider.setRange(rangeParameter->range.start, rangeParameter->range.end);
    mRangeSlider.setValue(*rangeParameter);
    addAndMakeVisible(mRangeSlider);
    
    AudioParameterFloat* blendParameter = (AudioParameterFloat*) params.getUnchecked(2);
    
    mBlendSlider.setBounds(200, 0, 100, 100);
    mBlendSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mBlendSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    mBlendSlider.setRange(blendParameter->range.start, blendParameter->range.end);
    mBlendSlider.setValue(*blendParameter);
    addAndMakeVisible(mBlendSlider);
    
    AudioParameterFloat* volumeParameter = (AudioParameterFloat*) params.getUnchecked(3);
    
    mVolumeSlider.setBounds(300, 0, 100, 100);
    mVolumeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mVolumeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    mVolumeSlider.setRange(volumeParameter->range.start, volumeParameter->range.end);
    mVolumeSlider.setValue(*volumeParameter);
    addAndMakeVisible(mVolumeSlider);
    
    driveAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"Drive", mDriveSlider));
    rangeAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"Range", mRangeSlider));
    blendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"Blend", mBlendSlider));
    volumeAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"Volume", mVolumeSlider));
}

HairballAudioProcessorEditor::~HairballAudioProcessorEditor()
{
}

//==============================================================================
void HairballAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void HairballAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
