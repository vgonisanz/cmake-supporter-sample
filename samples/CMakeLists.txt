#####################################################################################################################################################################################
# This is a Modules CMake configuration script. The steps are:
#   1º Configure options with differents samples to be built
#   2º Add samples if options is TRUE
#####################################################################################################################################################################################

PRINTSUBTITLE("Adding samples...")

# Modules step I: Configure options with differents samples to be built
# ------------------------------------------------------------------------------------------------------
OPTION(${PROJ_MAIN_NAME}_SAMPLE_COMMON   			"Sample common"        						     ON )

# Modules step II: Add samples if options is TRUE
# ------------------------------------------------------------------------------------------------------
IF ( ${PROJ_MAIN_NAME}_SAMPLE_COMMON )
  ADD_SUBDIRECTORY( common )
ENDIF()
