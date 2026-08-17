#include <DHT.h>
#include <Servo.h>

// =====================================================
// AEGIS AI v1.0
// Arduino Nano - I/O Controller
// =====================================================

// -------------------------
// DHT11
// -------------------------

#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);


// -------------------------
// DIGITAL INPUTS
// -------------------------

#define HALL_PIR_PIN       3
#define BEDROOM_PIR_PIN    4
#define MAIN_DOOR_IR_PIN   8


// -------------------------
// DIGITAL OUTPUTS
// -------------------------

#define HALL_LIGHT_PIN      5
#define BEDROOM_LIGHT_PIN   6
#define KITCHEN_LIGHT_PIN   7

#define BUZZER_PIN          9

#define GARAGE_SERVO_PIN   10


// -------------------------
// ANALOG INPUTS
// -------------------------

#define MQ2_PIN             A0
#define HALL_LDR_PIN        A1
#define BEDROOM_LDR_PIN     A2


// -------------------------
// SERVO
// -------------------------

Servo garageServo;


// -------------------------
// GARAGE POSITIONS
// -------------------------

const int GARAGE_CLOSED = 0;
const int GARAGE_OPEN   = 90;


// -------------------------
// SENSOR TIMING
// -------------------------

unsigned long lastSensorRead = 0;

const unsigned long SENSOR_INTERVAL = 2000;


// =====================================================
// SETUP
// =====================================================

void setup() {

    Serial.begin(9600);

    dht.begin();


    // -------------------------
    // INPUTS
    // -------------------------

    pinMode(
        HALL_PIR_PIN,
        INPUT
    );

    pinMode(
        BEDROOM_PIR_PIN,
        INPUT
    );

    pinMode(
        MAIN_DOOR_IR_PIN,
        INPUT
    );


    // -------------------------
    // OUTPUTS
    // -------------------------

    pinMode(
        HALL_LIGHT_PIN,
        OUTPUT
    );

    pinMode(
        BEDROOM_LIGHT_PIN,
        OUTPUT
    );

    pinMode(
        KITCHEN_LIGHT_PIN,
        OUTPUT
    );

    pinMode(
        BUZZER_PIN,
        OUTPUT
    );


    // -------------------------
    // Initial output states
    // -------------------------

    digitalWrite(
        HALL_LIGHT_PIN,
        LOW
    );

    digitalWrite(
        BEDROOM_LIGHT_PIN,
        LOW
    );

    digitalWrite(
        KITCHEN_LIGHT_PIN,
        LOW
    );

    digitalWrite(
        BUZZER_PIN,
        LOW
    );


    // -------------------------
    // Garage servo
    // -------------------------

    garageServo.attach(
        GARAGE_SERVO_PIN
    );

    garageServo.write(
        GARAGE_CLOSED
    );


    // -------------------------
    // Startup message
    // -------------------------

    Serial.println(
        "AEGIS_NANO_READY"
    );

}


// =====================================================
// LOOP
// =====================================================

void loop() {

    // -------------------------
    // Receive commands
    // -------------------------

    readCommands();


    // -------------------------
    // Send sensor data
    // -------------------------

    unsigned long now =
        millis();


    if (
        now - lastSensorRead
        >= SENSOR_INTERVAL
    ) {

        lastSensorRead =
            now;

        sendSensorData();

    }

}


// =====================================================
// READ COMMANDS FROM NODE
// =====================================================

