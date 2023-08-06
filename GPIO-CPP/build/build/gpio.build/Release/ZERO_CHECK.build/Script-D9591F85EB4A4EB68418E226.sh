#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build
  make -f /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build
  make -f /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build
  make -f /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build
  make -f /Users/egorbadjanov/projects/C-CPP-Projects/GPIO-CPP/build/CMakeScripts/ReRunCMake.make
fi

