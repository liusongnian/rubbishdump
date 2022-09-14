#ifndef ANDROID_AUDIO_ALSA_CAPTURE_HANDLER_USB_H
#define ANDROID_AUDIO_ALSA_CAPTURE_HANDLER_USB_H

#include "AudioALSACaptureHandlerBase.h"

namespace android {
class AudioALSACaptureHandlerUsb : public AudioALSACaptureHandlerBase {
public:
    AudioALSACaptureHandlerUsb(stream_attribute_t *stream_attribute_target);
    virtual ~AudioALSACaptureHandlerUsb();

    /**
     * open/close audio hardware
     */
    virtual status_t open();
    virtual status_t close();
    virtual status_t routing(const audio_devices_t input_device);


    /**
     * read data from audio hardware
     */
    virtual ssize_t  read(void *buffer, ssize_t bytes);
};

} // end namespace android

#endif // end of ANDROID_AUDIO_ALSA_CAPTURE_HANDLER_USB_H