void readCommands() {

    if (
        !Serial.available()
    ) {

        return;

    }


    String command =
        Serial.readStringUntil(
            '\n'
        );


    command.trim();


    if (
        command.length() == 0
    ) {

        return;

    }


    // =================================================
    // HALL LIGHT
    // =================================================

    if (
        command ==
        "HALL_LIGHT ON"
    ) {

        digitalWrite(
            HALL_LIGHT_PIN,
            HIGH
        );

        Serial.println(
            "HALL_LIGHT ON"
        );

        return;

    }


    if (
        command ==
        "HALL_LIGHT OFF"
    ) {

        digitalWrite(
            HALL_LIGHT_PIN,
            LOW
        );

        Serial.println(
            "HALL_LIGHT OFF"
        );

        return;

    }


    // =================================================
    // BEDROOM LIGHT
    // =================================================

    if (
        command ==
        "BEDROOM_LIGHT ON"
    ) {

        digitalWrite(
            BEDROOM_LIGHT_PIN,
            HIGH
        );

        Serial.println(
            "BEDROOM_LIGHT ON"
        );

        return;

    }


    if (
        command ==
        "BEDROOM_LIGHT OFF"
    ) {

        digitalWrite(
            BEDROOM_LIGHT_PIN,
            LOW
        );

        Serial.println(
            "BEDROOM_LIGHT OFF"
        );

        return;

    }


    // =================================================
    // KITCHEN LIGHT
    // =================================================

    if (
        command ==
        "KITCHEN_LIGHT ON"
    ) {

        digitalWrite(
            KITCHEN_LIGHT_PIN,
            HIGH
        );

        Serial.println(
            "KITCHEN_LIGHT ON"
        );

        return;

    }


    if (
        command ==
        "KITCHEN_LIGHT OFF"
    ) {

        digitalWrite(
            KITCHEN_LIGHT_PIN,
            LOW
        );

        Serial.println(
            "KITCHEN_LIGHT OFF"
        );

        return;

    }


    // =================================================
    // BUZZER
    // =================================================

    if (
        command ==
        "BUZZER ON"
    ) {

        digitalWrite(
            BUZZER_PIN,
            HIGH
        );

        Serial.println(
            "BUZZER ON"
        );

        return;

    }


    if (
        command ==
        "BUZZER OFF"
    ) {

        digitalWrite(
            BUZZER_PIN,
            LOW
        );

        Serial.println(
            "BUZZER OFF"
        );

        return;

    }


    // =================================================
    // GARAGE
    // =================================================

    if (
        command ==
        "GARAGE OPEN"
    ) {

        garageServo.write(
            GARAGE_OPEN
        );

        Serial.println(
            "GARAGE OPEN"
        );

        return;

    }


    if (
        command ==
        "GARAGE CLOSE"
    ) {
        garageServo.write(
            GARAGE_CLOSED
        );

        Serial.println(
            "GARAGE CLOSE"
        );

        return;

    }

}


// =====================================================
// READ SENSORS + SEND JSON
// =====================================================

void sendSensorData() {

    // -------------------------
    // DHT11
    // -------------------------

    float temperature =
        dht.readTemperature();

    float humidity =
        dht.readHumidity();


    // -------------------------
    // PIR
    // -------------------------

    int hallPir =
        digitalRead(
            HALL_PIR_PIN
        );

    int bedroomPir =
        digitalRead(
            BEDROOM_PIR_PIN
        );


    // -------------------------
    // Main door IR
    // -------------------------

    int mainDoorIr =
        digitalRead(
            MAIN_DOOR_IR_PIN
        );


    // -------------------------
    // Analog sensors
    // -------------------------

    int gas =
        analogRead(
            MQ2_PIN
        );

    int hallLdr =
        analogRead(
            HALL_LDR_PIN
        );

    int bedroomLdr =
        analogRead(
            BEDROOM_LDR_PIN
        );


    // =================================================
    // JSON
    // =================================================

    Serial.print("{");


    // -------------------------
    // DHT
    // -------------------------

    Serial.print(
        "\"temperature\":"
    );

    if (
        isnan(temperature)
    ) {

        Serial.print("null");

    }

    else {

        Serial.print(
            temperature,
            1
        );

    }


    Serial.print(
        ",\"humidity\":"
    );

    if (
        isnan(humidity)
    ) {

        Serial.print("null");

    }

    else {

        Serial.print(
            humidity,
            1
        );

    }


    // -------------------------
    // PIR
    // -------------------------

    Serial.print(
        ",\"hallPir\":"
    );

    Serial.print(
        hallPir
    );


    Serial.print(
        ",\"bedroomPir\":"
    );

    Serial.print(
        bedroomPir
    );


    // -------------------------
    // Main door
    // -------------------------

    Serial.print(
        ",\"mainDoorIr\":"
    );

    Serial.print(
        mainDoorIr
    );


    // -------------------------
    // MQ2
    // -------------------------

    Serial.print(
        ",\"gas\":"
    );

    Serial.print(
        gas
    );


    // -------------------------
    // LDR
    // -------------------------

    Serial.print(
        ",\"hallLdr\":"
    );

    Serial.print(
        hallLdr
    );


    Serial.print(
        ",\"bedroomLdr\":"
    );

    Serial.print(
        bedroomLdr
    );


    // -------------------------
    // Lights
    // -------------------------

    Serial.print(
        ",\"hallLight\":"
    );

    Serial.print(
        digitalRead(
            HALL_LIGHT_PIN
        )
    );


    Serial.print(
        ",\"bedroomLight\":"
    );

    Serial.print(
        digitalRead(
            BEDROOM_LIGHT_PIN
        )
    );


    Serial.print(
        ",\"kitchenLight\":"
    );

    Serial.print(
        digitalRead(
            KITCHEN_LIGHT_PIN
        )
    );


    // -------------------------
    // Complete JSON
    // -------------------------

    Serial.println(
        "}"
    );

}