#include <dht.h>
#include <LiquidCrystal.h>
#define LCD_LIGHT_PIN A4
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 7;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );



/*
   Initialize the serial port.
*/
void setup( )
{
  Serial.begin( 9600);
  lcd.begin(16, 2);
  pinMode(LCD_LIGHT_PIN, OUTPUT);
  digitalWrite(LCD_LIGHT_PIN, HIGH);
}



/*
   Poll for a measurement, keeping the state machine alive.  Returns
   true if a measurement is available.
*/
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
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



/*
   Main program loop.
*/
void loop( )
{
  float temperature;
  float humidity;

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if ( measure_environment( &temperature, &humidity ) == true )
  {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print(" IOT  Automatic");
    Serial.println( temperature, 1 );
  }
}
