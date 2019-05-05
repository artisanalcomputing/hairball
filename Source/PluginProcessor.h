/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class HairballAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
//    HairballAudioProcessor();
                                HairballAudioProcessor()
                                             : parameters (*this, nullptr, Identifier ("Hairball"),
                                         {
                                             std::make_unique<AudioParameterFloat> ("drive",            // parameterID
                                                                                    "Drive",            // parameter name
                                                                                    0.0f,              // minimum value
                                                                                    1.0f,              // maximum value
                                                                                    0.5f),             // default value
                                             std::make_unique<AudioParameterFloat> ("range",      // parameterID
                                                                                   "Range",     // parameter name
                                                                                   0.0f,              // minimum value
                                                                                   1.0f,              // maximum value
                                                                                   0.5f),              // default value
                                             std::make_unique<AudioParameterFloat> ("blend",      // parameterID
                                                                                   "Blend",     // parameter name
                                                                                   0.0f,              // minimum value
                                                                                   1.0f,              // maximum value
                                                                                   0.5f),
                                             std::make_unique<AudioParameterFloat> ("volume",      // parameterID
                                                                                   "Volume",     // parameter name
                                                                                   0.0f,              // minimum value
                                                                                   1.0f,              // maximum value
                                                                                   0.5f)
                                         }){
                                             driveParameter = parameters.getRawParameterValue ("drive");
                                             rangeParameter = parameters.getRawParameterValue ("range");
                                             blendParameter = parameters.getRawParameterValue ("blend");
                                             volumeParameter = parameters.getRawParameterValue ("volume");
                                         };
    ~HairballAudioProcessor(){};

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
private:
//    std::unique_ptr<AudioProcessorValueTreeState> parameters;
    AudioProcessorValueTreeState parameters;
    
    float* driveParameter = nullptr;
    float* rangeParameter = nullptr;
    float* blendParameter = nullptr;
    float* volumeParameter = nullptr;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HairballAudioProcessor)
};
