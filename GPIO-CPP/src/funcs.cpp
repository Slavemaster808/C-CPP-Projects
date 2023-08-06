#include "funcs.h"

void setMode(std::string mode) {
  int check = 0;

  for (auto iter : staticModuleMap) {
    if (mode == iter.second) {
      gpioMode = mode;
      check = 1;
    }
  }

  if (!check) {
    std::cout << "An invalid mode was passed to setmode(). Use one of the "
                 "following: ROCK, BOARD, BCM"
              << '\n';
  }
}

void setRock(std::string rock) {
  if (rock == "ROCK64" || rock == "ROCKPRO64") {
    rockMode = rock;
  } else {
    std::cout << "An invalid rock-mode was passed to setrock(). Use one "
                 "of the following: ROCK64, ROCKPRO64";
  }
}

std::string getMode(void) {
  for (auto iter : staticModuleMap) {
    if (gpioMode == iter.second) {
      return gpioMode;
    }
  }

  std::cout << "Error: An invalid mode is currently set";
  return NULL;
}

int getGpioNumber(int channel) {
  for (auto iter : staticModuleMap) {
    if (gpioMode == iter.second) {
      std::cout << "RuntimeError: Please set pin numbering mode using "
                   "GPIO.setmode(GPIO.ROCK), GPIO.setmode(GPIO.BOARD), or "
                   "GPIO.setmode(GPIO.BCM)";
      return -1;
    }
  }

  int channelNew = -1;
  if (gpioMode == "BOARD") {
    if (rockMode == "ROCK64") {
      channelNew = boardToRock64[channel];
    } else if (rockMode == "ROCKPRO64") {
      channelNew = boardToRockPro64[channel];
    }
  }
  if (gpioMode == "BCM") {
    if (rockMode == "ROCK64") {
      channelNew = bcmToRock64[channel];
    } else if (rockMode == "ROCKPRO64") {
      channelNew = bcmToRockPro64[channel];
    }
  }
  if (gpioMode == "ROCK") {
    channelNew = channel;
  }
  if (rockMode == "ROCK64") {
    for (std::vector<int>::const_iterator iter = rock64ValidChannels.begin();
         iter != rock64ValidChannels.end(); iter++) {
      if (*iter == channelNew) {
        return channelNew;
      }
    }
  } else if (rockMode == "ROCKPRO64") {
    for (std::vector<int>::const_iterator iter = rockPro64ValidChannels.begin();
         iter != rockPro64ValidChannels.end(); iter++) {
      if (*iter == channelNew) {
        return channelNew;
      }
    }
  } else {
    std::cout << "Error: GPIO not supported on {0} {1}";
    return -1;
  }
  return channelNew;
}