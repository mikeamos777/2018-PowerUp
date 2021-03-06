cmake_minimum_required(VERSION 3.3)
project(FRC2018)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES "src/*.*")
file(GLOB_RECURSE INCLUDES "src/*.*")
include_directories(src)

file(GLOB_RECURSE DEP_INCLUDES "build/tmp/expandedArchives/wpilibc-2018.1.1-headers.zip_0ba004690f48207547fbbd2a6f212388/*.*" "build/tmp/expandedArchives/hal-2018.1.1-headers.zip_4b49b4176ae22cb58a5421914aabf320/*.*" "build/tmp/expandedArchives/wpiutil-cpp-3.0.0-headers.zip_71db4973bf73247f06ec3fdb86e1126b/*.*" "build/tmp/expandedArchives/ntcore-cpp-4.0.0-headers.zip_517391151665b6a51f10f788c06ee62d/*.*" "build/tmp/expandedArchives/cscore-cpp-1.1.0-headers.zip_7179d2a404841338b55673d83c119071/*.*" "build/tmp/expandedArchives/opencv-cpp-3.2.0-headers.zip_1b8591564854592a4aff6bd224b2b0a3/*.*" "build/tmp/expandedArchives/ni-libraries-2018.1.1-headers.zip_6aedc4b55a982775a7b6e16df1020d5b/*.*" "build/tmp/expandedArchives/CTRE-phoenix-cpp-5.1.2.1-headers.zip_fff3d22e160106b698f6c35d0b2e8153/*.*" "build/tmp/expandedArchives/navx-cpp-3.0.342-headers.zip_ded0b7831bcd4688d480db0d93158974/*.*")
include_directories(build/tmp/expandedArchives/wpilibc-2018.1.1-headers.zip_0ba004690f48207547fbbd2a6f212388)
include_directories(build/tmp/expandedArchives/hal-2018.1.1-headers.zip_4b49b4176ae22cb58a5421914aabf320)
include_directories(build/tmp/expandedArchives/wpiutil-cpp-3.0.0-headers.zip_71db4973bf73247f06ec3fdb86e1126b)
include_directories(build/tmp/expandedArchives/ntcore-cpp-4.0.0-headers.zip_517391151665b6a51f10f788c06ee62d)
include_directories(build/tmp/expandedArchives/cscore-cpp-1.1.0-headers.zip_7179d2a404841338b55673d83c119071)
include_directories(build/tmp/expandedArchives/opencv-cpp-3.2.0-headers.zip_1b8591564854592a4aff6bd224b2b0a3)
include_directories(build/tmp/expandedArchives/ni-libraries-2018.1.1-headers.zip_6aedc4b55a982775a7b6e16df1020d5b)
include_directories(build/tmp/expandedArchives/CTRE-phoenix-cpp-5.1.2.1-headers.zip_fff3d22e160106b698f6c35d0b2e8153)
include_directories(build/tmp/expandedArchives/navx-cpp-3.0.342-headers.zip_ded0b7831bcd4688d480db0d93158974)
set(ALL_INCLUDES ${INCLUDES} ${DEP_INCLUDES} src/NumericalPIDOutput.cpp src/NumericalPIDOutput.h src/NumericalPIDOutput.cpp src/NumericalPIDOutput.h src/Subsystems/Arm.cpp src/Subsystems/Arm.h src/Subsystems/Intake.cpp src/Subsystems/Intake.h src/Subsystems/Autonomous.cpp src/Subsystems/Autonomous.h src/Subsystems/Vision.cpp src/Subsystems/Vision.h)

add_executable(fake_frcUserProgram ${SOURCES} ${ALL_INCLUDES})

add_custom_target(frcUserProgram_build gradlew.bat build WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
add_custom_target(frcUserProgram_deploy gradlew.bat deploy WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
