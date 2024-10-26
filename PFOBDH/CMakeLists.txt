# CMakeList.txt : CMake project for PFOBDH, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (PFOBDH "PFOBDH.cpp" "PFOBDH.h" "SendCommand.cpp" "SendCommand.h" "GetCommand.cpp" "GetCommand.h" "SplitTC.h" "clocktoclockr.h" "PF_verify.h" "int2hhmmss.h" "HK.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PFOBDH PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
