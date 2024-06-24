#include <stdio.h>
#include <assert.h>

int checkTempRange(float temperature)
{
	return (temperature < 0 || temperature > 45);
}

int checkSocRange(float soc)
{
	return (soc < 20 || soc > 80);
}

int checkCrRange(float chargeRate)
{
	return (chargeRate > 0.8);
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(checkTempRange(temperature)) {
    printf("Temperature out of range!\n");
    return 0;
  }

  if(checkSocRange(soc)) {
    printf("State of Charge out of range!\n");
    return 0;
  }

  if(checkCrRange(chargeRate)) {
    printf("Charge Rate out of range!\n");
    return 0;
  }

  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
