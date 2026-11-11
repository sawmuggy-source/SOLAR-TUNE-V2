
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class SolarTuneAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit SolarTuneAudioProcessorEditor(
        SolarTuneAudioProcessor& processor);

    ~SolarTuneAudioProcessorEditor() override;

    void paint(juce::Graphics& g) override;

    void resized() override;

private:
    SolarTuneAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
        SolarTuneAudioProcessorEditor)
};

