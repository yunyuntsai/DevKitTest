# 1 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino"
# 1 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino"
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
// To get started please visit https://microsoft.github.io/azure-iot-developer-kit/docs/projects/connect-iot-hub?utm_source=ArduinoExtension&utm_medium=ReleaseNote&utm_campaign=VSCode
# 5 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino" 2
# 6 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino" 2
# 7 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino" 2
# 8 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino" 2
# 9 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino" 2
# 10 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino" 2

static bool hasWifi = false;
int messageCount = 1;



void initWifi()
{
     Screen.print("IoT DevKit\r\n \r\nConnecting...\r\n");

    if (WiFi.begin() == WL_CONNECTED)
    {
        IPAddress ip = WiFi.localIP();
        Screen.print(1, ip.get_address());
        hasWifi = true;

        Screen.print(2, "Hello Alice... \r\n");
    }
    else
    {
        Screen.print(1, "No Wi-Fi\r\n ");
    }
}

void setup()
{
    hasWifi = false;
    initWifi();
    if (!hasWifi)
    {
        do{{ LOGGER_LOG l = xlogging_get_log_function(); if (l != 
# 40 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino" 3 4
       __null
# 40 "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino"
       ) l(AZ_LOG_INFO, "C:\\Users\\v-altsai\\Documents\\Arduino\\generated_examples\\GetStarted_24\\GetStarted.ino", __func__, 40, 0x01, "Please make sure the wifi connected!"); }; }while((void)0,0);
        return;
    }

    // Microsoft collects data to operate effectively and provide you the best experiences with our products. 
    // We collect data about the features you use, how often you use them, and how you use them.
    send_telemetry_data_async("", "HappyPathSetup", "");

    Serial.begin(115200);
    sensorInit();
    iothubInit();
}

void loop()
{
    char messagePayload[256];
    //bool temperatureAlert = readTMessage(messageCount, messagePayload);
    bool humidityAlert = readHMessage(messageCount, messagePayload);
    iothubSendMessage((const unsigned char *)messagePayload ,humidityAlert);
    iothubLoop();
    delay(3000);
}
