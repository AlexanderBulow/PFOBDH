# CMakeList.txt : CMake project for PFOBDH, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (PFOBDH "PFOBDH.cpp" "PFOBDH.h" "SendCommand.cpp" "SendCommand.h" "GetCommand.cpp" "GetCommand.h" "SetMode.cpp" "SetMode.h" "Init.cpp" "Init.h" "CheckMode.cpp" "CheckMode.h" "GetTime.cpp" "GetTime.h" "SetTime.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PFOBDH PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
