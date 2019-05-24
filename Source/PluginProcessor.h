/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "HairballDistortion.h"
#include "HairballParameters.h"

//==============================================================================
/**
*/
class HairballAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    HairballAudioProcessor();
    ~HairballAudioProcessor();

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
    
    AudioProcessorValueTreeState parameters;
    
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
    {
        std::vector<std::unique_ptr<AudioParameterFloat>> params;
        
        for(int i = 0; i < hParameter_TotalNumParameters; i++){
            params.push_back(std::make_unique<AudioParameterFloat>(
                                                                   HairballParameterID[i],
                                                                   HairballParameterLabel[i],
                                                                   HairballParameterRange[i],
                                                                   HairballParameterDefaultValue[i]));
        }
        return {params.begin(), params.end()};
    }

private:
    /** internal */
    void initializeDSP();
    
    std::unique_ptr<HairballDistortion> mDistortion[2];
    
    float* driveParameter = nullptr;
    float* rangeParameter = nullptr;
    float* blendParameter = nullptr;
    float* volumeParameter = nullptr;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HairballAudioProcessor)
};
