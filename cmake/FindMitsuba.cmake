# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

SET(_mts_HEADER_SEARCH_DIRS
  "/usr/include"
  "/usr/local/include")

SET(_mts_LIBRARY_SEARCH_DIRS
  "/usr/lib"
  "/usr/local/lib")

SET(_mts_ENV_ROOT_DIR "$ENV{MITSUBA_ROOT_DIR}")

IF(NOT MITSUBA_ROOT_DIR AND _mts_ENV_ROOT_DIR)
  SET(MITSUBA_ROOT_DIR "${_mts_ENV_ROOT_DIR}")
ENDIF(NOT MITSUBA_ROOT_DIR AND _mts_ENV_ROOT_DIR)

IF(MITSUBA_ROOT_DIR)
  SET(_mts_HEADER_SEARCH_DIRS "${MITSUBA_ROOT_DIR}"
    "${MITSUBA_ROOT_DIR}/include"
    ${_mts_HEADER_SEARCH_DIRS})
  SET(_mts_LIBRARY_SEARCH_DIRS "${MITSUBA_ROOT_DIR}"
    "${MITSUBA_ROOT_DIR}/lib"
    "${MITSUBA_ROOT_DIR}/bin"
    ${_mts_LIBRARY_SEARCH_DIRS})
ENDIF(MITSUBA_ROOT_DIR)

FIND_PATH(MITSUBA_INCLUDE_DIR "mitsuba/mitsuba.h"
  PATHS ${_mts_HEADER_SEARCH_DIRS}
  DOC "The directory where mitsuba/mitsuba.h resides")

SET(_mts_LIBRARY_BIDIR mitsuba-bidir)
SET(_mts_LIBRARY_CORE mitsuba-core)
SET(_mts_LIBRARY_HW mitsuba-hw)
SET(_mts_LIBRARY_RENDER mitsuba-render)

FIND_LIBRARY(MITSUBA_LIBRARY_BIDIR
  NAMES ${_mts_LIBRARY_BIDIR}
  PATHS ${_mts_LIBRARY_SEARCH_DIRS}
  DOC "The Mitsuba bidir library")
FIND_LIBRARY(MITSUBA_LIBRARY_CORE
  NAMES ${_mts_LIBRARY_CORE}
  PATHS ${_mts_LIBRARY_SEARCH_DIRS}
  DOC "The Mitsuba core library")
FIND_LIBRARY(MITSUBA_LIBRARY_HW
  NAMES ${_mts_LIBRARY_HW}
  PATHS ${_mts_LIBRARY_SEARCH_DIRS}
  DOC "The Mitsuba hw library")
FIND_LIBRARY(MITSUBA_LIBRARY_RENDER
  NAMES ${_mts_LIBRARY_RENDER}
  PATHS ${_mts_LIBRARY_SEARCH_DIRS}
  DOC "The Mitsuba render library")

SET(MITSUBA_LIBRARIES
  ${MITSUBA_LIBRARY_BIDIR} ${MITSUBA_LIBRARY_CORE} ${MITSUBA_LIBRARY_HW} ${MITSUBA_LIBRARY_RENDER})

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(MITSUBA DEFAULT_MSG MITSUBA_INCLUDE_DIR MITSUBA_LIBRARIES)

IF(MITSUBA_FOUND AND VERBOSE)
  MESSAGE(STATUS "MITSUBA_INCLUDE_DIR = ${MITSUBA_INCLUDE_DIR}")
  MESSAGE(STATUS "MITSUBA_LIBRARIES   = ${MITSUBA_LIBRARIES}")
ENDIF(MITSUBA_FOUND AND VERBOSE)
