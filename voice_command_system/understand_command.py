import sys

if len(sys.argv) < 2:
    print("unknown:")
    sys.exit(1)

text = sys.argv[1]
print("Text received:", text)  # أضف هذه السطر لتتبع النص المستلم

if text.startswith("ابحث على"):
    nom = text.replace("ابحث على", "").strip()
    print(f"search:{nom}")
elif text.startswith("أرسل إيميل إلى"):
    nom = text.replace("أرسل إيميل إلى", "").strip()
    print(f"email:{nom}")
else:
    print("unknown:")
