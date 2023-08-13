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
  if (gpioMode == "ROCK" || gpioMode == "BOARD" || gpioMode == "BCM") {
    int channelNew = 0;

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
      for (std::vector<int>::const_iterator iter =
               rockPro64ValidChannels.begin();
           iter != rockPro64ValidChannels.end(); iter++) {
        if (*iter == channelNew) {
          return channelNew;
        }
      }
    } else {
      std::cout << "Error: GPIO not supported on {0} {1}";
      return -1;
    }
  } else {
    std::cout << "RuntimeError: Please set pin numbering mode using "
                 "GPIO.setmode(GPIO.ROCK), GPIO.setmode(GPIO.BOARD), or "
                 "GPIO.setmode(GPIO.BCM)";
  }
  return -1;
}

std::string gpioFunction(int channel) {
  int channelInt = getGpioNumber(channel);

  if (channelInt == -1) {
    return "";
  }

  std::string varGpioFilePath =
      varGpioRoot + "/gpio" + std::to_string(channelInt) + "/direction";
  std::ifstream file(varGpioFilePath);

  if (!file) {
    return "GPIO.UNKNOWN";
  }

  std::string direction;
  file >> direction;
  file.close();

  if (direction == "i") {
    return " GPIO.INPUT";
  } else if (direction == "o") {
    return " GPIO.OUTPUT";
  } else {
    return " GPIO.UNKNOWN";
  }
}

void setWarning(int state) {
  if (state == 1 || state == 0) {
    warningMode = state;
  } else {
    std::cout << "Error: {} is not a valid warning mode. Use one of the "
                 "following: True, 1, False, 0";
  }
}

int validateDirection(int channel, std::string validationType) {
  int channelInt = getGpioNumber(channel);

  if (channelInt == -1) {
    return -1;
  }

  if (validationType == "both" || validationType == "input" ||
      validationType == "output") {
    std::string varGpioFilePath =
        varGpioRoot + "/gpio" + std::to_string(channelInt) + "/direction";
    std::ifstream file(varGpioFilePath);
    std::string direction;
    if (!file) {
      direction = "none";
    } else {
      file >> direction;
    }
    file.close();
    if (validationType == "input" && direction != "i") {
      std::cout
          << "You must setup() the GPIO channel ({0} {1}) as an input first";
      return 0;
    } else if (validationType == "output" && direction != "o") {
      std::cout
          << "You must setup() the GPIO channel ({0} {1}) as an output first";
      return 0;
    } else if (((validationType == "both") &&
                (direction != "i" && direction != "o")) ||
               (direction == "none")) {
      std::cout << "You must setup() the GPIO channel ({0} {1}) first";
      return 0;
    } else {
      return 1;
    }
  } else {
    std::cout << "Error: {} is not a valid direction. use one of the "
                 "following: input, output, both";
  }
  return -1;
}