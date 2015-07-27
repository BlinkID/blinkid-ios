#!/bin/sh
set -e

brew update
brew unlink xctool
brew install xctool
brew link --overwrite xctool