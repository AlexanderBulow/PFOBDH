# CMakeList.txt : CMake project for PFOBDH, include source and define
# project specific logic here.
#

# Add source to this project's executable.

add_executable (PFOBDH "PFOBDH.cpp" "PFOBDH.h" "SendCommand.cpp" "SendCommand.h" "GetCommand.cpp" "GetCommand.h" "editbucket.h" "editbucket.cpp" "compareseqinbucket.cpp" "compareseqinbucket.h" "removecommandline.cpp" "removecommandline.h" "hhmmss2int.cpp" "hhmmss2int.h" "timetag.cpp" "timetag.h" "comparetimeinbucket.cpp" "comparetimeinbucket.h" "extractfirstcommandbucket.cpp" "extractfirstcommandbucket.h" "changetimecombucket.cpp" "changetimecombucket.h" "int2hhmmss.cpp" "int2hhmmss.h" "GetTime.cpp" "GetTime.h" "Init.h" "Init.cpp" "SetTime.h" "SetTime.cpp" "SetMode.cpp" "SetMode.h" "CheckMode.h" "CheckMode.cpp" "TimeDiff.h" "TimeDiff.cpp" "SplitTC.cpp" "SplitTC.h" "HK.cpp" "HK.h" "PF_verify.cpp" "PF_verify.h" "clocktoclockr.cpp" "clocktoclockr.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PFOBDH PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
