## Makefile.am for DirectFB

ACLOCAL_AMFLAGS = -I m4

if HAVE_LINUX
LINUXONLY_DIRS = inputdrivers gfxdrivers
endif

if BUILD_TOOLS
TOOLS_DIR = tools
endif

if BUILD_TESTS
TESTS_DIR = tests
endif


NON_PURE_VOODOO_SUBDIRS = \
	systems			\
	wm			\
	interfaces 		\
	$(LINUXONLY_DIRS)

if ENABLE_DIVINE
DIVINE_DIR = lib/divine
endif

if ENABLE_SAWMAN
SAWMAN_DIR = lib/sawman
endif

SUBDIRS = \
	data			\
	docs			\
	include 		\
	lib			\
	src 			\
	$(SAWMAN_DIR)		\
	$(DIVINE_DIR)		\
	$(DVC_DIR)		\
	$(TOOLS_DIR)		\
	$(NON_PURE_VOODOO_SUBDIRS)	\
	$(PROXY_DIR)		\
	$(TESTS_DIR)		\
	patches			\
	rules			\
	build-android


bin_SCRIPTS = directfb-config

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = directfb.pc directfb-internal.pc

EXTRA_DIST = \
	autogen.sh	\
	fb.modes 		\
	directfb.spec.in	\
	directfb.spec


## Some special rules that may be useful ...

# Generate the HTML API documentation:
html:
	make -C docs/html

# Compile the directfb-csource utility:
directfb-csource:
	make -C tools directfb-csource


.PHONY: html directfb-csource
