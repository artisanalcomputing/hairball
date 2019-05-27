/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "HairballLookAndFeel.h"
//==============================================================================
HairballAudioProcessorEditor::HairballAudioProcessorEditor (HairballAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel.reset(new HairballMainPanel(&processor));
    addAndMakeVisible(*mMainPanel);
    
    mLookAndFeel.reset(new HairballLookAndFeel());
    setLookAndFeel(&*mLookAndFeel);
    LookAndFeel::setDefaultLookAndFeel(&*mLookAndFeel);
    
    mBackgroundImage = ImageCache::getFromMemory(BinaryData::hairball_png,BinaryData::hairball_pngSize);
    
}

HairballAudioProcessorEditor::~HairballAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}


//==============================================================================
void HairballAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
//    g.setColour(Colours::seagreen);
    g.fillAll();
    g.drawImage(mBackgroundImage, getLocalBounds().toFloat());
    
//    g.drawFittedText ("HAIRBALL", getLocalBounds(), Justification::centred, 1);
}

void HairballAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
