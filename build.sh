#!/bin/bash

#
# This is purely a build script to help me build all of my shit
#

set -x

# rm -f *.hex
# rm -f *.uf2

# make clean

# make dmqdesign/spin:warmwaffles
make lily58/mine:warmwaffles:flash \
    -e SPLIT_KEYBOARD=yes \
    -e OLED_ENABLE=yes \
    -e POINTING_DEVICE=cirque35 \
    -e POINTING_DEVICE_POSITION=right \
    -e USER_NAME=idank
