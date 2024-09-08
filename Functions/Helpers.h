#ifndef HELPERS
#define HELPERS

#include "../Globals/Aggregator.h"
#include "../Classes/Map/Map.h"

void Trivium();
char GetChar(char condition_1, char condition_2);
bool Replay(char condition_1, char condition_2);

#endif

/*
Helpers.h:
#ifndef HELPERS
#define HELPERS

#include "../Globals/Aggregator.h"
#include "../Classes/Map/Map.h"

//rest of the implementation
#endif

Helpers.cpp:
#include "Helpers.h"
//rest of the implementation
main.cpp:
#include "./Globals/Aggregator.h"
#include "./Classes/Map/Map.h"
#include "./Classes/AI/AI.h"
#include "./Functions/Helpers.h"
//rest of the implementation

tasks.json:
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "cppbuild",
      "label": "Build with GCC 13.2.0 Full file",
      "command": "C:\\Compilers\\mingw64\\bin\\g++.exe",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "-std=c++20",
        "${workspaceFolder}/*.cpp",
        "${workspaceFolder}/Classes/Map/*.cpp",
        "${workspaceFolder}/Classes/AI/*.cpp",
        "${workspaceFolder}/Functions/*.cpp",
        "-o",
        "${fileDirname}\\ThisIsNamedInTaskJson.exe"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": ["$gcc"],
      "group": "build",
      "detail": "compiler: C:\\Compilers\\mingw64\\bin\\g++.exe"
    }]}
    */