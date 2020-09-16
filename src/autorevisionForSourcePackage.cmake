cmake_minimum_required(VERSION 3.5)

# Runs autorevision to copy autorevision.cache to the source package
# (it should not be copied to binary package).

set(_STANDARD_CPACK_SOURCE_GENERATORS 7Z TGZ TXZ STGZ TBZ2 TZ ZIP CygwinSource)

# To detect if this is a CPack build of the *source* package, check whether $CPACK_GENERATOR
# (which is set to the current CPack generator) is in a standard list of source generators
# or is in the $CPACK_SOURCE_GENERATOR list.
#
if(("${CPACK_GENERATOR}" IN_LIST CPACK_SOURCE_GENERATOR) OR ("${CPACK_GENERATOR}" IN_LIST _STANDARD_CPACK_SOURCE_GENERATORS))

	if(NOT CPACK_SOURCE_INSTALLED_DIRECTORIES)
		execute_process(COMMAND "${CMAKE_COMMAND}" -E echo "Generator is \"${CPACK_GENERATOR}\", but this does not appear to be a source package")
		return()
	endif()

	# When packaging source, generate (and include) build_tools/autorevision.cache

	set(AUTOREVISION_OUTPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/build_tools/autorevision.cache")
	set(CACHEFILE "/home/lucas/warzone2100/build_tools/autorevision.cache")

	execute_process(COMMAND ${CMAKE_COMMAND} -DCACHEFILE=${CACHEFILE} -DOUTPUT_TYPE=sh -DOUTPUT_FILE=${AUTOREVISION_OUTPUT_FILE} -DSKIPUPDATECACHE="1" -P "/home/lucas/warzone2100/build_tools/autorevision.cmake"
		WORKING_DIRECTORY "/home/lucas/warzone2100")

	# Also generate (and include) lib/netplay/netplay_config.gen
	# for external scripts that need to determine the NETCODE_VERSION from the source tarball
	# (without running their own CMake build to generate netplay_config.h)

	set(OUTPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/lib/netplay/netplay_config.gen")
	set(CACHEFILE "${AUTOREVISION_OUTPUT_FILE}")
	set(_netplay_config_template_file "/home/lucas/warzone2100/lib/netplay/netplay_config.h.in")
	set(_project_root "/home/lucas/warzone2100")

	execute_process(COMMAND ${CMAKE_COMMAND} -DCACHEFILE=${CACHEFILE} -DPROJECT_ROOT=${_project_root} -DTEMPLATE_FILE=${_netplay_config_template_file} -DOUTPUT_FILE=${OUTPUT_FILE} -P "/home/lucas/warzone2100/lib/netplay/autorevision_netplay.cmake"
		WORKING_DIRECTORY "/home/lucas/warzone2100")

endif()
