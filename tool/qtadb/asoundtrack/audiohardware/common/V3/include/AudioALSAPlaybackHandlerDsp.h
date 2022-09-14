#ifndef ANDROID_AUDIO_ALSA_PLAYBACK_HANDLER_DSP_H
#define ANDROID_AUDIO_ALSA_PLAYBACK_HANDLER_DSP_H

#include "AudioALSAPlaybackHandlerBase.h"
#include "AudioDspType.h"
struct aurisys_dsp_config_t;


namespace android {

class AudioDspStreamManager;

class AudioALSAPlaybackHandlerDsp : public AudioALSAPlaybackHandlerBase {

public:
    AudioALSAPlaybackHandlerDsp(const stream_attribute_t *stream_attribute_source);
    virtual ~AudioALSAPlaybackHandlerDsp();

    /**
     * open/close audio hardware
     */
    virtual status_t open();
    virtual status_t close();

    virtual status_t routing(const audio_devices_t output_devices);

    /**
     * write data to audio hardware
     */
    virtual ssize_t  write(const void *buffer, size_t bytes);
    virtual int preWriteOperation(const void *buffer __unused, size_t bytes __unused) { return 0; }
    virtual int updateAudioMode(audio_mode_t mode __unused);
    virtual status_t updateVolumeIndex(int stream, int device, int index);
    virtual status_t setFilterMng(AudioMTKFilterManager *pFilterMng);

    /**
     * low latency
     */
    virtual status_t setScreenState(bool mode, size_t buffer_size, size_t reduceInterruptSize, bool bforce = false);

    /* dsp pcm API*/
    virtual String8 getPlaybackTurnOnSequence(unsigned int turnOnSeqType,
                                              const char *playbackSeq);

    virtual unsigned int getPlaygbackExBuffer();

    /* start and stop pcm */
    virtual status_t start();
    virtual status_t stop();

    status_t openDspHwPcm();
    status_t openDspPcmDriverWithFlag(const unsigned int device, unsigned int flag);
    status_t opeDspPcmDriver(const unsigned int device);
    status_t closeDspPcmDriver();
    status_t closePcmDriver();
    uint32_t updateKernelBufferSize(audio_devices_t outputdevice);

private:
    struct timespec mNewtime, mOldtime;
    bool deviceSupportHifi(audio_devices_t outputdevice);
    uint32_t chooseTargetSampleRate(uint32_t SampleRate, audio_devices_t outputdevice);
    uint32_t getLowJitterModeSampleRate(void);
    int setAfeDspShareMem(unsigned int flag, bool condition);
    int setDspRuntimeEn(bool condition);
    bool needAPAurisysProcess(const uint32_t aurisys_scenario);
    struct pcm_config mDsphwConfig;
    AudioDspStreamManager *mDspStreamManager;

    struct pcm *mDspHwPcm;
    bool mForceMute;
    int mCurMuteBytes;
    int mStartMuteBytes;
    bool mSupportNLE;

    uint8_t mTaskScene;
    struct aurisys_dsp_config_t *mAurisysDspConfig;
    struct aurisys_lib_manager_t *mAurisysDspLibManager;

    AudioLock mLock;
};

} // end namespace android

#endif // end of ANDROID_AUDIO_ALSA_PLAYBACK_HANDLER_DSP_H
