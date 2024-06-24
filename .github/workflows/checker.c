#include <stdio.h>
#include <assert.h>

#define TEMP_STR    "Temperature"
#define SOC_STR     "State of charge"
#define CR_STR      "Charge rate"
#define LOW_STR     "Low"
#define HIGH_STR    "High"

// Function to display error messages
void dispError(char *param, char *breach) {
	printf("%s out of range: %s\n", param, breach);
}

// Function to check temperature range
int checkTempRange(float temperature) {
	int tempValid_F = 1;
	if(temperature < 0) {
		dispError(TEMP_STR, LOW_STR);
		tempValid_F = 0;
	} else if(temperature > 45) {
		dispError(TEMP_STR, HIGH_STR);
		tempValid_F = 0;
	}
	else {
	    // Temperature within valid range
	}
    return tempValid_F;
}

// Function to check state of charge range
int checkSocRange(float soc) {
	int socValid_F = 1;
    if(soc < 20) {
		dispError(SOC_STR, LOW_STR);
		socValid_F = 0;
	} else if(soc > 80) {
		dispError(SOC_STR, HIGH_STR);
		socValid_F = 0;
	}
	else {
	    // SOC within valid range
	}
	return socValid_F;
}

// Function to check charge rate range
int checkCrRange(float chargeRate) {
	int crValid_F = 1;
	if(chargeRate > 0.8) {
	    dispError(CR_STR, HIGH_STR);
		crValid_F = 0;
	}
    else {
	    // Charge rate within valid range
	}
	return crValid_F;
}

// Function to check if battery parameters are within valid range
int batteryIsOk(float temperature, float soc, float chargeRate) {
  return (checkTempRange(temperature) && (checkSocRange(soc)) && (checkCrRange(chargeRate)));
}

// Tests
int main() {
  assert(!batteryIsOk(-5.0, 70, 0.7));  // Low temperature
  assert(!batteryIsOk(0, 70, 0.7));     // Boundary temperature - Low
  assert(!batteryIsOk(50, 70, 0.7));    // High temperature
  assert(!batteryIsOk(45, 70, 0.7));    // Boundary temperature - High
  assert(!batteryIsOk(25, 10, 0.7));    // Low SOC
  assert(!batteryIsOk(25, 20, 0.7));    // Boundary SOC - Low
  assert(!batteryIsOk(25, 90, 0.7));    // High SOC
  assert(!batteryIsOk(25, 80, 0.7));    // Boundary SOC - High
  assert(!batteryIsOk(25, 70, 0.9));    // High charge rate
  assert(!batteryIsOk(25, 70, 0.8));    // Boundary charge rate
  assert(!batteryIsOk(50, 90, 0.9));    // All parameters out of range
  assert(batteryIsOk(25, 70, 0.7));     // Normal parameters
}