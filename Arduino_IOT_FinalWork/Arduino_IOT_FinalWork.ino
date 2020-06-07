#define led 7
#define buzzer 8
#define pirSensor 9
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );



/*
   Initialize the serial port.
*/
void setup( )
{
  Serial.begin(9600);
  pinMode(pirSensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}



/*
   Poll for a measurement, keeping the state machine alive.  Returns
   true if a measurement is available.
*/
static bool measure_environment( float *temperature, float *humidity )
{
  {
    if ( dht_sensor.measure( temperature, humidity ) == true )
    {
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
  Temperatuur();
  Capteur();
}

void Temperatuur() {
  float temperature;
  float humidity;

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if ( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}

void Capteur()
{
  int x = digitalRead(pirSensor);
  if (x == LOW)
  {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println(x);
  }
  else
  {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println(x);
  }
}
