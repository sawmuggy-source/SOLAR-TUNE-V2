#include "PluginProcessor.h"
#include "PluginEditor.h"

SolarTuneAudioProcessor::SolarTuneAudioProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

SolarTuneAudioProcessor::~SolarTuneAudioProcessor()
{
}

void SolarTuneAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
}

void SolarTuneAudioProcessor::releaseResources()
{
}

bool SolarTuneAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    return layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet();
}

void SolarTuneAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
}

juce::AudioProcessorEditor* SolarTuneAudioProcessor::createEditor()
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

bool SolarTuneAudioProcessor::acceptsMidi() const { return false; }
bool SolarTuneAudioProcessor::producesMidi() const { return false; }
bool SolarTuneAudioProcessor::isMidiEffect() const { return false; }
double SolarTuneAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int SolarTuneAudioProcessor::getNumPrograms() { return 1; }
int SolarTuneAudioProcessor::getCurrentProgram() { return 0; }
void SolarTuneAudioProcessor::setCurrentProgram(int index) {}
const juce::String SolarTuneAudioProcessor::getProgramName(int index) { return {}; }
void SolarTuneAudioProcessor::changeProgramName(int index, const juce::String& newName) {}

void SolarTuneAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
}

void SolarTuneAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SolarTuneAudioProcessor();
}
