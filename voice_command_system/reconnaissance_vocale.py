import sys
import queue
import sounddevice as sd
import vosk
import json

model = vosk.Model("voice_command_system/model-fr")  # حط المسار الصحيح للموديل بعد ما تفك الضغط

q = queue.Queue()

def callback(indata, frames, time, status):
    q.put(bytes(indata))

with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16',
                       channels=1, callback=callback):
    print("Parlez maintenant...")
    rec = vosk.KaldiRecognizer(model, 16000)

    while True:
        data = q.get()
        if rec.AcceptWaveform(data):
            result = json.loads(rec.Result())
            print(result.get("text", ""))
            break
