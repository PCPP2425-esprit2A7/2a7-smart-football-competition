import sounddevice as sd
import queue
import sys
import json
from vosk import Model, KaldiRecognizer

# ⚠️ Chemin vers ton dossier de modèle (ajuste selon ta langue et ton PC)
chemin_modele = "voice_command_system/model/vosk-model-small-ar-0.22"
modele = Model(chemin_modele)

file_queue = queue.Queue()
reconnaisseur = KaldiRecognizer(modele, 16000)

def callback_micro(indata, frames, time, status):
    if status:
        print("Erreur micro:", status, file=sys.stderr)
    file_queue.put(bytes(indata))

print(" Parlez pour rechercher...")

with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16',
                       channels=1, callback=callback_micro):
    while True:
        data = file_queue.get()
        if reconnaisseur.AcceptWaveform(data):
            resultat = json.loads(reconnaisseur.Result())
            texte_reconnu = resultat.get("text", "")
            if texte_reconnu:
                print(f"search:{texte_reconnu}")
                break
