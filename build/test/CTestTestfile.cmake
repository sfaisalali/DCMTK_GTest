# CMake generated Testfile for 
# Source directory: E:/Work/RamSoftTest/test
# Build directory: E:/Work/RamSoftTest/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(runTests "E:/Work/RamSoftTest/build/test/Debug/runTests.exe")
  set_tests_properties(runTests PROPERTIES  _BACKTRACE_TRIPLES "E:/Work/RamSoftTest/test/CMakeLists.txt;29;add_test;E:/Work/RamSoftTest/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(runTests "E:/Work/RamSoftTest/build/test/Release/runTests.exe")
  set_tests_properties(runTests PROPERTIES  _BACKTRACE_TRIPLES "E:/Work/RamSoftTest/test/CMakeLists.txt;29;add_test;E:/Work/RamSoftTest/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(runTests "E:/Work/RamSoftTest/build/test/MinSizeRel/runTests.exe")
  set_tests_properties(runTests PROPERTIES  _BACKTRACE_TRIPLES "E:/Work/RamSoftTest/test/CMakeLists.txt;29;add_test;E:/Work/RamSoftTest/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(runTests "E:/Work/RamSoftTest/build/test/RelWithDebInfo/runTests.exe")
  set_tests_properties(runTests PROPERTIES  _BACKTRACE_TRIPLES "E:/Work/RamSoftTest/test/CMakeLists.txt;29;add_test;E:/Work/RamSoftTest/test/CMakeLists.txt;0;")
else()
  add_test(runTests NOT_AVAILABLE)
endif()
subdirs("../_deps/gtest-build")
