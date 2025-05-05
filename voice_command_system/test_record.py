import sounddevice as sd
import scipy.io.wavfile as wav

# اختر مدة قصيرة للتسجيل
duration = 3  # مدة 3 ثواني
fs = 16000  # معدل العينة (16000 هو المعدل الموصى به لـ Vosk)

# سجل الصوت
print("🔴 تسجيل لمدة 3 ثواني...")
recording = sd.rec(int(duration * fs), samplerate=fs, channels=1, dtype='int16')
sd.wait()

# حفظ الصوت باستخدام scipy
wav.write("test_record.wav", fs, recording)
print("تم حفظ التسجيل كـ test_record.wav")
