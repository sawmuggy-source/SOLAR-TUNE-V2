
#include "PluginProcessor.h"
#include "PluginEditor.h"

SolarTuneAudioProcessorEditor::SolarTuneAudioProcessorEditor(
    SolarTuneAudioProcessor& processor)
    : AudioProcessorEditor(&processor),
      audioProcessor(processor)
{
    setSize(600, 400);
}

SolarTuneAudioProcessorEditor::~SolarTuneAudioProcessorEditor()
{
}

void SolarTuneAudioProcessorEditor::paint(juce::Graphics& g)
{
    // Background
    g.fillAll(juce::Colour(0xff080808));

    // Main title
    g.setColour(juce::Colours::white);
    g.setFont(juce::Font(36.0f, juce::Font::bold));
    g.drawFittedText(
        "SOLAR TUNE",
        0, 65, getWidth(), 55,
        juce::Justification::centred,
        1
    );

    // Subtitle
    g.setColour(juce::Colour(0xffffa500));
    g.setFont(juce::Font(14.0f));
    g.drawFittedText(
        "VOCAL PITCH CORRECTION",
        0, 125, getWidth(), 25,
        juce::Justification::centred,
        1
    );

    // Center sun symbol
    g.setColour(juce::Colour(0xffffa500));
    g.setFont(juce::Font(64.0f));
    g.drawFittedText(
        juce::String::fromUTF8("\xe2\x98\x80"),
        0, 175, getWidth(), 90,
        juce::Justification::centred,
        1
    );

    // Footer
    g.setColour(juce::Colours::grey);
    g.setFont(juce::Font(12.0f));
    g.drawFittedText(
        "MUU MILL",
        0, 350, getWidth(), 20,
        juce::Justification::centred,
        1
    );
}

void SolarTuneAudioProcessorEditor::resized()
{
}

