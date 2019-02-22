#include "stdint.h"

#define ATT1 1     // A1     1-3
#define ATT2 2     // A2     1-2
#define ATT3 3     // A3     1-1
#define ATT4 4     // A4     1-0

#define DEC1 5     // A5     1-13
#define DEC2 6     // A6     1-14
#define DEC3 7     // A7     1-15
#define DEC4 8     // A8     1-8

#define SUS1 9     // A9     1-9
#define SUS2 10     // A10    1-10
#define SUS3 11     // A11    1-11
#define SUS4 12    // A12    1-12

#define REL1 13    // A13    2-4
#define REL2 14    // A14    2-5
#define REL3 15    // A15    2-6
#define REL4 16    // A16    2-7

#define VOL1 17    // A17    2-0
#define VOL2 18    // A18    2-1
#define VOL3 19    // A19    2-2 
#define VOL4 20    // A20    2-3

#define WAV1 21    // A21    2-15
#define WAV2 22    // A22    2-14
#define WAV3 23    // A23    2-13
#define WAV4 24    // A24    2-12

uint16_t routing [16][4] = {
  ATT4, 64, VOL1, 16,
  ATT3, 64, VOL2, 16,
  ATT2, 64, VOL3, 16,
  ATT1, 64, VOL4, 16,
     0,  0, REL1, 64,
     0,  0, REL2, 64,
     0,  0, REL3, 64,
     0,  0, REL4, 64,
  DEC4, 64,    0,  0,
  SUS1, 64,    0,  0,
  SUS2, 64,    0,  0,
  SUS3, 64,    0,  0,
  SUS4, 64, WAV4, 128,
  DEC1, 64, WAV3, 128,
  DEC2, 64, WAV2, 128,
  DEC3, 64, WAV1, 128  };


