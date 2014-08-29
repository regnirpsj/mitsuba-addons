# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

# sub directories, relative to CMAKE_BINARY_DIR or CMAKE_INSTALL_PREFIX
# depending on if they are used during build or install
SET(MITSUBA_ADDONS_CPACK_DIRECTORY   cpack)
SET(MITSUBA_ADDONS_RUNTIME_DIRECTORY bin)

IF(WIN32 OR WIN64)
  SET(MITSUBA_ADDONS_LIBRARY_DIRECTORY bin)
ELSE()
  SET(MITSUBA_ADDONS_LIBRARY_DIRECTORY lib)
ENDIF()

SET(MITSUBA_ADDONS_HEADER_DIRECTORY  include)
SET(MITSUBA_ADDONS_SHARE_DIRECTORY   share)
SET(MITSUBA_ADDONS_DOC_DIRECTORY     ${MITSUBA_ADDONS_SHARE_DIRECTORY}/doc)
SET(MITSUBA_ADDONS_EXTRA_DIRECTORY   ${MITSUBA_ADDONS_SHARE_DIRECTORY}/extra)
SET(MITSUBA_ADDONS_PLUGIN_DIRECTORY  ${MITSUBA_ADDONS_SHARE_DIRECTORY}/plugins)
SET(MITSUBA_ADDONS_SHADER_DIRECTORY  ${MITSUBA_ADDONS_SHARE_DIRECTORY}/shader)

# output directories, overwrite
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${MITSUBA_ADDONS_LIBRARY_DIRECTORY})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${MITSUBA_ADDONS_LIBRARY_DIRECTORY})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${MITSUBA_ADDONS_RUNTIME_DIRECTORY})

# output directories, project specific
SET(CMAKE_DOC_OUTPUT_DIRECTORY     ${CMAKE_BINARY_DIR}/${MITSUBA_ADDONS_DOC_DIRECTORY})
SET(CMAKE_EXTRA_OUTPUT_DIRECTORY   ${CMAKE_BINARY_DIR}/${MITSUBA_ADDONS_EXTRA_DIRECTORY})
SET(CMAKE_PLUGIN_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/${MITSUBA_ADDONS_PLUGIN_DIRECTORY})
SET(CMAKE_SHADER_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/${MITSUBA_ADDONS_SHADER_DIRECTORY})
