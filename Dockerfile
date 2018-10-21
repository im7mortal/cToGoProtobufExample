# Created by Petr Lozhkin on 8/17/18.
# Copyright (c) 2015-2025 STURFEE INC ALL RIGHTS RESERVED

FROM ubuntu:16.04

# Install dependencies.
RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates \
        cmake \
        git \
        libatlas-base-dev \
        libboost-all-dev \
        libgflags-dev \
        libgoogle-glog-dev \
        libhdf5-dev \
        libprotobuf-dev \
        pkg-config \
        protobuf-compiler \
        python-yaml \
        python-six \
        wget && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y --no-install-recommends g++

RUN apt-get install  -y --no-install-recommends  autoconf automake libtool curl make g++ unzip

RUN  git clone https://github.com/protocolbuffers/protobuf.git && \
    cd protobuf && \
    git submodule update --init --recursive && \
    ./autogen.sh && \
    ./configure CXXFLAGS="" && \
    make -j"$(nproc)" && \
    make install  && \
    ldconfig

WORKDIR /goToCPPExample

COPY . .

RUN protoc --cpp_out=. params.proto

#RUN find / | grep protobuf.so | grep .so && exit 1

RUN g++ -I. -std=c++11 params.pb.cc library.cpp main.cpp `pkg-config --cflags --libs protobuf`

RUN ./a.out