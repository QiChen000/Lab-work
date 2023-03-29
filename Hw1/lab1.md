## Lab1 C++ openframeworks with sound visualization of faces 

The young man's face is divided into three parts, hair, eyes, and mouth.

The hair is drawn through a for loop with 20 diagonal lines from narrow to wide; the eyes change with the frequency of the music; the red gradient of the mouth references the ofEnableAlphaBlending function to set the transparency of the color.

Eyes part

OfxGui can control the volume of the audio but also the visual effect of the music. Panels are set in the header file to control the audio volume and the visual effects' decay. If the decay value is very small, the audio will react to the visuals erratically and quickly. I set two pointers, fft and sound spectrum, to identify the audio, the less the frequency band, the less the visual response of our audio. I set the uploaded music to play immediately and loop. Set the value of the pointer and the frequency band. Logically, the frequency band of the audio-visual response cannot exceed the frequency itself, so the value of the frequency band is lower than the frequency. I associate the sound spectrum floating pointer with ofsoundgetspectrum and the attenuation control with fft. fft is brought to the radius of the circle eye so that the circle will move with the frequency of the sound. I set the circles to be hollow and duplicated to adjust the size and position.
