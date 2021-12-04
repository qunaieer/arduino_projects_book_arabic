#include   // تضمين مكتبة الأكواد الخاصة بالشاشة
#include "DHT.h"              // تضمين مكتبة الحساس
#define DHTTYPE DHT11        //تعرف نوع الحساس
#define DHTPIN 12                                 //تعريف رقم طرف توصيل الحساس
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);              //LCD connection pins
DHT dht(DHTPIN, DHTTYPE);
void setup()                   //دالة الإعداد وتنفذ مرة واحدة فقط فى بداية البرنامج
{ //كل الأوامر التالية بين القوسين ضمن هذه الدالة
  lcd.begin(16, 2);                              //أمر لبدء تشغيل الشاشة
  dht.begin();                                   //أمر لبدء تشغيل الحساس
  lcd.clear();            //أمر مسح الشاشة
  lcd.print("Temp & Humidity");                  //أمر طباعة رسالة تعريفية للدائرة
  lcd.setCursor(0, 1);
  lcd.print("  Measurement ");
  delay(2000);             //أمر إنتظار ثانيتين
  lcd.clear();
  lcd.print("  ARABS MAKERS  ");
  delay(2000);
  lcd.clear();
  lcd.print("Temp:  Humidity:");
}
void loop()                        //دالة التكرار وتنفذ باستمرار طالما يوجد تغذية كهرباء للأردوينو
{
  delay(500);
  lcd.setCursor(0, 1);                          //وضع المؤشر فى اول عمود والصف الثانى
  float h = dht.readHumidity();                 // قراءة نسبة الرطوبة
  float f = dht.readTemperature(true);          //قراءة قيمة درجة الحرارة بالفهرنهايت من الحساس
  float  c = (f - 32) / 1.8;                               //تحويل من فهرنهايت إلى سيليزيوس
  if (isnan(h) || isnan(f))
  {
    lcd.print("ERROR");
    return;
  }
  lcd.print(c);                                // طباعة درجة الحرارة
  lcd.setCursor(7, 1);
  lcd.print(h);                                // طباعة الرطوبة
}

