import queue
import sounddevice as sd
import sys
import json
from vosk import Model, KaldiRecognizer
import re

model = r"C:/Users/Hammami Yessmie/OneDrive/Desktop/Atelier_Connexion (2)/Atelier_Connexion/voice_command_system/model"
rec = KaldiRecognizer(model, 16000)
q = queue.Queue()

def callback(indata, frames, time, status):
    if status:
        print(status, file=sys.stderr)
    q.put(bytes(indata))

def understand_command(text):
    text = text.lower()
    text = re.sub(r"\b(chez|à|le|la|un|une|de|du|des)\b", "", text)

    if "cherche" in text or "recherche" in text:
        match = re.search(r"(cherche|recherche)\s+(.*)", text)
        if match:
            name = match.group(2).strip()
            return {"type": "recherche", "nom": name}

    # إذا تقال اسم وحدو
    mots = text.split()
    if mots:
        return {"type": "recherche", "nom": mots[-1]}  # آخر كلمة غالبًا الاسم

    return {"type": "inconnu", "message": text}

with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16',
                       channels=1, callback=callback):
    print("🟢 Parle maintenant... (CTRL+C pour quitter)")
    while True:
        data = q.get()
        if rec.AcceptWaveform(data):
            result = rec.Result()
            text = json.loads(result).get("text", "")
            if text:
                commande = understand_command(text)
                print(json.dumps(commande, ensure_ascii=False))
                break  # نحب نخرج بعد أمر واحد
