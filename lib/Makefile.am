## Makefile.am for DirectFB/lib

if ENABLE_ONE
ONE_DIR = One
endif

if ENABLE_VOODOO
VOODOO_DIR = voodoo
endif

if ENABLE_FUSIONDALE
FUSIONDALE_DIRS = fusiondale
if ENABLE_ONE
FUSIONDALE_DIRS += fusiondale/one
endif
endif
SUBDIRS = direct fusion $(ONE_DIR) $(VOODOO_DIR) $(FUSIONDALE_DIRS) 

