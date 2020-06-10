/* import libraries */
#include <dht.h>
#include <LiquidCrystal.h>
/* De nodige pin definieren van onze arduino */
#define LCD_LIGHT_PIN A4
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 7;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );


void setup( )
{
  /* Lcd scherm laten starten + de nodige contrast doorgeven voor de scherm */
  Serial.begin( 9600);
  lcd.begin(16, 2);
  pinMode(LCD_LIGHT_PIN, OUTPUT);
  digitalWrite(LCD_LIGHT_PIN, HIGH);
}



/*
   geeft de temperature en de humidity terug om de 4 seconde
*/
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  if ( millis( ) - measurement_timestamp > 3000ul )
  {
    if ( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return ( true );
    }
  }

  return ( false );
}


void loop( )
{
  float temperature;
  float humidity;

  /* /* Meet de temperatuur en de luchtvochtigheid.  Als de functies terugkeren
     waar, dan is er een meting beschikbaar.  */
  if ( measure_environment( &temperature, &humidity ) == true )
  {
    /*print de temperature op de lcd scherm + de naam IOT Automatic en print de temperature in de console(Om de 5 sec) */
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print(" IOT  Automatic");
    Serial.println( temperature, 1 );
    delay(5000);
  }
}
