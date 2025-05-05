import speech_recognition as sr

r = sr.Recognizer()
with sr.Microphone() as source:
    print("Parlez maintenant...")
    audio = r.listen(source, timeout=5)
try:
    text = r.recognize_google(audio, language="fr-FR")
    print(text)
except:
    print("")