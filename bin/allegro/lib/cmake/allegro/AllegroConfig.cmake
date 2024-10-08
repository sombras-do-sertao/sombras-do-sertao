#
# Allegro Package Config
#

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was AllegroConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

####################################################################################

set(ALLEGRO_PKG_BUGREPORT "https://github.com/liballeg/allegro5/issues")

# Allegro Targets
set(ALLEGRO_PKG_TARGETS "allegro;allegro_primitives;allegro_image;allegro_font;allegro_audio;allegro_acodec;allegro_ttf;allegro_color;allegro_memfile;allegro_physfs;allegro_dialog;allegro_video;allegro_main")

# Allegro Package Version
set(ALLEGRO_PKG_VERSION_MAJOR 5)
set(ALLEGRO_PKG_VERSION_MINOR 2)
set(ALLEGRO_PKG_VERSION_PATCH 9)
set(ALLEGRO_PKG_VERSION 5.2.9)

# Architecture, compiler and other low level flags
set(ALLEGRO_PKG_LIBRARY_ARCHITECTURE "")
set(ALLEGRO_PKG_COMPILER "GNU")
set(ALLEGRO_PKG_COMPILER_VERSION "13.2.0")
set(ALLEGRO_PKG_HOST_SYSTEM "Windows-10.0.18362")

# Targets
include("${CMAKE_CURRENT_LIST_DIR}/AllegroTargets.cmake")
