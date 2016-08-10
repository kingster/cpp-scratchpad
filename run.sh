#!/bin/bash

g++ -o $1.app $1.cpp
chmod +x $1.app
./$1.app
