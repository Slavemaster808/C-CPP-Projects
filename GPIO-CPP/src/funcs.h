#ifndef FUNCS_H
#define FUNCS_H
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define HIGH 1
#define LOW 0
#define PUD_UP 0
#define PUD_DOWN 1

static const std::string varGpioRoot = "/sys/class/gpio";

static const std::map<std::string, std::string> staticModuleMap = {
    {"ROCK", "ROCK"},       {"BOARD", "BOARD"}, {"BCM", "BCM"},
    {"OUT", "out"},         {"IN", "in"},       {"RISING", "rising"},
    {"FALLING", "falling"}, {"BOTH", "both"},   {"VERSION", "0.6.3"}};

static const std::map<std::string, std::string> rpiInfo = {
    {"PI_VERSION", "3"},      {"RAM", "1024M"},
    {"REVISION", "a22082"},   {"TYPE", "Pi 3 Model B"},
    {"PROCESSOR", "BCM2837"}, {"MANUFACTURES", "Embest"}};

static const std::vector<int> rock64ValidChannels = {
    27, 32, 33, 34, 35, 36, 37, 38, 60, 64, 65, 67, 68,  69,  76,  79,  80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 96, 97, 98, 100, 101, 102, 103, 104};

static const std::vector<int> boardToRock64 = {
    0,   0,  0,   89, 0,  88, 0,   60, 64,  0, 65, 0,  67, 0,  0,  100,
    101, 0,  102, 97, 0,  98, 103, 96, 104, 0, 76, 68, 69, 0,  0,  0,
    38,  32, 0,   33, 37, 34, 36,  0,  35,  0, 0,  81, 82, 87, 83, 0,
    0,   80, 79,  85, 84, 27, 86,  0,  0,   0, 0,  0,  0,  89, 88};

static const std::vector<int> bcmToRock64 = {
    68, 69, 89, 88, 81, 87, 83, 76, 104, 98,  97,  96,  38, 32,
    64, 65, 37, 80, 67, 33, 36, 35, 100, 101, 102, 103, 34, 82};

static const std::vector<int> rockPro64ValidChannels = {
    52,  53,  152, 54,  50, 33,  48,  39, 41, 43, 155, 156, 125, 122,
    121, 148, 147, 120, 36, 149, 153, 42, 45, 44, 124, 126, 123, 127};

static const std::vector<int> boardToRockPro64 = {
    0,  0,   0,  52,  0,   53,  0, 152, 148, 0,   147, 54, 120, 50,
    0,  33,  36, 0,   149, 48,  0, 39,  153, 41,  42,  0,  45,  43,
    44, 155, 0,  156, 124, 125, 0, 122, 126, 121, 123, 0,  127};

static const std::vector<int> bcmToRockPro64 = {
    43,  44,  52,  53, 152, 155, 156, 45,  42, 39, 48,  41,  124, 125,
    148, 147, 124, 54, 120, 122, 123, 127, 33, 36, 149, 153, 121, 50};

static std::string gpioMode = NULL;

static std::string rockMode = "ROCK64";

static int warningMode = 1;

class PWM {
 private:
  double freq;
  int gpio;
  int state;

 public:
  PWM(int channel, double frequency);
  void setFrequency(double frequency);
  void start(double dutyCycle, int pwmPrecision = HIGH);
};

void setMode(std::string mode);

void setRock(std::string rock);

std::string getMode(void);

int getGpioNumber(int channel);

std::string gpioFunction(int channel);

void setWarning(int state = 1);

int validateDirection(int channel, std::string validationType = "both");

#endif  // FUNCS_H