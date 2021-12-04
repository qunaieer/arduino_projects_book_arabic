#include     // تضمين مكتبة الأكواد الخاصة بالشاشة
#define trigger 1    //تعريف متغير بقيمة 1 لتوصيل طرف التريجر الخاص بالحساس
#define echo 0        //تعريف متغير بقيمة 0 لتوصيل طرف إيكو الخاص بالحساس
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //تعريف طرف توصيل حساس الحركة بالأردوينو
float the_time = 0, the_distance = 0; //تعريف متغيرين لتخزين الزمن والمسافة
void setup()        //دالة الإعداد وتنفذ مرة واحدة فقط فى بداية البرنامج
{ //كل الأوامر التالية بين القوسين ضمن هذه الدالة
  lcd.begin(16, 2);       //أمر لبدء تشغيل الشاشة
  lcd.print("   Ultrasonic  ");     //أمر طباعة رسالة تعريفية للدائرة
  lcd.setCursor(0, 1);
  lcd.print(" Distance Meter");
  delay(2000);       //أمر انتظار ثانيتين
  lcd.clear();         //أمر مسح الشاشة
}
void loop()           //دالة التكرار وتنفذ باستمرار طالما يوجد تغذية كهرباء للأردوينو
{
  pinMode(trigger, OUTPUT);     //تعريف طرف تريجر كخرج
  pinMode(echo, INPUT);        //تعريف طرف إيكو كدخل
  digitalWrite(trigger, LOW);   //إرسال صفر لطرف تريجر
  delayMicroseconds(2);        //أمر انتظار 2 ميكرو ثانية
  digitalWrite(trigger, HIGH);  //إرسال 1 لطرف تريجر لتفعيل الحساس لبدء إرسال نبضة
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  the_time = pulseIn(echo, HIGH);   //دالة قراءة البيانات من طرف إيكو لاستخراج قيمة الزمن
  the_distance = the_time * 340 / 20000;   //معادلة استخراج المسافة باستخدام الزمن
  lcd.clear();
  lcd.print("Distance :");
  lcd.setCursor(0, 1);
  lcd.print(the_distance);       //طباعة المسافة بالمتر
  lcd.print("cm , ");
  lcd.print(the_distance / 100);       //طباعة المسافة بالسنتيمتر
  lcd.print("m");
  delay(1000);
}

