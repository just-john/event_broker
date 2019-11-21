# project notes

## event_broker

A first attempt at an event management system.

## requirements
cmake
ninja
g++

## building
see build.sh, other than that, you're on your own.

## warning
Build with clang segfaults (clang++ 8.0.0).  Due to bad weak_ptr, apparently.  But just works under g++.  Haven't dug into the issue, but might be worth checking out if there's undefined behaviour somewhere in the code.

## profile
The profile file declares environment variables for the project build.  For example, profile exports variables like:

    export ARTIFACT_ROOT="/artifacts"

It's worth starting here to understand that 3rd party libraries are built (by you) and made available in this directory, then first referenced in profile.

