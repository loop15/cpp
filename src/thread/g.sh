#!/bin/bash
dos2unix *.cpp *.h
astyle --options=.astylerc *.cpp
make clean
git add *.cpp *.h
git commit---
