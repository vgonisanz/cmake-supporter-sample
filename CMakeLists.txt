####################################################################################################################################################################################
# How this script works:
#####################################################################################################################################################################################
#
# This is a MAIN configuration script. The steps are:
#   1º Configure Cmake minimun version
#   2º Include submodule cmakesupport with macros and scripts. Print with style, crosscompile helpers, etc... More info at cmakesupport project.
#   3º Configure MAIN project:  A)  Unique project name.
#                               B)  Project solution.
#                               C)  Check target architecture using cmakesupport scripts
#                               D)  Configure general variables and path using cmakesupport scripts
#
#   4º Configure options:       A)  What build: samples, test, auto generate documentation, profiling;
#                               B)  What Dependencies wants to compile
#                               C)  Cmake general variables
#                               Note: User must can change them
#   5º Configure variables:     A)  Set cmake options
#                               B)  Set dependencies variables with include and libs used by modules in main scope.
#                               C)  Set own include variable and library [Optional]
#                               Note: Some options could be forced. Some options could be changed by 3rdParty, if this happen override in ***FORCE CMAKE OPTIONS*** .
#   6º Add C++11 support
#   7º According configuration: A)  Add 3rdParty libraries
#                               B)  Print 3rdParty info. You must edit it!
#                               C)  Add modules (Must be Auto-compilables)
#                               D)  Add samples if option ON
#                               E)  Add test if option ON
#                               F)  Generate Doxygen Info if option ON
#                               G)  Print info if required in step 3.D
#
####################################################################################################################################################################################

# Main step I: Set CMake minimun version
# ------------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)

# Main step II: Import funcions;
# ------------------------------------------------------------------------------------------------------
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/cmake-supporter")
INCLUDE( cms )
PRINTTITLE("Main CmakeLists start configuration")

# Main step III: Configure unique Project name and invoque function to configurate paths and Version
# ------------------------------------------------------------------------------------------------------
SET(PROJ_MAIN_NAME "CMSSample")                         # 3.A This ID must be unique, change in template
PROJECT(${PROJ_MAIN_NAME}-main)                         # 3.B Create solution project
CHECKCROSSPLATFORM(${PROJ_MAIN_NAME})                   # 3.C Check target if crosscompile or not
CONFIGUREVARIABLESPROJECT(${PROJ_MAIN_NAME} 1 0 0 ON)   # 3.D Set basic variables, version, and print info

# Main step IV: Configure OPTIONS for this project, user must can change them
# ------------------------------------------------------------------------------------------------------
  # 4.A General configuration
OPTION(${PROJ_MAIN_NAME}_BUILD_SAMPLES       "Build samples in the project"            					ON )
OPTION(${PROJ_MAIN_NAME}_BUILD_TEST         "Build tests in the project"              					OFF ) # TODO add test
OPTION(${PROJ_MAIN_NAME}_BUILD_DOCS         "Create build rules for Doxygen Documentation" 		  OFF ) # TODO add Doxygen generation

  # 4.B Dependencies configuration
#OPTION(${PROJ_MAIN_NAME}_DEPENDENCY_XXX     "Compile and use Dependency X" 				                     ON )

  # 4.C CMake Options
  # More info for CMake Configuration, see https://cmake.org/Wiki/CMake_Useful_Variables
OPTION(CMAKE_VERBOSE "Verbose mode" OFF )

# Main step V: Configure project DEPENDENCIES
# ------------------------------------------------------------------------------------------------------
  # 5.A Cmake variables
SET(CMAKE_DEBUG_POSTFIX)
SET(CMAKE_INSTALL_PREFIX ${${PROJ_MAIN_NAME}_PATH_INSTALL})
SET(CMAKE_BINARY_DIR ${${PROJ_MAIN_NAME}_PATH_EXE})

  # 5.B Set dependencies variables with include and libs used by modules in main scope.
IF(${PROJ_MAIN_NAME}_DEPENDENCY_XXX)

ENDIF()

  # 5.C Set own include variable and library [Optional]
PRINT("Setting ${PROJ_MAIN_NAME} includes and libs variables")
SET(${PROJ_MAIN_NAME}_INCLUDE_PATH
            ${${PROJ_MAIN_NAME}_PATH_MAIN}/modules/common/include
            ${${PROJ_MAIN_NAME}_PATH_INSTALL}/common/include
            CACHE PATH "This directory have include autogenerated using common/in/*_config.h.in" )

# Main step VI: Add C++11, MSVS use it by default
# ------------------------------------------------------------------------------------------------------
ADD_CPP11()

# Main step VII: Project Logic to compile.
# Note: Using macro CHECKCROSSPLATFORM will assign a Crossplatform target, if not, will report an error.
#
# Project options to built:
# · 3rdParty: All dependencies from other repositories, added as submodules.
# · Modules: All libraries in THIS project
# · Samples: Executables using libraries in THIS project and 3rdParties if is needed
# · Test: Auto-Executables to check all modules work propertly
# ------------------------------------------------------------------------------------------------------
IF(NOT TARGET_PLATFORM STREQUAL TARGET_NONE)
  # 7.A Configure and compile 3rdParty, they can change CMake options.
  # If your variables are override, use SET(CMAKE_XXX FORCE) that you used in main step V.
  # ------------------------------------------------------------------------------------------------------
  #ADD_SUBDIRECTORY(3rdParty) # TODO

  # 7.B Print 3rdParty that you need
  # ------------------------------------------------------------------------------------------------------
  #PRINTTITLE("3rdParty info" )
  # TODO add in this project
  # TODO Check to add a environment variable checker.

  # 7.C Compile modules (libs)
  # Each one must be Auto-compilable it-self
  # ------------------------------------------------------------------------------------------------------
  ADD_SUBDIRECTORY(modules)

  # 7.D Compile sample (executables using libs and 3rdParty)
  # ------------------------------------------------------------------------------------------------------
  IF(${PROJ_MAIN_NAME}_BUILD_SAMPLES)
    ADD_SUBDIRECTORY(samples)
  ENDIF()

  # 7.E Compile test (executables testing all features working) with GMock
  # ------------------------------------------------------------------------------------------------------
  IF(${PROJ_MAIN_NAME}_BUILD_TEST)
    ADD_SUBDIRECTORY(test)
  ENDIF()

  # 7.F Print 3rdParty that you need
  # ------------------------------------------------------------------------------------------------------
  IF(${PROJ_MAIN_NAME}_BUILD_DOCS)
    PRINT("Build documentation using Doxygen TODO")
  ENDIF()

  # 7.G Configuration end. Print resume info if option TRUE on CONFIGUREVARIABLESPROJECT
  ########################################################################################################
  IF(${PROJ_MAIN_NAME}_PRINT)
    PRINTADVANCEDINFO(${PROJ_MAIN_NAME} 2010-2016)
  ENDIF()
  PRINTTITLE("Main CmakeLists end configuration")
ELSE()
  MESSAGE(FATAL_ERROR " TARGET no autodetected. Check if CHECKCROSSPLATFORM macro is called OR Please, select a TARGET manually.")
ENDIF()
