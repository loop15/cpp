#!/bin/bash
dos2unix *.cpp *.h
astyle --options=.astylerc *.cpp
