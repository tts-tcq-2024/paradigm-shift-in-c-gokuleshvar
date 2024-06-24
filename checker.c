#include <stdio.h>
#include <assert.h>

int checkTempRange(float temperature)
{
	if(temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
        return 0;
	}
    return 1;
}

int checkSocRange(float soc)
{
    if(soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
        return 0;
    }
	return 1;
}

int checkCrRange(float chargeRate)
{
	if(chargeRate > 0.8) {
	    printf("Charge Rate out of range!\n");
	    return 0;
	}
	return 1;
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
  return (checkTempRange(temperature) && (checkSocRange(soc)) && (checkCrRange(chargeRate)));
  }

int main() { 
  assert(!batteryIsOk(-5.0, 70, 0.7));
  assert(!batteryIsOk(50, 70, 0.7));
  assert(!batteryIsOk(25, 10, 0.7));
  assert(!batteryIsOk(25, 90, 0.7));
  assert(!batteryIsOk(25, 70, 0.9));
  assert(batteryIsOk(25, 70, 0.7));
}
