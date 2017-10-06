
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 

#ifndef UTILITY_H
#define UTILITY_H

void parseTwinMessage(const char *);
bool readTMessage(int, char *);
bool readHMessage(int, char *);
void sensorInit(void);
void blinkLED(void);
void blinkSendConfirmation(void);
int getInterval(void);

#endif /* UTILITY_H */