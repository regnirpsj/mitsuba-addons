# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

ADD_DEFINITIONS("-DSINGLE_PRECISION")
ADD_DEFINITIONS("-DSPECTRUM_SAMPLES=3")

INCLUDE_DIRECTORIES(${MITSUBA_INCLUDE_DIR})

PLUGIN_SETUP(dcomplex SOURCES dcomplex.cpp DEPENDENCIES ${MITSUBA_LIBRARY_CORE} DEBUG)
PLUGIN_SETUP(simplest SOURCES simplest.cpp DEPENDENCIES ${MITSUBA_LIBRARY_CORE} DEBUG)
