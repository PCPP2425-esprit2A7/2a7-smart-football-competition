from vosk import Model, KaldiRecognizer
import wave
import json

# المسار للموديل
model_path = r"C:/Users/Hammami Yessmie/OneDrive/Desktop/Atelier_Connexion (2)/Atelier_Connexion/voice_command_system/model"
audio_path = 'recording1.wav'


model = Model(model_path)
rec = KaldiRecognizer(model, 16000)

# نفتح الصوت
with wave.open(audio_path, "rb") as wf:
    data = wf.readframes(wf.getnframes())
    if rec.AcceptWaveform(data):
        result = json.loads(rec.Result())
        print("🎧 Texte reconnu :", result.get("text", "RIEN"))
    else:
        print("🚫 Impossible de reconnaître le texte.")
