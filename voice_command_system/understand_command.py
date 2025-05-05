import sys
import json
import vosk
import sounddevice as sd
from vosk import Model, KaldiRecognizer
import wave
from difflib import get_close_matches


sys.stdout.reconfigure(encoding='utf-8')

# 🔹 مسار الموديل
model_path = r"C:/Users/Hammami Yessmie/OneDrive/Desktop/Atelier_Connexion (2)/Atelier_Connexion/voice_command_system/model"
audio_file = "C:/Users/Hammami Yessmie/OneDrive/Desktop/Atelier_Connexion (2)/Atelier_Connexion/voice_command_system/recording1.wav"

# 🔹 تحميل الموديل
try:
    model = vosk.Model(model_path)
    recognizer = vosk.KaldiRecognizer(model, 16000)
except Exception as e:
    print(f"Error loading Vosk model: {e}")
    sys.exit()

# 🔹 فتح ملف الصوت
wf = wave.open(audio_file, "rb")
audio_data = wf.readframes(wf.getnframes())

if recognizer.AcceptWaveform(audio_data):
    result = recognizer.Result()
    print(f"Result from the audio file: {result}")
else:
    print("غير قادر على التعرف على الصوت.")

# 🔹 تسجيل صوت لمدة 3 ثواني
duration = 3
recording = sd.rec(int(duration * 16000), samplerate=16000, channels=1, dtype='int16')
sd.wait()
audio_bytes = recording.tobytes()

if recognizer.AcceptWaveform(audio_bytes):
    result = json.loads(recognizer.Result())
    noms_connus = ["yasmine", "senda", "ahmed", "mehdi"]  # بدّلهم حسب شكون موجودين عندك

spoken_text = result.get("text", "").strip().lower()
print(f"Text received: {spoken_text}")

# نقسم النص لمفردات
mots = spoken_text.split()

# نحاول نلقى أقرب اسم
for mot in mots:
    if mot not in ["le", "la", "de", "du", "chez"]:  # كلمات نتجاهلوهم
        match = get_close_matches(mot, noms_connus, n=1, cutoff=0.6)
        if match:
            print(f"search:{match[0]}")
            break
    else:
        print("unknown:commande")