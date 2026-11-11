
#include "PluginProcessor.h"
#include "PluginEditor.h"

SolarTuneAudioProcessor::SolarTuneAudioProcessor()
    : juce::AudioProcessor(
        BusesProperties()
            .withInput("Input", juce::AudioChannelSet::stereo(), true)
            .withOutput("Output", juce::AudioChannelSet::stereo(), true)
    )
{
}

SolarTuneAudioProcessor::~SolarTuneAudioProcessor()
{
}

void SolarTuneAudioProcessor::prepareToPlay(
    double sampleRate,
    int samplesPerBlock)
{
    juce::ignoreUnused(sampleRate, samplesPerBlock);
}

void SolarTuneAudioProcessor::releaseResources()
{
}

bool SolarTuneAudioProcessor::isBusesLayoutSupported(
    const BusesLayout& layouts) const
{
    const auto& mainInput = layouts.getMainInputChannelSet();
    const auto& mainOutput = layouts.getMainOutputChannelSet();

    if (mainInput != mainOutput)
        return false;

    return mainOutput == juce::AudioChannelSet::mono()
        || mainOutput == juce::AudioChannelSet::stereo();
}

void SolarTuneAudioProcessor::processBlock(
    juce::AudioBuffer<float>& buffer,
    juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    juce::ignoreUnused(midiMessages);

    const int totalInputChannels = getTotalNumInputChannels();
    const int totalOutputChannels = getTotalNumOutputChannels();

    for (int channel = totalInputChannels;
         channel < totalOutputChannels;
         ++channel)
    {
        buffer.clear(channel, 0, buffer.getNumSamples());
    }
}

juce::AudioProcessorEditor*
SolarTuneAudioProcessor::createEditor()
{
    return new SolarTuneAudioProcessorEditor(*this);
}

bool SolarTuneAudioProcessor::hasEditor() const
{
    return true;
}

const juce::String SolarTuneAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SolarTuneAudioProcessor::acceptsMidi() const
{
    return false;
}

bool SolarTuneAudioProcessor::producesMidi() const
{
    return false;
}

bool SolarTuneAudioProcessor::isMidiEffect() const
{
    return false;
}

double SolarTuneAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SolarTuneAudioProcessor::getNumPrograms()
{
    return 1;
}

int SolarTuneAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SolarTuneAudioProcessor::setCurrentProgram(int index)
{
    juce::ignoreUnused(index);
}

const juce::String SolarTuneAudioProcessor::getProgramName(int index)
{
    juce::ignoreUnused(index);
    return {};
}

void SolarTuneAudioProcessor::changeProgramName(
    int index,
    const juce::String& newName)
{
    juce::ignoreUnused(index, newName);
}

void SolarTuneAudioProcessor::getStateInformation(
    juce::MemoryBlock& destData)
{
    juce::ignoreUnused(destData);
}

void SolarTuneAudioProcessor::setStateInformation(
    const void* data,
    int sizeInBytes)
{
    juce::ignoreUnused(data, sizeInBytes);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SolarTuneAudioProcessor();
}
