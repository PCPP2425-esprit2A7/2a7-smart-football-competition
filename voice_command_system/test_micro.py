import sounddevice as sd
from scipy.io.wavfile import write

duration = 3  # en secondes
samplerate = 16000
print("Recording...")
audio = sd.rec(int(duration * samplerate), samplerate=samplerate, channels=1, dtype='int16')
sd.wait()
write("test_output.wav", samplerate, audio)
print("Saved to test_output.wav")
