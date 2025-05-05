import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import sys

def envoyer_email(destinataire, nom):
    # إعداد حساب البريد الإلكتروني
    expéditeur = "hamamihamami09876@gmail.com"  # استبدل هذا بعنوان بريدك الإلكتروني
    mot_de_passe = "uybb kouw vwjx oywb"  # استبدل هذا بكلمة مرور التطبيق الخاصة بك أو كلمة المرور الخاصة بحسابك (إذا كنت تستخدم التوثيق الثنائي).

    # إعداد الرسالة
    message = MIMEMultipart()
    message['From'] = expéditeur
    message['To'] = destinataire
    message['Subject'] = "Arbitrage du prochain match"

    # نص الرسالة
    body = f"🎉 Bonjour {nom},\n\nTu as été sélectionné pour arbitrer le prochain match !\n\nBonne chance !"
    message.attach(MIMEText(body, 'plain'))

    try:
        # الاتصال بخادم SMTP لإرسال البريد
        serveur = smtplib.SMTP('smtp.gmail.com', 587)
        serveur.starttls()  # تشفير الاتصال
        serveur.login(expéditeur, mot_de_passe)
        text = message.as_string()
        serveur.sendmail(expéditeur, destinataire, text)
        serveur.quit()
        print("Email envoyé avec succès !")
    except Exception as e:
        print(f"Erreur lors de l'envoi de l'email : {e}")

# تأكد من أن السكربت يستقبل البريد الإلكتروني والاسم من البرنامج
if len(sys.argv) == 3:
    email = sys.argv[1]
    nom = sys.argv[2]
    envoyer_email(email, nom)
else:
    print("Erreur: Paramètres manquants.")
