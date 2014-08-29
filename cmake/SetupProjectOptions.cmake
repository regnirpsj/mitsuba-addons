# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

# glibcxx parallel support
OPTION(MITSUBA_ADDONS_GLIBCXX_PARALLEL "Enable GLIBCXX parallel mode" OFF)

# doxygen docs
OPTION(MITSUBA_ADDONS_DOC_DEV "Enable generation of developer documentation" OFF)
OPTION(MITSUBA_ADDONS_DOC_USR "Enable generation of user documentation"      OFF)

# unit testing
OPTION(MITSUBA_ADDONS_BLD_UTEST "Enable unit-test building by default"                          ON)
OPTION(MITSUBA_ADDONS_RUN_CTEST "Enable unit-test execution using CTest by default"             ON)
OPTION(MITSUBA_ADDONS_RUN_UTEST "Enable unit-test execution using the build system by default" OFF)

# coverage testing
OPTION(MITSUBA_ADDONS_PROFILE   "Enable support for coverage testing" OFF)

# tracing
OPTION(MITSUBA_ADDONS_TRACE_ALL "Enable runtime function tracing for everything!" OFF)
