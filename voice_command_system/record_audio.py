import sounddevice as sd
import wave

# ⚙️ الإعدادات
filename = "test.wav"
duration = 3  # مدة التسجيل بالثواني
samplerate = 16000  # تردد العينة (VosK يستعمل 16000)
channels = 1  # قناة وحدة للصوت

print("🎤 يبدأ التسجيل...")
recording = sd.rec(int(duration * samplerate), samplerate=samplerate, channels=channels, dtype='int16')
sd.wait()
print("✅ التسجيل كمل، جاري الحفظ...")

# 📝 نحفظو التسجيل في test.wav
with wave.open(filename, "wb") as wf:
    wf.setnchannels(channels)
    wf.setsampwidth(2)  # 16 bits → 2 bytes
    wf.setframerate(samplerate)
    wf.writeframes(recording.tobytes())

print(f"📁 تم الحفظ في: {filename}")
