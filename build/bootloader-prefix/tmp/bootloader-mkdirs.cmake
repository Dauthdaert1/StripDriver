# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "A:/esp/v5.2.2/esp-idf/components/bootloader/subproject"
  "A:/ESP32Projects/StripExample/build/bootloader"
  "A:/ESP32Projects/StripExample/build/bootloader-prefix"
  "A:/ESP32Projects/StripExample/build/bootloader-prefix/tmp"
  "A:/ESP32Projects/StripExample/build/bootloader-prefix/src/bootloader-stamp"
  "A:/ESP32Projects/StripExample/build/bootloader-prefix/src"
  "A:/ESP32Projects/StripExample/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "A:/ESP32Projects/StripExample/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "A:/ESP32Projects/StripExample/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
